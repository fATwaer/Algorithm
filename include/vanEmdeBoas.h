#ifndef VANEMDEBOAS_H
#define VANEMDEBOAS_H
#include "vEBnode.h"


class vanEmdeBoas
{
    public:
        /** Default constructor */
        vanEmdeBoas(int universe);
        /** Default destructor */
        virtual ~vanEmdeBoas();
        void debug1(vEBnode*);
        vEBnode* getRoot();
        void Insert(int key);
        void Delete(int x);
        bool isMember(int x);
        int successor(int x);
        int predecressor(int x);
    private:
        int vEB_predecressor(vEBnode* v, int x);
        int vEB_successor(vEBnode* v, int x);
        bool vEB_isMember(vEBnode* v, int x);
        void vEB_tree_delete(vEBnode* v, int x);
        void vEB_empty_tree_insert(vEBnode*, int);
        void vEB_tree_insert(vEBnode*, int);
        void build_vEB_tree(vEBnode* x);
        inline int vEB_tree_minimum(vEBnode* x);
        inline int vEB_tree_maximum(vEBnode* x);
        inline int high(int unvs, int x);
        inline int low(int unvs, int x);
        inline int index(int unvs, int x, int y);

        int u;
        vEBnode* root;
};

inline int
vanEmdeBoas::vEB_tree_minimum(vEBnode* x)
{
    return x->minimum;
}

inline int
vanEmdeBoas::vEB_tree_maximum(vEBnode* x)
{
    return x->maximum;
}

inline int
vanEmdeBoas::high(int unvs, int x)
{
    return x / int(sqrt(unvs));
}

inline int
vanEmdeBoas::low(int unvs, int x)
{
    return x % int(sqrt(unvs));
}

inline int
vanEmdeBoas::index(int unvs, int x, int y)
{
    return x * int(sqrt(unvs)) + y;
}

#endif // VANEMDEBOAS_H
