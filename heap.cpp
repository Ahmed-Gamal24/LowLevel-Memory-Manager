#include<string>
#include<iostream>

#include"heap.h"
#include"memoryOperators.cpp"


heap::heap(const char* name){
    strncpy(this->name, name, NAMELENGTH - 1);
    this->name[NAMELENGTH - 1] = '\0';

    numOfAllocations = 0;
    nextValidAllocId = 0;
    totalAllocatedSize = 0;
    pListHead = nullptr;    
    lastAdedHeader = nullptr;    
}

const char* heap::getName()const{
    return name;
}

int heap::nextValidAllocID(){
    return nextValidAllocId++;
}

void heap::AddAllocation(size_t size, allocHeader* allocHead){
    totalAllocatedSize += size;
    numOfAllocations++;

    if(allocHead->allocID == 0){//first allocation header
        allocHead->pPrev = nullptr;
        lastAdedHeader = allocHead;
        pListHead = allocHead;
    }
    
    lastAdedHeader->pNext = allocHead;
    allocHead->pPrev = lastAdedHeader;
    allocHead->pNext = nullptr;
    lastAdedHeader = allocHead;

}

void heap::RemoveAllocation(allocHeader* allocHead){
    numOfAllocations--;
    totalAllocatedSize -= allocHead->size;

    //trying to remove when the list is empty
    if(pListHead == nullptr){
        return;
    }
    //remove when list have one header
    if(allocHead == pListHead && pListHead->pNext == nullptr){
        pListHead = nullptr;
        delete allocHead;
    }
    // remove first header
    else if(allocHead == pListHead){
        pListHead = pListHead->pNext;
        delete allocHead;
    }
    // remove the last header
    else if(allocHead->pNext == nullptr){
        allocHead->pPrev->pNext = nullptr;
        allocHead->pPrev = nullptr;
        lastAdedHeader = lastAdedHeader->pPrev;
        delete allocHead;
    }

    // remove any other position
    else{
        allocHead->pPrev->pNext = allocHead->pNext;
        allocHead->pNext->pPrev = allocHead->pPrev;
        allocHead->pPrev = nullptr;
        allocHead->pNext = nullptr;
        delete allocHead;
    }
}

int heap::getMemoryBookMark(){
    return nextValidAllocID();
}

void heap::reportMemoryLeaks(int bookMark1, int bookMark2){
    //bookMark1 is the first snapshot 

    allocHeader* temp = pListHead;
    while(temp != nullptr){//loop throug the heap in the second snapshot
        if(temp->allocID >= bookMark1 && temp->allocID < bookMark2){//leak happened
            //print the info of headers that caused leaks
            cout << "------leak happened!------" << endl;
            cout << "Allocation ID:" << temp->allocID << endl;
            cout <<"Allocation Size: " <<  temp->size << endl;
        }
        temp = temp->pNext;
    }

}