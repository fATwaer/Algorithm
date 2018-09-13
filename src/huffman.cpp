#include "greedy.h"
#include "huffmannode.h"
#include "lib.h"
#include "stdio.h"

void
Huffmantranslations::heapify(hfnode arr[], int len)
{
    buildHeap(arr, len+1);
}



hfnode *
Huffmantranslations::buildHuffmanTree(hfnode arr[], int len)
{
    int n = len;

    for (int i = 1; i < n; i++) {
            hfnode x = extractmin(arr, len);
            hfnode y = extractmin(arr, len);
            hfnode *z = new hfnode;
            z->left = &x;
            z->right = &y;
            z->freq = x.freq + y.freq;
            heapInsert(arr, len, *z);
            printf("%d %d\n", x.freq, y.freq);
    }
    return &arr[0];
}
