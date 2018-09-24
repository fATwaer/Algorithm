#include "vanEmdeBoas.h"
#include "vEBnode.h"
#include "math.h"
#include "stdio.h"
#include "lib.h"

int
vanEmdeBoas::predecressor(int x)
{
    return vEB_predecressor(root, x);
}

int
vanEmdeBoas::vEB_predecressor(vEBnode* v, int x)
{
    int min_low, offset, pred_cluster;

    if (v->u == 2)
    {
        if (x == 1 && v->minimum == 0)
            return 0;
        else
            return -1;
    }
    else if (v->maximum != -1 && x > v->maximum)
    {
        return  v->maximum;
    }
    else
    {
        min_low = vEB_tree_minimum((v->cluster)[high(v->u, x)]);

        if (min_low != -1 && low(v->u, x) > min_low)
        {
            offset = vEB_predecressor((v->cluster)[high(v->u, x)], low(v->u, x));
            return index(v->u, high(v->u, x), offset);
        }
        else
        {
            pred_cluster = vEB_predecressor(v->summary, high(v->u, x));

            if (pred_cluster == -1)
            {
                if (v->minimum != -1 && x > v->minimum)
                    return v->minimum;
                else
                    return -1;
            }
            else
            {
                offset = vEB_tree_maximum((v->cluster)[pred_cluster]);
                return index(v->u, pred_cluster, offset);
            }

        }
    }
}

int
vanEmdeBoas::successor(int x)
{
    return vEB_successor(root, x);
}


int
vanEmdeBoas::vEB_successor(vEBnode* v, int x)
{
    int max_low, succ_cluster, offset;

    if (v->u == 2)
    {
        if (x == 0 && v->maximum == 1)
            return 1;
        else
            return -1;

    }
    else if (v->minimum != -1 && x < v->minimum)
    {
        return v->minimum;
    }
    else
    {
        max_low = vEB_tree_maximum((v->cluster)[high(v->u, x)]);
        printf("u(%d): x %d low %d, hight %d, max_low %d\n", v->u, x, low(v->u, x), high(v->u, x), max_low);
        if (max_low != -1 && low(v->u, x) < max_low)
        {
            offset = vEB_successor((v->cluster)[high(v->u, x)], low(v->u, x));
            return index(v->u, high(v->u, x), offset);
        }
        else
        {
            printf("summary: ");
            succ_cluster = vEB_successor(v->summary, high(v->u, x));
            printf("cluster: %d\n", succ_cluster);
            if (succ_cluster == -1)
                return -1;
            else
            {
                offset = vEB_tree_minimum((v->cluster)[succ_cluster]);
                return index(v->u, succ_cluster, offset);
            }
        }
    }
}

bool
vanEmdeBoas::isMember(int x)
{
    return vEB_isMember(root, x);
}

bool
vanEmdeBoas::vEB_isMember(vEBnode* v, int x)
{
    if (x == v->maximum || x == v->minimum)
        return true;
    else if (v->u == 2)
        return false;
    else
        return vEB_isMember((v->cluster)[high(v->u, x)], low(v->u, x));
}

void
vanEmdeBoas::Delete(int x)
{
    vEB_tree_delete(root, x);
}

void
vanEmdeBoas::vEB_tree_delete(vEBnode* v, int x)
{
    int fisrt_cluster, summary_max;
    printf("u(%d): delete %d\n", v->u, x);
    if (v->minimum == v->maximum)
    {
        v->maximum = -1;
        v->minimum = -1;
    }
    else if (v->u == 2)
    {
        if (x == 0)
            v->minimum = 1;
        else
            v->minimum = 0;

        v->maximum = v->minimum;
    }
    else
    {
        if (x == v->minimum)
        {
            fisrt_cluster = vEB_tree_minimum(v->summary);
            x = index(v->u, fisrt_cluster, vEB_tree_minimum((v->cluster)[high(v->u, x)]));
            v->minimum = x;
        }

        vEB_tree_delete((v->cluster)[high(v->u, x)], low(v->u, x));

        if (vEB_tree_minimum((v->cluster)[high(v->u, x)]) == -1)
        {
            vEB_tree_delete(v->summary, high(v->u, x));
            if (x == v->maximum)
            {
                summary_max = vEB_tree_maximum(v->summary);
                if (summary_max == -1)
                    v->maximum = v->minimum;
                else
                    v->maximum = index(v->u, summary_max,
                    vEB_tree_maximum((v->cluster)[high(v->u, summary_max)]));

            }
        }
        else if (x == v->maximum)
            v->maximum = index(v->u, high(v->u, x), vEB_tree_maximum((v->cluster)[high(v->u, x)]));
    }
}

void
vanEmdeBoas::Insert(int key)
{
    vEB_tree_insert(root, key);
}

void
vanEmdeBoas::vEB_tree_insert(vEBnode* v, int x)
{
    printf("u(%d) : insert %d, high %d, low %x\n", v->u, x, high(v->u, x), low(v->u, x));
    if (v->minimum == -1)
        vEB_empty_tree_insert(v, x);
    else
    {
        if (x < v->minimum)
            myswap(x, v->minimum);

        if (v->u > 2)
        {
            printf("  ");
            if (vEB_tree_minimum((v->cluster)[high(v->u, x)]) == -1)
            {
                vEB_tree_insert(v->summary, high(v->u, x));
                vEB_empty_tree_insert((v->cluster)[high(v->u, x)], low(v->u, x));
            }
            else
            {
                vEB_tree_insert((v->cluster)[high(v->u, x)], low(v->u, x));
            }

        }

        if (x > v->maximum)
            v->maximum = x;
    }
}


void
vanEmdeBoas::vEB_empty_tree_insert(vEBnode* v, int x)
{
    v->minimum = x;
    v->maximum = x;
}

void
vanEmdeBoas::build_vEB_tree(vEBnode* x)
{
    if (x->u == 2)
        return;

    int sqrt_u = sqrt(x->u);

    //summary
    x->summary = new vEBnode(sqrt_u);
    build_vEB_tree(x->summary);

    //cluster
    for (int i = 0; i < (sqrt_u); i++) {
        (x->cluster)[i] = new vEBnode(sqrt_u);
        build_vEB_tree((x->cluster)[i]);
    }

}

void
vanEmdeBoas::debug1(vEBnode* x)
{
    if (x->u == 2)
        return;

    printf("u: %d %p\nsummary: %p \n", x->u, x, x->summary);

    debug1(x->summary);

    for (int i = 0; i < sqrt(x->u); i++)
        printf("cluster: %p\n", (x->cluster)[i]);
    printf("\n");
    for (int i = 0; i < sqrt(x->u); i++)
        debug1((x->cluster)[i]);
}

vEBnode*
vanEmdeBoas::getRoot()
{
    return root;
}

vanEmdeBoas::vanEmdeBoas(int universe) : u(universe)
{
    //ctor
    root = new vEBnode(u);
    build_vEB_tree(root);
}

vanEmdeBoas::~vanEmdeBoas()
{
    //dtor
}
