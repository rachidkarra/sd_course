#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "queue.h"

void init_queue(queue* q) {
    q->first = 0;
    q->last = QUEUESIZE - 1;
    q->count = 0;
}

void enqueue(queue* q, int x) {   //mettre en file d'attente
    if (q->count >= QUEUESIZE) {
        printf("Attention: queue overflow enqueue x=%d\n", x);
    }
    else {
        q->last = (q->last + 1) % QUEUESIZE;   // %: garanti la navigation entre 0 et 100.
        q->q[q->last] = x;
        q->count = q->count + 1;
    }
}

int dequeue(queue* q) {       //retirer de la file d'attente
    int x;

    if (q->count <= 0) printf("Attention: file vide.\n");

    x = q->q[q->first];
    q->first = (q->first + 1) % QUEUESIZE;
    q->count = q->count - 1;

    return(x);
}

int headq(queue* q) {    // Tete de la queue
    return(q->q[q->first]);
}

int empty_queue(queue* q) {  // test file vide
    if (q->count <= 0) {
        return (true);
    }
    return (false);
}

void print_queue(queue* q) {
    int i;

    i = q->first;

    while (i != q->last) {
        printf("%d ", q->q[i]);
        i = (i + 1) % QUEUESIZE;
    }

    printf("%2d ", q->q[i]);
    printf("\n");
}

int main() {
	char c;
	int d;
    queue f; 
    queue* q = &f;    // L'adresse du tableau
    init_queue(q);
    printf("Entrez: \n 'i' pour ajouter un element, \n 'd' pour retirer un element, \n 'p' pour afficher la file,\n 'h' pour afficher la tete de la file\n");

	while (scanf("%c", &c) != EOF) {
		if (tolower(c) == 'p') {
			print_queue(q);
		}

		if (tolower(c) == 'i') {   
			scanf("%d", &d);
			printf("Nouveau element enqueue: %d\n", d);
            enqueue(q, d);
		}

		if (tolower(c) == 'd') {   
            dequeue(q);
			printf("element dequeued \n");
		}

        if (tolower(c) == 'h') {
           printf("La tete de la file est %d\n", headq(q)) ;
        }
	}

	return 0;
}