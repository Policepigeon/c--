#include <iostream>
#include <iomanip>
using namespace std;

int main(){
int peopleclicked = 10;
switch (peopleclicked){
  case 10:
  cout << "you are the tenth person" << endl;
            break;
  case 100:
  cout << "you are the hundredth person" << endl;
            break;
}
    
    cout << "You have clicked on the button "<< to_string(peopleclicked) <<" times.";
}