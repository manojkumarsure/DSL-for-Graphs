/*
 * NS.cpp
 *
 *  Created on: 26-Mar-2015
 *     Authors: vamsi and Manoj
 */

#include "NS.h"

namespace std {

NS::NS() {
	// TODO Auto-generated constructor stub

	commands.push_back("create");
	commands.push_back("addNodes");
	commands.push_back("addEdges");
	commands.push_back("delNodes");
	commands.push_back("delEdges");
	commands.push_back("algorithm");
	commands.push_back("print");
	commands.push_back("union");
	commands.push_back("difference");
	commands.push_back("assign");
	commands.push_back("parse");
//	sort(commands.begin(),commands.end());

}

NS::~NS() {
	// TODO Auto-generated destructor stub
}

bool NS::isPresent(string s){
	return !(names.find(s)==names.end());
}


void NS::run(){
	string s;
	string prompt="\n>>> ";
	cout<<prompt;
	while(getline(cin,s)){
		stringstream ss(s);
		string commandName,graphName;
		if(ss>>commandName>>graphName){
			if(commandName!="create" && (find(commands.begin(), commands.end(), commandName)!=commands.end()) && !isPresent(graphName)){
				cerr<<"Graph Does Not Exist"<<endl;
				cout<<prompt;
				continue;
			}

			if(commandName=="create"){
				string from,file;
				if(ss>>from){
					ss>>file;
					if(from=="from" && file!=""){
						names[graphName]=Graph(file.c_str());
					}
					else
						cerr<<"Format create <graphName> (from <filename>)?"<<endl;

				}else{
					names[graphName]=Graph();
				}
				cout<<"\nGraphs present in Namespace:"<<endl;
				for(map<string,Graph>::iterator i=names.begin(),j=names.end();i!=j;i++)
					cout<<i->first<<" ";
				cout<<endl;
			}
			else if(commandName=="addNodes"){
				string a="I";
				while(ss>>a){
					names[graphName].addvertex(a);
					a="";
				}
				if(a!="")
					cerr<<"Format addNodes <graphName> (<vertexLabel>)+";
			}
			else if(commandName == "addEdges"){
				string a="I",b="I",c="I";
				while(ss>>a>>b>>c){
					names[graphName].addedge(a,b,c);
					a=b=c="";
				}
				if(a != "")
					cerr<<"Fomat addEdges <graphName> (<fromNode> <toNode> <Weight>)+"<<endl;

			}
			else if(commandName == "delNodes"){
				string a="I";
				while(ss>>a){
					names[graphName].delvertex(a);
					a="";
				}
				if(a!="")
					cerr<<"Format delNodes <graphName> (<VertexLabel>)+"<<endl;
			}
			else if(commandName == "delEdges"){
				string a,b;
				while(ss>>a>>b){
					names[graphName].deledge(a,b);
					a=b="";
				}
				if(a!="")
					cerr<<"Fomat delEdges <graphName> (<fromNode> <toNode>)+"<<endl;

			}
			else if(commandName == "algorithm"){
				string algName;
				if(ss>>algName){
					if(algName=="dijkstra"){
						string source="I";
						while(ss>>source){
							names[graphName].dijkstra(source);
							source="";
						}
						if(source!="")
							cerr<<"Foramt algorithm <graphName> dijkstra (source)+"<<endl;

					}
					else if(algName == "kruskal"){
						names[graphName].kruskal();
					}
					else{
						cerr<<algName <<" Not yet implemented"<<endl;
					}

				}else{
					cerr<<"Foramt algorithm <graphName> <algorithmName> <otherOptions>"<<endl;
					cerr<<"Available Algorithms:"<<endl;
					cerr<<"dijkstra Foramt - algorithm <graphName> dijkstra (source)+"<<endl;
					cerr<<"kruskal Foramt - algorithm <graphName> kruskal"<<endl;
				}
			}
			else if(commandName == "print"){
				names[graphName].print();
			}
			else if(commandName == "union"){
				string g1,g2;
				if(ss>>g2){
					if(names.find(g2)==names.end()){
						cerr<<g2<<" graph not created in the Namespace"<<endl;
					}else{
						names[graphName].Union(names[g2]);
					}

				}else{
					cerr<<"Format - union <graphName1> <graphName2>"<<endl;
				}
			}
			else if(commandName == "difference"){
				string g2;
				if(ss>>g2){
					if(names.find(g2)==names.end()){
						cerr<<g2<<" graph not created in the Namespace"<<endl;
					}else{
						names[graphName].difference(names[g2]);
					}
				}else{
					cerr<<"Format - difference <graphName1> <graphName2>"<<endl;
				}
			}else if(commandName == "assign"){
				string g2;
				if(ss>>g2){
					if(names.find(g2)==names.end()){
						cerr<<g2<<" graph not created in the Namespace"<<endl;
					}else{
						names[graphName]=names[g2];
					}
				}else{
					cerr<<"Format - assign <graphName1> <graphName2>"<<endl;
				}
			}else if(commandName == "parse"){
				string newGraphName,node;
				if(ss>>newGraphName){
					names[newGraphName]=Graph();
					string vertex="I";
					while(ss>>vertex){
						names[newGraphName].addAdjListOf(names[graphName],vertex);
						vertex="";
					}
					if(vertex!="")
						cerr<<"Foramt algorithm <graphName> dijkstra (source)+"<<endl;

				}else{
					cerr<<"Format - parse <graphName> <resultantGraphName> (nodes)+"<<endl;
				}

			}
			else
				cerr<<"Invalid Command"<<endl;

		}else if(commandName==""){

		}
		else{
			if((find(commands.begin(), commands.end(), commandName)!=commands.end()))
				cerr<<"Format : "<<commandName<<" <graphName> <otherOptions(if present)>"<<endl;
			else
				cerr<<"Format : <CommandName> <GraphName> <other options>"<<endl;
		}
		cout<<prompt;

	}

}

} /* namespace std */
