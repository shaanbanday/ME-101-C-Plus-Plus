/*
Programmers: Shaan Banday and Milind Kumar
Student #s: 20993610 and (21017888)
Class: ME 101
Date: Wednesday, March 15th, 2023
*/

//Shaan is Partner A, Milind is Partner B

//Import libraries
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std; //namespace

//Declare global constants
const int MAX = 50; //Maximum number of spots
const int HALF = 25; //Maximum number of additions and removals

//question b)
//Partner A: Shaan
void read_current(bool status[MAX], string names[MAX], ifstream &fin)
{ //function reads the current parking file and fills the appropriate array
  
  //Declare variables within the scope of this function
  bool staff_status = false; //boolean for the read in status
  string name = ""; //String for the read in name
  int parking_spot = 0; //integer for the read in parking spot
  
  //While there are lines to read, keep running loop
  while(fin >> staff_status >> name >> parking_spot) //take the input in order
  { 
    //Set status of the person in the array at the element based on parking spot
    status[parking_spot - 1] = staff_status; 
    
    //Decisions
    if (name == "") //If their name is blank
    {
      names[parking_spot - 1] = "OPEN"; //Set the name to OPEN
    }
    
    else //Otherwise, if the name is anything else
    {
      names[parking_spot - 1] = name; //otherwise, set the name normally
    }
  }
  //no return, void function
}

//question c)
//Partner B: Milind
void populate_array (bool status [HALF], string names [HALF], ifstream &fin)
{ //function reads the add and remove parking file, fills arrays
  
  //Declare variables within the scope of this function
  bool staff_status = false; //boolean for the read in status
  string name = ""; //String for the read in name
  int count = 0;  //integer to count number of iterations
  
  //While there are lines to read, keep running loop
  while(fin >> staff_status >> name) //take the input in order
  { 
    status[count] = staff_status; //Fill array at element count with input
    names[count] = name; //Fill array at element count with input
    count ++; //increment (move on to next element in array)
  }
}

//question d)
//Partner A: Shaan
void remove_person(string names [MAX], bool status [MAX], string person_to_remove)
{ //Function is given a name and removed them from the array
  //Assumption: any name given can be found 
  
  //Declare variables within the scope of this function
  bool found_name = false; //boolean to hold status o
  int count = (MAX - 1); //Highest element in the array (minus 1 since start at 0)
  
  //While the name is not found
  while (!found_name) //keep running loop, starting at the end of the array
  {
    //Decisions
    if (person_to_remove == names [count]) //If the target name matches
    {
      names [count] = "OPEN"; //Set the name to OPEN since person is leaving
      status[count] = false; //Set their status to student by default
      found_name = true; //Name is found, break the loop
    }
    count --; //Decrement (move on to earlier element)
  }
}

//question e)
//Partner B: Milind
int lowest_spot (string names [MAX], bool status)
{ //Function returns the lowest spot available
  
  //Declare variables within the scope of this function
  int lowest_avail = 0; //Integer to hold the lowest spot
  int start = 0; //Integer for the starting point
  
  //Decisions
  if (!status) //If they are a student
  {
    start = HALF; //set the starting point to 25
  }
  
  //Loop
  for (start; start < MAX; start++) //Interate from starting point to end
  {
    //Decisions
    if (names[start] == "OPEN") //If the spot is open
    {
      lowest_avail = start + 1; //set the lowest available spot to element + 1
      start = MAX; //break the loop
    }
  }
  return lowest_avail; //return the lowest spot
}

//question f)
//Partner A: Shaan
bool assign_spots(string names [MAX], bool status [MAX], string name, bool isStaff)
{
  //Declare variables within the scope of this function
  int lowest = lowest_spot (names, isStaff); //Integer for the lowest spot
  bool is_open = false;  //Boolean to hold the status of whether sp
  
  //Decision
  if (lowest != 0) //So long as open 
  { //Since lowest in other function is initialized to 0, no open spots means 0
    names [lowest - 1] = name; //Set name in array
    status [lowest - 1] = isStaff; //Set status in array
    is_open = true; //Spot was indeed open
  }
  //Otherwise, if no spot is open, do not assign spot
  
  return is_open; //return boolean of whether of not spot is open
}

//question g)
//Both Partners: Milind and Shaan
void sort_staff (string names[MAX], bool status[MAX])
{ //Function moves staff 26-50 to 1-25, if possible
  
  //Loops
  for (int i = HALF; i < MAX; i++) //Start at the half way point, iterate to end
  {
    //Decisions
    if ((status[i]) //If they are a staff
    && (names[i] != "OPEN") //Their name is not open
    && (assign_spots(names, status, names[i], status [i]))) //And a spot is open
    {
      remove_person(names, status, names[i]); //Remove them from their old spot
    }
    //Otherwise, keep them where they are
  }
}

