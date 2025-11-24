#pragma once


#include"memoryOperators.h"
#include"memoryOperators.cpp"

const int NAMELENGTH = 30;

class heap{
    private:
        char name[NAMELENGTH];
        int numOfAllocations ;
        int nextValidAllocId;
        size_t totalAllocatedSize;
        allocHeader* pListHead;
        allocHeader* lastAdedHeader;
        
        
        public:
        heap(const char* name);
        const char* getName()const;
        int nextValidAllocID();
        void AddAllocation(size_t size, allocHeader* allocHead);
        void RemoveAllocation(allocHeader* allocHead);
        int getMemoryBookMark();
        void reportMemoryLeaks(int bookMark1, int bookMark2);
};