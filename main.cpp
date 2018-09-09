#include <iostream>
#include "SortAlgorithm.h"
#include "binarysearchtree.h"
#include "rbtree.h"
using namespace std;



int main()
{
    /* algorithm  */
    SortAlgorithm instance;
    //instance.insertSort(0, instance.arrayLength());
    //instance.mergeSort(0, instance.arrayLength()-1);
    //instance.bulidMaxHeap();
    //instance.heapSort();
    //instance.quickSort(1, instance.arrayLength());
    //instance.outputArray();
    //instance.countSort();
    //instance.radixSort();
    //instance.outputArray();

    /* data struct */
    //BinarySearchTree bst;
//    node a1(10), a2(5), a3(4), a4(8), a5(11), a6(9);
//    bst.treeInsert(&a1);
//    bst.treeInsert(&a2);
//    bst.treeInsert(&a3);
//    bst.treeInsert(&a4);
//    bst.treeInsert(&a5);
//    bst.treeInsert(&a6);
//    bst.inorderTreeWalk(bst.getRoot());
//    cout << endl;
//    node *d = bst.searchNode(5);
//    bst.treeDelete(d);
//
//    bst.inorderTreeWalk(bst.getRoot());
    //cout << bst.getRoot()->key;

    /* red-black-tree*/
    rbtree rbt;
    rbt.Insert(11);
    rbt.Insert(2);
    rbt.Insert(13);
    rbt.Insert(1);
    rbt.Insert(15);
    rbt.Insert(7);
    rbt.Insert(5);
    rbt.Insert(8);
    rbt.Insert(4);
//    rbt.Insert(3);
//    rbt.Insert(2);
//    rbt.Insert(1);
    rbt.inorder(rbt.getRoot());

    rbnode *c = rbt.nodesearch(2);
    printf("find: %d\n", c->key);
    rbt.rbDelete(c);
    rbt.inorder(rbt.getRoot());
}


