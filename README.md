# Compilar y correr .cpp
Para compilar usamos
```bash
g++ -o nombre_que_queremos_dar ./archivo.cpp
```
Para correr
```bash
./nombre_que_queremos_dar.exe
```

# Variables y constantes
* Se definen con su tipo de dato correspondiente
* Son una ubicación en la memoria donde se pueden almacenar datos
* Estos datos se pueden moficar según sea el caso
* Tienen nombre único el cual es su identificador

Definiendo variables
```cpp
int number1, number2, number3;
int number4;
```
Inicializando variables
```cpp
int number;
number = 100;
int number2 = 200;
```
Para nombrar variables debos seguir las siguientes reglas
1. Sólo pueden contener [A-Za-z0-9_]
2. El primer caracter puede ser letra o underscore

Para definir una constante lo hacemos de la siguiente forma
```cpp
const int number = 10;
```

# Tipos de datos
La memoria está compuesta por celdas, cada celda puede almacenar **1 byte = 8 bit** de data, entonces cada celda puede almacenar un valor desde 0 a 255

## Tipos primitivos
* Integer
* Floating-point
* Double
* Void
* Character
* Boolean

## Tipos derivados
* Function
* Arrays
* Pointers
* Reference

## Tipos definidos por el usuario
* Structure
* Union
* Enum
* Class
* Typedef

## Primitivos
* Integer: Son número enteros y negativos, se le asignan **4 bytes** de memoria a una variable tipo **int**. Almacena cualquier valor entre **-231 y 231-1**

* Floating-point: Almacena un número decimal, se le asignan **4 bytes** de memoria a una variable tipo **float**. Almacena cualquier valor entre **+-(3.40 * 10^(+-(38)))**

* Double: Almacena un número decimalm, se le asignan **8 bytes** de memoria a una variable tipo **double**. Almacena cualquier valor entre **+-(1.79 * 10^(+-(308)))**

La diferencia entre float y double es que float puede almacenar hasta **7** decimales, mientras que double puede almacenar hasta **15** decimales

* Character: Contiene un solo caracter, usa comillas simples, se le asignan **1 bytes** de memoria a una variable tipo **char**. Almacena cualquier valor entre **-2^7 y 2^7 - 1**

* Boolean: Contiene un valor de verdaro o falso, se le asignan **1 bytes** de memoria a una variable tipo **bool**.

* Void: Representa un entidad sin valor, está vacía

## Modificadores del tipo de datos
* Long: se utiliza para aumentar la longitud de un tipo de datos a **4 bytes** más, se puede usar con **int** y con **double**
```cpp
#include <iostream>

using namespace std;

int main() {
  // Initialize variables
  int integer = 2147483649;
  long int long_integer = 2147483649;
  // Display variables value
  cout << "integer = " << integer << endl;
  cout << "long_integer = " << long_integer << endl; 
}
```

* Short: se utiliza para disminuir la longitud disponible de un tipo de datos a **2 bytes**, se pueda usar con **int**
```cpp
#include <iostream>

using namespace std;

int main() {
  // Initialize variables
  int integer = 32768;
  short int short_integer = 32768;
  // Display variables value
  cout << "integer = " << integer << endl;
  cout << "short_integer = " << short_integer << endl; 
}
```

* Unsigned: Permite almacenar valores positivos, se puede usar con **int** y con **char**
```cpp
#include <iostream>

using namespace std;

int main() {
  // Initialize variables 
  int integer = -10;
  unsigned int unsigned_integer = -10;

  char character = 'A';
  unsigned char unsigned_character = 'B';
  // Display variables value
  cout << "integer = " << integer << endl;
  cout << "unsigned_integer = " << unsigned_integer << endl;

  cout << "character = " << character << endl;
  cout << "unsigned_character = " << unsigned_character << endl;
}
```

* Signed: Permite almacenar tano positivos como negativos, se puede usar con **int** y con **char**
```cpp
#include <iostream>

using namespace std;

int main() {
  // Initialize variables
  int integer = -90;
  signed int signed_integer = -90;

  char character = 'A';
  signed char signed_character = 'A';
  // Display variables value
  cout << "integer = " << integer << endl;
  cout << "signed_integer = " << signed_integer << endl;

  cout << "character = " << character << endl;
  cout << "signed_character = " << signed_character << endl;  
}
```

