#include <stdio.h>
#include <stdlib.h>

/* define data-type and compare operators here */
typedef int T;                  /* type of item to be stored */
#define compLT(a,b) (a < b)
#define compEQ(a,b) (a == b)

/* levels range from (0 .. MAXLEVEL) */
#define MAXLEVEL 15

typedef struct Node_ {
    T data;                     /* user's data */
    struct Node_ *forward[1];   /* skip list forward pointer */
} Node;

typedef struct {
    Node *hdr;                  /* list Header */
    int listLevel;              /* current level of list */
} SkipList;

SkipList list;                  /* skip list information */

#define NIL list.hdr

Node *insertNode(T data) {
    int i, newLevel;
    Node *update[MAXLEVEL+1];
    Node *x;

   /***********************************************
    *  allocate node for data and insert in list  *
    ***********************************************/

    /* find where data belongs */
    x = list.hdr;
    for (i = list.listLevel; i >= 0; i--) {
	while (x->forward[i] != NIL && compLT(x->forward[i]->data, data))
	    x = x->forward[i];
	update[i] = x;
    }
    x = x->forward[0];
    if (x != NIL && compEQ(x->data, data)) return(x);

    /* determine level */
    for (newLevel = 0; rand() < RAND_MAX/2 && newLevel < MAXLEVEL; newLevel++);

    if (newLevel > list.listLevel) {
	for (i = list.listLevel + 1; i <= newLevel; i++)
	    update[i] = NIL;
	list.listLevel = newLevel;
    }

    /* make new node */
    if ((x = (Node *) malloc(sizeof(Node) + newLevel*sizeof(Node *))) == 0) {
	printf ("insufficient memory (insertNode)\n");
	exit(1);
    }
    x->data = data;

    /* update forward links */
    for (i = 0; i <= newLevel; i++) {
	x->forward[i] = update[i]->forward[i];
	update[i]->forward[i] = x;
    }
    return(x);
}

void deleteNode(T data) {
    int i;
    Node *update[MAXLEVEL+1], *x;

   /*******************************************
    *  delete node containing data from list  *
    *******************************************/

    /* find where data belongs */
    x = list.hdr;
    for (i = list.listLevel; i >= 0; i--) {
	while (x->forward[i] != NIL
	  && compLT(x->forward[i]->data, data))
	    x = x->forward[i];
	update[i] = x;
    }
    x = x->forward[0];
    if (x == NIL || !compEQ(x->data, data)) return;

    /* adjust forward pointers */
    for (i = 0; i <= list.listLevel; i++) {
	if (update[i]->forward[i] != x) break;
	update[i]->forward[i] = x->forward[i];
    }

    free (x);

    /* adjust header level */
    while ((list.listLevel > 0) && (list.hdr->forward[list.listLevel] == NIL))
	list.listLevel--;
}

Node *findNode(T data) {
    int i;
    Node *x = list.hdr;

   /*******************************
    *  find node containing data  *
    *******************************/

    for (i = list.listLevel; i >= 0; i--) {
	while (x->forward[i] != NIL && compLT(x->forward[i]->data, data))
	    x = x->forward[i];
    }
    x = x->forward[0];
    if (x != NIL && compEQ(x->data, data)) return (x);
    return(0);
}

void initList() {
    int i;

   /**************************
    *  initialize skip list  *
    **************************/

    if ((list.hdr = (Node *) malloc(sizeof(Node) + MAXLEVEL*sizeof(Node *))) == 0) {
	printf ("insufficient memory (initList)\n");
	exit(1);
    }
    for (i = 0; i <= MAXLEVEL; i++)
	list.hdr->forward[i] = NIL;
    list.listLevel = 0;
}
/* Function main */
int main()
{
    int i, *a, maxnum, random;
    printf(" Input Data ");
    scanf("%d", &maxnum);

    printf("Input type of operation 2 or 1 for sequential more than 2 for random: ");
    scanf("%d",&random);
    random = random > 2; /* This statement decides whether we interested in sequential or random */
    initList();

    if ((a = malloc(maxnum * sizeof(*a))) == 0) {
        fprintf (stderr, "insufficient memory (a)\n");
        exit(1);
    }

    if (random) {
        /* fill "a" with unique random numbers */
        for (i = 0; i < maxnum; i++) a[i] = rand();
        printf ("ran, %d items\n", maxnum);
    } else {
        for (i = 0; i < maxnum; i++) a[i] = i;
        printf ("seq, %d items\n", maxnum);
    }

    for (i = 0; i < maxnum; i++) {
        insertNode(a[i]);
    }

    for (i = maxnum-1; i >= 0; i--) {
        findNode(a[i]);
    }

    for (i = maxnum-1; i >= 0; i--) {
        deleteNode(a[i]);
    }
    return 0;
}
