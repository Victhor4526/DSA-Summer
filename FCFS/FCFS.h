#ifndef FCFS_h
#define FCFS_h
#define MAXPROCESS 15

typedef struct {
	int burstTime;
	int arivalTime;
} Inputype;

typedef struct {
	int executionTime;
	int waitingTime;
	int turnaroundTime;
} Timetype;

typedef struct node{
	Inputype input;
	Timetype t;
	struct node *next;
} *Nodetype;

typedef struct {
	Nodetype front;
	Nodetype rear;
} Queue;

typedef struct {
    Queue prod [MAXPROCESS];
    char IDs[MAXPROCESS];
    int count;
} Process;

void initQueue(Queue *Q);
void initProcess(Process *P);
void enqueue(Queue *Q, Inputype input);
int getBurstT(Queue Q);
int getArrivalT(Queue Q);
void input(Process *P);
void calculateProcess(Process *P);
int getTotalWeighT(Process P);
int getTotalTurnaroundT(Process P);
float getAve(int total, int count);
void getsorted(Process *P);
void visualize(Process P);

#endif
