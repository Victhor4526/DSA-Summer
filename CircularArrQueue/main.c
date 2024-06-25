#include <stdio.h>
#include <stdlib.h>
#include "Circular_Arr.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	    
	CircullarQ Q;
    initQueue(&Q);
    
    enqueue(&Q, 1);
    enqueue(&Q, 2);
    
    dequeue(&Q);
    dequeue(&Q);
    
    enqueue(&Q, 3);
    enqueue(&Q, 4);
    enqueue(&Q, 5);
    enqueue(&Q, 6);
    enqueue(&Q, 7);
    enqueue(&Q, 8);
    enqueue(&Q, 9);
    enqueue(&Q, 10);
    
    dequeue(&Q);
    
    enqueue(&Q, 11);
    enqueue(&Q, 12);

    dequeue(&Q);
    enqueue(&Q, 13);
    enqueue(&Q, 14);
    
    visualizeCircullarQueue(Q);
    
  
	return 0;
}
