#ifndef FIBNODE_H_INCLUDED
#define FIBNODE_H_INCLUDED

typedef struct FIBnode {

    FIBnode() {};
    FIBnode(int k) : key(k){};
    int key;
    int degree;
    struct FIBnode *child;
    struct FIBnode *p;
    struct FIBnode *left;
    struct FIBnode *right;
    bool mark;

}fibn;

#endif // FIBNODE_H_INCLUDED
