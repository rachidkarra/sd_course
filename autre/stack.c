//
//#include <stdio.h>
//#include <stdlib.h>
//
//#include "llist.h"
//#include "stack.h"
//
//
//void init_stack(stack *S)
//{
//    S -> L.head = (elist*) 0;
//}
//
//int stack_empty(stack *S)
//{
//    if (S -> L.head == (elist*) 0) return 1;
//    else return 0;
//}
//
///* The following will not work because the memory used for storing e
//   will be released as soon as we exit the function */
//
///* void push(stack S, int x) */
///* { */
///*     elist e; */
///*     e.key = x; */
///*     e.next = S.L.head; */
///*     S.L.head = &e; */
///* } */
//
//void push(stack *S, int x)
//{
//    elist *e = malloc(sizeof(elist));
//    if (e == NULL) { 
//	printf("malloc failed\n");
//	exit(1);
//    }
//    e -> key = x; /* equivalent to (*e).key = x; */
//    e -> next = S -> L.head;
//    S -> L.head = e;
//}
//
//int pop(stack *S)
//{
//    elist *e;
//    int k;
//    if (stack_empty(S)) {
//	printf("Error: stack underflow\n");
//	exit(1);
//    }
//    e = S -> L.head;
//    S -> L.head = e -> next;
//    k = e -> key;
//    free(e);
//    return k;
//}
//
//void print_stack(stack *S) 
//{
//    elist *e = S -> L.head;
//    printf("S: ");
//    while (e != (elist*) 0) {
//	printf("%d ", e -> key);
//	e = e -> next;
//    }
//    printf("\n");
//}
//
//
//int check_order(stack *S)
//{
//    int okey = 0;
//    elist *e = S -> L.head;
//    while (e != (elist*) 0) {
//	if (e -> key < okey) return 0;
//	okey = e -> key;
//	e = e -> next;
//    }
//    return 1;
//}
//
//
//
///* int main() */
///* { */
///*     stack T; */
///*     stack *S = &T; */
///*     init_stack(S); */
///*     print_stack(S); */
//
///*     push(S, 10); print_stack(S); */
///*     push(S, 9); print_stack(S); */
///*     push(S, 6); print_stack(S); */
///*     pop(S); print_stack(S); */
///*     pop(S); print_stack(S); */
///*     push(S, 8); print_stack(S); */
///*     push(S, 9); print_stack(S); */
///*     pop(S); print_stack(S); */
//
///*     return 0; */
///* } */
//
//
//
