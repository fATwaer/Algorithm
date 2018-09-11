#include "DynamicProgramming.h"
#include <iostream>
#include <stdlib.h>

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
DynamicProgramming::LCSlengthIterate()
{
    int i = 0, j = 0;

    /*as b[m, n], c[m, n]*/
    direction **b = (direction **)malloc(sizeof(direction *[m]) * n);
    int **c = (int **) malloc (sizeof(int *[m]) * n);

    *b = (direction *)malloc(sizeof(direction) * m * n);
    *c = (int *)malloc(sizeof(int) * m * n);

    for (int y = 1; y < n; y++ ) {
        b[y] = b[y-1] + m;
        c[y] = c[y-1] + m;
    }


    for (i = 1; i < m; i++)
        c[0][i] = 0;
    for (i = 0; i < n; i++)
        c[i][0] = 0;

    for (i = 1; i < n; i++)
        for (j = 1; j < m; j++)
            if (strA[j-1] == strB[i-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = UpperLeft;
            } else if (c[i][j-1] >= c[i-1][j]) {
                c[i][j] = c[i][j-1];
                b[i][j] = LEFT;
            } else {
                c[i][j] = c[i-1][j];
                b[i][j] = UP;
            }
    }

    PrintLCS(b, c, m, n);
}


void
DynamicProgramming::PrintLCS(direction **b, int **c, int x, int y)
{

    if (x == 0 || y == 0)
        return ;
    if (b[y-1][x-1] == UpperLeft) {
        PrintLCS(b, c, x-1, y-1);
        cout << strB[y-2] <<endl;
    } else if (b[y-1][x-1] == LEFT)
        PrintLCS(b, c, x-1, y);
    else
        PrintLCS(b, c, x, y-1);
}






