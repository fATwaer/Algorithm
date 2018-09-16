#include "Btree.h"
#include "stdio.h"


bnode*
Btree::Allocate_Node()
{
    bnode* x = new bnode;
    x->key = new char[2 * t - 1 + 1];
    x->cp = new bnode*[2 * t + 1];
    return x;
}


bnode*
Btree::BTree_Create()
{
    bnode* x = new bnode;
    x->leaf = true;
    x->n = 0;

    x->key = new char[2 * t - 1 + 1];
    x->cp = new bnode*[2 * t + 1]; // abort the first element of the array;

    DiskRead(x);
    root = x;
    return x;
}

void
Btree::BTree_SplitChild(bnode *x, int i)
{

    bnode* z = Allocate_Node();
    bnode* y = (x->cp)[i];

    z->leaf = y->leaf;
    z->n = t-1;

    for (int j = 1; j <= t-1; j++)
        (z->key)[j] = (y->key)[j+t]; // j+t = j + (t-1) + 1
    if (y->leaf == false)
        for (int j = 1; j <= t; j++)
            (z->cp)[j] = (y->cp)[j+t];

    y->n = t-1;
    for (int j = x->n + 1; j >= i+1; j--)
        (x->cp)[j+1] = (x->cp)[j];
    (x->cp)[i+1] = z;

    for (int j = x->n; j >= i; j--)
        (x->key)[j+1] = (x->key)[j];
    (x->key)[i] = (y->key)[t];
    printf("split->[%c]\n", (x->key)[i]);
    x->n++;
    DiskWrite(x);
    DiskWrite(y);
    DiskWrite(z);
}


void
Btree::BTree_Insert(char key)
{

    bnode* r = root;
    if (r->n == 2 * t - 1) {
        bnode *s = Allocate_Node();
        root = s;
        s->leaf = false;
        s->n = 0;
        (s->cp)[1] = r;
        BTree_SplitChild(s,1);
        BTree_Insert_NONFULL(s, key);
    }
    else
        BTree_Insert_NONFULL(r, key);

}

void
Btree::BTree_Insert_NONFULL(bnode *x, char k)
{

    int i = x->n;
    if (x->leaf == true) {

        while (i >= 1 && k < (x->key)[i]) {
            (x->key)[i+1] = (x->key)[i];
            i--;
        }

        printf("insert : %c\n", k);

        (x->key)[i+1] = k;
        x->n++;

        DiskWrite(x);

    } else {
        while (i >= 1 && k < (x->key)[i])
            i--;
        i += 1;

        DiskRead((x->cp)[i]);

        if ((x->cp)[i]->n == 2 * t - 1) {
            BTree_SplitChild(x, i);
            if (k > (x->key)[i]) // the new key comes from child node
                i += 1;
        }

        BTree_Insert_NONFULL((x->cp)[i], k);
    }
}





