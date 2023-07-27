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
# Clases
Son usadas para crear tipos de datos definidos por el usuario. Una clase es como un plano para un objeto, define los atributos y métodos que un objeto puede tener.
```cpp
class className {

};

int main() {
  int i;
  className obj;
}
```
## Modificadores de acceso
Podemos imponer restricciones de acceso a diferentes partes de una clase. Hay tres tipos de modificadores de acceso:
1. __private__: Los miembros de una clase son privados por defecto. Los miembros privados solo pueden ser accedidos por funciones miembro de la misma clase.
```cpp
class Class1 {
  int num; // This is, by default, a private data member
  ...
};

class Class2 {
  private: // We have explicitly defined that the variable is private
  int num;
  ...
};
```
2. __public__: Significa que los miembros de la clase pueden ser accedidos desde cualquier parte del programa. Los miembros públicos pueden ser accedidos por funciones miembro de la misma clase, funciones de otras clases y funciones fuera de la clase.
```cpp
class myClass {
  int num; // Private variable
  
  public: // Attributes in this list are public
  void setNum(){
    // The private variable is directly accessible over here!
  }
};

int main() {
  myClass c; // Object created
  c.setNum(); // Can manipulate the value of num
  c.num = 20; // This would cause an error since num is private
}
```
3. __protected__: Su uso es principalmente en herencia
## Funciones miembro
```cpp
class Rectangle {
  int length;
  int width;

  public:
  void setLength(int l){ // This function changes the value of length
    length = l;
  }
  
  int area(){
    return length * width; // Only the values of the data members are accessed and used to calculate the area
  }
};
```
### Operador scope resolution
El operador __(::)__ nos permite declarar las funciones miembro fuera de la clase
```cpp
class Rectangle {
  int length;
  int width;

  public:
  
  // We only write the declaration here
  void setLength(int l);
  int area();
};

// Somewhere else in the code
void Rectangle::setLength(int l){ // Using the scope resolution operator
  length = l;
}

int Rectangle::area(){
  return length * width; 
}
```
### Funciones Get y Set
Son simples como cualquier otra función miembro, pero su propósito es obtener y establecer el valor de los atributos privados de la clase
```cpp
class Rectangle {
  int length;
  int width;

  public:
  
  // get and set for length
  void setLength(int l);
  int getLength();
  
  // get and set for width
  void setWidth(int w);
  int getwidth();
  
  int area();
};


void Rectangle::setLength(int l){ 
  length = l;
}
int Rectangle::getLength(){ 
  return length;
}

void Rectangle::setWidth(int w){ 
  width = w;
}
int Rectangle::getWidth(){ 
  return width;
}

int Rectangle::area(){
  return length * width; 
}
```
## Overloading
Es cuando hay varias funciones con el mismo nombre pero con diferentes parámetros. El compilador decide cuál función ejecutar dependiendo de los argumentos que se le pasen
```cpp
class Rectangle {
  int length;
  int width;

  public:
  
  // get and set for length
  void setLength(int l);
  int getLength();
  
  // get and set for width
  void setWidth(int w);
  int getwidth();
  
  int area();
  
  // Overloading the area function
  int area(int l, int w);
};
```
## Constructores
Es una función especial que se ejecuta cada vez que se crea un objeto de una clase. Se usa para inicializar los objetos de la clase
```cpp
#include <iostream>
#include <string>
using namespace std;

class Date {
  int day;
  int month;
  int year;

  public:
  // Default constructor
  Date(){
    // We must define the default values for day, month, and year
    day = 0;
    month = 0;
    year = 0;
  }

  // A simple print function
  void printDate(){ 
    cout << "Date: " << day << "/" << month << "/" << year << endl;
  }
};

int main(){
  // Call the Date constructor to create its object;
  
  Date d; // Object created with default values!
  d.printDate();
}
```
## Parametros de constructor
```cpp
#include <iostream>
#include <string>
using namespace std;

class Date {
  int day;
  int month;
  int year;

  public:
  // Default constructor
  Date(){
    // We must define the default values for day, month, and year
    day = 0;
    month = 0;
    year = 0;
  }
  
  // Parameterized constructor
  Date(int d, int m, int y){
    // The arguments are used as values
    day = d;
    month = m;
    year = y;
  }

  // A simple print function
  void printDate(){ 
    cout << "Date: " << day << "/" << month << "/" << year << endl;
  }
};

int main(){
  // Call the Date constructor to create its object;
  
  Date d(1, 8, 2018); // Object created with specified values!
  d.printDate();
}
```
### this
Es un puntero que apunta al objeto actual. Se usa para acceder a los miembros de la clase
```cpp
#include <iostream>
#include <string>
using namespace std;

class Date {
  int day;
  int month;
  int year;

  public:
  // Default constructor
  Date(){
    // We must define the default values for day, month, and year
    day = 0;
    month = 0;
    year = 0;
  }
  
  // Parameterized constructor
  Date(int day, int month, int year){
    // Using this pointer
    this->day = day;
    this->month = month;
    this->year = year;
  }

  // A simple print function
  void printDate(){ 
    cout << "Date: " << day << "/" << month << "/" << year << endl;
  }
};

int main(){
  // Call the Date constructor to create its object;
  
  Date d(1, 8, 2018); // Object created with specified values!
  d.printDate();
}
```
## Destructor
Contrario al constructor se llama cuando el objeto es destruido. Se usa para liberar la memoria reservada por el objeto. Usa el operador __~__ seguido del nombre de la clase
### Explicit Garbage Collection
Lo podemos crear mediante punteros inteligentes. Manteniendo un contador de referencias para cada objeto. Cuando el contador llega a cero, el objeto es eliminado
```cpp
#include <iostream>
#include <string>
using namespace std;

class Collector {
  int * list;
  int size;
  int capacity;

  public:
  // Default constructor
  Collector(){
    // We must define the default values for the data members
    list = nullptr;
    size = 0;
    capacity = 0;
  }
  
  // Parameterized constructor
  Collector(int cap){
    // The arguments are used as values
    capacity = cap;
    size = 0;
    list = new int[capacity];
  }

  bool append(int v){
    if (size < capacity) {
      list [ size++ ] = v;
      return true;
    }
    return false;
  }

  // A simple print function
  void dump(){ 
    for(int i = 0 ; i < size ; i++) {
      cout << list[i] << " ";
    }
    cout << endl;
  }
  
  ~Collector(){
    cout << "Deleting the object " << endl;
    if (capacity > 0)
      delete[] list; 
  }
};

int main(){  
  Collector c(10); 
  for (int i = 0 ; i < 15 ; i++){
    cout << c.append(i) << endl;
  }
}
```
## Funciones friend
Es una función independiente que tiene acceso a las variables privadas de una clase. Se declara precediendo la declaración de la clase con la palabra clave __friend__
```cpp
#include <iostream>
#include <string>

using namespace std;

class Ball{
  double radius;
  string color;
  
  public:
  Ball(){
    radius = 0;
    color = "";
  }
  
  Ball(double r, string c){
    radius = r;
    color = c;
  }
  
  void printVolume();
  void printRadius();
  
  // The friend keyword specifies that this is a friend function
  friend void setRadius(Ball &b, double r); 
    
};

// This is a member function that calculates the volume.
void Ball::printVolume(){
  cout << (4/3) * 3.142 * radius * radius * radius << endl;
}

void Ball::printRadius(){
  cout << radius << endl;
}

// The implementation of our friend function
void setRadius(Ball &b, double r){
  b.radius = r;
}

 int main(){
   Ball b(30, "green");
   cout << "Radius: ";
   b.printRadius();
   setRadius(b, 60);
   cout << "New radius: ";
   b.printRadius();
   cout << "Volume: ";
   b.printVolume();
 }
 #include <iostream>
#include <string>

using namespace std;

class Ball{
  double radius;
  string color;
  
  public:
  Ball(){
    radius = 0;
    color = "";
  }
  
  Ball(double r, string c){
    radius = r;
    color = c;
  }
  
  void printVolume();
  void printRadius();
  
  // The friend keyword specifies that this is a friend function
  friend void setRadius(Ball &b, double r); 
    
};

// This is a member function that calculates the volume.
void Ball::printVolume(){
  cout << (4/3) * 3.142 * radius * radius * radius << endl;
}

void Ball::printRadius(){
  cout << radius << endl;
}

// The implementation of our friend function
void setRadius(Ball &b, double r){
  b.radius = r;
}

 int main(){
   Ball b(30, "green");
   cout << "Radius: ";
   b.printRadius();
   setRadius(b, 60);
   cout << "New radius: ";
   b.printRadius();
   cout << "Volume: ";
   b.printVolume();
 }
```
# Data hiding
Se trata de interactuar externamente con una clase sin conocer su implementación interna. Se usa para proteger los datos de una clase de modificaciones externas
## Encapsulación
Proveemos una interfaz de métodos públicos para interactuar con los datos privados de una clase. Sus ventajas son:
* Clases fáciles de modificar y mantener
* Podemos especificar qué datos son accesibles y cuáles no
* Definimos que se puede modificar y que no
```cpp
#include <iostream>
#include <string>
using namespace std;

class Movie{
  string title;
  int year;
  string genre;

  public:
  Movie(){
    title = "";
    year = -1;
    genre = "";
  }

  Movie(string t, int y, string g){
    title = t;
    year = y;
    genre = g;
  }
  
  string getTitle(){
    return title;
  }
  void setTitle(string t){
    title = t;
  }
  
  int getYear(){
    return year;
  }
  void setYear(int y){
    year = y;
  }
  
  string getGenre(){
    return genre;
  }
  void setGenre(string g){
    genre = g;
  }
  
  void printDetails(){
    cout << "Title: " << title << endl;
    cout << "Year: " << year << endl;
    cout << "Genre: " << genre << endl;
  }
};

int main() {
  Movie m("The Lion King", 1994, "Adventure");
  m.printDetails();
  
  cout << "---" << endl;
  m.setTitle("Forrest Gump");
  cout << "New title: " << m.getTitle() << endl;
}
```
## Abstracción
Se trata de revelar sólo las características esenciales de un objeto. Se usa para mostrar solo los detalles relevantes de un objeto a los usuarios
```cpp
#include <iostream>
using namespace std;

class Circle{
  double radius;
  double pi;
  
  public:
  Circle (){
    radius = 0;
    pi = 3.142;
  }
  Circle(double r){
    radius = r;
    pi = 3.142;
  }
  
  double area(){
    return pi * radius * radius;
  }
  
  double perimeter(){
    return 2 * pi * radius;
  }
};

int main() {
  Circle c(5);
  cout << "Area: " << c.area() << endl;
  cout << "Perimeter: " << c.perimeter() << endl;
}
```
# Herencia
Es una relación entre dos clases, donde una clase es la clase base y la otra es la clase derivada. La clase derivada hereda los miembros de la clase base y puede acceder a ellos. La clase base no puede acceder a los miembros de la clase derivada.
```cpp
class Vehicle{
  protected:
  string Make;
  string Color;
  int Year;
  string Model;

  public:
  Vehicle(){
    Make = "";
    Color = "";
    Year = 0;
    Model = "";
  }
  
  Vehicle(string mk, string col, int yr, string mdl){
    Make = mk;
    Color = col;
    Year = yr;
    Model = mdl;
  }

  void print_details(){
    cout << "Manufacturer: " << Make << endl;
    cout << "Color: " << Color << endl;
    cout << "Year: " << Year << endl;
    cout << "Model: " << Model << endl;
  }
};

int main(){
  Vehicle v("Ford Australia", "Yellow", 2008, "Falcon");  
  v.print_details();
}
```
## Clase base y clase derivada
* __Clase base__: Es la clase de la que se heredan los miembros
* __Clase derivada__: Es la clase que hereda los miembros de la clase base

