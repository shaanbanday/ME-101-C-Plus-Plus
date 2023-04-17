/*
Programmers: Shaan Banday and James Yu
Student #s: 20993610 and 21013316
Class: ME 101
Date: Wednesday, March 8th, 2023
*/

//Import libraries
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std; //namespace

//Pass by value function calculates unrounded amount of money spent
double unrounded_spent (int num_parts, double cost, int set_size)
{
  return (cost/set_size) * num_parts; //Do calculations and return
}

//Pass by Reference as amount spent is modified in original function
double calculate_error(double &amount_spent)
{
  //Declare variables within the scope of this function
  double before_rounding = amount_spent; //double stores unrounded value
  
  //Round the amount spent to nearest cent
  amount_spent = round(amount_spent*100)/100;  
  //Since pass by reference, value also changes in original function
  
  //Calculate and return error
  return (before_rounding - amount_spent);
  //error is difference between unrounded and rounded
}

void output_headers() //void command function
{
  cout << setw(20) << "Part Name:" << setw(15) << "Money Spent:" 
       << setw(13) << "Error:" << endl; //Output to console
}

void output_part_info(string name, double spent, double error_value)
{
  cout << setw(20) << name << setw(15) << fixed << setprecision(2)
         << spent << setw(13) << fixed << setprecision(4) 
         << error_value << endl; //Output to console
}

void read_and_calculate(ifstream &input)
{
  //Declare variables within the scope of this function
  double money_spent = 0.0, error = 0.0, cost_per_part = 0.0;
  int num_of_parts = 0, parts_per_set = 0; //int values
  string part_name = " "; //String for the name of the part
  
  //Output headers to console
  output_headers();
  
  //Read the first line of headings in the file and discard them
  input >> part_name >> part_name >> part_name >> part_name;
  
  //While there are lines to read, keep running loop
  while(input>> part_name>>num_of_parts>>cost_per_part>>parts_per_set)
  {
    //Calculate unrounded amount of money spent
    money_spent = unrounded_spent(num_of_parts, 
                cost_per_part, parts_per_set);
    
    //Calculate rounded money spent (through reference) and error
    error = calculate_error (money_spent);
    
    //Output to console with correct spacing and decimal values
    output_part_info(part_name, money_spent, error);
  } 
  
}

int main () //Main function, entry point of program
{
  //File IO
  ifstream fin("part_costs.txt"); //Read from text file
  
  //Decisions
  if (!fin) //If the file cannot be opened or is not found
  {
    cout <<"ERROR! File not found or could not be opened." << endl;
    return EXIT_FAILURE; //Program terminates on return statement
  }
  //Otherwise, if there are no issues with the file, proceed
  
  read_and_calculate(fin); //pass FileIO object to other function
  
  fin.close(); //Close the file to prevent memory leak
  
  return EXIT_SUCCESS; //Terimate program
}
/*
OUTPUT: Directly copyed from console


          Part Name:   Money Spent:       Error:
                M1#6           7.08       0.0040
               M3#12           5.02      -0.0010
           Spring2mm           4.00       0.0000
        Motor35mm30V          52.40      -0.0050
       FHV50033MJNEB          11.79      -0.0027
         HCL16568RCX          24.42       0.0024
          Samoflange         163.33      -0.0033
AlRoundStock8mmx50cm          33.09       0.0033
           MT1024-40          47.15      -0.0020
          TheFlapper         409.75      -0.0029
         BritaFilter          64.27      -0.0033
                DC9V          18.53      -0.0019
          CottonSwab           0.02       0.0012
*/