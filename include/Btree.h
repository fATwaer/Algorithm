#ifndef BTREE_H
#define BTREE_H
#include "bnode.h"


class Btree
{
    public:
        /** Default constructor */
        Btree();
        /** Default destructor */
        virtual ~Btree();
        bnode* BTree_Create();
        void BTree_SplitChild(bnode *x, int i);
        void DiskRead(bnode *x);
        void DiskWrite(bnode *x);
        void BTree_Insert(char key);
        void BTree_Insert_NONFULL(bnode *x, char k);
    private:
        int t;      // minimum degree
        bnode *root;
};

#endif // BTREE_H