## Type casting
Se trata de la conversión de datos

* Implícito: Se convierte automáticamente
```cpp
#include <iostream>

using namespace std;

int main() {
  // Stores floating point value in variable of type int
  int int_value = 13.9;
  // Displays the value of variable
  cout << int_value;
}
```

* Explícito: El usuario convierte de forma manual de un tipo de dato a otro
```cpp
#include <iostream>

using namespace std;

int main() {
  // Initializes a variable of char data type
  char character = 'A';
  // Declares a variable of int type
  int ASCII;
  // Converts char data type into int explicitly
  ASCII = (int) character;
  // Prints value of variable
  cout << "ASCII value = " << ASCII;
}
```

## Strings
Es simplemente texto plano
```cpp
#include <iostream>

using namespace std;

int main() {
  // Initialize a string variable
  string text = "Hey12345";
  // Displays value of string variable
  cout << text;
}
```

## Input de usuario
Se usa el operador **>>** para tomar el input del usuario y **cin** para tomar el input del usuario

# Operadores
Existen diferentes tipos de operadores
* Aritméticos
* Relacionales
* Lógicos
* Asignación
* Bitwise

## Operadores de asignación
Se utilizan para asignar un valor a una variable
```cpp
int main() {
  int number;
  number = 10; // Asigna el valor 10 a la variable number
}
```

Podemos asignar de forma compuesta
```cpp
int main() {
  int number;
  number += 10; // Asigna el valor 10 a la variable number
}
```

## Operadores relacionales
Para usarlos debemos definir la operación dentro de paréntesis, si es verdadera devuelve 1, si es falsa devuelve 0
```cpp
int main() {
  int number1 = 10;
  int number2 = 20;
  cout << (number1 == number2); // Devuelve 0
  cout << (number1 != number2); // Devuelve 1
  cout << (number1 > number2); // Devuelve 0
  cout << (number1 < number2); // Devuelve 1
  cout << (number1 >= number2); // Devuelve 0
  cout << (number1 <= number2); // Devuelve 1
}
```

## Operadores lógicos
Combinan dos o más expresiones relacionales o lógicas
```cpp
int main() {
  int number1 = 10;
  int number2 = 20;
  cout << (number1 == 10 && number2 == 20); // Devuelve 1
  cout << (number1 == 10 || number2 == 20); // Devuelve 1
  cout << (!(number1 == 10 && number2 == 20)); // Devuelve 0
}
```
* **&&**: Devuelve 1 si ambas expresiones son verdaderas
* **||**: Devuelve 1 si al menos una expresión es verdadera
* **!**: Devuelve 1 si la expresión es falsa

## Bitwise
Operan en números binarios. Ellos operan bit a bit, es decir, realizan una operación entre los bits de los operandos
```cpp
int main() {
  int number1 = 10;
  int number2 = 20;
  cout << (number1 & number2); // Devuelve 0
  cout << (number1 | number2); // Devuelve 30
  cout << (number1 ^ number2); // Devuelve 30
  cout << (~number1); // Devuelve -11
  cout << (number1 << 2); // Devuelve 40
  cout << (number1 >> 2); // Devuelve 2
}
```
* **&**: Devuelve 1 si ambos bits son 1 (AND)
* **|**: Devuelve 1 si al menos un bit es 1 (OR)
* **^**: Devuelve 1 si ambos bits son diferentes (XOR)
* **~**: Devuelve el complemento de 1 (NOT)
* **<<**: Desplaza los bits a la izquierda (LEFT SHIFT)
* **>>**: Desplaza los bits a la derecha (RIGHT SHIFT)

# Presedencia y asociatividad

## Presedencia
Determina el orden de evaluación de los operadores

## Asociatividad
Determina el orden de evaluación de los operadores con la misma presedencia

