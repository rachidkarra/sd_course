
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

// Fonction pour vérifier si le tableau est k-unique
int is_k_unique(int A[], int n, int k) {
    tree *root = NULL;

    for (int i = 0; i < n; i++) {
        if (search_tree(root, A[i]) != NULL)
            return 0; // Doublon trouvé dans la plage k, non k-unique

        insert_tree(&root, A[i], NULL);

        if (i >= k) {
            root = delete_tree(root, A[i - k]); // Supprimer l'ancien élément
        }
    }

    return 1; // Il est k-unique
}

int main(void) {
  
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 5;
    is_k_unique(A, n, k) ? printf("Le tableau A est %d-unique\n", k) : printf("Le tableau A n'est pas %d-unique\n",k);
    return 0;
}
