#include <iostream>

using namespace std;

int power (int base , int exponent ) {
    int result = 1;

    if (exponent == 0) {
        return result;
    } else {
        result *= base;
        return result * power(base, exponent - 1);
    }
}

int count_digits(int number) {
  if (abs(number)/10 == 0) {
    return 1;
  } else {
    return 1 + count_digits(number / 10);
  }
}

int Fibonacci(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return Fibonacci(n - 1) + Fibonacci(n - 2);
  }
}

int main() {
    int base, exponent;
    cout << "Enter base and exponent: ";
    cin >> base >> exponent;
    cout << base << " to the power of " << exponent << " is " << power(base, exponent) << endl;

    int number = 8625;
    int result;
    result = count_digits(number);
    cout << "Number of digits = " << result;

    int n = 4;
    int result2;
    result2 = Fibonacci(n);
    cout << "Fibonacci number = " << result2;

    return 0;
}