# Condicionales
Se usan para tomar decisiones. Son ejecutados de forma secuencial, es decir, de arriba hacia abajo. Se ejecuta el bloque de código que cumpla con la condición

## Switch
Si queremos verificar sobre una gran cantidad de casos, usamos **switch**. Solo acepta valores enteros, no acepta rangos ni decimales
```cpp
int main() {
  int number = 10;
  switch (number) {
    case 10:
      cout << "number es igual a 10";
      break;
    case 20:
      cout << "number es igual a 20";
      break;
    default:
      cout << "number no es igual a 10 ni a 20";
  }
}
```

Podemos usar **...** para indicar un rango de valores
```cpp
int main() {
  int number = 10;
  switch (number) {
    case 0 ... 10:
      cout << "Entre 0 y 10";
      break;
    case 11 ... 20:
      cout << "Entre 11 y 20";
      break;
    default:
      cout << "No 
  }
}
```

## Operador condicional ternario
Es una forma abreviada de escribir un if-else
```cpp
int main() {
  int number = 10;
  string result = (number == 10) ? "number es igual a 10" : "number no es igual a 10";
  cout << result;
}
```

Si se cumple la condición, se ejecuta la primera expresión, si no se cumple, se ejecuta la segunda expresión

## Loops
Hay diferentes tipos de loops
* __While__: Se ejecuta mientras la condición sea verdadera
* __Do-while__: Se ejecuta primero y luego verifica la condición
* __For__: Se ejecuta mientras la condición sea verdadera

Nested loop son los loops dentro de loops
```cpp
#include <iostream>

using namespace std;

int main() {
  // Declares variable inner and outer
  int inner, outer;
  // Outer for loop
  for (outer = 6; outer <= 8; outer++) {
    // Outer for loop body
    cout << "Table of " << outer << " is:" << endl;
    // Inner for loop
    for (inner = 1; inner <= 5; inner++) {
      // Inner for loop body
      cout << outer << " * " << inner << " = " << (outer * inner) << endl;
    }
    // Exit inner for loop
  }
  // Exit outer for loop
  return 0;
}
```

## Funciones
Es un bloque de código que realiza una tarea específica. Hay diferentes tipos de funciones
* __Funciones predefinidas__: Son funciones que ya vienen con el lenguaje
* __Funciones definidas por el usuario__: Son funciones que el usuario define

Se declaran siempre antes de la función **main**.

Para declarar funciones debemos usar el siguiente formato
```cpp
tipo_de_retorno nombre_de_la_funcion(tipo_de_dato parametro1, tipo_de_dato parametro2, ...) {
  // Código
}
```

## Función Main
Es la función principal del programa, es la que se ejecuta primero. Es de tipo **int** porque devuelve un valor entero
```cpp
int main() {
  // Código
}
```

## Parámetros
Tenemos dos tipos de parámetros
* __Parámetros formales__: Son los parámetros que se definen en la declaración de la función
* __Parámetros reales__: Son los parámetros que se pasan a la función cuando se llama

También podemos definir parámetros por defecto
```cpp
int sum(int number1 = 10, int number2 = 20) {
  return number1 + number2;
}
```

## Pasar parámetros por valor
Es cuando llamamos una función y pasamos la copia de los valores de las variables
```cpp
void cube(int number) {
  number = number * number * number;
  cout << "number = " << number << endl;
}

int main() {
  int number = 5;
  cube(number); // Devuelve 125
  cout << "number = " << number << endl; // Devuelve 5

  return 0;
}
```

## Pasar parámetros por referencia
Es cuando llamamos una función y pasamos la dirección de memoria de las variables. Usamos el operador **&** para indicar que es por referencia
```cpp
void cube(int &number) {
  number = number * number * number;
  cout << "number = " << number << endl;
}

int main() {
  int number = 5;
  cube(number); // Devuelve 125
  cout << "number = " << number << endl; // Devuelve 125

  return 0;
}
```

## Scope de las variables
Define la accesibilidad y visibilidad de una variable. Hay dos tipos de scope
* __Local__: Es cuando la variable es declarada dentro de una función, solo es accesible dentro de la función
* __Global__: Es cuando la variable es declarada fuera de una función, es accesible en todo el programa

