#ifndef UID_Array
#define UID_Array
#define MAX 100

typedef struct{
	int content[MAX];
	int count;
}SET;

void initSet(SET *S);
SET UnionSet(SET A, SET B);
SET IntersectionSet(SET A, SET B);
void insertLastSet(SET *A, int elem);
void deleteSet(SET *A, int elem);
void displaySet(SET S);

#endif
