#include <stdio.h>
#include <ctype.h>
#include "stack.h"

void init_stack(stack* s) {
    s->top = -1;
    s->count = 0;
}

// Just a comment
void push(stack* s, int x) {
    if (s->count >= STACKSIZE) {
        printf("Attention: stack overflow x=%d\n", x);
    }
    else {
        s->top = s->top + 1;
        s->s[s->top] = x;
        s->count = s->count + 1;
    }
}

int pop(stack* s) {
    int x;

    if (s->count <= 0) printf("Attention: la pile est vide.\n");

    x = s->s[s->top];
    s->top = s->top - 1;
    s->count = s->count - 1;

    return(x);
}

int empty_stack(stack* s) {  // test sur la pile si elle est vide
    return (s->count <= 0);
}

void print_stack(stack* s) {
    int i;    /* counter */

    for (i = (s->count - 1); i >= 0; i--) {
        printf("%d ", s->s[i]);
    }
    printf("\n");
}

int main() {
	char c;
	int d;
    stack t; 
    stack* s = &t;    // L'adresse du tableau
	init_stack(s);

	while (scanf("%c", &c) != EOF) {
		if (tolower(c) == 'p') {
			print_stack(s);
		}

		if (tolower(c) == 'i') {   //push
			scanf("%d", &d);
			printf("Nouveau element pushed: %d\n", d);
			push(s, d);
		}

        if (tolower(c) == 'e') {
            if (empty_stack(s) == 1) {
                printf("La pile est vide \n");
            }
            else {
                printf("La pile n'est pas vide\n");
            }
      }

		if (tolower(c) == 'd') {   //pop
            pop(s);
				printf("Element poped \n");
		}
	}

	return 0;
}