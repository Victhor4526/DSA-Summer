#include <stdio.h>
#include <stdlib.h>
#include "UID_Array.h"
#include <stdbool.h>

void initSet(SET *S){
	S->count=0;
}
SET UnionSet(SET A, SET B){
	SET C;
	initSet(&C);
	int a=0, b=0;
	
	while(a<A.count && b<B.count){
		if(A.content[a] < B.content[b]){
			C.content[C.count++] = A.content[a++];
		}else if(A.content[a] > B.content[b]){
			C.content[C.count++] = B.content[b++];
		}else{
			C.content[C.count++] = A.content[a++];
			b++;
		}
	}
	while(a < A.count){
		C.content[C.count++] = A.content[a++];
	}
	while (b < B.count){
		C.content[C.count++] = B.content[b++];
	}
	
	return C;		
}


SET IntersectionSet(SET A, SET B) {
	SET C;
	initSet(&C);
	
	int a = 0, b = 0;
	while(a < A.count && b < B.count) {
		if(A.content[a] < B.content[b]) {
			a++;
		} else if(A.content[a] > B.content[b]) {
			b++;
		} else {
			C.content[C.count++] = A.content[a++];
			b++;
		}
	}
	return C;
}

void insertLastSet(SET *A, int elem) {
	if(A->count < MAX) {
		int i;
		bool found = false;
		for(i = 0; i < A->count; i++) {
			if(A->content[i] == elem) {
				found = true;
				break;
			}
		}
		if(!found) {
			A->content[A->count++] = elem;
		} else {
			printf("Element %d already exist--", elem);
		}
	}
}

void deleteSet(SET *A, int elem) {
	if(A->count != 0) {
		int i, indx;
		bool found = false;
		for(i = 0; i < A->count; i++) {
			if(A->content[i] == elem) {
				found = true;
				indx = i;
				break;
			}
		}
		if(found) {
			for(i = indx; i < A->count; i++) {
				A->content[i] = A->content[i+1];
			}
			A->count--;
		} else {
			printf("Content '%d' does not exist in Set  \n", elem);
		}
	}
}

void displaySet(SET S){
	int i;
	
	for(i=0; i < S.
	count; i++){
		printf("%d ", S.content[i]);
	}
}

