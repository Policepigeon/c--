#include <iostream>

using namespace std;
//the stupid makes a return
unsigned long long int factorial(int n) {
    if (n == 0 || n == 1)  // Base case
        return 1;
    return n * factorial(n - 1);  // Recursive case
}
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (num >= 21) {
    cout << "Number Too large, causes an overflow as using a stupid data type"
    }
    else {
      cout << "Factorial of " << num << " is " << factorial(num) << endl;
    }
    return 0;
  }