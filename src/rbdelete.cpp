#include "rbtree.h"
#include <cstdlib>
#include <stdio.h>

void
rbtree::rbTransplant(rbnode *u, rbnode *v)
{
    if (u->p == NULL)
        root = v;
    else if (u == u->p->left)
        u->p->left = v;
    else
        u->p->right = v;
    if (v != NULL)
        v->p = u->p;
}

rbnode *
rbtree::nodesearch(int key)
{
    rbnode *x = root;
    int last;
    while (x != NULL) {
        if (key < x->key)
            x = x->left;
        else if (key > x->key)
            x = x->right;
        else
            return x;
    }
    return NULL;
}

rbnode *
rbtree::minimum(rbnode *x)
{
    while (x->left != NULL)
        x = x->left;
    return x;
}


void
rbtree::rbDelete(rbnode *z)
{
    rbnode *x, *y = z;
    color origin = y->c;
    if (z->left == NULL) {
        x = z->right;
        rbTransplant(z, z->right);
    } else if (z->right == NULL) {
        x = z->left;
        rbTransplant(z, z->left);
    } else {
        y = minimum(z->right);
        origin = y->c;
        x = y->right;
        if (y->p == z) {
            if (x != NULL)
                x->p = y;
        }
        else {
            rbTransplant(y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        rbTransplant(z, y);
        y->left = z->left;
        if (y->left != NULL)
            y->left->p = y;
        y->c = z->c;
        free(z);
    }
   if (origin == BLACK)
        rbDeleteFixup(x);

}

void
rbtree::rbDeleteFixup(rbnode *x)
{
    rbnode *w;

    while (x != root && x->c == BLACK) {
        if (x == x->p->left) {
            w = x->p->right;
            if (w->c == RED) { //case 1
                w->c = BLACK;
                x->p->c = RED;
                LeftRotate(x->p);
                w = x->p->right;
            }
            if (w->left->c == BLACK && w->right->c == RED) { // case 2
                w->c = RED;
                x = x->p;
            } else {
                if (w->right->c == BLACK) { // case 3
                    w->left->c = BLACK;
                    w->c = RED;
                    RightRotate(w);
                    w = x->p->right;
                }
                // case 4
                w->c = x->p->c;
                x->p->c = BLACK;
                w->right->c = BLACK;
                LeftRotate(x->p);
                x = root;
            }
        } else {
            w = x->p->left;
            if (w->c == RED) {
                w->c = BLACK;
                x->p->c = RED;
                RightRotate(x->p);
                w = x->p->left;
            }
            if (w->left->c == RED && w->right->c == BLACK) {
                w->c = RED;
                x = x->p;
            } else {
                if (w->left->c == BLACK) {
                    w->right->c = BLACK;
                    w->c = RED;
                    LeftRotate(w);
                    w = x->p->left;
                }
                w->c = x->p->c;
                x->p->c = BLACK;
                w->left->c = BLACK;
                RightRotate(x->p);
                x = root;
            }
        }
    }

    x->c = BLACK;
}
