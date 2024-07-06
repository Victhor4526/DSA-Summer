#ifndef CLOSE_HASHING
#define CLOSE_HASHING
#define MAX 10
#define EMPTY 
#define DELETED 


typedef struct {
    
    char name[16];
    int age;
} AnimalType;

typedef struct {
    AnimalType Animal;
    char species[24]; 
    char location[16]; 
    int cageNo;
    int status;
} AnimalInfo;

typedef AnimalInfo Dictionary[MAX];

void initDict(Dictionary D);
int hash(int houseNo);
void insert(Dictionary D, AnimalInfo info);
void deleteInfoByCageNo(Dictionary D, int houseNo);
void visualize(Dictionary D);

#endif
