#include <iostream>

using namespace std;

int main() {
  int money = 20;
  int price = 10;

  cout << "money = " << money << endl;
  cout << "price = " << price << endl;

  while (money > 0) {
    cout << "money = " << money << endl;
    money -= price;
  }

  cout << "money = " << money << endl;

  do {
    cout << "money = " << money << endl;
    money += price;
  } while (money < 0);


  for (int i = 0; i < 10; i++) {
    cout << "i = " << i << endl;
  }
}