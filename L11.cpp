#include <iostream>

using namespace std;

struct Student {
  string name;
  int roll_number;
  int marks;
};

int main() {
  struct Student s1, s2, s3;

  s1 = {"John", 1, 50};

  cout << "s1 Information:" << endl;
  cout << "Name = " << s1.name << endl;
  cout << "Roll Number = " << s1.roll_number << endl;
  cout << "Marks = " << s1.marks << endl;

  s2 = {"Alice", 2, 43};

  cout << "s2 Information:" << endl;
  cout << "Name = " << s2.name << endl;
  cout << "Roll Number = " << s2.roll_number << endl;
  cout << "Marks = " << s2.marks << endl;

  // Estructuras de arreglos
  struct Student s[100];

  s[0] = {"John", 1, 50};

  cout << "s1 Information:" << endl;
  cout << "Name = " << s[0].name << endl;
  cout << "Roll Number = " << s[0].roll_number << endl;
  cout << "Marks = " << s[0].marks << endl;

  s[1] = {"Alice", 2, 43};

  cout << "s2 Information:" << endl;
  cout << "Name = " << s[1].name << endl;
  cout << "Roll Number = " << s[1].roll_number << endl;
  cout << "Marks = " << s[1].marks << endl;

  return 0;
}