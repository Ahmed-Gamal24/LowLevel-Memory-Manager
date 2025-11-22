#pragma once
#include <cstddef>
class heap;
void* operator new(std::size_t size, heap* pointerHeap);
void operator delete(void* pointerMemory);