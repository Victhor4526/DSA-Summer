#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H
#define MAX 5

typedef struct{
	int adjjacenyMatrix[MAX][MAX];
	int vertices;
}Graph;

Graph *initGraph(int vertices);
void addEdges(Graph *g, char head, char tail);
void printGraph(Graph graph);

#endif
