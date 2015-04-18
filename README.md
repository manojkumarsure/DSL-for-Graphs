# DSL-for-Graphs
This is done as part of Program Analysis Course(Jan-May'15).
This is a Domain specific language for graphs created by two of us (Myself and Vamsi).
As of now, the language supports the following commands.
#####################################################################
      DSL for Graph Algorithms                                      #
 Command        Usage                                               #
 create   - create <graphName> from <filename>                      #
 addNodes - addNodes <graphName> (<vertexLabel>)+                   #
 addEdges - addEdges <graphName> (<fromNode> <toNode> <Weight>)+    #
 delNodes - delNodes <graphName> (<VertexLabel>)+                   #
 delEdges - delEdges <graphName> (<fromNode> <toNode>)+             #
 algorithm- algorithm <graphName> <algorithmName> <otherOptions>    #
     dijkstra -algorithm <graphName> dijkstra (source)+             #
     kruskal  -algorithm <graphName> kruskal                        #
 print   - print <graphName>                                        #
 union   - union <graphName1> <graphName2>                          #
 difference   - difference <graphName1> <graphName2>                #
 assign   - assign <graphName1> <graphName2>                        #
 parse    - parse <graphName> <resultantGraphName> (nodes)+         #
 Ctrl+D   - quit                                                    #
#####################################################################
