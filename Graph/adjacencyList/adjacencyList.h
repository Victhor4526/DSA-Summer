#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H
#define MAX 5

typedef struct node {
	char data;
	struct node *next;
}*Nodetype;

typedef Nodetype AdjacenyL[MAX];

void initList(AdjacenyL L);
void addEdge(AdjacenyL L, char front, char rear);
void printAdjacencyList(AdjacenyL L);

#endif
