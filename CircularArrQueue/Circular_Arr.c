#include <stdio.h>
#include <stdlib.h>
#include "Circular_Arr.h"



void initQueue(CircullarQ *Q) {
    Q->front = 0;
    Q->rear = MAX - 1;
}

void enqueue(CircullarQ *Q, int elem) {
    if ((Q->rear + 2) % MAX != Q->front) {
        Q->rear = (Q->rear + 1) % MAX;
        Q->data[Q->rear] = elem;
    }
}

void dequeue(CircullarQ *Q) {
    if ((Q->rear + 1) % MAX != Q->front) {
        Q->front = (Q->front + 1) % MAX;
    }
}

bool isEmpty(CircullarQ Q) {
    return ((Q.rear + 1) % MAX == Q.front) ? true : false;
}

bool isFull(CircullarQ Q) {
    return ((Q.rear + 2) % MAX == Q.front) ? true : false;
}

void visualizeCircullarQueue(CircullarQ Q) {
    printf("%-10s %-10s %-10s\n", "INDEX", "DATA", "FRONT/REAR");
    int i;
    for (i = Q.front; i != (Q.rear + 1) % MAX; i = (i + 1) % MAX) {
        printf("%-10d %-10d", i, Q.data[i]);
        if (i == Q.front) {
            printf("<-FRONT");
        }
        if (i == Q.rear) {
            printf("<-REAR");
        }
        
        printf("\n");
    }
}

