# Programación Orientada a Objetos con C++
Se basa en la idea de objetos, los cuales son entidades con __propiedades__ y __funciones__ que interactúan entre sí.
## Funciones
```cpp
#include <iostream>
using namespace std;

int main() {
  int arr1[] = {40, 60, 20, 15, 50, 90};
  int size = sizeof(arr1)/sizeof(arr1[0]); // Compute length of an array
  int sum = 0;
  for(int i = 0; i < size; i++){ // A for loop to add each element of the array
    sum += arr1[i];
  }
  cout << "Sum of arr1: " << sum << endl;
  
  int arr2[] = {2, 4, 6, 8, 10};
  size = sizeof(arr2)/sizeof(arr2[0]);
  sum = 0;
  for(int i = 0; i < size; i++){ // A for loop to add each element of the array
    sum += arr2[i];
  }
  cout << "Sum of arr2: " << sum << endl;
  
  int arr3[] = {18, 40, 9, 17, 36};
  size = sizeof(arr3)/sizeof(arr3[0]);
  sum = 0;
  for(int i = 0; i < size; i++){ // A for loop to add each element of the array
    sum += arr3[i];
  }  
  cout << "Sum of arr3: " << sum << endl;  
}
```
Una función es un conjunto de sentencias que realizan operaciones.
Las funciones se usan para no repetir código haciendolo más limpio y fácil de leer
### Crear una función
Debemos declarar tipo de dato que regresa, nombre de la función y parámetros de entrada.
```cpp
#include <iostream>
#include <string>
using namespace std;

int sum(int num1, int num2){
  return num1 + num2;
}

string blah(){
  string s = "Hello World";
  return s;
}

void printName(string name){
  cout << name << endl;
  // No return statement needed as this is a void function
}

int main()
{
  int x = 10;
  int y = 20;
  int total = sum(x, y); // We store the returned value into a variable
  // of the corresponding type
  cout << total <<endl;

  string str = blah();
  cout << str <<endl;
  
  printName("Educative");  // This is a void function, so it doesn't need to be stored
}
```
#### Argumentos y scope
* __Por valor__: Nunca se pasan las variables dentro de las funcines, se hace una copia de cada argumento y se usan dentro de la función. Cuando la función termina todos los argumentos son destruidos. No se modifica el scope de la variable original.
```cpp
#include <iostream>
using namespace std;

void multiplyBy10(int num){
  num = num * 10;
}

int main(){
  int x = 10;
  
  cout << "Before function call" << endl; 
  cout << "x: " << x << endl;

  // Multiplying by 10
  multiplyBy10(x);

  cout << "After function call" << endl;
  cout << "x: " << x << endl;
}
```
* __Por referencia__: Cada variable se guarda en una dirección de memoria, entonces se pasa la dirección de memoria de la variable como argumento. Modifica el scope de la variable original.
```cpp
#include <iostream>
using namespace std;

void multiplyBy10(int &num){ // num will contain the reference of the 
                             // input variable
  num = num * 10;
}

int main(){
  int x = 10;
  
  cout << "Before function call" << endl; 
  cout << "x: " << x << endl;

  // Multiplying by 10
  multiplyBy10(x); 

  cout << "After function call" << endl;
  cout << "x: " << x << endl; // The actual value of x is changed!
}
```
#### Sobre carga de funciones