int
Btree::BTree_Delete(bnode* x, char k)
{
    int j = 1;
    // find k;
    while (j <= x->n && k > (x->key)[j])
        j++;

    /** case 1: key 'k' is in the node x, and node x is a leaf node*/

    if (x->leaf && x->n > t-1) {
        printf("case 1\n");
        j += 1;
        // left shift
        while (j <= x->n) {
            (x->key)[j-1] = (x->key)[j];
            j++;
        }
        x->n--;
        // set nil
        while ((j-1) < 2 * t ) {
            (x->key)[j-1] = 0;
            j++;
        }
        printf("remove [%c]\n", k);
        DiskWrite(x);
        return 0;

    } else if (k == (x->key)[j] && !(x->leaf)) {


    /** case 2: node x is not a leaf node, it need keep the number of elements greater than t-1*/

        bnode* y = (x->cp)[j];
        bnode* z = (x->cp)[j+1];

        DiskRead(y);
        DiskRead(z);


        if (y->n >= t) {


    /** case 2a: y node >= t-1 + 1, the precursor replaces the x->key.*/


            printf("precursor: %c\n", (y->key)[y->n]);
            (x->key)[j] = (y->key)[y->n];
            BTree_Delete(y, (y->key)[y->n]);


        } else if (z->n >= t) {


    /** case 2b: z node >= t-1 +1, the successor replaces the x->key.*/


            printf("successor: %c\n", (z->key)[1]);
            (x->key)[j] = (z->key)[1];
            BTree_Delete(z, (z->key)[1]);


        } else {


    /** case 2c: both y and z don't have extra key, merge k and z into node
    y, and simply delete k in the node z finally.*/
            printf(" case 2c  \n");
            int i;

            //merge k into y
            (y->key)[y->n+1] = k;
            y->n += 1;

            //merge node z into y
            for (i = 1; i <= t-1; i++)
                (y->key)[y->n+i] = (z->key)[i];
            for (i = 1; i <= t; i++)
                (y->cp)[y->n+i+1] = (z->cp)[i];
            y->n = 2 * t - 1;
            delete z;
            //deleting key is in the node x
            for (i = j; i <= x->n; i++)
                (x->key)[i] = (x->key)[i+1];
            (x->key)[x->n] = 0;
            for (i = j+1; i <= x->n+1; i++)
                (x->cp)[i] = (x->cp)[i+1];
            (x->key)[x->n+1] = NULL;
            x->n--;

            if (x->n == 0) {
                delete x;
                root = y;
            }

            //deleting key is in the node y
            BTree_Delete(y, k);


            DiskWrite(y);
            DiskWrite(z);
        }
    } else {
            /** case 3: the key isn't in the node, it need to
            recursively find the corresponding key */


            printf("case 3 \n");
            bnode *ch;
            int r;

            //find the node recursively
            if (k != (x->key)[j])
            {
                // it will return when the node
                // does have the key.

                ch = (x->cp)[j];

                r = BTree_Delete(ch, k);
                if (r == 0)
                    return 0;
            } else
                return j;



            bnode* pre = (x->cp)[j-1];
            bnode* nxt = (x->cp)[j+1];

            DiskRead(ch);
            DiskRead(pre);
            DiskRead(nxt);

            printf("p: %p\n", nxt);

            /** case 3a: node doesn't have enough key,
            steeling key from brother node */
            if (pre && pre->n >= t) {

                printf("case 3a1\n");
                for (int i = r; i > 1; i--)
                    (ch->key)[i] = (ch->key)[i-1];

                (ch->key)[1] = (x->key)[j-1];

                (x->key)[j-1] = (pre->key)[pre->n];
                BTree_Delete(pre, (pre->key)[pre->n]);
                DiskWrite(ch);
                DiskWrite(pre);

            } else if (nxt && nxt->n >= t) {

                printf("case 3a2\n");
                for (int i = r; i < nxt->n; i++)
                    (ch->key)[i] = (ch->key)[i+1];


                (ch->key)[nxt->n] = (x->key)[j];

                (x->key)[j] = (nxt->key)[1];
                BTree_Delete(nxt, (nxt->key)[1]);
                DiskWrite(ch);
                DiskWrite(nxt);
            } else {

                /** case 3b: both of the brother node haven't
                enough key, steeling key from the parent node*/

                printf("case 3c\n");

                for (int i = r; i < (t-1)+1-1; i++)
                        (ch->key)[i] = (ch->key)[i+1];
                if (pre == NULL) { //merge next child node

                    (ch->key)[t] = (x->key)[j];
                    for (int i = 1; i <= t-1; i++)
                        (ch->key)[i+t] = (nxt->key)[i];
                    delete nxt;
                    BTree_Delete(x, (x->key)[j]);
                    DiskWrite(ch);
                } else { // merge previous node

                    (pre->key)[t] = (x->key)[j-1];
                    for (int i = 1; i <= t-1-1; i++)
                        (pre->key)[i+t] = (ch->key)[i];
                    delete ch;
                    BTree_Delete(x, (x->key)[j-1]);
                    DiskWrite(pre);

                }



            }


            return 0;




        }





}




Btree::Btree()
{
    //ctor
    t = 2;
}

Btree::~Btree()
{
    //dtor
}
void
Btree::DiskRead(bnode *)
{
}
void
Btree::DiskWrite(bnode *)
{
}

bnode*
Btree::_root()
{
    return root;
}
