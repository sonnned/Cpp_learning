#include <iostream>

using namespace std;

int main() {
  int number;
  number = 100;
  int number2 = 200;
  int temp = number;
  number = number2;
  number2 = temp;

  cout << "number = " << number << endl;
  cout << "number2 = " << number2 << endl;
}