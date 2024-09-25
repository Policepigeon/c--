/*This program is a demonstration
 of how to create and edit variables*/
#include <iomanip>
#include <iostream>

using namespace std;
int main()
{
    int number = 0; //makes an integer called "number"
    cout << number <<endl;

    number = 10; //changes the value of the integer "number"
    cout <<number <<endl;

    double flt = 5.123456789123456798;
    /*makes a floating point number 
    with the name "flt" 
    and 15 decimal points of  precision*/
    cout <<flt <<endl;

    float fltter = 5.123456789123456798;
    /*makes a new floating point number
    with the name "fltter" 
    and 7 decimal points of precision */
    cout << fltter <<endl;

    cout << setprecision(12); //setting the floaing point precision
    /* this shows that 
    while doubles have twice the floating point accuracy as floats, 
    they take up more memory, 
    meaning it is beneficial to use floats instead of doubles 
    when dealing with few decimal places, 
    and instead use doubles 
    when high accuracy or rounding is needed*/
    cout << flt << endl;
    cout << fltter << endl;
    
    char letter = 'D'; /* stores a character
    using a variable name 
    (low memory usage)*/
    cout << letter << endl;
    
    string text = "hello world"; /*makes a new string 
    with the name text*/
    cout << text <<endl;

    bool boolean = true;/* stores a boolean value using 
    a variable name*/
    cout << boolean <<endl;


    /* you can also use e as a scientific number to do x10^power*/
    float f1 = 35e3;
    double d1 = 12E4;
    cout << f1;
    cout << d1; 
return 0;}