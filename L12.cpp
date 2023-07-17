#include <iostream>

using namespace std;
// Student structure
struct Student {
  string name;
  int roll_number;
  int marks;
};
// function fillStudent
Student fillStudent(string name, int roll_number, int marks) {
  Student s;
  s.name = name;
  s.roll_number = roll_number;
  s.marks = marks;
  return s;
}
// printStudent function prints the members of structure variable
void printStudent(Student s) {

  cout << "Student information" << endl;
  cout << "Name = " << s.name << endl;
  cout << "Roll Number = " << s.roll_number << endl;
  cout << "Marks = " << s.marks << endl;

}

int main() {
  struct Student s[100];

  s[0] = fillStudent("John", 1, 50);
  printStudent(s[0]);

  s[1] = fillStudent("Alice", 2, 43);
  printStudent(s[1]);

  return 0;
}