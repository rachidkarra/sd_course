#define QUEUESIZE 100

typedef struct {
    int q[QUEUESIZE + 1];              
    int first;                          /* position du premier element */
    int last;                           /* position du dernier element */
    int count;                          /* nombre d'element de la file */
} queue;
// juste a comment from feature_1

// comment depuis sd_projet_1

void init_queue(queue* q);
void enqueue(queue* q, int x);
int dequeue(queue* q);
int headq(queue* q);
int empty_queue(queue* q);
void print_queue(queue* q);