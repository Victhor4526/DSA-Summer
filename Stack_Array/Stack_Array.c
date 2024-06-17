#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack_Array.h"


void initStack(Stack *S) {
	S->top = -1;
}

Stack createStack() {
	Stack S;
	initStack(&S);
	
	return S;
}

bool stack_push(Stack *S, int elem) {
	if(S->top < MAX) {
		S->data[++S->top] = elem;
	}
	return (S->top < MAX) ? true : false;
}

bool stack_pop(Stack *S) {
	if(S->top != -1) {
		S->top--;
	}
	return (S->top != -1) ? true : false;
}

int stack_top(Stack S) {
	return (S.top != -1) ? S.data[S.top] : -1;
}


void display(Stack S) {
	int i;
    if (S.top == -1) {
        printf("--STACK IS EMPTY--\n");
    } else {
        printf(" elements:\n");
        for ( i = S.top; i >= 0; i--) {
            printf("%d\n", S.data[i]);
        }
    }
}

// you can traverse
void visualize(Stack S) {
	int i;
	if(S.top != -1) {
		printf("%-10s %-10s %-10s\n", "INDEX", "DATA", "TOP");
		for(i = 0; i <= S.top; i++) {
			printf("%-11d %-9d", i, S.data[i]);
			if(i == S.top) {
				printf("<---%s", "top");
			}
		printf("\n");
		}
	} else {
		printf("--STACK IS EMPTY--");
	}
	
}


// removing from the old stack

Stack get_even(Stack S) {
	Stack newStack;
	initStack(&newStack);
	int currTop = S.top;
	
	if(currTop != -1) { // check if stack is not empty
		while(currTop != -1) {
			if(S.data[currTop] % 2 == 0) {
				newStack.top++;
				newStack.data[newStack.top] = S.data[currTop];
				currTop--;
			}
		}
	}
	
	return newStack;
}
