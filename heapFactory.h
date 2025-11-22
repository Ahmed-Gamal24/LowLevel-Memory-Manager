#pragma once

#include"heap.h"

static class heapFactory{

    public:
        static heap * createHeap(const char* name);
};