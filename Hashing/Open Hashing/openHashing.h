#ifndef OPEN_HASHING
#define OPEN_HASHING
#define MAX 10

typedef struct {
    
    char name[16];
    int age;
} AnimalType;

typedef struct {
    AnimalType Animal;
    char species[24]; // municipality
    char location[16]; // species
    int cageNo;
} AnimalInfo;

typedef struct node {
    AnimalInfo info;
    struct node *next;
} Node;

typedef Node* Dictionary[MAX];


void initDict(Dictionary D);
int hash(int houseNo);
void SortviaAge(Dictionary D, AnimalInfo info);
void deleteCageNo(Dictionary D, int cageNo);
void visualize(Dictionary D);

#endif
