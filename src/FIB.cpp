#include "FIB.h"
#include "fibnode.h"
#include "stdlib.h"
#include "stdio.h"

FIB::FIB()
{
    //ctor
    root = NULL;
}

FIB::~FIB()
{
    //dtor
}


/** Insert */
void
FIB::Insert(int key)
{
    fibn *x = new fibn(key);

    x->degree = 0;
    x->p = NULL;
    x->child = NULL;

    FIB_HeapInsert(x);
}

void
FIB::FIB_wlink(fibn* x)
{

    if (root == NULL) {

        root = x;
        root->right = root;
        root->left = root;

    } else {

        if (root->right != root) {

            root->right->left = x;
            x->right = root->right;
            root->right = x;
            x->left = root;

        } else {

            root->right = x;
            x->left = root;
            x->right = root;
            root->left = x;
            rear = x;

        }
    }
}

/**
*
* before insertion, it should be set x.degree, x.p and x.child
*
*/
void
FIB::FIB_HeapInsert(fibn* x)
{
    x->mark = false;


    if (heapmin == NULL) {
        FIB_wlink(x);
        heapmin = x;
    } else {
        FIB_wlink(x);
        if (x->key < heapmin->key)
            heapmin = x;
    }
    n += 1;

}

FIB&
makeUp_newHeap(fibn* s, fibn* f)
{
    FIB* newheappointer = new FIB(s, f);
    return (*newheappointer);
}


/** UNION */
FIB&
FIB::FIB_HeapUnion(FIB* h2)
{
    // concatenate
    fibn* h2begin = (*h2).getRoot();
    fibn* h2end = (*h2).getRear();
    fibn* h2min = (*h2).getMin();

    h2begin->left = rear;
    rear->right = h2begin;
    h2end->right = root;
    root->left = h2end;
    // new fib-heap
    FIB& H = makeUp_newHeap(root, h2end);

    H.setMin(h2min);
    if ((heapmin != NULL) ||
        (h2min != NULL &&
         h2min->key < heapmin->key))
         H.setMin(h2min);

    H.setN((*h2).getN() + this->n);



    delete h2;
    delete this;
    return H;


}


/** extract a node from root list
*
*
*/
int
FIB::ExtractMin()
{
    fibn* z = FIB_ExtractMin();
    int value;
    if (z != NULL) {
        value = z->key;
        delete z;
        return value;
    } else
        return NULL;

}

fibn*
FIB::FIB_ExtractMin()
{
    fibn* z = heapmin;
    fibn* x, *r;

    if (z != NULL) {
        //each child x of z are added to the root list

        if (z->child != NULL) {

            x = z->child;
            r = z->child;
            do {
                z->child = x->right;
                x->p = NULL;
                FIB_HeapInsert(x); // insert into root list, and set x.p null
                printf("add %d into root list, parent %d\n", x->key, z->key);
                x = z->child;
            } while(x != r);
        }

        //remove z from root list
        FIB_remove(z);

        if (z == z->right) {
            heapmin = NULL;
            root = NULL;
        }
        else {
            heapmin = z->right;
            Consolidate();
        }

        n -= 1;


    }


    return z;
}


/** Consolidate */
void
FIB::Consolidate()
{
    fibn* A[3+1] = {NULL};
    fibn* w = root;
    fibn* x, *y, *t;
    int d;
    debug();
    printf("Consolidate: \n");
    //consolidates each node have same degree
    printf("%d %p\n", n, w->degree);
    do {
        x = w;
        d = x->degree;

        w = w->right;

        while (A[d] != NULL) {
            y = A[d];

            //exchange
            if (x->key > y->key) {

                t = x;
                x = y;
                y = t;
            }

            //heap link
            FIB_plink(y, x);

            printf("link %d(%d)->%d(%d)\n", y->key, y->degree, x->key, x->degree);
            A[d] = NULL;
            d += 1;
        }

        A[d] = x;

        //debug();
    } while (w != root);

    heapmin = NULL;

    int endit = n;
    for (int i = 0; i <= 3; i++) {
            printf("%d->",i);
        if (A[i] != NULL)
        {
        printf("%d(%d)",A[i]->key, A[i]->degree);
            if (heapmin == NULL) {

                init_rootlist();

                FIB_HeapInsert(A[i]);

                heapmin = A[i];

            } else {

                FIB_HeapInsert(A[i]);
                if (A[i]->key < heapmin->key)
                    heapmin = A[i];

            }

        }
        printf("\n");

    }

}

void
FIB::init_rootlist()
{
    root = NULL;
    rear = NULL;
    n = 0;
}

/** link*/
fibn*
FIB::FIB_plink(fibn* y, fibn* x)
{
    // remove y from root list
    y = FIB_remove(y);

    //make y a child of x, incrementing x.degree
    if (x->child == NULL) {
        x->child = y;
        y->left = y;
        y->right = y;
    } else {
        if (x->child->right == x->child) {
            x->child->right = y;
            x->child->left  = y;
            y->left = x->child;
            y->right = x->child;


        } else {
            x->child->right = y;
            y->left = x;
            x->child->left->left = y;
            y->right = x->child->left;
        }

    }

    y->p = x;

    x->degree += 1;

    y->mark = false;

    return x;
}

/** remove */
fibn*
FIB::FIB_remove(fibn* y)
{
    fibn* l = y->left;
    fibn* r = y->right;

    l->right = r;
    r->left = l;

    if (root == y)
        root = y->right;
    else if (rear == y)
        rear = y->left;

    return y;
}

void
FIB::FIB_DecreaseKey(fibn* x, int k)
{
    if (k > x->key) {
        printf("the key is greater than the current key\n");
        return;
    }

    x->key = k;
    fibn* y = x->p;

    if (y != NULL && x->key < y->key) {
        FIB_Cut(x, y);
        FIB_CasecadingCut(y);
    }

    if (x->key < heapmin->key)
        heapmin = x;
}

void
FIB::FIB_Cut(fibn* x, fibn* y)
{
    FIB_remove(x);
    FIB_HeapInsert(x);
    x->p = NULL;
    x->mark = false;
}

void
FIB::FIB_CasecadingCut(fibn *y)
{
    fibn* z = y->p;
    if (z != NULL)
        if (y->mark == false)
            y->mark = true;
        else {
            FIB_Cut(y, z);
            FIB_CasecadingCut(z);
        }
}

void
FIB::debug()
{
    fibn* x = root;

    if (x == NULL) {
        printf("haven't any element, extract failed");
        return;
    }

    do {
        printf("%d(%d) ->", x->key, x->degree);
        x = x->right;
    } while(x != root);

    printf(" (min : %d, N: %d)\n", heapmin->key, n);
}


void
FIB::DecreaseRoot()
{
    fibn* x = root;
    FIB_DecreaseKey(x, 1);

}
