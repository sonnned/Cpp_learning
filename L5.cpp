#include <iostream>

using namespace std;

int main() {
  int edad = 18;

  if (edad < 18) {
    cout << "No puedes votar" << endl;
  } else if (edad == 18) {
    cout << "Puedes votar por primera vez" << endl;
  } else {
    cout << "Puedes votar" << endl;
  }
  
  return 0;
}