Para heredar los miembros de una clase base a una clase derivada usamos el operador __:__ seguido del nombre de la clase base
```cpp
class Vehicle{
  protected:
  string Make;
  string Color;
  int Year;
  string Model;

  public:
  Vehicle(){
    Make = "";
    Color = "";
    Year = 0;
    Model = "";
  }
  
  Vehicle(string mk, string col, int yr, string mdl){
    Make = mk;
    Color = col;
    Year = yr;
    Model = mdl;
  }

  void print_details(){
    cout << "Manufacturer: " << Make << endl;
    cout << "Color: " << Color << endl;
    cout << "Year: " << Year << endl;
    cout << "Model: " << Model << endl;
  }
};

class Cars: public Vehicle{
  string trunk_size;

  public:
  Cars(){
    trunk_size = "";
  }

  Cars(string mk, string col, int yr, string mdl, string ts)
    :Vehicle(mk, col, yr, mdl){
    trunk_size = ts;
  }

  void car_details(){
    print_details();
    cout << "Trunk size: " << trunk_size << endl;
  }
};

class Ships: public Vehicle{
  int Number_of_Anchors;

  public:
  Ships(){
    Number_of_Anchors = 0;
  }
  
  Ships(string mk, string col, int yr, string mdl, int na)
  :Vehicle(mk, col, yr, mdl){
    Number_of_Anchors = na;
  }

  void Ship_details(){
    print_details();
    cout << "Number of Anchors: " << Number_of_Anchors << endl;
  }
};

int main(){
  Cars car("Chevrolet", "Black", 2010, "Camaro", "9.1 cubic feet");
  car.car_details();
  
  cout << endl;
  
  Ships ship("Harland and Wolff, Belfast", "Black and whilte",
            1912, "RMS Titanic", 3);
  ship.Ship_details();
}
```
### Constructor clase base
Instanciamos la __clase derivada__ sin parámetros primero llamará al constructor por defecto de la __clase base__ y luego a la __clase derivada__
```cpp
#include <iostream> 
using namespace std; 
  
// Base class 
class Base {    
    
    public: 
    Base(){
      cout << "Base class default constructor!" << endl;
    }
    // Base class's parameterised constructor     
    Base(float i) {
        cout << "Base class parameterized constructor" << endl; 
    } 
}; 
  
  
// Derived class 
class Derived : public Base { 
    public:  
    Derived(){
      cout << "Derived class default constructor!" << endl;
    }
  
    // Derived class's parameterised constructor 
    Derived(float num): Base(num){ 
        cout << "Derived class parameterized constructor" << endl; 
    } 
}; 
  
// main function 
int main() {    
    // creating object of Derived Class 
    Derived obj;
    cout << endl;
    Derived obj1(10.2);
} 
```
### Destructor clase base
Primero se llama el destructor de la __clase derivada__ y luego el destructor de la __clase base__
```cpp
#include <iostream> 
using namespace std; 
  
// Base class 
class Base {    
    
    public:  
    ~Base(){
      cout << endl << "Base class Destructor!" ;
    }
}; 
  
  
// Derived class 
class Derived : public Base { 
    public:  
    
    ~Derived(){
      cout << endl << "Derived class Destructor!" ;
    }
}; 
  
// main function 
int main() {    
    // creating object of Derived Class 
    Derived obj;
    
} 
```
## Overriding
Cuando una __clase derivada__ hereda de un __clase base__ podemos cambiar parte de la funcionalidad heredada, esto es overriding. Se usa para modificar el comportamiento de una función heredada
```cpp
#include <iostream>
using namespace std;

class Employee {
  protected:
    string name;
    int ID;
    int reportsTo;
  public:
    Employee(string name, int ID, int boss) : name(name), ID(ID), reportsTo(boss) { }
    string getName() { return name; }
    int getID() { return ID; }
    int getBoss() { return reportsTo; }
    void display() {
      cout << ID << " " << name << " reports to " << reportsTo << endl;
    }

    void display(string salutation)
    {
      cout << salutation << " ";
      display();
    }
};

class Manager : public Employee {
  protected:
    string teamName;
  public:
    Manager(string name, int ID, int boss, string teamName) : Employee(name, ID, boss), teamName(teamName) { }
    void display() {
      Employee::display();
      cout << "   Heads the team " << teamName << endl;
    }
};



int main() {
  Employee worker("John Smith", 10, 2);
  Manager ceo("Jack Hobbs", 0, 0, "Eats R Us");
  Manager cto("Elizabeth Shaw", 2, 0, "IT");
  worker.display("Mr");
  ceo.display();
  cto.display();
  //ceo.display("Mr")
  return 0;
}
```
El __overriding__ de una función en una clase derivada oculta todos los __overloads__ de la misma función de la clase base
## Modos de herencia
### Private
Los miembros de datos privados y las funciones miembros de la __clase base__ son inaccesibles desde la __clase derivada__. Los miembros protegidos y públicos de la __clase base__ son accesibles a la __clase derivada__ y se comportan como miembros privados de la __clase derivada__
```cpp
class Vehicle{
  
  string Make;
  string Color;
  int Year;
  
  protected:
  string Model;
  
  public:
  Vehicle(){
    Make = "";
    Color = "";
    Year = 0;
    Model = "";
  }
  
  Vehicle(string mk, string col, int yr, string mdl){
    Make = mk;
    Color = col;
    Year = yr;
    Model = mdl;
  }

  void print_details(){
    cout << "Manufacturer: " << Make << endl;
    cout << "Color: " << Color << endl;
    cout << "Year: " << Year << endl;
  }
};

class Car: private Vehicle{
  string trunk_size;

  public:
  Car(){
    trunk_size = "";
  }

  Car(string mk, string col, int yr, string mdl, string ts)
    :Vehicle(mk, col, yr, mdl){
    trunk_size = ts;
  }

  void car_details(){
    print_details();
    cout << "Trunk size: " << trunk_size << endl;
    cout << "Model: " << Model << endl;  // Model is protected and 
    // is accessible in derived class
  }
};

int main(){
  Car car("Chevrolet", "Black", 2010, "Camaro", "9.1 cubic feet");
  // car.Year = 2000;     // this will give error as Year is private
  // car.Model = "Accord";   // this will give error as Model is protected
  
  car.car_details();
  //car.print_details();   // public functions of base class are inaccessible in main
}
```
### Protected
Los miembros privados de la __clase base__ son inaccesibles en la __clase derivada__. Los miembros protegidos de la __clase base__ son accesibles a la __clase derivada__ y se comportan como miembros protegidos de la __clase derivada__. Los miembros públicos de la __clase base__ son accesibles a la __clase derivada__ y se comportan como miembros públicos de la __clase derivada__
```cpp
class Vehicle{
  
  string Make;
  string Color;
  int Year;
  
  protected:
  string Model;
  
  public:
  Vehicle(){
    Make = "";
    Color = "";
    Year = 0;
    Model = "";
  }
  
  Vehicle(string mk, string col, int yr, string mdl){
    Make = mk;
    Color = col;
    Year = yr;
    Model = mdl;
  }

  void print_details(){
    cout << "Manufacturer: " << Make << endl;
    cout << "Color: " << Color << endl;
    cout << "Year: " << Year << endl;
  }
};

class Car: protected Vehicle{
  string trunk_size;

  public:
  Car(){
    trunk_size = "";
  }

  Car(string mk, string col, int yr, string mdl, string ts)
    :Vehicle(mk, col, yr, mdl){
    trunk_size = ts;
  }

  void car_details(){
    print_details();
    cout << "Trunk size: " << trunk_size << endl;
    cout << "Model: " << Model << endl;  // Model is protected and 
    // is accessible in derived class
  }
};

int main(){
  Car car("Chevrolet", "Black", 2010, "Camaro", "9.1 cubic feet");
  // car.Year = 2000;     // this will give error as Year is private
  // car.Model = "Accord";   // this will give error as Model is protected
  
  car.car_details();
  //car.print_details();   // public functions of base class are inaccessible in main
}
```
### Public
Los miembros privados de la clase base son inaccesibles en la clase derivada. Los miembros protegidos de la clase base son accesibles a la clase derivada y se comportan como miembros protegidos de la clase derivada. Los miembros públicos de la clase base son accesibles a la clase derivada y se comportan como miembros públicos de la clase derivada.
```cpp
class Vehicle{
  
  string Make;
  string Color;
  int Year;
  
  protected:
  string Model;
  
  public:
  Vehicle(){
    Make = "";
    Color = "";
    Year = 0;
    Model = "";
  }
  
  Vehicle(string mk, string col, int yr, string mdl){
    Make = mk;
    Color = col;
    Year = yr;
    Model = mdl;
  }

  void print_details(){
    cout << "Manufacturer: " << Make << endl;
    cout << "Color: " << Color << endl;
    cout << "Year: " << Year << endl;
  }
};

class Car: public Vehicle{
  string trunk_size;

  public:
  Car(){
    trunk_size = "";
  }

  Car(string mk, string col, int yr, string mdl, string ts)
    :Vehicle(mk, col, yr, mdl){
    trunk_size = ts;
  }

  void car_details(){
    cout << "Trunk size: " << trunk_size << endl;
    cout << "Model: " << Model << endl;  // Model is protected and 
    // is accessible in derived class
  }
};

int main(){
  Car car("Chevrolet", "Black", 2010, "Camaro", "9.1 cubic feet");
  // car.Year = 2000;     // this will give error as Year is private
   //car.Model = "Accord";   // this will give error as Model is protected
  
  car.car_details();
  car.print_details();   // public functions of base class are accessible in main
}
```
## Herencia múltiple
Se trata de heredar múltiples clases a una clase derivada. La clase derivada hereda todos los miembros de las clases base
```cpp
class Vehicle{
  protected:
  string Make;
  string Color;
  int Year;
  string Model;

  public:
  Vehicle(){
    Make = "";
    Color = "";
    Year = 0;
    Model = "";
  }
  
  Vehicle(string mk, string col, int yr, string mdl){
    Make = mk;
    Color = col;
    Year = yr;
    Model = mdl;
  }

  void print_details(){
    cout << "Manufacturer: " << Make << endl;
    cout << "Color: " << Color << endl;
    cout << "Year: " << Year << endl;
    cout << "Model: " << Model << endl;
  }
};

class Car{
  string trunk_size;

  public:
  Car(){
    trunk_size = "";
  }

  Car(string ts){
    trunk_size = ts;
  }

  void car_details(){
    cout << "Trunk size: " << trunk_size << endl;
  }
};

class Honda: public Vehicle, public Car{
  int top_speed;

  public:
  Honda(){
    top_speed = 0;
  }
  
  Honda(string mk, string col, int yr, string mdl, string na, int ts)
  :Vehicle(mk, col, yr, mdl), Car(na){
    top_speed = ts;
  }

  void Honda_details(){
    print_details();
    car_details();
    cout << "Top speed of the car: " << top_speed << endl;
  }
};

int main(){
  Honda car("Honda", "Black", 2006, "Accord", "14.7 cubic feet", 260);
  car.Honda_details();
}
```
## Problema del diamante
Cuando una clase derivada hereda de dos clases base que a su vez heredan de una misma clase base. La clase derivada hereda dos copias de la clase base. Problema:
```cpp
#include<iostream>
using namespace std;
 
class A
{
protected:
    int ID;
public:
    A() : ID(0) { }
};
 
class B:  public A
{
public:
    int length;
};
 
class C:  public A
{
public:
    int radius;
};
 
class D: public B, public C
{
public:
    int getID()  {   return ID;  }
};
 
int main(void)
{
    D d;
    cout << d.getID();
    return 0;
}
```
Solución:
```cpp
#include<iostream>
using namespace std;
 
class A
{
protected:
    int ID;
public:
    A() : ID(0) { }
};
 
class B:  virtual public A
{
public:
    int length;
};
 
 
class C:  virtual public A
{
public:
    int radius;
};
 
class D: public B, public C
{
public:
    int getID()  {   return ID;  }
};
 
int main(void)
{
    D d;
    cout << d.getID();
    return 0;
}
```