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
	//Declare variables
	double lowest_high = 0, highest_low = 0;
	
	//File IO
	ifstream fin ("NovDec2022.txt"); //declare text file to take input
	
	//Decisions
	if (!fin) //If file cannot be opened or is not found
	{
		cout << "Unable to open file or it was not found." << endl; //Output
		return EXIT_FAILURE; //Terminate program
	}
	//Otherwise, proceed

	//Loops
	for (int count = 0; count < 61; count++) //Start at 0 and increment to 61
	{
		//Declare variables in-scope of loop
		double temp_lowest_high = 0, temp_highest_low = 0;
		
		//File input
		fin >> temp_lowest_high >> temp_highest_low; // Read line of text file
		
		//Decisions
		//If the read temperature is less than the previously stored one
		if (temp_lowest_high <= lowest_high)
		{
			lowest_high = temp_lowest_high; //update the previously stored one
		}
		//otherwise, proceed
		
		//Different Decisions
		//If the read temperature is greater than the previously stored one
		if (temp_highest_low >= highest_low)
		{
			highest_low = temp_highest_low; //update the previously stored one
		}
		//otherwise, proceed
	}
	
	//Output results to user through console
	cout << "The lowest daily high temperature in November and December is " 
			 << lowest_high << "." << endl
			 << "The highest daily low temperature in November and December is "
			 << highest_low << "." << endl;
	
	
	fin.close(); //Close the file to prevent memory leak
	return EXIT_SUCCESS; //Terminate the program
}
/*
The lowest daily high temperature in November and December is -10.8.
The highest daily low temperature in November and December is 13.5.

--------------------------------
Process exited after 0.125 seconds with return value 0
Press any key to continue . . .
*/