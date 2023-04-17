/*
Programmer: Shaan Banday and Ryan Yau
Student #s: 20993610 and 21025670
Class: ME 101
Date: Wednesday, February 1st, 2023
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() //main function
{
  
  //Declare Varibles
	int number = 0, increment = 0;
	
  //Prompt user for input
  do //Do this AT LEAST once
  {
    cout << "Input a positive number to find all of its factors: " << endl;
    cin >> number; //Take user input 
  }
  while (number <= 0); //If number is less than of equal to 0, run loop again
	
  //Find factors
  for (int i = number; i > 0; i--) 
  //set i to the number and keep on decreasing by one until it is 0, then break
  {
    //Decisions 
    if ((number % i) == 0) //If the number is divisible by i (produces a factor)
    {
      //Nested Decisions
      if (increment == 5) //If 5 factors have already been outputted on the line
      {
        cout << endl; //Start a new line to prevenrt word wrap
        cout << i << " "; //print the factor
        increment = 1; //reset increment to 0 since new line
      }
      
      else //otherwise, if 5 factors have not been outputted 
      {
        cout << i << " "; //print the factor
        increment ++; //count an increment
      }
    }
  }
  
  return EXIT_SUCCESS; //Terimate program
}
/*
Test Case: 500500
Input a positive number to find all of its factors:
-1000
Input a positive number to find all of its factors:
0
Input a positive number to find all of its factors:
500500
500500 250250 125125 100100 71500
50050 45500 38500 35750 25025
22750 20020 19250 17875 14300
11375 10010 9625 9100 7700
7150 6500 5500 5005 4550
4004 3850 3575 3500 3250
2860 2750 2275 2002 1925
1820 1750 1625 1540 1430
1375 1300 1100 1001 910
875 770 715 700 650
572 550 500 455 385
364 350 325 308 286
275 260 250 220 182
175 154 143 140 130
125 110 100 91 77
70 65 55 52 50
44 35 28 26 25
22 20 14 13 11
10 7 5 4 2
1
--------------------------------
Process exited after 58.07 seconds with return value 0
Press any key to continue . . .
*/