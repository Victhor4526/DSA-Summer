#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "QueueLL.h"

void initQueue(Queue *Q) {
    Q->front = NULL;
    Q->rear = NULL;    
}

void enqueue(Queue *Q, int elem) { // always remember inserting element in the rear for the concept of Queue
    NodePtr temp = (NodePtr)malloc(sizeof(struct node));
    if(temp != NULL) {
        temp->data = elem;
        temp->next = NULL;
        if(Q->front == NULL) {
            Q->front = temp;
        } else {
            Q->rear->next = temp;
        }
        Q->rear = temp;
    }
}

void dequeue(Queue *Q) { // always remember dequeue is deleting element at the front for the concept of Queue
    if(Q->front != NULL) {
        NodePtr temp = Q->front;
        Q->front = temp->next;
        if(Q->front == NULL) {
            Q->rear = NULL;
        }
        free(temp);
    }
}

int front(Queue Q) {
    return (Q.front != NULL) ? Q.front->data : -1;
}

int rear(Queue Q) {
    return (Q.rear != NULL) ? Q.rear->data : -1;    
}

bool isEmpty(Queue Q) {
    return (Q.front == NULL && Q.rear == NULL) ? true : false;
}

void display(Queue Q) {
    if(Q.front != NULL) {
        NodePtr trav;
        printf("The Queue Number: ");
        for(trav = Q.front; trav != NULL; trav = trav->next) {
            printf("%d", trav->data);
            if(trav->next != NULL) {
                printf(" > ");
            }
        }
    } 
}
