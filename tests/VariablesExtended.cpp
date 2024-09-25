/*this program exists to teach about 
adding, subtracting, multiplying and dividing variables*/

#include <iomanip>
#include <iostream>

using namespace std;
int main()
{
    /*here is how to declare multiple variables at the same time */
    int x= 5, y= 12, z = 50 ;
    cout << x+y+z;

    /*here is how to add a single value to multiple variables:*/
    int a, b, c;
    a=b=c=50;
    cout << a+b+c;

    /* you can also make constants, which cannot be changed but use less memory than variables*/
    const int minutesPerHour = 60;
    const double PI = 3.14159;

    /* you can manupilate the variables by using normal mathematic operationss*/
    
return 0;}