# Recursividad
Es una función que se llama a sí misma. Se usa para resolver problemas que se pueden dividir en subproblemas más pequeños
```cpp
int factorial(int n) {
  // Invalid value
  if (n < 0){
    return -1;
  }
  // Base case
  if (n == 1 || n == 0) {
    return 1;
  } 
  // Recursive Case
  else {
    return n * factorial(n - 1);
  }
}
```

## Recursión vs Iteración
La iteración es más rápida que la recursión, pero la recursión es más fácil de implementar y la iteración toma menos memoria

# Arrays
Es una colección de elementos del mismo tipo. Se declaran de la siguiente forma
```cpp
tipo_de_dato nombre_del_array[tamaño_del_array];
```

## Inicializar arrays
Podemos inicializar arrays de la siguiente forma
```cpp
int main() {
  int numbers[5] = {1, 2, 3, 4, 5};
  int numbers2[] = {1, 2, 3, 4, 5};
  int numbers3[5] = {1, 2};
  int numbers4[5] = {0};
}
```

## Acceder a los elementos de un array
Para acceder a los elementos de un array, usamos el índice del elemento al que queremos acceder
```cpp
int main() {
  int numbers[5] = {1, 2, 3, 4, 5};
  cout << numbers[0]; // Devuelve 1
  cout << numbers[1]; // Devuelve 2
  cout << numbers[2]; // Devuelve 3
  cout << numbers[3]; // Devuelve 4
  cout << numbers[4]; // Devuelve 5
}
```

## Modificar elementos de un array
Para modificar elementos de un array, usamos el índice del elemento al que queremos acceder
```cpp
int main() {
  int numbers[5] = {1, 2, 3, 4, 5};
  numbers[0] = 10;
  numbers[1] = 20;
  numbers[2] = 30;
  numbers[3] = 40;
  numbers[4] = 50;
  cout << numbers[0]; // Devuelve 10
  cout << numbers[1]; // Devuelve 20
  cout << numbers[2]; // Devuelve 30
  cout << numbers[3]; // Devuelve 40
  cout << numbers[4]; // Devuelve 50
}
```

## Pasar arrays a funciones
Podemos pasar arrays a funciones
```cpp
void modify_array(int number[], int size) {
  // Traverse array
  for (int i = 0; i < size; i++) {
    // If value less tha 50 set it to -1
    if (number[i] < 50)
      number[i] = -1;
  }
  cout << "Values of array inside the function:" << endl;
  // Call print_array function 
  print_array(number,size);
}

void print_array(int number[], int size) {
  // Traverse array
  for (int i = 0; i < size; i++) {
    cout << number[i] << endl;
  }
}

int main() {
  // Initialize array
  int number[5] = {10, 20, 30, 40, 50};
  cout << "Values of array before calling function:" << endl;
  // Call print_array function
  print_array(number,5);
  // Call modify_array function
  modify_array(number,5);
  cout << "Values of array after calling function:" << endl;
  // Call print_array function
  print_array(number,5);
}
```

## Arrays multidimensionales
Son arrays que tienen más de una dimensión. Se declaran de la siguiente forma
```cpp
tipo_de_dato nombre_del_array[tamaño_del_filas][tamaño_de_columnas];
```

## Inicializar arrays multidimensionales
Podemos inicializar arrays multidimensionales de la siguiente forma
```cpp
int main() {
  int numbers[2][3] = {{1, 2, 3}, {4, 5, 6}};
  int numbers2[][3] = {{1, 2, 3}, {4, 5, 6}};
  int numbers3[2][3] = {{1, 2}, {4}};
  int numbers4[2][3] = {{0}};
}
```

## Acceder a los elementos de un array multidimensional
Para acceder a los elementos de un array multidimensional, usamos el índice de la fila y el índice de la columna del elemento al que queremos acceder
```cpp
int main() {
  int numbers[2][3] = {{1, 2, 3}, {4, 5, 6}};
  cout << numbers[0][0]; // Devuelve 1
  cout << numbers[0][1]; // Devuelve 2
  cout << numbers[0][2]; // Devuelve 3
  cout << numbers[1][0]; // Devuelve 4
  cout << numbers[1][1]; // Devuelve 5
  cout << numbers[1][2]; // Devuelve 6
}
```

