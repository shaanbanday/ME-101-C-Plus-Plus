/*
Programmer: Shaan Banday
Student #: 20993610
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
	double a_side = 0, b_side = 0, c_side = 0; //Side lenghts
  double a_angle_deg = 0, b_angle_deg = 0, c_angle_deg = 0; //Angles in degrees
  double a_angle_rad = 0, c_angle_rad = 0; //Angles in radians
  double area = 0, perimeter = 0, semi_perimeter = 0; //Varibles for A and P
  
  //Output to Terminal
  cout << "Enter two side lengths of a triangle and their contained angle (in "
       << "degrees).\nMake sure each value is in the order above, seperated by "
       << "spaces:" << endl; //Prompt user for values
  
  //Take input
  cin >> a_side >> b_side >> c_angle_deg;
  
  //Calculate contained angle in radians
  c_angle_rad = (c_angle_deg * M_PI) / 180.0;
  
  //Calcuate Side C using Cosine Law
  c_side = sqrt((a_side * a_side) + (b_side * b_side) 
           - (2 * a_side * b_side * cos(c_angle_rad)));
           
  //Calculate angle a using rearranged Cosine Law
  a_angle_rad = acos(((b_side * b_side) + (c_side * c_side) - (a_side * a_side))
                / (2*b_side*c_side));
  a_angle_deg = (a_angle_rad * 180.0) / M_PI;
  
  //Calculate angle b using Triangle inner angle theorem
  b_angle_deg = 180 - a_angle_deg - c_angle_deg;
  
  //Calculate perimeter
  perimeter = a_side + b_side + c_side;
  semi_perimeter = perimeter / 2.0;
  
  //Calculate area using Heron's formula
  area = sqrt(semi_perimeter * (semi_perimeter - a_side) * 
         (semi_perimeter - b_side) * (semi_perimeter - c_side));
         
  //Output results
  cout << "Side C: " << c_side << " units." << endl;
  cout << "Angle A: " << a_angle_deg << " degrees." << endl;
  cout << "Angle B: " << b_angle_deg << " degrees." << endl;
  cout << "Perimeter : " << perimeter << " units." << endl;
  cout << "Area : " << area << " square units." << endl;
  
  system("PAUSE");  // Only needed for UW computers
  return EXIT_SUCCESS; //return statement
}

/* 
Test Case 1: 10 10 60
Enter two side lengths of a triangle and their contained angle (in degrees).
Make sure each value is in the order above, seperated by spaces:
10 10 60
Side C: 10 units.
Angle A: 60 degrees.
Angle B: 60 degrees.
Perimeter : 30 units.
Area : 43.3013 square units.
Press any key to continue . . .


Test Case 2: 5 4 34
Enter two side lengths of a triangle and their contained angle (in degrees).
Make sure each value is in the order above, seperated by spaces:
5 4 34
Side C: 2.79973 units.
Angle A: 92.9726 degrees.
Angle B: 53.0274 degrees.
Perimeter : 11.7997 units.
Area : 5.59193 square units.
Press any key to continue . . .

Test Case 3: 7 8 55
*/