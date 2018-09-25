#ifndef HASHTABLES_H
#define HASHTABLES_H
#include "linklist.h"

class HashTables
{
    public:
        /** Default constructor */
        HashTables();
        /** Default destructor */
        virtual ~HashTables();
        void debug();
        void Insert(int key);
    private:
        int m = 100;
        lknode** division_p;
};

inline int
hash_function(int key)
{
    return key % 43;
}
#endif // HASHTABLES_H
