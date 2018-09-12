#ifndef DYNAMICPROGRAMMING_H
#define DYNAMICPROGRAMMING_H
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

enum direction {
    LEFT = 0,
    UP,
    UpperLeft
};

class DynamicProgramming
{

    public:
        /** Default constructor */
        DynamicProgramming();
        /** Default destructor */
        ~DynamicProgramming();

        /** longest common substring */
        DynamicProgramming(string s1, string s2) : strA(s1), strB(s2), lcs("") , m(strA.length()+1), n(strB.length()+1){
                b = (direction **)malloc(sizeof(direction *[m]) * n);
                c = (int **) malloc (sizeof(int *[m]) * n);

                *b = (direction *)malloc(sizeof(direction) * m * n);
                *c = (int *)malloc(sizeof(int) * m * n);

                for (int y = 1; y < n; y++ ) {
                    b[y] = b[y-1] + m;
                    c[y] = c[y-1] + m;
                }
        }
        void DebugPrint1();
        void LCSlengthIterative();
        int LCSlengthRecursive(int i, int j);
        void PrintLCS(direction **b, int **c, int x, int y);

    private:
        /** longest common substring */
        string strA;
        string strB;
        string lcs;
        int m,n;
        direction **b;
        int **c;

};

#endif // DYNAMICPROGRAMMING_H
