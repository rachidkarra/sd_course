
#define STACKSIZE 100

typedef struct {
    int s[STACKSIZE + 1];     /* stockage de la pile */
    int top;                /* la position de l'element en haut */
    int count;              /* Nombre d'elements */
} stack;

void init_stack(stack* s);
void push(stack* s, int x);
int  pop(stack* s);
void print_stack(stack* s);
int empty_stack(stack* s);