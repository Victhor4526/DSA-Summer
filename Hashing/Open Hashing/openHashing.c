#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "openHashing.h"
#define MAX 10



void initDict(Dictionary D) {
	int i;
    for ( i = 0; i < MAX; i++) {
        D[i] = NULL;
    }
}

int hash(int cageNo) {
    return cageNo % MAX;
}

void SortviaAge(Dictionary D, AnimalInfo info) {
    Node **trav, *temp;
   
    int hashVal = hash(info.cageNo);

    for (trav = &D[hashVal]; *trav != NULL && ((*trav)->info.Animal.age < info.Animal.age || (*trav)->info.cageNo == info.cageNo); trav = &(*trav)->next) {}

    if (*trav == NULL || (*trav)->info.cageNo != info.cageNo) {
        temp = (Node*)malloc(sizeof(Node));
        if (temp != NULL) {
            temp->info = info;
            temp->next = *trav;
            *trav = temp;
        }
    }
}

void deleteCageNo(Dictionary D, int cageNo) {
    Node **trav, *temp;
    int hashVal = hash(cageNo);

    for (trav = &D[hashVal]; *trav != NULL && (*trav)->info.cageNo != cageNo; trav = &(*trav)->next) {}

    if (*trav != NULL) {
        temp = *trav;
        *trav = temp->next;
        free(temp);
    } else {
        printf("--OPPS Cage no %d doesn't exist--\n", cageNo);
    }
}

void visualize(Dictionary D) {
    int i;
	printf("%-10s %-10s\n", "INDEX", "INFO");

    for (i = 0; i < MAX; i++) {
        printf("%-10d", i);

        if (D[i] == NULL) {
            printf("%-10s", "EMPTY");
        } else {
            Node *trav;
            for (trav = D[i]; trav != NULL; trav = trav->next) {
                printf(" %s | %d | %s | %s | %d", trav->info.Animal.name, trav->info.Animal.age, trav->info.location, trav->info.species, trav->info.cageNo);
                if (trav->next != NULL) {
                    printf(" --> ");
                }
            }
        }
        printf("\n");
    }
}