## Array transversal
Es cuando recorremos un array. Podemos hacerlo de dos formas
```cpp
int main() {
  int numbers[5] = {1, 2, 3, 4, 5};
  // For loop
  for (int i = 0; i < 5; i++) {
    cout << numbers[i] << endl;
  }
  // For each loop
  for (int number : numbers) {
    cout << number << endl;
  }
}
```

# Punteros

## Memoria
La memoria es un dispositivo de almacenamiento que almacena datos y programas. Cada celda de memoria tiene una dirección única. Se puede considerar como un array de bytes

Un bit es la unidad más pequeña de almacenamiento, puede almacenar 0 o 1. Un byte es un grupo de 8 bits, con un byte podemos almacenar 256 valores diferentes

## Variables y memoria
Las variables son una ubicación en la memoria donde se pueden almacenar datos. Estos datos se pueden modificar según sea el caso. Tienen nombre único el cual es su identificador

## Dirección de operador
Sabemos que cuando se declara una variable el compilador la almacena en la memoria. Para obtener la dirección de memoria de una variable usamos el operador **&**
```cpp
int main() {
  int number = 10;
  cout << &number; // Devuelve 0x61ff08
}
```

Un puntero es una variable que almacena la dirección de memoria de otra variable. Para declarar un puntero usamos el operador **\***. Para asignarle la dirección de memoria de una variable a un puntero usamos el operador **&**
```cpp
int main() {
  int number = 10;
  int *pointer = &number;
  cout << pointer; // Devuelve 0x61ff08
}
```

Usamos **nullptr** para inicializar un puntero
```cpp
int main() {
  int *pointer = nullptr;
  cout << pointer; // Devuelve 0
}
```

## Operador de desreferencia/Idirección
Es el operador **\***. Se usa para acceder al valor de la variable a la que apunta el puntero
```cpp
int main() {
  // Declares a variable Alice
  int Alice = 5;
  // Declares a pointer variable John that can point to int value
  int *John = nullptr;
  // Stores the address of Alice in John
  John = &Alice;
  // Prints value of Alice
  cout << "Value of Alice = " << Alice << endl;
  // Prints value (address of Alice) of John 
  cout << "Value of John = " << John << endl;
  // Prints value of Alice
  cout << "Value of Alice = " << *John << endl;
  
  return 0;
}
```

# Funciones y punteros

## Pasar punteros a funciones
Para declarar un puntero como parámetro de una función, debemos usar el operador **\***
```cpp
void swap(int *number1, int *number2) {
  int temp = *number1;
  *number1 = *number2;
  *number2 = temp;
}
```

# Asignaciones
- __Estática__: Se asigna una cantidad fija de memoria a las variables antes de que se ejecute el programa, durante la compilación. No se puede cambiar el tamaño de la memoria asignada

- __Dinámica__: Se asigna una cantidad de memoria a las variables durante la ejecución del programa. Se puede cambiar el tamaño de la memoria asignada

## Asignación dinámica
Debemos seguir los siguientes pasos
1. Asignar espacio en memoria
2. almacenar la dirección de memoria en un puntero


## Operador new
Permite asignar memoria dinámicamente. Devuelve la dirección de memoria asignada
```cpp
int main() {
  int *pointer = nullptr;
  pointer = new int;
  cout << pointer; // Devuelve 0x61ff08
}
```

## Acceder al espacio dinámico
Para acceder al espacio dinámico, usamos el operador **\***
```cpp
int main() {
  // Declare pointer ptr
  int * ptr = nullptr;
  // Store the starting address of dynamically reserved 4 bytes in ptr
  ptr = new int;
  // Store 100 in dynamic space
  *ptr = 100;
  // Print value pointed by ptr
  cout << *ptr;
  return 0;
}
```

