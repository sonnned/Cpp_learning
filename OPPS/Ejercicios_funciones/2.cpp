#include <iostream>

using namespace std;

int secondMinimum(int arr[], int size) {

    int min = 214748364;
    int secondmin = 214748364;
 
    for (int i = 0; i < size; i++) {
      if (arr[i] < min) {
        secondmin = min;
        min = arr[i];
      }
      else if (arr[i] < secondmin) {
        secondmin = arr[i];
      }
    }
    return secondmin;
}
int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  
  cout << secondMinimum(arr, size) << endl;
  
  return 0;
}