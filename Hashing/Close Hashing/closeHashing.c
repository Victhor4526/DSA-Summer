#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define EMPTY 
#define DELETED 
#include "closeHashing.h"
#define MAX 10



void initDict(Dictionary D) {
	int i;
	for(i = 0; i < MAX; i++) {
		D[i].status = EMPTY;
	}
}

int hash(int cageNo) {
	return cageNo % MAX;
}

void insertSortByAge(Dictionary D, AnimalInfo info) {
	int hashVal = hash(info.cageNo);
	int indx = hashVal;
	int front = indx;
	
	while(D[indx].cageNo != info.cageNo && D[indx].status != EMPTY && D[indx].status != DELETED){
		indx = (indx+ 1) % MAX;
		if(indx == front) {
			printf("OPPS Dictionary is full. CageNo : %d not inserted", info.cageNo);
			return;
		}
	}
	if(D[indx].status == EMPTY || D[indx].status == DELETED) {
		D[indx] = info;
	} else if (D[indx].cageNo == info.cageNo) {
		printf("Opps Duplicate Cage No: %d\n", info.cageNo);
		return;
	}
}

void deleteInfoByCageNo(Dictionary D, int cageNo) {
	int hashVal = hash(cageNo);
	int indx = hashVal;
	int front = indx;
	
	while(D[indx].cageNo != cageNo) {
		indx = (indx + 1) % MAX;
		if(indx == front) {
			printf("Error: Not exist cage no: %d\n", cageNo);
			return;
		}
	}
	
	if(D[indx].cageNo == cageNo) {
		D[indx].status = DELETED;
	}
}

void visualize(Dictionary D) {
	int i;
	printf("%-10s %-10s\n", "INDEX", "DATA");
	for(i = 0; i < MAX; i++) {
		printf("%-10d", i);
		if(D[i].status == EMPTY) {
			printf("%-10s", "EMPTY"); 
		} else if(D[i].status == DELETED) {
			printf("%-10s", "DELETED");
		} else {
			printf("%-8s, %-8d | %-8s, %-8s %-8d", D[i].Animal.name, D[i].Animal.age, D[i].species, D[i].location, D[i].cageNo);
		}
		printf("\n");
	}
}
