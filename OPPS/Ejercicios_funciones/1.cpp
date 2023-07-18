#include <iostream>

using namespace std;

int sumAllOdds(int arr[], int size) {
  int sum = 0;  
  
  // write your code here
  for (int i = 0; i <= size; i++) {
    if (arr[i] % 2 != 0) {
      sum += arr[i];
    }
  }
  
  return sum;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  
  cout << sumAllOdds(arr, size) << endl;
  
  return 0;
}