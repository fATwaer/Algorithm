#include "Btree.h"


bnode*
Btree::BTree_Create()
{
    bnode* x = new bnode;
    x->leaf = true;
    x->n = 0;
    x->key = new char[2 * t - 1];
    x->cp = new bnode*[2 * t - 1];
    DiskRead(x);
    root = x;
    return x;
}

void
Btree::BTree_SplitChild(bnode *x, int i)
{
    bnode* z = new bnode;

}


void
Btree::BTree_Insert(char key)
{
    bnode* r = root;
    if (r->n == 2 * t - 1);
    else
        BTree_Insert_NONFULL(r, key);

}

void
Btree::BTree_Insert_NONFULL(bnode *x, char k)
{
    int i = x->n;
    if (x->leaf == true) {
        while (i >= 1 && k < (x->key)[i]) {
            (x->key)[i+1] = (x->key)[i];
            i--;
        }
        (x->key)[i+1] = k;
        x->n++;
        DiskWrite(x);
    } else {
        ;
    }
}

















Btree::Btree()
{
    //ctor
    t = 3;
}

Btree::~Btree()
{
    //dtor
}
void
Btree::DiskRead(bnode *)
{
}
void
Btree::DiskWrite(bnode *)
{
}
