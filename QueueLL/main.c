#include <stdio.h>
#include <stdlib.h>
#include "QueueLL.h"
#include <stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Queue Q;
	
	
	initQueue(&Q);
	
	enqueue(&Q, 21);
	enqueue(&Q, 22);
	enqueue(&Q, 22);
	
	dequeue(&Q); // delete 21
	
	display(Q);
	
	bool res =isEmpty(Q);
	printf("\n Front Number is : %d ",front(Q));
	printf("\n Rear Number is : %d ",rear(Q));
	

	return 0;
}
