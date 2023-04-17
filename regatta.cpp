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
	const int TESTS = 25; //Number of lines in the text file
  int start_time = 0, end_time = 0, time_elapsed = 0; //Set start, end
  int longest = 0, shortest = 2359; //Set longest time to 0, shorest to 2359
  /*2359 is the longest possible time, assuming starting at midnight and ending 
    at 1 minute before midnight, a little less than 24 hours later*/
  
  
  //File IO
  ifstream input("boat_regatta.txt"); //Read from text file
  ofstream output("results.txt"); //Output results to text file
  
  //Decisions
  if (!input) //If the file cannot be opened or is not found
  {
    cout <<"ERROR! File not found or could not be opened." << endl; //Output
    return EXIT_FAILURE; //Program terminates on return statement
  }
  //Otherwise, if there are no issues with the file, proceed
  
  
  for (int i = 0; i < TESTS; i++)
  {
    //File input
		input >> start_time >> end_time; // Read line of text file
    
    //Convert to minutes
    start_time = ((start_time / 100) * 60) + (start_time % 100);
    end_time = ((end_time / 100) * 60) + (end_time % 100);
    
    //Decisions
    if (end_time < start_time) //If the end time is the next day
    {
      time_elapsed = (1440 + end_time) - start_time; //Add midnight to end time
    }
    
    else //Otherwise, if start and end_time are in the same day
    {
      time_elapsed = end_time - start_time; //find elapsed time
    }
    
    //output total to txt file
    output << time_elapsed << endl;	
    
    //More decisions
    if (time_elapsed > longest)
    {
      longest = time_elapsed;
    }
    
    if (time_elapsed < shortest)
    {
      shortest = time_elapsed;
    }
  }
  
  //Output to text file
  output << "The longest race time for a boat is: " << longest << endl;
  output << "The shortest race time for a boat is: " << shortest << endl;
  
  input.close(); //Close the file to prevent memory leak
  output.close(); //Close the file to prevent memory leak
  
  return EXIT_SUCCESS; //Terimate program
}
/*
961
709
931
648
621
501
676
364
445
809
736
798
650
693
905
933
422
787
308
636
643
494
827
710
870
The longest race time for a boat is: 961
The shortest race time for a boat is: 308
*/