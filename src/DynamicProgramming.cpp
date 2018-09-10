#include "DynamicProgramming.h"
#include <iostream>
using namespace std;
DynamicProgramming::DynamicProgramming()
{
    //ctor
}

DynamicProgramming::~DynamicProgramming()
{
    //dtor
}

void
DynamicProgramming::DebugPrint1()
{
    //printf("A: %s \nB: %s \nLCS: %s", strA, strB, lcs);
    std::cout << strA << std::endl;
    std::cout << strB << std::endl;
    std::cout << lcs ;
}


void
DynamicProgramming::LCSlength()
{
    int m = strA.length();
    int n = strB.length();
    cout << m << " " << n;
}
