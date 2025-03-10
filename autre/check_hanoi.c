//
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#include "llist.h"
//#include "stack.h"
//
//
//void current_status(stack *S)
//{
//    int i;
//    printf("------\n");
//    for (i = 0; i < 3; i++) { 
//	print_stack(S + i);
//	if (!check_order(S + i)) {
//	    printf("INVALID STACK\n");
//	    exit(1);
//	}
//    }
//    return;
//}
//
//
//int main(int argc, char **argv)
//{
//    int i, n, from, to;
//    stack S[3];
//    FILE *in;
//    if (argc < 2) {
//    	printf("Usage: %s <n> [ filename ]\n", argv[0]);
//    	exit(1);
//    }
//    n = atoi(argv[1]);
//    // for (i = 0; i < 3; i++) init_stack(&S[i]);
//    for (i = 0; i < 3; i++) init_stack(S + i);
//    for (i = n; i > 0; i--) push(&S[0], i);
//    current_status(S);
//    
//    if (argc == 3) { 
//	in = fopen(argv[2], "r");
//	if (in == NULL) {
//	    printf("Failed to open %s\n", argv[2]);
//	    exit(1);
//	}
//    }
//    else in = stdin;
//    /* while (!feof(in)) { */
//    while (fscanf(in, "%d%d", &from, &to) == 2) {
//	/* printf("%d -> %d\n", from, to); */
//	push(S + to - 1, pop(S + from - 1));
//	current_status(S);
//    }
//    /* } */
//    return 0;
//}
