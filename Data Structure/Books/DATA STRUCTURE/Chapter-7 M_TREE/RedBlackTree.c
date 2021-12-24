/* red-black tree */
/* RedBlackTree.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


/* implementation dependend declarations */
typedef enum {
    STATUS_OK,
    STATUS_MEM_EXHAUSTED,
    STATUS_DUPLICATE_KEY,
    STATUS_KEY_NOT_FOUND
} statusEnum;

typedef int keyType;            /* type of key */

/* user data stored in tree */
typedef struct {
    int stuff;                  /* optional related data */
} recType;

#define compLT(a,b) (a < b)
#define compEQ(a,b) (a == b)

/* implementation independent declarations */
/* Red-Black tree description */
typedef enum { BLACK, RED } nodeColor;

typedef struct nodeTag {
    struct nodeTag *left;       /* left child */
    struct nodeTag *right;      /* right child */
    struct nodeTag *parent;     /* parent */
    nodeColor color;            /* node color (BLACK, RED) */
    keyType key;                /* key used for searching */
    recType rec;                /* user data */
} nodeType;

#define NIL &sentinel           /* all leafs are sentinels */
nodeType sentinel = { NIL, NIL, 0, BLACK, 0};

nodeType *root = NIL;               /* root of Red-Black tree */

void rotateLeft(nodeType *x) {

   /**************************
    *  rotate node x to left *
    **************************/

    nodeType *y = x->right;

    /* establish x->right link */
    x->right = y->left;
    if (y->left != NIL) y->left->parent = x;

    /* establish y->parent link */
    if (y != NIL) y->parent = x->parent;
    if (x->parent) {
        if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
    } else {
        root = y;
    }

    /* link x and y */
    y->left = x;
    if (x != NIL) x->parent = y;
}

void rotateRight(nodeType *x) {

   /****************************
    *  rotate node x to right  *
    ****************************/

    nodeType *y = x->left;

    /* establish x->left link */
    x->left = y->right;
    if (y->right != NIL) y->right->parent = x;

    /* establish y->parent link */
    if (y != NIL) y->parent = x->parent;
    if (x->parent) {
        if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;
    } else {
        root = y;
    }

    /* link x and y */
    y->right = x;
    if (x != NIL) x->parent = y;
}

void insertFixup(nodeType *x) {

   /*************************************
    *  maintain Red-Black tree balance  *
    *  after inserting node x           *
    *************************************/

    /* check Red-Black properties */
    while (x != root && x->parent->color == RED) {
        /* we have a violation */
        if (x->parent == x->parent->parent->left) {
            nodeType *y = x->parent->parent->right;
            if (y->color == RED) {

                /* uncle is RED */
                x->parent->color = BLACK;
                y->color = BLACK;
                x->parent->parent->color = RED;
                x = x->parent->parent;
            } else {

                /* uncle is BLACK */
                if (x == x->parent->right) {
                    /* make x a left child */
                    x = x->parent;
                    rotateLeft(x);
                }

                /* recolor and rotate */
                x->parent->color = BLACK;
                x->parent->parent->color = RED;
                rotateRight(x->parent->parent);
            }
        } else {

            /* mirror image of above code */
            nodeType *y = x->parent->parent->left;
            if (y->color == RED) {

                /* uncle is RED */
                x->parent->color = BLACK;
                y->color = BLACK;
                x->parent->parent->color = RED;
                x = x->parent->parent;
            } else {

                /* uncle is BLACK */
                if (x == x->parent->left) {
                    x = x->parent;
                    rotateRight(x);
                }
                x->parent->color = BLACK;
                x->parent->parent->color = RED;
                rotateLeft(x->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

statusEnum insert(keyType key, recType *rec) {
    nodeType *current, *parent, *x;

   /***********************************************
    *  allocate node for data and insert in tree  *
    ***********************************************/

    /* find future parent */
    current = root;
    parent = 0;
    while (current != NIL) {
        if (compEQ(key, current->key)) 
            return STATUS_DUPLICATE_KEY;
        parent = current;
        current = compLT(key, current->key) ?
            current->left : current->right;
    }

    /* setup new node */
    if ((x = malloc (sizeof(*x))) == 0)
        return STATUS_MEM_EXHAUSTED;
    x->parent = parent;
    x->left = NIL;
    x->right = NIL;
    x->color = RED;
    x->key = key;
    x->rec = *rec;

    /* insert node in tree */
    if(parent) {
        if(compLT(key, parent->key))
            parent->left = x;
        else
            parent->right = x;
    } else {
        root = x;
    }

    insertFixup(x);

    return STATUS_OK;
}

void deleteFixup(nodeType *x) {

   /*************************************
    *  maintain Red-Black tree balance  *
    *  after deleting node x            *
    *************************************/

    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            nodeType *w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateLeft (x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rotateRight (w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                rotateLeft (x->parent);
                x = root;
            }
        } else {
            nodeType *w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateRight (x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    rotateLeft (w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rotateRight (x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

statusEnum delete(keyType key) {
    nodeType *x, *y, *z;

   /*****************************
    *  delete node z from tree  *
    *****************************/

    /* find node in tree */
    z = root;
    while(z != NIL) {
        if(compEQ(key, z->key)) 
            break;
        else
            z = compLT(key, z->key) ? z->left : z->right;
    }
    if (z == NIL) return STATUS_KEY_NOT_FOUND;

    if (z->left == NIL || z->right == NIL) {
        /* y has a NIL node as a child */
        y = z;
    } else {
        /* find tree successor with a NIL node as a child */
        y = z->right;
        while (y->left != NIL) y = y->left;
    }

    /* x is y's only child */
    if (y->left != NIL)
        x = y->left;
    else
        x = y->right;

    /* remove y from the parent chain */
    x->parent = y->parent;
    if (y->parent)
        if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
    else
        root = x;

    if (y != z) {
        z->key = y->key;
        z->rec = y->rec;
    }


    if (y->color == BLACK)
        deleteFixup (x);

    free (y);
    return STATUS_OK;
}

statusEnum find(keyType key, recType *rec) {

   /*******************************
    *  find node containing data  *
    *******************************/

    nodeType *current = root;
    while(current != NIL) {
        if(compEQ(key, current->key)) {
            *rec = current->rec;
            return STATUS_OK;
        } else {
            current = compLT (key, current->key) ?
                current->left : current->right;
        }
    }
    return STATUS_KEY_NOT_FOUND;
}


void main(int argc, char **argv) {
    int maxnum, ct, n;
    recType rec;
    keyType key;
    statusEnum status;

    /* command-line:
     *
     *   rbt maxnum
     *
     *   rbt 2000
     *       process 2000 records
     *
     */

    maxnum = atoi(argv[1]);

    printf("maxnum = %d\n", maxnum);
    for (ct = maxnum; ct; ct--) {
        key = rand() % 9 + 1;
        if ((status = find(key, &rec)) == STATUS_OK) {
            status = delete(key);
            if (status) printf("fail: status = %d\n", status);
        } else {
            status = insert(key, &rec);
            if (status) printf("fail: status = %d\n", status);
        }
    }
}
