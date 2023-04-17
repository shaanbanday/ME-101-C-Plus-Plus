/*
Programmer: Shaan Banday and James Lewis
Student #s: 20993610 and 21014583
Class: ME 101
Date: Wednesday, January 18th, 2023
*/

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() //main function
{
  //Declare all variables and constants
	int number = 0, thousands = 0, hundreds = 0; //Varibles to store values
  
	//Output to Terminal
	cout << "Please enter a number (in the thousands): " << endl; //Prompt user
	//Take input
	cin >> number; //Take user input
  
  //Calculations
  thousands = ((number % 1000000)/1000); //Find thousands digits
  hundreds = (number % 1000); //Find hundreds digits
  
  //Decisions
  if (hundreds == 0) //If there are no hundreds digits
  {
    cout << "The number is " << thousands << ",000" << endl; //Output to console
  }
  
  else if (abs(hundreds) < 10) //If the hundreds section is between 1 and 9
  {
    cout << "The number is " << thousands << ",00" << abs(hundreds) << endl;
    //Output to console
  }
  
  else if (abs(hundreds) < 100) //If the hundreds section is between 10 and 99
  {
    cout << "The number is " << thousands << ",0" << abs(hundreds) << endl;
    //Output to console
  }
  
  else //Otherwise, if the hundreds section is greater than 100
  {
    cout << "The number is " << thousands << "," << abs(hundreds) << endl; 
    //Output to console
  }
  
  system("PAUSE");  // Only needed for UW computers
  return EXIT_SUCCESS; //return statement
}

/* 
Test Case 1: 425081
Please enter a number (in the thousands):
425081
The number is 425,081
Press any key to continue . . .

Test Case 2: 1000
Please enter a number (in the thousands):
1000
The number is 1,000
Press any key to continue . . .

Test Case 3: -11004
Please enter a number (in the thousands):
-11004
The number is -11,004
Press any key to continue . . .

Test Case 4: -987654
Please enter a number (in the thousands):
-987654
The number is -987,654
Press any key to continue . . .
*/
