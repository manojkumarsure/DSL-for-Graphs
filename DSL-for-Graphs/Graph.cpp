/*
 * Graph.cpp
 *
 *  Created on: 26-Mar-2015
 *      Author: vamsi and Manoj
 */

#include "Graph.h"

namespace std {

/*
Graph class Implementation
*/
Graph::Graph() {
	// TODO Auto-generated constructor stub

	vertices=0;
	edges=0;
}

Graph::Graph(const char* filename){

	vertices=0;
	edges=0;

	ifstream file(filename);
	if(!file.is_open()){
		cerr<<"File doesnot exist"<<endl;
		return;
	}
	string a,b,c;
	while(file>>a>>b>>c){
		addedge(a,b,c);
	}
	file.close();

}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}
bool Graph::addedge(string a,string b,string c){
	if(numbers.find(a)==numbers.end()){
		numbers[a]=vertices++;
		labels[vertices-1]=a;
	}
	if(numbers.find(b)==numbers.end()){
		numbers[b]=vertices++;
		labels[vertices-1]=b;
	}
	stringstream ss(c);
	int weight;
	if((ss>>weight).fail()){
		cerr<<"Weight of edge ("<<a<<" "<<b<<") should be integer (given "<<c<<")"<<endl;
		return false;
	}
	bool found=false;
	for(vector<ii>::iterator i=adj[numbers[a]].begin(),j=adj[numbers[a]].end();i!=j;i++){
		if(i->first==numbers[b]){
			found = true;
			i->second = weight;
			break;
		}
	}
	if(!found)
		adj[numbers[a]].push_back(make_pair(numbers[b],weight));
	adj[numbers[b]];

	edges++;
	return true;
}

bool Graph::deledge(int f,int t){
	if(adj.find(f)==adj.end())
		return false;
	/*
	 * Code to find the edge in adjacency list
	 */

	for(vector<ii>::iterator i = adj[f].begin(),j = adj[f].end();i!=j;i++){
		if(i->first == t){
			adj[f].erase(i);
			return true;
		}else
			continue;
	}

	return false;

}

bool Graph::deledge(string from,string to){
	if(numbers.find(from)==numbers.end())
		return false;
	if(numbers.find(to)==numbers.end())
		return false;
	int f = numbers[from];
	int t = numbers[to];

	return deledge(f,t);
}

bool Graph::addvertex(string v){
	if(numbers.find(v)!=numbers.end())
		return false;
	numbers[v]=vertices++;
	labels[vertices-1]=v;
	adj[vertices-1];
	return true;
}

bool Graph::delvertex(string a){
	if(numbers.find(a) == numbers.end())
		return false;
	int v = numbers[a];
	adj.erase(v);

	bool deleted=false;

	for(map<int, vector<ii> >::iterator i=adj.begin(),j=adj.end();i!=j;i++){
		deleted = deleted || deledge(i->first,v);
	}
	return deleted;
}

int Graph::noOfVertices(){
	return adj.size();
}

int Graph::noOfEdges(){
	int total=0;
	for(map<int, vector<ii> >::iterator i = adj.begin(),j=adj.end();i!=j;i++)
		total+=i->second.size();
	return total;
}

bool Graph::dijkstra(int s){
	double duration;
	clock_t start=clock();
		vector<int> dist(vertices,INF);
		vector<int> parent(vertices,-1);
		dist[s]=0;
		priority_queue<ii, vector<ii> ,greater<ii> > pq;
		pq.push(make_pair(0,s));
		while(!pq.empty()){
			ii u=pq.top();
			pq.pop();
			if(dist[u.second]==u.first){
				for(vector<ii>::iterator i=adj[u.second].begin(),j=adj[u.second].end();i!=j;i++){
					ii v=*i;
					if(dist[u.second]+v.second < dist[v.first]){
						dist[v.first]=dist[u.second]+v.second;
						parent[v.first]=u.second;
						pq.push(make_pair(dist[v.first],v.first));
					}
				}
			}
		}
		duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;


		/*
		 * Printing the nodes and their distances from source nde
		 * */
		cout<<"Node : Distance from source ("<<labels[s]<<")"<<endl;
		for(map<int, vector<ii> >::iterator i = adj.begin(),j=adj.end();i!=j;i++){
			cout<<labels[i->first]<<" : ";
			if(dist[i->first]==INF)
				cout<<"inf"<<endl;
			else
				cout<<dist[i->first]<<endl;

		}
		cout<<"Time Taken in milliseconds : "<<duration*1000<<endl;
		return true;
}

