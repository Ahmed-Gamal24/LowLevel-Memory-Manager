#pragma once

#include<vector>
#include"memoryOperators.h"

const int NAMELENGTH = 30;

class heap{
    private:
        char name[NAMELENGTH];
        int numOfAllocations ;
        size_t totalAllocatedSize;
        vector<allocHeader*> allocations;
        
        public:
        heap(const char* name);
        

        const char* getName()const;

        int nextValidAllocNumber();

        void AddAllocation(size_t size, allocHeader* allocHead);
        void RemoveAllocation(size_t size);

};