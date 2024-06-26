#include<stdio.h>
#include<stdlib.h>
#include "FCFS.h"
#include <stdbool.h>

void initQueue(Queue *Q){
	Q->front=NULL;
	Q->rear=NULL;
}
void initProcess(Process *P){
	int i;
	for(i = 0; i < MAXPROCESS; i++) {
		initQueue(&P->prod[i]);
		P->IDs[i] = 'A' + i;
	}
	P->count = 0;
}
void enqueue(Queue *Q, Inputype input){
	Nodetype temp = (Nodetype)malloc(sizeof(struct node));
	if(temp != NULL) {
		temp->input = input;
		temp->t.executionTime=0;
		temp->t.waitingTime = 0;
		temp->t.turnaroundTime = 0;
		temp->next = NULL;
		if(Q->front == NULL) {
			Q->front = temp;
		} else {
			Q->rear->next = temp;
		}
		Q->rear = temp;
	}
}
int getBurstT(Queue Q){
	return(Q.front != NULL) ? Q.front->input.burstTime : -1;
}
int getArrivalT(Queue Q){
	return(Q.front != NULL) ? Q.front->input.arivalTime : -1;
}
void input(Process *P){
		int i;
	Inputype input;
	for(i = 0; i < P->count; i++) {
		printf("Process %c: ", i + 65);
		scanf("%d %d", &input.burstTime, &input.arivalTime);
		enqueue(&P->prod[i], input);
	}
	system("cls");
	calculateProcess(P);
	getsorted(P);
}
void calculateProcess(Process *P){
	bool visited[MAXPROCESS] = { false };
	int i, v = 0, currtTime = 0, index;
	
	while(v < P->count) {
		int Arrival = 999;
		index = -1;
		
		for(i = 0; i < P->count; i++) {
			int ArrivalT = getArrivalT(P->prod[i]);
			if(ArrivalT < Arrival && visited[i] == false) {
				Arrival = ArrivalT;
				index = i;
			}
		}
		
		int burstT = getBurstT(P->prod[index]);
		int ArrivalT = getArrivalT(P->prod[index]);
		
		P->prod[index].front->t.executionTime = currtTime + burstT;
		
		currtTime = P->prod[index].front->t.executionTime;
		
		P->prod[index].front->t.waitingTime = P->prod[index].front->t.executionTime - burstT - ArrivalT;
		
		P->prod[index].front->t.turnaroundTime = P->prod[index].front->t.waitingTime + burstT;
		
		visited[index] = true;
		
		v++;
	}
}
int getTotalWeighT(Process P){
	int i, total = 0;
	for(i = 0; i < P.count; i++) {
		total += P.prod[i].front->t.waitingTime;
	}
	return total;
}
int getTotalTurnaroundT(Process P){
	int i, total = 0;
	for(i = 0; i < P.count; i++) {
		total += P.prod[i].front->t.turnaroundTime;
	}
	return total;
}
float getAve(int total, int count){
	return (float)total/count;
}
void getsorted(Process *P){
	 int i, j;
    for(i = 0; i < P->count; i++) {
        for(j = i + 1; j < P->count; j++) {
            if(P->prod[i].front->t.executionTime > P->prod[j].front->t.executionTime) {
                Queue temp_Queue = P->prod[i];
                P->prod[i] = P->prod[j];
                P->prod[j] = temp_Queue;
                
                char temp_ID = P->IDs[i];
                P->IDs[i] = P->IDs[j];
                P->IDs[j] = temp_ID;
    		}	
		}
	}
}
void visualize(Process P){
		if(P.count != 0) {
		printf("Total process: %d", P.count);
		printf("\n\nOUTPUT INFORMATION\n");
		printf("%10s : %-5d", "Waiting Time Total", getTotalWeighT(P));
		printf("\n%10s : %-5.2f", "Waiting Time Average", getAve(getTotalWeighT(P), P.count));
		printf("\n%10s : %-5d", "Turnaround Time Total", getTotalTurnaroundT(P));
		printf("\n%10s : %-5.2f", "Turnaround Time Average", getAve(getTotalTurnaroundT(P), P.count));
		printf("\n\n\n%10s | %5s | %5s | %5s | %5s | %5s\n", "PROCESS", "BT", "AT", "ET", "WT", "TT");
    	int i;
    	for(i = 0; i < P.count; i++) { 
    		printf("%10c | %5d | %5d | %5d | %5d | %5d\n", P.IDs[i], P.prod[i].front->input.burstTime, P.prod[i].front->input.arivalTime, P.prod[i].front->t.executionTime, P.prod[i].front->t.waitingTime, P.prod[i].front->t.turnaroundTime);
		}
		printf("%10s - ----- - ----- - ----- | %5d | %5d\n\n\n", "TOTAL", getTotalWeighT(P), getTotalTurnaroundT(P));
	}
	

}