bool Graph::dijkstra(string s){
	if(numbers.find(s)==numbers.end()){
		cerr<<"Source "<<s<<" Doesn't exist"<<endl;
		return false;
	}else{
		return dijkstra(numbers[s]);
	}
}


bool Graph::Union(Graph& g){
	double duration;
	clock_t start=clock();
	for(map<int, vector<ii> >::iterator i=g.adj.begin(),j=g.adj.end();i!=j;i++){
		for(vector<ii>::iterator k=i->second.begin(),kd=i->second.end();k!=kd;k++){
			stringstream ss;
			ss<<k->second;
			addedge(g.labels[i->first],g.labels[k->first],ss.str());
		}
	}
	duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	cout<<"Union done Time Taken in milliseconds : "<<duration*1000<<endl;
	return true;
}

bool Graph::difference(Graph& g){
	double duration;
	clock_t start=clock();
	for(map<int, vector<ii> >::iterator i=g.adj.begin(),j=g.adj.end();i!=j;i++){
		for(vector<ii>::iterator k=i->second.begin(),kd=i->second.end();k!=kd;k++){
			deledge(g.labels[i->first],g.labels[k->first]);
		}
	}
	duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	cout<<"Union done Time Taken in milliseconds : "<<duration*1000<<endl;
	return true;
}

int find_(vector<int>& pset,int x){
	if(pset[x]==-1)
		return x;
	return find_(pset,pset[x]);
}

void Union_(vector<int>& pset,int x,int y){
	int xset=find_(pset,x);
	int yset=find_(pset,y);
	pset[xset]=yset;
}

bool Graph::kruskal(){
	double duration;
	clock_t start=clock();
	vector<pair<int,ii> > edgeList,Mst;
	for(map<int, vector<ii> >::iterator i=adj.begin(),j=adj.end();i!=j;i++){
		for(vector<ii>::iterator k=i->second.begin(),kd=i->second.end();k!=kd;k++){
			edgeList.push_back(make_pair(k->second,make_pair(i->first,k->first)));
		}
	}
	sort(edgeList.begin(),edgeList.end());
	int mstCost=0;

	vector<int> pset(vertices,-1);
	for(vector<pair<int,ii> >::iterator i=edgeList.begin(),j=edgeList.end();i!=j;i++){
		pair<int,ii>& uv=(*i);
		if(find_(pset,uv.second.first)!=find_(pset,uv.second.second)){
			mstCost+=uv.first;
//			cout<<uv.first<<endl;
			Mst.push_back(uv);
			Union_(pset,uv.second.first,uv.second.second);
		}
	}
	duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	cout<<"Edges of MST are:"<<endl;
	for(vector<pair<int,ii> >::iterator i=Mst.begin(),j=Mst.end();i!=j;i++){
		pair<int,ii>& uv=(*i);
		cout<<"("<<labels[uv.second.first]<<","<<labels[uv.second.second]<<"):"<<uv.first<<endl;
	}
	cout<<"MST COST : "<<mstCost<<endl;
	cout<<"Kruskal done Time Taken in milliseconds : "<<duration*1000<<endl;
	return true;
}

ostream& Graph::print(ostream& o){
	for(map<int, vector<ii> >::iterator i = adj.begin(),j=adj.end();i!=j;i++){
		o<<labels[i->first]<<" : ";
		vector<ii>& temp=i->second;
		for(vector<ii>::iterator k=temp.begin(),kd=temp.end();k!=kd;k++){
			o<<" ("<<(labels[k->first])<<","<<k->second<<") ";
		}
		o<<endl;
	}
	cout<<"No of Vertices : "<<noOfVertices()<<endl;
	cout<<"No of Edges : "<<noOfEdges()<<endl;
	return o;
}

bool Graph::addAdjListOf(Graph& g,string vertex){
	if(g.numbers.find(vertex) == g.numbers.end()){
		cerr<<vertex<<" Doesn't exist in the input graph"<<endl;
		return false;
	}
	for(vector<ii> ::iterator i=g.adj[g.numbers[vertex]].begin(),j=g.adj[g.numbers[vertex]].end();i!=j;i++){
		stringstream ss1,ss2;
		ss1<<g.labels[i->first];
		ss2<<i->second;
		addedge(vertex,ss1.str(),ss2.str());
	}
	return true;
}
} /* namespace std */
