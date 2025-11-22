#include<string>
#include<vector>

#include"heap.h"
#include"memoryOperators.cpp"


heap::heap(const char* name){
    strncpy(this->name, name, NAMELENGTH - 1);
    this->name[NAMELENGTH - 1] = '\0';

    numOfAllocations = 0;
    totalAllocatedSize = 0;
}

const char* heap::getName()const{
    return name;
}

void heap::AddAllocation(size_t size, allocHeader* allocHead){
    totalAllocatedSize += size;
    allocations.push_back(allocHead);
}

int heap::nextValidAllocNumber(){
    return ++numOfAllocations;
}