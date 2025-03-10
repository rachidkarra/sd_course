
typedef struct tree {
    int item;         
    struct tree *parent;    /* pointer to parent */
    struct tree *left;      /* pointer to left child */
    struct tree *right;     /* pointer to right child */
} tree;

