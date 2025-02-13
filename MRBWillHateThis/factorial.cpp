#include <iostream>
  
using namespace std;
  
int main() {
  int NumbertoFact = 0;
  //this is an unfathomably stupid thing to do because now you will never know whether it is greater than the signed int cap. it also sucks for memory and will cause leaks
  unsigned long long int EndNum = 1;
  cout << "what would you like the number to fact! to be?";
  cin >> NumbertoFact;
  for (int i = 1; i <= NumbertoFact; i++){
    EndNum *= i;
    /* for debug but i didnt take time to fix it
    story of my programming life lmao
    will cause issues later*/
    cout << EndNum;
    cout << "\n";
  }
  return 0;
}
