#include"heapFactory.h"
#include"heap.h"


heap * heapFactory::createHeap(const char* name){
     heap * newHeap = new heap("Game Object");
     return newHeap;
}