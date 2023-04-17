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
	double mass = 0, c_friction = 0, kinetic_energy = 0, initial_distance = 0;
  double friction_force = 0; //Force of friction calculated from user input
  double final_distance = 0; //Output from formula provided in the problem
  const double GRAV = 9.81; //Constant for the accelration due to gravity
  
  //Output to Terminal
  cout << "Enter the mass (in kg), coefficient of friction, kinetic energy (in "
       << "J) and initial distance of the suitcase (in m).\nMake sure each" 
       << "value is in the order above, seperated by spaces:" << endl; 
       //Prompt user for values
  
  //Take input
  cin >> mass >> c_friction >> kinetic_energy >> initial_distance;
  
  //Decisions
  if ((mass > 0) && (c_friction > 0)) //If mass and c_friction make sense
  {
    friction_force = c_friction*mass*GRAV; //Calculate force of friction
    
    final_distance = initial_distance + (kinetic_energy/friction_force);
    //Calculate final distance based on formula given in question
    
    //Output to Terminal
    cout << "The final distance travelled by the suitcase (in m) is " 
         << final_distance << " m." << endl;
  }
  else //if the input is invalid
  {
    cout << "Error! The mass and coefficient of friction "
         << "must be greater than 0." << endl;
  }
  
  system("PAUSE");  // Only needed for UW computers
  return EXIT_SUCCESS; //return statement
}

/* 
Test Case 1: 2 0.5 200 0.5
Enter the mass (in kg), coefficient of friction, kinetic energy (in J) and 
initial distance of the suitcase (in m).
Make sure eachvalue is in the order above, seperated by spaces:
2 0.5 200 0.5
The final distance travelled by the suitcase (in m) is 20.8874 m.
Press any key to continue . . .


Test Case 2: 26 0.3 400 12
Enter the mass (in kg), coefficient of friction, kinetic energy (in J) and 
initial distance of the suitcase (in m).
Make sure eachvalue is in the order above, seperated by spaces:
26 0.3 400 12
The final distance travelled by the suitcase (in m) is 17.2275 m.

  Reference for coefficient of Friction: 
  https://mae.ufl.edu/designlab/Class%20Projects/Background%20Information/Frict
  ion%20coefficients.htm
  Used value for hard-plastic and dry concrete from Shaan's Assignment 1

  Refernce for mass of suitcase
  https://www.quora.com/How-many-kgs-does-a-suitcase-hold-on-average
  Used value of 26 kg from airplane flight limit
  
  Inferred 400 J and 12 m as reasonble values


Test Case 3: 0.0 0.2 100 0.25
Enter the mass (in kg), coefficient of friction, kinetic energy (in J) and 
initial distance of the suitcase (in m).
Make sure eachvalue is in the order above, seperated by spaces:
0.0 0.2 100 0.25
Error! The mass and coefficient of friction must be greater than 0.
Press any key to continue . . .

Test Case 4: -3 -4 20 34
Enter the mass (in kg), coefficient of friction, kinetic energy (in J) and 
initial distance of the suitcase (in m).
Make sure eachvalue is in the order above, seperated by spaces:
-3 -4 20 34
Error! The mass and coefficient of friction must be greater than 0.
Press any key to continue . . .
*/