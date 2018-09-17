#include "greedy.h"
//#include "lib.h"
#include "stdio.h"
greedy::greedy()
{
    //ctor
}

greedy::~greedy()
{
    //dtor
}

void
 ActivitySelect::debug()
 {
    int len = 11;
    for (int i = 0; i < len; i++)
        printf("%d ", s[i]);

    printf("\n");

    for (auto i : greedy_sequence)
        printf("%d ", i);

//    buildHeap(s, len);

//    int result = extractmin(s, len);
//    printf("result: %d \n", result);
//    result = extractmin(s, len);
//    printf("result: %d \n", result);
//    result = extractmin(s, len);
//    printf("result: %d \n", result);
//    for (int i = 0; i < len; i++)
//        printf("%d ", s[i]);


 }

 void
 ActivitySelect::recursive_selector(int k, int n)
 {
    int m = k + 1;

    while (m < n && f[k] > s[m])
        m++;
    if (m <= n) {
        greedy_sequence.push_back(m);
        recursive_selector(m, n);
    }
 }


void
ActivitySelect::iterative_selector(int n)
{
int k = 1;
greedy_sequence.push_back(k);
for (int m = 2; m <= n; m++)
    if (s[m] >= f[k]) {
        greedy_sequence.push_back(m);
        k = m;
    }
}
