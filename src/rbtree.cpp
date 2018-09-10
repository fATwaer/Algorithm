#include "rbtree.h"
#include <cstdlib>
#include <stdio.h>

rbtree::rbtree()
{
    //ctor
    root = NULL;

}

rbtree::~rbtree()
{
    //dtor
}


void
rbtree::LeftRotate(rbnode *x)
{
    rbnode *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->p = x;
    y->p = x->p;
    if (x->p == NULL)
        root = y;
    else if (x == x->p->left)
        x->p->left = y;
    else
        x->p->right = x;
    y->left = x;
    x->p = y;
}

void
rbtree::RightRotate(rbnode *y)
{
    printf("%rotate:%d\n", y->key);
    rbnode *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->p = y;
    x->p = y->p;
    if (y->p == NULL)
        root = x;
    else if (y = y->p->left)
        x = y->p->left;
    else
        x = y->p->right;
    x->right = y;
    y->p = x;

}

void
rbtree::Insert(int key)
{
    rbnode *x = new rbnode;
    x->key = key;
    RBInsert(x);
}

void
rbtree::RBInsert(rbnode* z)
{
    rbnode *x, *y;
    y = NULL;
    x = root;
    while (x != NULL) {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else x = x->right;
    }
    z->p = y;

    if (y == NULL)
        root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;

    z->c = RED;
    z->left = NULL;
    z->right = NULL;
    RBinsertFixup(z);

}

void
rbtree::RBinsertFixup(rbnode* z)
{
    rbnode *y;

    printf("node : %d %s\n", z->key, z->c ? "RED":"BLACK");
    while (z->p != NULL && z->p->p != NULL && z->p->c == RED) {
        if (z->p == z->p->p->left) {
            y = z->p->p->right;
            /*case 1*/
            if (y != NULL && y->c == RED) { //uncle node is red
                z->p->c = BLACK;
                y->c = BLACK;
                z->p->p->c = RED;
                z = z->p->p;
            } else  {
                if (z == z->p->right) {
                    /*case 2*/
                    z = z->p;
                    LeftRotate(z);
                }
                /*case 3*/
                z->p->c = BLACK;
                z->p->p->c =RED;
                RightRotate(z->p->p);
            }

        }else {
            y = z->p->p->left;
            if (y != NULL && y->c == RED) {
                z->p->c = BLACK;
                y->c = BLACK;
                z->p->p->c = RED;
                z = z->p->p;
            } else  {
                if (z == z->p->left) {
                    z = z->p;
                    RightRotate(z);
                }
                z->p->c = BLACK;
                z->p->p->c = RED;
                LeftRotate(z->p->p);

            }
        }
    }
    root->c = BLACK;
}

rbnode *
rbtree::getRoot()
{
    printf("root : %d\n", root->key);
    return root;
}


void
rbtree::inorder(rbtreenode* x)
{
    if (x == NULL)
        return;
    inorder(x->left);
    printf("%d %s   ", x->key, x->c ? "RED":"BLACK");
    inorder(x->right);
}
