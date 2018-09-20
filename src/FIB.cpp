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
void
FIB::Insert(int key)
{
    fibn *x = new fibn(key);
    FIB_HeapInsert(x);
}
void
FIB::FIB_link(fibn* x)
{
    if (root == NULL) {
        root = x;
        root->right = NULL;
        root->left = NULL;
    } else {
        if (root->right != NULL) {
            root->right->left = x;
            x->right = root->right;

            root->right = x;
            x->left = root;
        } else {
            root->right = x;
            x->left = root;
            x->right = NULL;
        }
    }
}
void
FIB::FIB_HeapInsert(fibn* x)
{
    x->degree = 0;
    x->p = NULL;
    x->child = NULL;
    x->mark = false;

    if (heapmin == NULL) {
        FIB_link(x);
        heapmin = x;
    } else {
        FIB_link(x);
        if (x->key < heapmin->key)
            heapmin = x;
    }
    n += 1;

}
