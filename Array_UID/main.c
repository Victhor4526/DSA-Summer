#include <stdio.h>
#include <stdlib.h>
#include "UID_Array.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	SET A = {{1, 2, 4, 15, 18,},  5};
	SET B = {{2, 4, 6, 15, 1}, 5};
	
	printf("\t\t\t\t WELCOME TO UID TOPIC");
	printf("\nSET A : ");
	displaySet(A);
	

	
	printf("\nSET B : ");
	displaySet(B);
	
	SET C = UnionSet(A, B);
	printf("\n\nUnion of SET: ");
	displaySet(C);
	
	SET D = IntersectionSet(A, B);
	printf("\n\nIntersection of SET: ");
	displaySet(D);
	
	printf("\n\nInserting element in SET A: ");
	insertLastSet(&A, 69);
	displaySet(A);
	
	printf("\n\nDeleting an element in Set:\n ");
	deleteSet(&A, 18); // delete 18
//	deleteSet(&A, 70); //  Content '70' does not exist in Set 
	displaySet(A);
	return 0;
}