## Desasignar memoria dinámica
El compilador desasigna automáticamente el espacio estático cuando ya no se utiliza. Dado que la memoria asignada dinámicamente es gestionada por un programador, cuando el espacio asignado dinámicamente ya no es necesario, debemos liberarlo.

## Operador delete
Se usa para liberar la memoria asignada dinámicamente
```cpp
#include <iostream>
using namespace std;

int main() {
  // Declare pointer ptr
  int * ptr = nullptr;
  // Store the starting address of dynamically reserved 4 bytes in ptr
  ptr = new int;
  // Store 100 in dynamic space
  *ptr = 100;
  // Print value pointed by ptr
  cout << *ptr;
  // Free the space pointed by pointer ptr
  delete ptr;
  return 0;
}
```

## Arrays dinámicos
Crecen y se reducen según sea necesario. Para declarar un array dinámico, debemos usar el operador **new** y especificar el tamaño del array
```cpp
#include <iostream>

using namespace std;

int main(){
  int size = 5;
  //Declare dynamic array
  int *Array = new int[size];
  //Initialize dynamic array
  for(int i = 0 ; i< size; i++){
    Array[i] = i;
  }   
  //Prints dynamic array
  for(int i = 0 ; i< size; i++){
    cout << Array[i] << " ";
  } 
 // Deletes a memory allocated to dynamic array
   delete[] Array;
}
```

# Estruturas
Es una estructura de datos que permite almacenar diferentes tipos de datos. Se declara de la siguiente forma
```cpp
#include <iostream>

using namespace std;
// Student structure
struct Student {
  string name;
  int roll_number;
  int marks;
};
// main function
int main() {
  Student s1, s2, s3;
  return 0;
}
```

## Estructuras y punteros
El puntero que almacena la dirección de la variable de estructura se conoce como puntero de estructura.
```cpp
#include <iostream>

using namespace std;

// Student structure
struct Student {
  string name;
  int roll_number;
  int marks;
};

// main function
int main() {
  // Declare structure variable
  Student s1;
  // Declare structure pointer
  Student *ptrs1;
  // Store address of structure variable in structure pointer
  ptrs1 = &s1;
  return 0;
}
```
Podemos acceder de dos formas a los miembros de una estructura
* Indirección y operador de punto
* Operador de flecha
### Indirección y operador de punto
Usamos la siguiente sintaxis
```
(*StructurePointer).MemberName
```
Ejemplo
```cpp
#include <iostream>

using namespace std;

// Student structure
struct Student {
  string name;
  int roll_number;
  int marks;
};

// main function
int main() {
  // Declare structure variable
  Student s1;
  // Declare structure pointer
  Student *ptrs1;
  // Store address of structure variable in structure pointer
  ptrs1 = &s1;
  
  // Set value of name
  (*ptrs1).name = "John";
  // Set value of roll_number
  (*ptrs1).roll_number = 1;
  // Set value of marks
  (*ptrs1).marks = 50;

  // Print value of structure member
  cout << "s1 Information:" << endl;
  cout << "Name = " << (*ptrs1).name << endl;
  cout << "Roll Number = " << (*ptrs1).roll_number << endl;
  cout << "Marks = " << (*ptrs1).marks << endl;

  return 0;
}
```
### Operador de flecha
Usamos la siguiente sintaxis
```
StructurePointer->MemberName
```
Ejemplo
```cpp
#include <iostream>

using namespace std;

// Student structure
struct Student {
  string name;
  int roll_number;
  int marks;
};

// main function
int main() {
  // Declare structure variable
  Student s1;
  // Declare structure pointer
  Student *ptrs1;
  // Store address of structure variable in structure pointer
  ptrs1 = &s1;
  
  // Set value of name
   ptrs1->name = "John";
  // Set value of roll_number
   ptrs1->roll_number = 1;
  // Set value of marks
   ptrs1->marks = 50;

  // Print value of structure member
  cout << "s1 Information:" << endl;
  cout << "Name = " << ptrs1->name << endl;
  cout << "Roll Number = " << ptrs1->roll_number << endl;
  cout << "Marks = " << ptrs1->marks << endl;

  return 0;
}
```