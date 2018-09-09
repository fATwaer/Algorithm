
#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

enum color{
    black = 0,
    red = 1,
};

typedef struct treenode {
    treenode(int value);
    int key;
    enum color;
    struct treenode *left;
    struct treenode *right;
    struct treenode *p; //parent
}rbt;

class RedBlackTree
{
    public:
        /** Default constructor */
        RedBlackTree();
        /** Default destructor */
        virtual ~RedBlackTree();


    private:
        rbt *root;

};

#endif // REDBLACKTREE_H
