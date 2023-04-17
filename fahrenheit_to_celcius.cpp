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
    //Declare all variables and constants
	double temp_in_f = 0; //variable of the temperature in fahrenheit, set to 0
	double temp_in_c = 0; //variable of the temperature in fahrenheit, set to 0
	const double F_TO_C = (5.0/9.0); //Set the conversion to 5/9ths 

	//Output to Terminal
	cout << "Please input a temperature in farenheit: " << endl; //Prompt user
	
	//Take input
	cin >> temp_in_f; //Take user input and set to side_length
	
	//Conversion
	temp_in_c = (F_TO_C*(temp_in_f - 32));

	//Output to Terminal
    cout << "The temperature in celcius is " << temp_in_c 
         << " degrees." << endl; //Prints temperature in degrees celcius
    
    system("PAUSE");  // Only needed for UW computers
    return EXIT_SUCCESS; //return statement
}

/* 
First Test Case:
Please input a temperature in farenheit:
212
The temperature in celcius is 100 degrees.
Press any key to continue . . .

--------------------------------
Process exited after 5.481 seconds with return value 0
Press any key to continue . . .


Second Test Case:
Please input a temperature in farenheit:
100
The temperature in celcius is 37.7778 degrees.
Press any key to continue . . .

--------------------------------
Process exited after 5.168 seconds with return value 0
Press any key to continue . . .


Third Test Case:
Please input a temperature in farenheit:
32
The temperature in celcius is 0 degrees.
Press any key to continue . . .

--------------------------------
Process exited after 9.458 seconds with return value 0
Press any key to continue . . .


Fourth Test Case:
Please input a temperature in farenheit:
-40
The temperature in celcius is -40 degrees.
Press any key to continue . . .

--------------------------------
Process exited after 1.9 seconds with return value 0
Press any key to continue . . .
*/
