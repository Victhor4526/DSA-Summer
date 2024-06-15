#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct {
    char Fname[20];
    char Lname[20];
}studName;

typedef struct {
    int month;
    int year;
}bday;

typedef struct {
    studName name;
    bday birthdate;
    int age;
    int idNum;
}studentInfo;

typedef struct {
    studentInfo studList[MAX];
    int studCount;
}classRecord;

// typedef enum {TRUE, FALSE} Boolean;

void initialize(classRecord *L);
void insertFirst(classRecord *L, studentInfo LL);
void insertLast(classRecord *L, studentInfo LL);
void insertAtIndex(classRecord *L, studentInfo LL, int index);
void sort(classRecord *L);
void insertSortedByAge(classRecord *L, studentInfo LL);

void deleteFirst(classRecord *L);
void deleteLast(classRecord *L);


void deleteStudByID(classRecord *L, int idNum);

void printArray(classRecord L);

int main () {
    classRecord L;
    initialize(&L);
    
    studentInfo stud1 = {{"Luke Joseph", "Balisacan"}, {01, 1990}, 34, 18105635};
    studentInfo stud2 = {{"CCJ", "Balisacan"}, {02, 1991}, 33, 16105635};
    studentInfo stud3 = {{"Kent Joseph", "Riconalla"}, {03, 1992}, 32, 18111111};
    studentInfo stud4 = {{"Maria", "Zaragoza"}, {03, 1994}, 30, 15195444};
    studentInfo stud5 = {{"Murliwani", "Gangaram"}, {04, 1995} , 29, 18122321};
    
    insertFirst(&L, stud1);
    insertLast(&L, stud2);
    insertFirst(&L, stud3);
    insertAtIndex(&L, stud4, 2);
    
    printArray(L);
    
    printf("\n Student Count: %d", L.studCount);
    
    printf("\n\nAfter sorting by age:\n\n");
    sort(&L);
    printArray(L);
    
    printf("\n\n After inserting by age:--\n\n");
    insertSortedByAge(&L, stud5);
    printArray(L);
    
    printf("\n\nAfter deleting first:--\n\n");
    deleteFirst(&L);
    printArray(L);
    
    printf("\n\nAfter deleting last:--\n\n");
    deleteLast(&L);
    printArray(L);
    
    printf("\n\nAfter deleting stud by id:--\n\n");
    deleteStudByID(&L, 18102929);
    printArray(L);
    
    return 0; 
}

void initialize(classRecord *L) {
    L->studCount = 0;
}

void insertFirst(classRecord *L, studentInfo LL) {
    int i;
    if(L->studCount < MAX) {
        for(i = L->studCount; i > 0; i--) {
            L->studList[i] = L->studList[i-1];
        }
        L->studList[0] = LL;
        L->studCount++;
    }
}

void insertLast(classRecord *L, studentInfo LL) {
    if(L->studCount < MAX) {
        L->studList[L->studCount] = LL;
        L->studCount++;
    }
}

void insertAtIndex(classRecord *L, studentInfo LL, int index) {
    if(L->studCount < MAX && L->studCount >= index) {
        int i;
        for(i = L->studCount; i > index; i--) {
            L->studList[i] = L->studList[i-1];
        }
        L->studList[index] = LL;
        L->studCount++;
    }
} 

void sort(classRecord *L) {
    int i, j;
    studentInfo temp;
    for(i = 0; i < L->studCount; i++) {
        for(j = i + 1; j < L->studCount; j++) {
            if(L->studList[i].age > L->studList[j].age) {
                temp = L->studList[i];
                L->studList[i] = L->studList[j];
                L->studList[j] = temp;
            }
        }
    }
}

void insertSortedByAge(classRecord *L, studentInfo LL) {
    if(L->studCount < MAX) {
        int i;
        for(i = L->studCount; i > 0 && L->studList[i].age > LL.age; i--) {
            L->studList[i] = L->studList[i-1];
        }
        L->studList[i+1] = LL;
        L->studCount++;
    }
}

void deleteFirst(classRecord *L) {
    if(L->studCount != 0) {
        int i;
        for(i = 0; i < L->studCount; i++) {
            L->studList[i] = L->studList[i+1];
        }
        L->studCount--;
    }
}

void deleteLast(classRecord *L) {
    if(L->studCount != 0) {
        L->studCount--;
    }
}

void deleteStudByID(classRecord *L, int idNum) {
	if(L->studCount != 0) {
		int i, found = 0;
		for(i = 0; i < L->studCount; i++) {
			if(L->studList[i].idNum == idNum) {
				found = 1;
				break;
			}
		}
		if(found != 0) {
			for(; i < L->studCount; i++) {
				L->studList[i] = L->studList[i+1];
			}
			L->studCount--;
		} else {
			printf("ID number not found\n\n");
		}
	}
}

void printArray(classRecord L) {
    int i;
    printf("%-10s %-10s %-10s %-10s %-10s %-10s\n", "FIRSTNAME", "LASTNAME", "MONTH", "YEAR", "AGE", "IDNUM");
    for(i = 0; i < L.studCount; i++) {
        printf("%-10s %-10s %-10d %-10d %-10d %-10d", L.studList[i].name.Fname, L.studList[i].name.Lname, L.studList[i].birthdate.month, L.studList[i].birthdate.year, L.studList[i].age, L.studList[i].idNum);
        printf("\n");
    }
}
