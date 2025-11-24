#include"player.h"
#include"memoryOperators.h"

palyer::palyer(){
    pointerHeap = nullptr;
}

void * palyer::operator new(size_t size){
    if(pointerHeap == nullptr){
        pointerHeap = heapFactory::createHeap("Player Objects");
    }
    
    return ::operator new(size, pointerHeap);
} 

void palyer::operator delete(void * p, size_t size){
    ::operator delete(p);
}