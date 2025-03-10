
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

tree *parent;    /* last node visited */

tree *init_tree(void) {
    return(NULL);
}

bool empty_tree(tree *t) {
    if (t == NULL) {
        return (true);
    }
    return (false);
}

/* [[[ search_tree_cut */
tree *search_tree(tree *l, int x) {
    if (l == NULL) {
        return(NULL);
    }

    if (l->item == x) {
        return(l);
    }

    if (x < l->item) {
        return(search_tree(l->left, x));
    } else {
        return(search_tree(l->right, x));
    }
}
/* ]]] */

/* [[[ insert_tree_cut */
void insert_tree(tree **l, int x, tree *parent) {
    tree *p;    /* temporary pointer */

    if (*l == NULL) {
        p = malloc(sizeof(tree));
        p->item = x;
        p->left = p->right = NULL;
        p->parent = parent;
        *l = p;
        return;
    }

    if (x < (*l)->item) {
        insert_tree(&((*l)->left), x, *l);
    } else {
        insert_tree(&((*l)->right), x, *l);
    }
}
/* ]]] */

void print_tree(tree *l) {
    if (l != NULL) {
        print_tree(l->left);
        printf("%d ", l->item);
        print_tree(l->right);
    }
}

tree *successor_descendant(tree *t) {
    tree *succ;    /* successor pointer */

    if (t->right == NULL) {
        return(NULL);
    }

    succ = t->right;
    while (succ->left != NULL) {
        succ = succ->left;
    }
    return(succ);
}

/* [[[ find_minimum_cut */
tree *find_minimum(tree *t) {
    tree *min;    /* pointer to minimum */

    if (t == NULL) {
        return(NULL);
    }

    min = t;
    while (min->left != NULL) {
        min = min->left;
    }
    return(min);
}
/* ]]] */

tree *predecessor_descendant(tree *t) {
    tree *pred;    /* predecessor pointer */

    if (t->left == NULL) {
        return(NULL);
    }

    pred = t->left;
    while (pred->right != NULL) {
        pred = pred->right;
    }
    return(pred);
}

tree *delete_tree(tree *t, int x) {
    tree *d;             /* node with key to delete */
    tree *p;             /* node to be physically deleted */
    int new_key;   /* key to overwrite deleted key */
    tree *child;         /* d's only child, if any */
    tree *search_tree();

    d = search_tree(t, x);

    if (d == NULL) {
        printf("Warning: key to be deleted %d is not in tree.\n", x);
        return(t);
    }

    if (d->parent == NULL) {    /* if d is the root */
        if ((d->left == NULL) && (d->right == NULL)) {
            free(d);
            return NULL;    /* root-only tree */
        }

        if (d->left != NULL) {    /* find node to physically delete */
            p = predecessor_descendant(d);
        } else { 
            p = successor_descendant(d);
        }
    } else {
        if ((d->left == NULL) || (d->right == NULL)) {
            /* d has <=1 child, so try to find non-null child */
            if (d->left != NULL) {
                child = d->left;
            } else {
                child = d->right;
            }

            if ((d->parent)->left == d) {    /* fill null pointer */
              d->parent->left = child;
            } else {
              d->parent->right = child;
            }
            if (child != NULL) {
                child->parent = d->parent;
            }
            free(d);
            return(t);
        } else {
            p = successor_descendant(d);    /* p has 2 children */
        }
    }

    new_key = p->item;    /* deal with simpler case of deletion */
    delete_tree(t, p->item);
    d->item = new_key;
    return (t);
}

// Helper function to find k-th smallest element (inorder traversal)
void find_kth_smallest(tree *l, int k, int *count, int *result) {
    if (l == NULL || *count >= k)
        return;

    // Traverse left subtree
    find_kth_smallest(l->left, k, count, result);

    // Process current node
    (*count)++;
    if (*count == k) {
        *result = l->item;
        return;
    }

    // Traverse right subtree
    find_kth_smallest(l->right, k, count, result);
}

// Wrapper function to call the recursive function
int kth_smallest(tree *l, int k) {
    int count = 0;
    int result = -1;
    find_kth_smallest(l, k, &count, &result);
    return result;
}

int main(void) {
  
    tree *l;
    l = init_tree();
    
    // Inserting elements into BST
    insert_tree(&l, 5, NULL);
    insert_tree(&l, 3, NULL);
    insert_tree(&l, 8, NULL);
    insert_tree(&l, 2, NULL);
    insert_tree(&l, 4, NULL);
    insert_tree(&l, 10, NULL);
    
    int k = 3;
    int result = kth_smallest(l, k);
    if (result != -1)
        printf("The %d-th element est: %d\n", k, result);
    else
        printf("Erreur.\n");

    return 0;
}
