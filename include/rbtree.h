#ifndef RBTREE_H
#define RBTREE_H
enum color
{
    BLACK, RED
};

typedef struct rbtreenode {
    rbtreenode() = default;
    int key;
    struct rbtreenode *left;
    struct rbtreenode *right;
    struct rbtreenode *p; //parent
    color c;
}rbnode;


class rbtree
{
    public:
        /** Default constructor */
        rbtree();
        /** Default destructor */
        virtual ~rbtree();
        void LeftRotate(rbnode *);
        void RightRotate(rbnode *);
        void Insert(int);
        void RBInsert(rbnode *);
        void RBinsertFixup(rbnode *);
        void inorder(rbnode* );
        rbnode *getRoot();
        void rbTransplant(rbnode *, rbnode *);
        rbnode *nodesearch(int);
        void rbDelete(rbnode *);
        rbnode *minimum(rbnode *);
        void rbDeleteFixup(rbnode *);

    private:
        rbnode *root ;
};

#endif // RBTREE_H
