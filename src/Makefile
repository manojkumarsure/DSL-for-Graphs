gsl: DSLGraph.cpp NS.o Graph.o
	g++ -std=c++11 DSLGraph.cpp NS.o Graph.o  -o gsl

Graph.o:Graph.cpp Graph.h
	g++ -std=c++11 -c Graph.cpp -o Graph.o

NS.o:NS.cpp NS.h
	g++ -std=c++11 -c NS.cpp -o NS.o

clean:
	rm *.o gsl
