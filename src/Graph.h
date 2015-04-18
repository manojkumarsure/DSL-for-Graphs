/*
 * Graph.h
 *
 *  Created on: 26-Mar-2015
 *      Author: vamsi and Manoj
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <thread>
#define INF 1000000000

namespace std {
typedef pair<int,int> ii;

/*
* Graph implementation
*/
class Graph {
	map<int, vector<ii> > adj;
	map<string,int> numbers;
	map<int,string> labels;
	int vertices,edges;
public:
	Graph();
	Graph(const char* filename);
	int noOfEdges();
	int noOfVertices();
	bool addedge(string from,string to,string weight);
	bool deledge(int f,int t);
	bool deledge(string from,string to);
	bool addvertex(string v);
	bool delvertex(string a);
	bool dijkstra(string s);
	bool dijkstra(int s);
	bool kruskal();
	bool Union(Graph& g);
	bool difference(Graph& g);
	bool addAdjListOf(Graph& g,string vertex);
	ostream& print(ostream& o=cout);
	virtual ~Graph();
};


} /* namespace std */

#endif /* GRAPH_H_ */
