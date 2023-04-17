/*
Programmer: Shaan Banday and Matthew Stefanov
Student #s: 20993610 and 21021373
Class: ME 101
Date: Wednesday, January 25th, 2023
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() //main function
{
	//*ASSUMPTION MADE VALUES MUST BE LESS THAN OR EQUAL TO TOLERANCES
  
  //Declare Varibles
	double side_1 = 0, side_2 = 0, angle = 0;
	double const SIDETOL = 0.1, ANGTOL = 0.5; 
	
  //Output to user
	cout << "Enter two adjacent sides (in cm) and their contained angle"
       << " in degrees (in that order):" << endl; //Prompt user for input
	
  //User input
	cin >> side_1 >> side_2 >> angle; //Take input for the stone properties
	
  //Decisions 
  /*If the angle is out of range (less than 0 or greater than 180) OR either of
  the side lengths are out of range (less than 0)*/
	if  (((angle <= 0) || (angle >= 180)) || (side_1 <= 0) || (side_2 <= 0))
	{
		cout << "ERROR! Invalid data." << endl; //Output to console
		return EXIT_FAILURE; //Terimate program
	}
  
  //Otherwise, if just the angle is within 0.5 degrees of a right angle
  else if (fabs(angle - 90) <= ANGTOL)
  {
    //Nested Decisions
    //If the side lengths are within 1 mm of each other
    if (fabs(side_1 - side_2) <= SIDETOL)
    {
      cout << "The paving stone is a square." << endl; //Output to console
    }
      
    //Otherwise, if the side lengths are NOT within 1 mm of each other
    else
    {
      cout << "The paving stone is a rectangle." << endl; //Output to console
    }
  }
  
  //Otherwise, if the angle is not within 0.5 degrees of a right angle
  else
  {
    cout << "The paving stone is a parallelogram." << endl; //Output to console
  }
  
  return EXIT_SUCCESS; //Terimate program
}
/*
Test Case 1: 9.34 9.44 180
Enter two adjacent sides (in cm) and their contained angle in degrees (in that order):
9.34 9.44 180
ERROR! Invalid data.


Test Case 2: 324.4 345.2 0
Enter two adjacent sides (in cm) and their contained angle in degrees (in that order):
324.4 345.2 0
ERROR! Invalid data.


Test Case 3: 2 3 270
Enter two adjacent sides (in cm) and their contained angle in degrees (in that order):
2 3 270
ERROR! Invalid data.


Test Case 4: 4 8 -9
Enter two adjacent sides (in cm) and their contained angle in degrees (in that 
order):
4 8 -9
ERROR! Invalid data.


Test Case 5: -2 5 -13
Enter two adjacent sides (in cm) and their contained angle in degrees (in that 
order):
-2 5 -13
ERROR! Invalid data.


Test Case 6: 12 -34.64234351234234234234 7
Enter two adjacent sides (in cm) and their contained angle in degrees (in that 
order):
12 -34.64234351234234234234 7
ERROR! Invalid data.


Test Case 7: 6.5 6.4 89.5
Enter two adjacent sides (in cm) and their contained angle in degrees (in that 
order):
6.5 6.4 89.5
The paving stone is a square.


Test Case 8: 6.5 6.39 89.5
Enter two adjacent sides (in cm) and their contained angle in degrees (in that 
order):
6.5 6.39 89.5
The paving stone is a rectangle.

Test Case 9: 12.4 34.3 90.2
Enter two adjacent sides (in cm) and their contained angle in degrees (in that 
order):
12.4 34.3 90.2
The paving stone is a rectangle.

Test Case 10: 12.4 12.4 70
Enter two adjacent sides (in cm) and their contained angle in degrees (in that 
order):
12.4 12.4 70
The paving stone is a parallelogram.

Test Case 11: 3434 56565 89.4
Enter two adjacent sides (in cm) and their contained angle in degrees (in that 
order):
3434 56565 89.4
The paving stone is a parallelogram.
*/