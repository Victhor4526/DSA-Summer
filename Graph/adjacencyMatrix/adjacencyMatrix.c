#include <stdio.h>
#include <string.h>
#include "AdjacencyMatrix.h"

Graph *initGraph(int vertices){
	int i, j;
	Graph *graph = (Graph*)malloc(sizeof(Graph));
	if(graph !=NULL){
		graph->vertices=vertices;
		
		for(i=0; i < graph->vertices; i++){
			for(j=0; j < graph->vertices; j++){
				graph->adjjacenyMatrix[i][j]=0;
			}
		}
	}
	return graph; 
}

void addEdges(Graph *g, char head, char tail){
	g->adjjacenyMatrix[head - 'A'] [tail - 'A'] = 1;
	g->adjjacenyMatrix[head - 'A'] [tail - 'A'] = 1;
}

void printGraph(Graph g){
	printf("Adjacency Matrix: \n\n");
	printf("");
	int i, j;
	
	for(i=0; i<g.vertices; i++){
		printf("%c", 'A' +i);
	}
	printf("\n");
	
	for(i=0; i<g.vertices; i++){
		printf("%c", 'A' + i);
		for(j=0; j<g.vertices; j++){
			printf("%d ", g.adjjacenyMatrix[i][j]);
		}
		printf("\n");
	}
}
