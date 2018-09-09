#include "SortAlgorithm.h"
#include <iostream>
using namespace std;
//SortAlgorithm::SortAlgorithm()
//{
//    //ctor
//}

SortAlgorithm::~SortAlgorithm()
{
    //dtor
}

int
SortAlgorithm::arrayLength()
{
    return len;
}

void
SortAlgorithm::outputArray()
{
    for (int i = 0; i < olen; i++)
        cout << a[i] << " ";
    cout << endl;
}