//question h)
//Partner B: Milind
void output_headers(ofstream &fout) //Auxillary function to output headers
{
  fout << setw(7) << "Spot #:" << setw(22) << "Name:" 
       << setw(17) << "Status:" << endl; //Output to console
}

//question h) continued.
void output_to_file (ofstream &fout, string names [MAX], bool status [MAX])
{ //This is the actual function that takes input to output
  
  output_headers(fout); //Output the headers first
  
  //Loops
  for (int i = 0; i < MAX; i ++) //Start at 0, iterate through parking lot
  {
    //Output the parking spot, then the name
    fout << setw(7) << (i + 1) << setw(22) << names [i] << setw(17);
    
    //Decisions
    if ((names[i] == "OPEN") || (names [i] == "")) //If spot is OPEN
    {
      fout << "N/A"; //Output the status as N/A
    }
    
    else if (status[i]) //Otherwise, if the spot is for a staff
    {
      fout << "Staff"; //Output the status as staff
    }
    
    else //Otherwise, if the spot is for a student
    {
      fout << "Student"; //Output status as student
    }
    
    fout << endl; //Jump to next line
  }
}

//question i)
//Both Partners: Milind and Shaan
int main() //Main function, entry point of program
{
  //Current parking arrays (which are objects, not variables)
  bool current_isStaff [MAX] = {false}; //Array for status of current parking
  string current_names [MAX]; //Array for names of current parking
  
  //Loops
  for (int i = 0; i < MAX; i++) //Start at 0, iterate through parking array
  {
    current_names[i] = "OPEN"; //Set all of the names to "OPEN" by default
  }
  
  //Add parking arrays
  bool add_isStaff [HALF] = {false}; //Array for status of add parking
  string add_names [HALF] = {" "}; //Array for names of add parking

  //Remove parking arrays
  bool remove_isStaff [HALF] = {false}; //Array for status of remove parking
  string remove_names [HALF] = {" "}; //Array for names of remove parking
  
  //File IO
  ifstream currentIn("parking_current.txt"); //Read from current parking file
  ifstream addIn("parking_add.txt");  //Read from add to parking file
  ifstream removeIn("parking_remove.txt"); //Read from removing parking file
  
  ofstream output("parking_update.txt"); //Write final results to file
  
  //Decisions
  if ((!currentIn) || (!addIn) || (!removeIn)) //If the file cannot be opened
  {
    cout <<"ERROR! File not found or could not be opened." << endl;
    return EXIT_FAILURE; //Program terminates on return statement
  }
  //Otherwise, if there are no issues with the file, proceed
  
  read_current(current_isStaff, current_names, currentIn); //Read current file
  
  populate_array(add_isStaff, add_names, addIn); //Read add file
  
  populate_array(remove_isStaff, remove_names, removeIn); //Read remove file
  
  //Output the initial parking lot with nice formating
  output << "<----------------|   LAST TERM   |---------------->"<<endl<<endl;
  output_to_file(output, current_names, current_isStaff); //Call function
  output << "<------------------------------------------------->"<<endl<<endl;
  
  //Loops 
  for (int i=0;i<(HALF-16);i++) //Start at 0, iterate through array
  {
    //Remove people from the remove names file 
    remove_person (current_names, current_isStaff, remove_names[i]);
  }
  
  sort_staff(current_names, current_isStaff); //Sort the staff 
  
  //Output the parking lot after removing and re-assigning unused spaces
  output << "<------|   AFTER REMOVING AND REASSIGNING  |------>"<<endl<<endl;
  output_to_file(output, current_names, current_isStaff); //Call function
  output << "<------------------------------------------------->"<<endl<<endl;
  
  //Loops
  for (int i = 0; i < HALF; i++) //Start at 0, iterate thorugh array
  {
    //Decisions
    if(!assign_spots(current_names,current_isStaff,add_names[i],add_isStaff[i]))
    { //If the spot could not be assigned, output to console
      cout << "No Spot" << endl; //Asked Ryan Consell, said to just cout
    }
    //Otherwise, assign spots normally and don't print message
  }
  
  //Output the final parking lot
  output << "<------------|   FINAL PARKING LOT   |------------>"<<endl<<endl;
  output_to_file(output, current_names, current_isStaff); //Call function
  output << "<------------------------------------------------->"<<endl<<endl;
  
  //Close all files to prevent memory leak
  currentIn.close();
  addIn.close();
  removeIn.close();
  output.close();
  
  return EXIT_SUCCESS; //Terimate program
} //DONE!!!

/*
Output to file is in question c)
Output to Console: 

No Spot
No Spot
No Spot
No Spot

--------------------------------
Process exited after 0.09145 seconds with return value 0
Press any key to continue . . .

*/