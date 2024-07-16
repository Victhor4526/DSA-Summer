#include <stdio.h>
#include <stdlib.h>
#include "AdjacencyMatrix.h"


int main(int argc, char *argv[]) {
	Graph *graph = initGraph(5);
	
	addEdges(graph, 'A', 'B');
	addEdges(graph, 'A', 'C');
	addEdges(graph, 'A', 'D');

	addEdges(graph, 'B', 'C');
	addEdges(graph, 'B', 'D');
	addEdges(graph, 'B', 'E');

	addEdges(graph, 'C', 'D');

	addEdges(graph, 'D', 'E');
	
	printGraph(*graph);
	
	return 0;
}
