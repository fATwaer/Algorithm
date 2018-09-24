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

    private:
        lknode* division_p;
};

#endif // HASHTABLES_H
