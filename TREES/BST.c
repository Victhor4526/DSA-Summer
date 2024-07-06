#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"
#include <stdbool.h>

void initBST(NodePtr* T){
	*T = NULL;
}

Product populate(NodePtr *T){
		Product candy[] = {
    		{"Bobot", 1.00, 69, {4, 1, 2024}},
    		{"Nougat", 2.50, 50, {26, 2, 2024}},
    		{"Safari", 2.50, 40, {1, 3, 2024}},
    		{"Pintura", 1.00, 30, {25, 4, 2024}},
    		{"Yaki", 1.00, 200, {15, 5, 2024}},
    		{"Barnuts", 2.50, 90, {17, 6, 2024}},
    		{"Mikmik", 1.50, 100, {19, 7, 2024}},
    		{"Judge", 1.50, 75, {20, 8, 2024}},
    		{"Snowbear", 2.00, 79, {29, 2, 2024}}
			};
	int i;
	for(i = 0; i < 9; i++) {
		 insertRecursive(T, candy[i]);
	}
}

void insertRecursive(NodePtr *T, Product prod){
	NodePtr *trav, temp;
	
	if(*T!=NULL && strcmp((*T)->item.prodName, prod.prodName)!=0){
		if(strcmp(prod.prodName, (*T)->item.prodName) < 0){
			 insertRecursive(&(*T)->left, prod);
		}else{
			 insertRecursive(&(*T)->right, prod);
		}
	}
	if(*T==NULL){
		*T = (NodePtr)malloc(sizeof(NodeType));
		if(*T !=NULL){
			(*T)->item=prod;
			(*T)->left = (*T)->right = NULL;
		}
	} 
}


void deleteRecursive(NodePtr *T, char *prodName){
	NodePtr *trav, temp;
	
	if(*T !=NULL && strcmp((*T)->item.prodName, prodName) != 0 ){
		(strcmp(prodName,(*T)->item.prodName) < 0) ? deleteRecursive(&(*T)->left, prodName) : deleteRecursive(&(*T)->right, prodName);
	}else if (*T !=NULL){
		if((*T)->right == NULL ){
			temp = *T;
			*T = temp->left;
			free(temp);
		}
	}else{
		for(trav=&(*T)->right; (*trav)->left != NULL; trav= &(*trav)->left){}
		temp = *trav;
		(*T)->item = temp->item;
		*trav = temp ->left;
		free(temp);
	}
}

void printBFS(NodePtr T) {
	Queue Q;
	initQueue(&Q);
	enqueue(&Q, T);
	
	while(!isEmpty(Q)) {
		NodePtr current = dequeue(&Q);
		if(current != NULL) {
			printf("%s ", current->item.prodName);
			enqueue(&Q, current->left);
			enqueue(&Q, current->right);
		}
	}
}


void preorder(NodePtr T){
    if (T != NULL) {
        printf("Product Name: %s\n", T->item.prodName);
        printf("Product Price: %.2f\n", T->item.prodPrice);
        printf("Product Quantity: %d\n", T->item.prodQty);
        printf("Expiration Date: %02d-%02d-%04d\n\n", T->item.expDate.day, T->item.expDate.month, T->item.expDate.year);
        
        preorder(T->left);
        preorder(T->right);
    }
}

void inorder(NodePtr T){
    if (T != NULL) {
        inorder(T->left);
        
        printf("Product Name: %s\n", T->item.prodName);
        printf("Product Price: %.2f\n", T->item.prodPrice);
        printf("Product Quantity: %d\n", T->item.prodQty);
        printf("Expiration Date: %02d-%02d-%04d\n\n", T->item.expDate.day, T->item.expDate.month, T->item.expDate.year);
        
        inorder(T->right);
    }
}

void postorder(NodePtr T){
    if (T != NULL) {
        postorder(T->left);
        postorder(T->right);
        
        printf("Product Name: %s\n", T->item.prodName);
        printf("Product Price: %.2f\n", T->item.prodPrice);
        printf("Product Quantity: %d\n", T->item.prodQty);
        printf("Expiration Date: %02d-%02d-%04d\n\n", T->item.expDate.day, T->item.expDate.month, T->item.expDate.year);
    }
}

void initQueue(Queue *Q) {
	Q->front = NULL;
	Q->rear = NULL;	
}

bool isEmpty(Queue Q) {
	return (Q.front == NULL) ? true : false;
}

void enqueue(Queue *Q, NodePtr Tree) {
	QueueNodePtr newQueueNode = (QueueNodePtr)malloc(sizeof(QueueNode));
	if(newQueueNode != NULL) {
		newQueueNode->Tree = Tree;
		newQueueNode->next = NULL;
		if(Q->rear == NULL) {
			Q->front = newQueueNode;
		} else {
			Q->rear->next = newQueueNode;
		}
		Q->rear = newQueueNode;
	}	
}

NodePtr dequeue(Queue *Q) {
	if(!isEmpty(*Q)) {
		QueueNodePtr temp = Q->front;
        NodePtr Tree = temp->Tree;
        Q->front = temp->next;
        
        if (Q->front == NULL) {
            Q->rear = NULL;
        }
        
        free(temp);
        return Tree;
	}
}

