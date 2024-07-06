#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    NodePtr T;
    initBST(&T);
    
    Product candy = populate(&T);
    Product prod1 = {"Yakult", 9.00, 30, {22, 10, 2024}};
    
    insertRecursive(&T, prod1);
    
    printf("Bread First Search Traversal:\n");
    printBFS(T);
    
    printf("\n\nAfter deleting 'Bobot'\n");
    deleteRecursive(&T, "Bobot"); 
    
    printf("\n\n Inorder traversal Trees:\n");
   	inorder(T);
    
    printf("\n\n Preorder traversal Trees:\n");
   	preorder(T);
    
    printf("\n\nPostorder traversal Trees:\n");
    postorder(T);
    
    return 0;
}

