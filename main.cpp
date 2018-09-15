
#include "SortAlgorithm.h"
#include "binarysearchtree.h"
#include "rbtree.h"
#include "DynamicProgramming.h"
#include "greedy.h"
#include "Btree.h"
#include "bnode.h"

#include <iostream>
#include <string>
using namespace std;



int main()
{
    /* algorithm  */
    //SortAlgorithm instance;
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
//    rbtree rbt;
//    rbt.Insert(11);
//    rbt.Insert(2);
//    rbt.Insert(13);
//    rbt.Insert(1);
//    rbt.Insert(15);
//    rbt.Insert(7);
//    rbt.Insert(5);
//    rbt.Insert(8);
//    rbt.Insert(4);
////    rbt.Insert(3);
////    rbt.Insert(2);
////    rbt.Insert(1);
//    rbt.inorder(rbt.getRoot());
//
//    rbnode *c = rbt.nodesearch(2);
//    printf("find: %d\n", c->key);
//    rbt.rbDelete(c);
//    rbt.inorder(rbt.getRoot());

    /*lcs*/

//    DynamicProgramming instance2("abcd", "bc");
//    instance2.LCSlengthRecursive(4, 2);
//    instance2.DebugPrint1();

    /* greedy algorithm*/

        //activity select
//    ActivitySelect instance3;
//    instance3.recursive_selector(0, 11);
//    instance3.iterative_selector(11);
//    instance3.debug();

        // huffman
//        hfnode arr[] = {
//            hfnode('a', 45),
//            hfnode('b', 13),
//            hfnode('c', 12),
//            hfnode('d', 16),
//            hfnode('e', 9),
//            hfnode('f', 5),
//        };
//        int len = sizeof(arr)/sizeof(arr[0]);
//        Huffmantranslations instance4;
//        instance4.heapify(arr, len);
//        for (int i = 0; i < 6; i++) {
//            printf("%c: %d \n", arr[i].character, arr[i].freq);
//
//        }
//        instance4.buildHuffmanTree(arr, len);
//        cout << endl;
//        for (int i = 0; i < 6; i++) {
//            printf("%c: %d \n", arr[i].character, arr[i].freq);
//
//        }


    Btree instance5;
    bnode* x = instance5.BTree_Create();
    instance5.BTree_Insert('a');
    instance5.BTree_Insert('b');
    //printf("(x->key)[0]: %c, (x->key)[1]: %c", (x->key)[0], (x->key)[1]);


}


