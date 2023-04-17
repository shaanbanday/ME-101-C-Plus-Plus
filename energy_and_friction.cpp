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
	double mass = 0; //variable for the suitcase mass in kg, set to 0
	double height = 0; //variable of the height in m, set to 0
	const double ACCEL_GRAV = 9.81; //constant for the accelration due to g
	double c_friction = 0; //variable of the coefficient of friction, set to 0
	double potential_energy = 0; //variable of the potential energy, set to 0
	double force_friction = 0; //variable of the force of friction, set to 0

	//Output to Terminal
	cout << "Please input the mass of the suitcase in kg: " << endl; //Prompt
	//Take input
	cin >> mass; //Take user input and set to mass
	
	//Output to Terminal
	cout << "Please input the height in m: " << endl; //Prompt
	//Take input
	cin >> height; //Take user input and set to height
	
	//Output to Terminal
	cout << "Please input the coefficient of friction: " << endl; //Prompt
	//Take input
	cin >> c_friction; //Take user input and set to c_friction
	
	//Calculations
	potential_energy = ((mass)*(height)*(ACCEL_GRAV));
	force_friction = ((mass)*(c_friction)*(ACCEL_GRAV));

	//Output to Terminal
    cout << "The Potential Energy  is " << potential_energy 
         << " joules." << endl; //Prints potential energy in joules
         
    //Output to Terminal
    cout << "The Force of Friction  is " << force_friction 
         << " Newtons." << endl; //Prints Force in joules     
    
    system("PAUSE");  // Only needed for UW computers
    return EXIT_SUCCESS; //return statement
}

/* 
First Test Case:
Please input the mass of the suitcase in kg:
2.0
Please input the height in m:
1.5
Please input the coefficient of friction:
0.5
The Potential Energy  is 29.43 joules.
The Force of Friction  is 9.81 Newtons.
Press any key to continue . . .


Second Test Case: 
Please input the mass of the suitcase in kg:
7
Please input the height in m:
10
Please input the coefficient of friction:
0.3
The Potential Energy  is 686.7 joules.
The Force of Friction  is 20.601 Newtons.
Press any key to continue . . .

--------------------------------
Process exited after 15.87 seconds with return value 0
Press any key to continue . . .

Reference: 
https://mae.ufl.edu/designlab/Class%20Projects/Background%20Information/Friction
%20coefficients.htm
Used value for hard-plastic and dry concrete
*/
