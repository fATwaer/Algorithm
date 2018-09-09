#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
typedef struct treenode {
    treenode(int value);
    int key;
    struct treenode *left;
    struct treenode *right;
    struct treenode *p; //parent
}node;

class BinarySearchTree
{
    public:
        /** Default constructor */
        BinarySearchTree();
        /** Default destructor */
        virtual ~BinarySearchTree();
        void treeInsert(node *z);
        void inorderTreeWalk(node *x);
        node* getRoot();
        node* searchNode(int value);
        node* treeMin(node *x);
        node* treeMAX(node *x);
        node* successor(node *x);
        void treeDelete(node *z);
        void transplant(node* u, node* v);

    private:
        node *root;
};

#endif // BINARYSEARCHTREE_H
