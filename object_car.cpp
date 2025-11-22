#include"object_car.h"
#include"memoryOperators.h"

car::car(){
    pointerHeap = nullptr;
}

void * car::operator new(size_t size){
    if(pointerHeap == nullptr){
        pointerHeap = heapFactory::createHeap("Car Objects");
    }
    
    return ::operator new(size, pointerHeap);
} 

void car::operator delete(void * p, size_t size){
    ::operator delete(p);
}