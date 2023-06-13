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