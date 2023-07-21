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
Consiste en hacer que una función realice distintas operaciones dependiendo de los argumentos que se le pasen.
```cpp
#include <iostream>
using namespace std;

double product(double x, double y){
  return x * y;
}

// Overloading the function to handle three arguments
double product(double x, double y, double z){
  return x * y * z;
}

// Overloading the function to handle floats
float product(float x, float y){
  return x * y;
}

int main() {
  double x = 10;
  double y = 20;
  double z = 5;
  float a = 12.5;
  float b = 4.654;
  cout << product(x, y) << endl;
  cout << product(x, y, z) << endl;
  cout << product(a, b) << endl;
  // cout << product(x) << endl;
}
```
La sobre carga nos ahorra memoria en el sistema, por lo tanto se compilan más rápido
## Punteros
### Direcciones variables en Stack
La estructura de los Stacks
```cpp
int main() {
  int var = 10;
}
```
Esto reserva memoria para __var__ en el stack, en el stack se almacenan diferentes funciones, en la parte superior del stack se encuentra la función que se llamó más recientemente, en este caso __main()__ junto con todas las variables que se declararon dentro de la función, en este caso __var__.

Cada vez que se libera una función, se libera su espacio en la memoria y esas variables se pierden para siempre,, por lo tanto __var__ es local por naturaleza, solo existe dentro de la función __main()__.

A las variables del stack se les asigna memoria en la compilación, este espacio de memoria es fijo y no puede cambiar durante la ejecución del programa.

Solo podemos acceder a una función si esta está en la parte superior del stack, por lo tanto no podemos acceder a las variables de una función que no esté en la parte superior del stack.
### Acceso a la dirección de una variable
Cada variable del stack se almacena en una dirección determinada. La dirección de memoria puede ser obtenida usando el operador __&__.
```cpp
#include <iostream>
using namespace std;

int main() {
  int var = 10;
  cout << &var; // 0x7ffe364a82c4
}
```
## Punteros
Un puntero contiene la dirección de un objeto almacenado en memoria. se usa la sintaxis __type *name__ para declarar un puntero.
* __&__ permite acceder a la dirección de una variable
* __*__ permite acceder al valor de una variable a través de su dirección
```cpp
#include <iostream>
using namespace std;

int main() {
  int var = 10;
  int *p;
  p = &var; // p points to the address of var 
  cout << "The address of var: " << p << endl; // The address of var: 0x7ffe3d6a0844
  cout << "The value of var: " << *p << endl; //The value of var: 10
  
  *p = 15; // update the value of p
  cout << "The new value of var is: " << var << endl; // var is updated! -- The new value of var is: 15
  
  var = 20; // the value of var is updated
  cout << "The new value of *p and var: " << *p << endl; // p has been updated as well! -- The new value of *p and var: 20
  
  int arr[] = {1, 3, 5, 7};
  p = arr; // p now points to the first element of arr
  cout << *p << endl; // the element at the zero-th index -- 1
  cout << *(p + 2) << endl; // the element at the second index -- 5
}
```
## Punteros y memoria dinámica
### Heap: El almacén dinámico de memoria
Se trata de un espacio de memoria que no está siendo gestionado por la CPU. Podemos especificar la cantidad de espacio que queremos, y una porción aleatoria del heap se reservará para nosotros

Una variable en memoria dinámica (heap) puede tener un ámbito __global__ en lugar de ser sólo una variable local para una función
### Objetos en heap
Para acceder al heap usamos punteros Nos permite crear objetos dinámicos utilizando __new__. __delete__ libera la memoria reservada por un determinado puntero

El puntero se almacena en el stack y puede acceder tanto al stack como al heap
```cpp
#include <iostream>
using namespace std;

int main() {
  int *p = new int;   // dynamic memory reserved for an integer 
  *p = 10;   // the object is assigned the value of 10
  cout << "The value of the object p points to: " << *p << endl; // The value of the object p points to: 10
  
  int *q = p;   // both pointers point to the same object
  cout << "The value of the object q points to: " << *q << endl; // The value of the object q points to: 10
  
  double *arr = new double[500]; // an array of size 500 has been created in the heap
  arr[0] = 50;
  cout << "arr[0]: " << arr[0] << endl; // arr[0]: 50
  
  // delete pointers and free up space
  delete p, q;
  delete[] arr;
  cout << "p now points to a random value and should not be accesed: " << *p << endl; // p now points to a random value and should not be accesed: 175094648
  p = new int(5); // The pointer can now be re-used to point to something else
  cout << "The value of the object p points to: " << *p << endl; // The value of the object p points to: 5
}
```
Los objetos __new__ son creados durante el tiempo de ejecución
# Punteros cheat sheet
Syntax | Purpose
--- | ---
int *p |	Declares a pointer p
p = new int |	Creates an integer variable in dynamic memory and places its address in p
p = new int(5) |	Creates an integer object in dynamic memory with the value of 5
p = new int[5] |	Creates a dynamic array of size 5 and places the address of its first index in p
p = &var |	Points p to the var variable
*p |	Accesses the value of the object p points to
*p = 8 |	Updates the value of the object p points to
p |	Accesses the memory address of the object p points to
delete p |	Deletes the object p points to

## Pasar punteros como argumentos
Los argumentos de las funciones usualmente están en el scope local de la función. Cuando la función retorna todas las variables son eliminadas

```cpp
#include <iostream>
using namespace std;

void square(int *a){ // the function takes a pointer and replaces the value with its square
  if(a != NULL){
    *a = (*a) * (*a);
  }
}

int main() {
  int *p = new int(5);
  cout << "The value of p before the function call: " << *p << endl; // The value of p before the function call: 5
  square(p);
  cout << "The value of p after the function call: " << *p << endl; // The value of p after the function call: 25
}
```
Los punteros pueden actuar como una variable global
## Aritmética de punteros
* __p + 1__: Incrementa el puntero en 1
* __p - 1__: Decrementa el puntero en 1
Se incrementa y decrementa la dirección de memoria en un tamaño de __4 bytes__