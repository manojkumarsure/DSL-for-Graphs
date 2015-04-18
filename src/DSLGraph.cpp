//============================================================================
// Name        : DSlGraph.cpp
// Author      : CS12B057 & CS12B028
// Version     :
// Copyright   : Your copyright notice
// Description : DSL in C++, Ansi-style
//============================================================================

#include <iostream>
#include "NS.h"
using namespace std;

int main(int argc,char* argv[]) {
	cout<<"######################################################################"<<endl;
	cout<<"#      DSL for Graph Algorithms                                      #"<<endl;
	cout<<"# Command        Usage                                               #"<<endl;
	cout<<"# create   - create <graphName> from <filename>                      #"<<endl;
	cout<<"# addNodes - addNodes <graphName> (<vertexLabel>)+                   #"<<endl;
	cout<<"# addEdges - addEdges <graphName> (<fromNode> <toNode> <Weight>)+    #"<<endl;
	cout<<"# delNodes - delNodes <graphName> (<VertexLabel>)+                   #"<<endl;
	cout<<"# delEdges - delEdges <graphName> (<fromNode> <toNode>)+             #"<<endl;
	cout<<"# algorithm- algorithm <graphName> <algorithmName> <otherOptions>    #"<<endl;
	cout<<"#     dijkstra -algorithm <graphName> dijkstra (source)+             #"<<endl;
	cout<<"#     kruskal  -algorithm <graphName> kruskal                        #"<<endl;
	cout<<"# print   - print <graphName>                                        #"<<endl;
	cout<<"# union   - union <graphName1> <graphName2>                          #"<<endl;
	cout<<"# difference   - difference <graphName1> <graphName2>                #"<<endl;
	cout<<"# assign   - assign <graphName1> <graphName2>                        #"<<endl;
	cerr<<"# parse    - parse <graphName> <resultantGraphName> (nodes)+         #"<<endl;
	cout<<"# Ctrl+D   - quit                                                    #"<<endl;
	cout<<"######################################################################"<<endl;
	NS n;
	n.run();
	return 0;
}
