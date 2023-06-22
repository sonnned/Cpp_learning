#include <iostream>

using namespace std;

int main() {
  int operand1, operand2;
  operand1 = 10;
  operand2 = 20;

  cout << "Operand 1: " << operand1 << endl;
  cout << "Operand 2: " << operand2 << endl;

  cout << "Addition: " << operand1 + operand2 << endl;
  cout << "Subtraction: " << operand1 - operand2 << endl;
  cout << "Multiplication: " << operand1 * operand2 << endl;
  cout << "Division: " << operand1 / operand2 << endl;
  cout << "Modulus: " << operand1 % operand2 << endl;

  cout << "Relational Operators" << endl;
  cout << "Equal to: " << (operand1 == operand2) << endl;
  cout << "Not equal to: " << (operand1 != operand2) << endl;
  cout << "Greater than: " << (operand1 > operand2) << endl;
  cout << "Less than: " << (operand1 < operand2) << endl;
  cout << "Greater than or equal to: " << (operand1 >= operand2) << endl;
  cout << "Less than or equal to: " << (operand1 <= operand2) << endl;
  
}