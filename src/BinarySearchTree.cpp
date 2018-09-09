#include "binarysearchtree.h"
#include <iostream>
using namespace std;

treenode::treenode(int value)
{
    key = value;
    left = NULL;
    right = NULL;
    p = NULL;
}


BinarySearchTree::BinarySearchTree()
{
    root = NULL;

}

BinarySearchTree::~BinarySearchTree()
{
    //dtor
}

node *
BinarySearchTree::getRoot()
{
    return root;
}

void
BinarySearchTree::inorderTreeWalk(node *x)
{
    if (x == NULL)
        return;
    inorderTreeWalk(x->left);
    cout << x->key << " ";
    inorderTreeWalk(x->right);
}


node*
BinarySearchTree::treeMin(node *x)
{
    while (x->left != NULL)
        x = x->left;
    return x;
}
node*
BinarySearchTree::treeMAX(node *x)
{
    while (x->right != NULL)
        x = x->right;
    return x;
}
node* successor(node *x)
{

}



