#ifndef BST_H
#define BST_H

#include <stdbool.h>
typedef struct{
	int day, month, year;
}Date;

typedef struct{
	char prodName[20];
	float prodPrice;
	int prodQty;
	Date expDate;
}Product;

typedef struct node{
	Product item;
	struct node *left, *right;
}NodeType, *NodePtr;

typedef struct queueNode{
	NodePtr Tree;
	struct queueNode *next;
}QueueNode, *QueueNodePtr;

typedef struct {
	QueueNodePtr front;
	QueueNodePtr rear;
}Queue;



void initBST(NodePtr* T);
Product populate(NodePtr *T);
void insertRecursive(NodePtr *T, Product prod);
void deleteRecursive(NodePtr *T, char *prodName);
void inorder(NodePtr root);
void preorder(NodePtr root);
void postorder(NodePtr root);
void BFS(NodePtr root);

void initQueue(Queue *Q);
bool isEmpty(Queue Q);
void enqueue(Queue *Q, NodePtr tree);
NodePtr dequeue(Queue *Q);

#endif
