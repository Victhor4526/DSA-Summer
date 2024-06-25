#ifndef QUEUE_CIRCULLAR
#define QUEUE_CIRCULLAR
#include <stdbool.h>
#define MAX 10

typedef struct{
	int data[MAX];
	int front;
	int rear;
}CircullarQ;

void initQueue(CircullarQ *Q);
void enqueue(CircullarQ *Q, int elem);
void dequeue(CircullarQ *Q);
bool isEmpty(CircullarQ Q);
bool isFull(CircullarQ Q);
void visualizeCircullarQueue(CircullarQ Q);

#endif
