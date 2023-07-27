#include <iostream>
using namespace std;

class Father {
  string eye_color;
  string hair_color;
public:
	Father(string eye, string hair) {
    eye_color = eye;
    hair_color = hair;
  }
  
  void father_traits(){
    cout << "Eye color: " << eye_color << endl;
    cout << "Hair color: " << hair_color << endl;
  }
};

class Daughter : public Father {
  string name;
  public:
	Daughter(string nam, string eye, string hair) : Father(eye, hair) {
    name = nam;
  }
  
  void Daughter_traits(){
    father_traits();
    cout << name << " has long hair!\n";
  }
};

class Son : public Father {
  string name;
  public:
	Son(string nam,string eye, string hair): Father(eye, hair) {
    name = nam;
  }
  
  void Son_traits(){
    father_traits();
    cout << name << " has beard!\n";
  }
};

int main ()
{
	Daughter obj("Rapunzel","Green","Golden");
	obj.Daughter_traits();
  
	cout << endl;
  
  Son Obj("Ralph","Brown","Black");
	Obj.Son_traits();
}