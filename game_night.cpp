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
  string day = ""; //Variable to hold the day the user inputs
  bool is_cards = false; //variable to if preference for card games
  int time = 0; //variable to hold start time (to the nearest hour)
  const int TESTS = 24; 
  //For TEST, 4 possible days * 2 options for cards or not * 3 different times
  
  //File IO
  ifstream fin("game_night.txt"); //Read from text file
  ofstream fout("results.txt"); //Output results to text file
  
  //Decisions
  if (!fin) //If the file cannot be opened or is not found
  {
    cout <<"ERROR! File not found or could not be opened." << endl; //Output
    return EXIT_FAILURE; //Program terminates on return statement
  }
  //Otherwise, if there are no issues with the file, proceed
  
  for (int i = 0; i < TESTS; i++)
  {
    fin >> day >> is_cards >> time; //Take input on the ith line from text file
    
    //Decisions (Exactly the same as flow chart)
    if ((day == "Friday") || (day == "Saturday")) //If Friday or Saturday
    {
      //Nested Decisions
      if (is_cards) //If there is a preference for a card game 
      {
        fout << "My boy Forrest is playing Bridge" << endl; //Output to file
      }
      
      else //Otherwise, if there is no preference for a card game 
      {
        fout << "My boy Forrest is playing Risk" << endl; //Output to file
      }
    }
    
    else //If it is Sunday or a Weekday
    {
      //Nested Decisions
      //If it is a weekday and after 6PM OR it is Sunday and between 6 to 9
      if (((day == "Weekday") && (time >= 6)) || 
      ((day == "Sunday") && ((time >= 6) && (time <= 9))))
      {
        fout << "My boy Forrest is playing Dominion" << endl; //Output to file
      }
      
      //If it is not a weekday and after 6PM nor is it Sunday and between 6 to 9
      else 
      {
        //Double Nested Decisions 
        if (time < 6) //If it is before 6 PM
        {
          fout << "My boy Forrest is playing Spirit Island" << endl; //Output
        }
        
        else //Otherwise, if it is after 6 PM
        {
          fout << "My boy Forrest is playing Castle Panic" << endl; //Output
        }
      }
    }
  }
  
  //Close files to prevent a memory leak
  fin.close();
  fout.close();
  
  cout <<"File(s) was succesfully opened and closed" << endl; //Output
  return EXIT_SUCCESS; //Program terminates on return statement
}
/*
Input Text File:
Weekday 0 5
Weekday 0 7
Weekday 0 10
Weekday 1 5
Weekday 1 7
Weekday 1 10
Friday 0 5
Friday 0 7
Friday 0 10
Friday 1 5
Friday 1 7
Friday 1 10
Saturday 0 5
Saturday 0 7
Saturday 0 10
Saturday 1 5
Saturday 1 7
Saturday 1 10
Sunday 0 5
Sunday 0 7
Sunday 0 10
Sunday 1 5
Sunday 1 7
Sunday 1 10


Output Text File:
My boy Forrest is playing Spirit Island
My boy Forrest is playing Dominion
My boy Forrest is playing Dominion
My boy Forrest is playing Spirit Island
My boy Forrest is playing Dominion
My boy Forrest is playing Dominion
My boy Forrest is playing Risk
My boy Forrest is playing Risk
My boy Forrest is playing Risk
My boy Forrest is playing Bridge
My boy Forrest is playing Bridge
My boy Forrest is playing Bridge
My boy Forrest is playing Risk
My boy Forrest is playing Risk
My boy Forrest is playing Risk
My boy Forrest is playing Bridge
My boy Forrest is playing Bridge
My boy Forrest is playing Bridge
My boy Forrest is playing Spirit Island
My boy Forrest is playing Dominion
My boy Forrest is playing Castle Panic
My boy Forrest is playing Spirit Island
My boy Forrest is playing Dominion
My boy Forrest is playing Castle Panic
*/