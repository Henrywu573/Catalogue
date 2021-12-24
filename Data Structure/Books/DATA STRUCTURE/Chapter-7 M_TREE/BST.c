/* binary search tree */
/* BST.C */
#include <stdio.h>
#include <stdlib.h>

#define compLT(a,b) (a < b)
#define compEQ(a,b) (a == b)

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

typedef struct nodeTag {
    struct nodeTag *left;       /* left child */
    struct nodeTag *right;      /* right child */
    struct nodeTag *parent;     /* parent */
    keyType key;                /* key used for searching */
    recType rec;                /* user data */
} nodeType;

nodeType *root = NULL;          /* root of binary tree */

statusEnum insert(keyType key, recType *rec) {
    nodeType *x, *current, *parent;

   /***********************************************
    *  allocate node for data and insert in tree  *
    ***********************************************/

    /* find future parent */
    current = root;
    parent = 0;
    while (current) {
        if (compEQ(key, current->key)) 
            return STATUS_DUPLICATE_KEY;
        parent = current;
        current = compLT(key, current->key) ? 
            current->left : current->right;
    }

    /* setup new node */
    if ((x = malloc (sizeof(*x))) == 0) {
        return STATUS_MEM_EXHAUSTED;
    }
    x->parent = parent;
    x->left = NULL;
    x->right = NULL;
    x->key = key;
    x->rec = *rec;

    /* insert x in tree */
    if(parent)
        if(compLT(x->key, parent->key))
            parent->left = x;
        else
            parent->right = x;
    else
        root = x;

    return STATUS_OK;
}

statusEnum delete(keyType key) {
    nodeType *x, *y, *z;

   /***************************
    *  delete node from tree  *
    ***************************/

    /* find node in tree */
    z = root;
    while(z != NULL) {
        if(compEQ(key, z->key)) 
            break;
        else
            z = compLT(key, z->key) ? z->left : z->right;
    }
    if (!z) return STATUS_KEY_NOT_FOUND;

    /* find tree successor */
    if (z->left == NULL || z->right == NULL)
        y = z;
    else {
        y = z->right;
        while (y->left != NULL) y = y->left;
    }

    /* x is y's only child */
    if (y->left != NULL)
        x = y->left;
    else
        x = y->right;

    /* remove y from the parent chain */
    if (x) x->parent = y->parent;
    if (y->parent)
        if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
    else
        root = x;

    /* if z and y are not the same, replace z with y. */
    if (y != z) {
        y->left = z->left;
        if (y->left) y->left->parent = y;
        y->right = z->right;
        if (y->right) y->right->parent = y;
        y->parent = z->parent;
        if (z->parent)
            if (z == z->parent->left)
                z->parent->left = y;
            else
                z->parent->right = y;
        else
            root = y;
        free (z);
    } else {
        free (y);
    }
    return STATUS_OK;
}

statusEnum find(keyType key, recType *rec) {

   /*******************************
    *  find node containing data  *
    *******************************/

    nodeType *current = root;
    while(current != NULL) {
        if(compEQ(key, current->key)) {
            *rec = current->rec;
            return STATUS_OK;
        } else {
            current = compLT(key, current->key) ? 
                current->left : current->right;
        }
    }
    return STATUS_KEY_NOT_FOUND;
}

int main(int argc, char **argv) {
    int i, maxnum, random;
    recType *rec;
    keyType *key;
    statusEnum status;

    /* command-line:
     *
     *   bin maxnum random
     *
     *   bin 5000        // 5000 sequential
     *   bin 2000 r      // 2000 random
     *
     */
    maxnum = atoi(argv[1]);
    random = argc > 2;

    if ((rec = malloc(maxnum * sizeof(recType))) == 0) {
        fprintf (stderr, "insufficient memory (rec)\n");
        exit(1);
    }
    if ((key = malloc(maxnum * sizeof(keyType))) == 0) {
        fprintf (stderr, "insufficient memory (key)\n");
        exit(1);
    }

    if (random) { /* random */
        /* fill "key" with unique random numbers */
        for (i = 0; i < maxnum; i++) key[i] = rand();
        printf ("ran bt, %d items\n", maxnum);
    } else {
        for (i=0; i<maxnum; i++) key[i] = i;
        printf ("seq bt, %d items\n", maxnum);
    }


    for (i = 0; i < maxnum; i++) {
        status = insert(key[i], &rec[i]);
        if (status) printf("pt1, i=%d: %d\n", i, status);
    }

    for (i = maxnum-1; i >= 0; i--) {
        status = find(key[i], &rec[i]);
        if (status) printf("pt2, i=%d: %d\n", i, status);
    }

    for (i = maxnum-1; i >= 0; i--) {
        status = delete(key[i]);
        if (status) printf("pt3, i=%d: %d\n", i, status);
    }
    return 0;
}
