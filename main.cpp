
#include "SortAlgorithm.h"
#include "binarysearchtree.h"
#include "rbtree.h"
#include "DynamicProgramming.h"
#include "greedy.h"
#include "Btree.h"
#include "bnode.h"
#include "FIB.h"
#include "vanEmdeBoas.h"
#include "HashTables.h"
#include "cstdlib"

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


        //b - tree

//    Btree instance5;
//    bnode* x = instance5.BTree_Create();
//    instance5.BTree_Insert('a');
//    instance5.BTree_Insert('c');
//    instance5.BTree_Insert('e');
//    instance5.BTree_Insert('b');
//    instance5.BTree_Insert('d');
//    //instance5.BTree_Insert('f');
////
////    for (int i = 'a'; i < 'a'+3; i++)
////        instance5.BTree_Insert(i);
//
////    instance5.BTree_Delete(x, 'a');
////    instance5.BTree_Delete(x, 'b');
////    for (int i = 0; i < 4; i++)
////        printf("(x->key)[%d]: %c\n", i, (x->key)[i]);
////
//
//    //printf("%c", (((x->cp)[1])->key)[2]);
//    x = instance5._root();
////    for (int i = 0; i < 4; i++)
////        printf("(x->key)[%d]: %c\n", i, (x->key)[i]);
////    for (int i = 0; i < 4; i++)
////        printf("%d: (left:%c right: %c)\n", i, (((x->cp)[1])->key)[i], (((x->cp)[2])->key)[i]);
//
//    instance5.BTree_Delete(x,'e');
//    x = instance5._root();
//    for (int i = 0; i < 4; i++)
//        printf("root[%d]: %c\n", i, (x->key)[i]);
//    printf("n : %d\n", x->n);
//    for (int i = 0; i < 4; i++)
//        printf("%d: (left:%c right: %c)\n", i, (((x->cp)[1])->key)[i], (((x->cp)[2])->key)[i]);
//    printf("left : %d, right : %d \n", (((x->cp)[1])->n), (((x->cp)[2])->n));
//
//
//    instance5.BTree_Delete(x,'d');
//    x = instance5._root();
//    for (int i = 0; i < 4; i++)
//        printf("root[%d]: %c\n", i, (x->key)[i]);
//    printf("n : %d\n", x->n);
//    for (int i = 0; i < 4; i++)
//        printf("%d: (left:%c right: %c)\n", i, (((x->cp)[1])->key)[i], (((x->cp)[2])->key)[i]);
//    printf("left : %d, right : %d \n", (((x->cp)[1])->n), (((x->cp)[2])->n));
//
//
//    instance5.BTree_Delete(x,'c');
//    x = instance5._root();
//    for (int i = 0; i < 4; i++)
//        printf("root[%d]: %c\n", i, (x->key)[i]);
//    printf("n : %d\n", x->n);

    // fib heap
//    FIB *instance6 = new FIB;
//    (*instance6).Insert(10);
//    (*instance6).Insert(11);
//    (*instance6).Insert(12);
//    (*instance6).debug();
//
//    FIB *instance7 = new FIB;
//    (*instance7).Insert(20);
//    (*instance7).Insert(2);
//    (*instance7).Insert(7);
//    (*instance7).Insert(0);
//    (*instance7).debug();
//
//    FIB &H = (*instance6).FIB_HeapUnion(instance7);
//    H.debug();
//
//    printf("extract value: %d\n", H.ExtractMin());
//    H.debug();
//    H.DecreaseRoot();
//    H.debug();

    //van emde boas tree
//    vanEmdeBoas instance10(16);
//    //instance10.debug1(instance10.getRoot());
//    instance10.Insert(2);
//    instance10.Insert(3);
//    instance10.Insert(4);
//    instance10.Insert(5);
//    instance10.Insert(7);
//    instance10.Insert(14);
//    instance10.Insert(15);
//
//    printf("7 is member ? %s\n", instance10.isMember(7) == 1 ? "true" : "false");
//    printf("8 is member ? %s\n", instance10.isMember(8) == 1 ? "true" : "false");
//
//    printf("the successor of %d is %d\n", 7, instance10.successor(7));
//    printf("the successor of %d is %d\n", 4, instance10.successor(4));
//
//    printf("the predecressor of %d is %d\n", 4, instance10.predecressor(4));
//    instance10.Delete(2);

    HashTables instance11;
    //instance11.debug();
    for (int i = 0; i < 100; i++)
        instance11.Insert(rand()%1000);
    instance11.debug();

}


