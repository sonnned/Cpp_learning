// Derived Class
class Car : public Vehicle {
  
  string name; //  Name of a Car
  
  public:
  Car() { // Default Constructor
    name = "";
  }
  
  // This function sets the name of the car
  void setDetails(string name) { // Setter Function
    this->name = name;
  }

  // This function calls the Base class functions and appends the result with the input 
  string getDetails(string carName) {

    string details = carName + ", " + getModel() + ", " + getSpeed(); // calling Base Class Function
    return details;
  } 
};