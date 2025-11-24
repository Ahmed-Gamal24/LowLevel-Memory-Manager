#include"baseClass.h" 
#include"memoryOperators.h"

base::base(){
    pointerHeap = nullptr;
}

void * base::operator new(size_t size){
    if(pointerHeap == nullptr){
        pointerHeap = heapFactory::createHeap("Heap");
    }

    return ::operator new(size, pointerHeap);
} 

void base::operator delete(void * p, size_t size){
    ::operator delete(p);
}