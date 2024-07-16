#include <stdio.h>
#include <stdlib.h>
#include "adjacencyList.h"
void initList(AdjacenyL L){
	int i;
	
	for(i=0; i<MAX; i++){
		L[i]=NULL;
	}
}

void addEdges(AdjacenyL L, char front, char rear){
	if(front - 'A' < MAX) {
		Nodetype *trav, temp;
		for(trav = &L[front-'A']; *trav != NULL; trav = &(*trav)->next){}
		if(*trav == NULL) {
			temp = (Nodetype)malloc(sizeof(struct node));
			if(temp != NULL) {
				temp->data = rear;
				temp->next = *trav;
				*trav = temp;
			}
		}
	}
	
	if(rear - 'A' < MAX) {
		Nodetype *traverse1, temp1;
		for(traverse1 = &L[rear - 'A']; *traverse1 != NULL; traverse1 = &(*traverse1)->next){}
		if(*traverse1 == NULL) {
			temp1 = (Nodetype)malloc(sizeof(struct node));
			if(temp1 != NULL) {
				temp1->data = front;
				temp1->next = *traverse1;
				*traverse1 = temp1;
			}
		}
	}
}

void printAdjacencyList(AdjacenyL L){
	int i;
	printf("Adjacency List:\n\n");
	for(i = 0; i < MAX; i++) {
		printf("%c: ", i + 65);
		if(L[i] == NULL) {
			printf("OPPS EMPTY");
		}else {
			Nodetype trav;
			for(trav = L[i]; trav != NULL; trav = trav->next) {
				printf("%c", trav->data);
				if(trav->next != NULL) {
					printf(" -> -> ");
				}
			}
		}
		
		printf("\n");
	}
}
