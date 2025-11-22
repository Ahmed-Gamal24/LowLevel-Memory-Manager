#pragma once

#include"heap.h"
#include"heapFactory.h"

class car{
    private:
        static heap * pointerHeap;

    public:
        car();
        /* we should write these two operator functions inside each class we
          are using in our app */
        static void * operator new(size_t size);
        static void operator delete(void * p, size_t size);


};
