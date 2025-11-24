#include<iostream>
#include<string>
#include<vector>

#include"memoryOperators.h"
#include"heapFactory.h"
#include"heap.h"
#include"car.h"
#include"player.h"

using namespace std;



int main(){

  size_t size = 40;

  car* car1;
  car1->operator new(size);
  car1->operator delete(car1, size);

  palyer* player1;
  player1->operator new(size);
  player1->operator delete(player1, size);

  return 0;
}


