#include "binarysearchtree.h"
#include <iostream>
using namespace std;

void
BinarySearchTree::treeInsert(node *z)
{
    node *y = NULL;
    node *x = root;

    while (x != NULL) {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->p = y;
    if (y == NULL)
        root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;

}

node*
BinarySearchTree::searchNode(int value)
{
    node *x = root;
    while (x != NULL && x->key != value)
        if (value < x->key)
            x = x->left;
        else
            x = x->right;
    return x;
}

void
BinarySearchTree::transplant(node *u, node *v)
{
    // v -> u
    if (u->p == NULL)
        root = v;
    else if (u == u->p->left)
        u->p->left = v;
    else
        u->p->right = v;

    if (v != NULL)
        v->p = u->p;
}

void
BinarySearchTree::treeDelete(node *z)
{
    if (z->left == NULL)
        transplant(z, z->right);
    else if (z->right == NULL)
        transplant(z, z->left);
    else {
        node *y = treeMin(z->right);
        if (y->p != z) {
            transplant(y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->p = y;



    }
}
