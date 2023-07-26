#include <iostream>
using namespace std;

void swapVals(int *p, int *q){
  int temp = *p;
  *p = *q;
  *q = temp;
}