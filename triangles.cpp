/*
Programmers: Shaan Banday and Sabrina Mogus
Student #s: 20993610 and 21009761
Class: ME 101
Date: Wednesday, February 15th, 2023
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//function to convert angle from degrees to radians and vice versa
double convert_angle (double input_angle, char target)
{ //takes paramters of the angle and what to convert to as a character
  
  //Declare variables within the scope of this function
  double output_angle = 0.0; //double angle to be returned
  
  //Decisions
  if (target == 'R') //If the goal is to convert to radians
  {
    output_angle = input_angle * (M_PI / 180.0); //converion
  }
  
  else if (target == 'D') //Otherwise, if the goal is to convert to degrees
  {
    output_angle = input_angle * (180.0 / M_PI); //converion
  }
  
  else //Otherwise, if this function is called with any other char
  {
    cout << "Error. Invalid conversion!"; //Output error to console
  }
  
  return output_angle; //return the output angle
}

//function to check if the given input will create a possible triangle
bool is_triangle(double a_side, double b_side, double c_angle)
{ //paramters of two sides lenghts and their contained angle
  
  //Declare variables within the scope of this function
  bool is_valid = false; //boolean for triangle validity to be returned
  
  //Decisions
  if (((c_angle < 180) && (c_angle > 0)) && ((a_side > 0) && (b_side > 0)))
  { //If the angle is between 0 and 180 AND both sides are positive
    is_valid = true; //triangle is valid
  }
  else
  {
    is_valid = false; //triangle is invalid
  }
  
  return is_valid; //return validity
}

//function to calculate third side using cosine law
double cosine_law(double a_side, double b_side, double c_angle)
{ //paramters of two sides lenghts and their contained angle
  
  //Declare variables within the scope of this function
  double c_side = 0.0; //double side length to be returned
  
  //first convert to radians
  c_angle = convert_angle (c_angle, 'R'); //call conversion function
  
  //Calculations
  c_side = sqrt(pow(a_side, 2) + pow(b_side, 2) -
           2 * a_side * b_side * cos(c_angle)); //Use cosine law
  
  return c_side; //return the side length
}

//function to calculate third side using cosine law
double inverse_cosine_law(double a_side, double  b_side, double c_side)
{ //takes paramters of three sides

  //Declare variables within the scope of this function
  double c_angle = 0; //double angle to be returned
  
  //Calculations
  c_angle = acos((pow(a_side, 2) + pow(b_side, 2) - pow(c_side, 2))
            / ( 2 * a_side * b_side)); //Use rearranged cosine law

  c_angle = convert_angle(c_angle, 'D'); //convert angle to degrees
  
  return c_angle; //return the angle
}

//function to calculate permimeter of triangle
double find_perimeter(double a_side, double b_side, double c_side)
{ //takes parameters of three side lengths
  return a_side + b_side + c_side; //return sum of side lengths
}

//function to calculate area of triangle using heron's formula
double find_area(double a_side, double b_side, double c_side)
{ //takes parameters of three side lenghts

  //Declare variables within the scope of this function
  double semi_p = find_perimeter (a_side, b_side, c_side) / 2.0;
  
  //return the area
  return sqrt(semi_p*(semi_p - a_side)*(semi_p - b_side)*(semi_p - c_side));
}

int main() //main function
{
  //Declare variables
  double side_A = 0.0, side_B = 0.0, side_C = 0.0;
  double angle_A_deg = 0.0, angle_B_deg = 0.0, angle_C_deg = 0.0;
  double angle_A_rad = 0.0, angle_B_rad = 0.0, angle_C_rad = 0.0;
  double area = 0.0, perimeter = 0.0;
  
  //File IO
  ifstream input("test_cases.txt"); //Read from text file
  ofstream output("tri_output.txt"); //Output results
  
  //Decisions
  if (!input) //If the file cannot be opened or is not found
  {
    cout <<"ERROR! File not found or could not be opened." << endl;
    return EXIT_FAILURE; //Program terminates on return statement
  }
  //Otherwise, if there are no issues with the file, proceed
  
  output << fixed << setprecision(2); //Set precision of 2 decimal places
  
  //Output to text file
  output << "Side A" << setw(9) << "Side B" << setw(9) << "Side C" 
         << setw(16) << "Angle A (deg)" << setw(16) << "Angle B (deg)" 
         << setw(16) << "Angle C (deg)" << setw(16) << "Angle A (rad)" 
         << setw(16) << "Angle B (rad)" << setw(16) << "Angle C (rad)" 
         << setw(12) << "Perimeter" << setw(7) << "Area" << endl;
         
  //Loops
  while(input >> side_A >> side_B >> angle_C_deg) //So long as there's lines
  {
    //Decisions
    if (!(is_triangle(side_A, side_B, angle_C_deg))) //If triangle is invalid
    {
      output << "Invalid Triangle!" << endl; //output message to text file
    }
    
    else //Otherwise, if it is valid
    {
      //Calculations 
      side_C = cosine_law(side_A, side_B, angle_C_deg);
      angle_A_deg = inverse_cosine_law(side_B, side_C, side_A);
      angle_B_deg = 180.0 - angle_C_deg - angle_A_deg;
      perimeter = find_perimeter(side_A, side_B, side_C); 
      area = find_area(side_A, side_B, side_C); 
      
      
      //Convert all angles to radians
      angle_A_rad = convert_angle(angle_A_deg, 'R');
      angle_B_rad = convert_angle(angle_B_deg, 'R');
      angle_C_rad = convert_angle(angle_C_deg, 'R');
      
      //Output results to text file
      output << side_A << setw(9) << side_B << setw(9) << side_C
         << setw(10) << angle_A_deg << setw(16) << angle_B_deg
         << setw(16) << angle_C_deg << setw(15) << angle_A_rad
         << setw(16) << angle_B_rad << setw(16) << angle_C_rad
         << setw(17) << perimeter<< setw(12) << area << endl;
    }
  } //end of loop
  
  input.close(); //Close the file to prevent memory leak
  output.close(); //Close the file to prevent memory leak
  
  return EXIT_SUCCESS; //Terimate program
} //end of main function

/*
Shaan's Assignment 2 Test Case: 
10 10 60
5 4 34
7 8 55

Output:
Side A   Side B   Side C   Angle A (deg)   Angle B (deg)   
10.00    10.00    10.00     60.00           60.00                      
5.00     4.00     2.80     92.97           53.03                      
7.00     8.00     6.98     55.20           69.80                  

Angle C (deg)
60.00
34.00
55.00    

Angle A (rad)   Angle B (rad)   Angle C (rad)   Perimeter   Area
1.05            1.05            1.05            30.00       43.30
1.62            0.93            0.59            11.80        5.59
0.96            1.22            0.96            21.98       22.94

Sabrina's Assignment 2 Test Case: 
5 5 45
12.5 4.5 60
8 8 60

Output:
Side A   Side B   Side C   Angle A (deg)   Angle B (deg)
5.00     5.00     3.83     67.50           67.50 
12.50     4.50    10.97     99.18           20.82  
8.00     8.00     8.00     60.00           60.00   

Angle C (deg)  
45.00          
60.00
60.00 

Angle A (rad)   Angle B (rad)   Angle C (rad)   Perimeter   Area
1.18            1.18            0.79            13.83        8.84
1.73            0.36            1.05            27.97       24.36
1.05            1.05            1.05            24.00       27.71
*/