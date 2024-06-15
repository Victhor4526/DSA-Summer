#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char name[20];
    int idNum;
    int age;
} info;

typedef struct node {
    info data;
    struct node *next;
} node, *nodePtr;

void initialize(nodePtr *L) {
    *L = NULL;
}

void insertFront(nodePtr *head, info data) {
    // Allocate memory for the new node
    nodePtr newNode = (nodePtr)malloc(sizeof(node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
    }
    
    // Populate the new node with data
    strcpy(newNode->data.name, data.name);
    newNode->data.idNum = data.idNum;
    newNode->data.age = data.age;
    
    // Set the next pointer of the new node to point to the current head
    newNode->next = *head;
    
    // Update the head of the list to point to the new node
    *head = newNode;
}

void displayList(nodePtr head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    nodePtr current = head;
    printf("List Contents:\n");
    while (current != NULL) {
        printf("Name: %s, ID: %d, Age: %d\n", current->data.name, current->data.idNum, current->data.age);
        current = current->next;
    }
}

int main() {
    nodePtr head = NULL; // Initialize an empty list
    
    info data[4] = {
        {"Victor Aguhob", 18105635, 25},
        {"Murli Gangaram", 16105635, 26},
        {"Lj Baliscan", 15105635, 24},
        {"Angel Zaragoza", 1105324, 29},
    };

    insertFront(&head, data[0]);
    insertFront(&head, data[1]);
    insertFront(&head, data[2]);
    insertFront(&head, data[3]);
    
    displayList(head);

    return 0;
}

