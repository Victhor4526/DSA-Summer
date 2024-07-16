#include <stdio.h>
#include <stdlib.h>
#include "adjacencyList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	AdjacenyL L;
	initList(L);
	
	addEdges(L, 'A', 'B');
	addEdges(L, 'A', 'C');
	addEdges(L, 'A', 'D');

	addEdges(L, 'B', 'C');
	addEdges(L, 'B', 'D');
	addEdges(L, 'B', 'E');

	addEdges(L, 'C', 'D');
	
	addEdges(L, 'D', 'E');	
		
	printAdjacencyList(L);
	
	return 0;
}
