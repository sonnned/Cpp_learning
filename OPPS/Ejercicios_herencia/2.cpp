#include <iostream>
using namespace std;

class Animal {
  string Name;
  string Sound;
  
  public:
  Animal() {
    Name = "";
    Sound = "";
  }
  
  Animal(string nam, string soun) {
    Name = nam;
    Sound = soun;
  }
  
  void Animal_detail() {
    cout << "Animal Name : " << Name << endl;
    cout << "Animal Sound : " << Sound << endl;
  }
};

class Dog : public Animal {
  
  string family;
  
  public:
  Dog(string N, string S): Animal(N, S) {
    family = "Carnivores";
  }
  void Dog_detail() {
    Animal_detail();
    cout << "Dog's Family : " << family  << endl; 
  }
};

class Sheep : public Animal {
  
  string color;
  
  public:
  Sheep(string N, string S): Animal(N, S) {
    color = "White";
  }
  void Sheep_detail() {
    Animal_detail();
    cout << "Sheep Color: " << color << endl; 
  }
};


int main() {
  Dog d("Pongo", "Woof Woof");
  d.Dog_detail();
  
  cout << endl;
  
  Sheep s("Billy", "Baaa Baaa");
  s.Sheep_detail();
}