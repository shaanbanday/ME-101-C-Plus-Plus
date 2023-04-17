/*
Programmer: Shaan Banday
Student #: 20993610
Class: ME 101
Date: Wednesday, January 11th, 2023
*/

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() //main function
{
    //Declare all variables
	int side_length = 0; //variable of the side length for a square, set to 0

	//Output to Terminal
	cout << "Please input a side length: " << endl; //Primpt user for input
	
	//Take input
	cin >> side_length; //Take user input and set to side_length

	//Output to Terminal
    cout << "The square of " << side_length 
         << " is " << (side_length*side_length) << endl; //Print 9^2

    cout << "& the cube of " << side_length
         << " is " << (side_length*side_length*side_length) << endl; //Print 9^3
    
    system("PAUSE");  // Only needed for UW computers
    return EXIT_SUCCESS; //return statement
}

/* 
Please input a side length:
5
The square of 5 is 25
& the cube of 5 is 125
Press any key to continue . . .

--------------------------------
Process exited after 1.805 seconds with return value 0
Press any key to continue . . .
*/
