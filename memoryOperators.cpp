#include<iostream>
#include<string>
#include <cassert>

#include"heap.h"

using namespace std;


const uint32_t MEMSYSTEM_SIGNATURE = 0xBDDDF00Du;
const uint32_t MEMSYSTEM_ENDMARKER = 0xBAADF00Du;


struct allocHeader{
    uint32_t signature;
    int allocID;
    int size;
    heap* pointerHeap;
    allocHeader * pNext;
    allocHeader * pPrev;
};


static int allocCounterForAllHeaps = 0;

//overloading operators new and delete
void * operator new(size_t size, heap * pointerHeap){
    size_t iRequestedBytes = size + sizeof(allocHeader);
    char * pointerMemory = (char *)malloc(iRequestedBytes);
    allocHeader * pHeader = (allocHeader *)pointerMemory;
    pHeader->signature = MEMSYSTEM_SIGNATURE;
    pHeader->pointerHeap = pointerHeap;
    pHeader->size = size;
    pHeader->allocID = pointerHeap->nextValidAllocID();
    allocCounterForAllHeaps++;
  
    char * startMemBlock = pointerMemory + sizeof(allocHeader);
    int * endMarker = (int*) (startMemBlock + size);
    *endMarker = MEMSYSTEM_ENDMARKER;

    pointerHeap->AddAllocation(size, pHeader);

    return startMemBlock;
}

void operator delete (void * pointerMemory) {
    allocCounterForAllHeaps--;
    allocHeader * pHeader = (allocHeader *) ( (char *)pointerMemory - sizeof(allocHeader) );
    int * endMarker = (int*) ((char*)pointerMemory + pHeader->size);
    assert (*endMarker == MEMSYSTEM_ENDMARKER);
    pHeader->pointerHeap->RemoveAllocation(pHeader);
    free(pHeader);
}