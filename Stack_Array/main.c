#include <stdio.h>
#include <stdlib.h>
#include "Stack_Array.h"
#include "Stack_Array.c"	
#include <stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Stack S = createStack();
	
	// Push elements onto the stack
    bool result1=stack_push(&S, 10);
    bool result2=stack_push(&S, 4);
    bool result3=stack_push(&S, 16);
    bool result4=stack_push(&S, 6);
    bool result5=stack_push(&S, 8);
    
    bool respop1 = stack_pop(&S); // will pop 8 because pop will select current top
    bool respop2 = stack_pop(&S); // pop 6
	
	


    // Visualize the stack using visualize function
    printf("Visualizing Stack Element in the Array:\n");
    visualize(S);
    printf("\n");

    // Get a new stack with even numbers using get_even function
    Stack evenStack = get_even(S);

    // Display the new stack containing even numbers
    printf("Even numbers stack");
    display(evenStack);
    printf("\n");

    return 0;
}

