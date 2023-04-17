/*
Programmers: Shaan Banday (20993610)
Class: ME 101
Date: Wednesday, April 5th, 2023
*/

//Import libraries
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

//Declare global constants
const int MAX_HEIGHT = 200; //Maximum height (i.e., number of rows) for an image
const int MAX_WIDTH = 79; //Maximum width (i.e., number of coloumns) for an image

//Function reads all the symbols and fills the matrix
void read_data(ifstream &fin, char coordinates[MAX_HEIGHT][MAX_WIDTH]) 
{ //void function so no return
  
  //Declare variables within the scope of this function
  int row_num = 0, column_num = 0; //integers to take input for the coordiates of the symbol
  char input_symbol = ' '; //char for the read in symbol
  
  //While there are lines to read, keep running loop
  while(fin >> row_num >> column_num >> input_symbol) //take the input in order
  {
    //Set the symbol in the matrix to what has been read 
    coordinates[row_num][column_num] = input_symbol; 
  }
  //once all data is read, return to main function
}

//Function to print out the ASCII Art
void print_art(char coordinates[MAX_HEIGHT][MAX_WIDTH], int art_height)
{ //void function so no return
  
  //Loops
  for(int row_num = 0; row_num < art_height; row_num++) 
  { //Start at 0 and iterate for every row until the height of the image
    
    //Nested Loops
    for(int column_num = 0; column_num < MAX_WIDTH; column_num++) 
    { //Start at 0 and iterate for every coloumn until the maximum
      
      //Decisions
      if(coordinates[row_num][column_num] == ' ') //If the symbol at that coordiate is empty
      {
        cout << " "; //print a space to the console
      }
      
      else //Otherwise, if the symbol is anything else
      {
        cout << coordinates[row_num][column_num]; //Print that symbol at the specified coordiate
      }
    }
    cout << endl; //go to new line after the art is produced
  }
}

//Function to initialise matrix as to empty chars
void empty_matrix(char coordinates[MAX_HEIGHT][MAX_WIDTH])
{ //void function so no return

  //Loops
  for (int i = 0; i < MAX_HEIGHT; i++) //Start at 0 and iterate through the rows
  {
    for (int j = 0; j < MAX_WIDTH; j++) //Start at 0 and iterate through the columns
    {
      coordinates[i][j] = ' '; //Set the symbol at at the specified coordiates to an empty char
    }
  }
}

int main() //Main function, entry point of program
{
  //Declare variables within the scope of this function
  string art_file_name = " "; //String to hold the file name
  int height_of_image = 0; //integer to hold the height of the image
  char symbols[MAX_HEIGHT][MAX_WIDTH]; //matrix for the symbols as individual chars 
  
  empty_matrix(symbols); //Initilaise matrix with empty chars
  
  //Prompt user for file name
  cout << "Enter the name of the file you want to be turned into art: ";
  cin >> art_file_name; //Take in user input as string
  ifstream input(art_file_name.c_str()); //Convert to c-style string
  
  //Decisions
  if (!input) //If the file cannot be opened
  {
    cout <<"ERROR! File not found or could not be opened." << endl;
    return EXIT_FAILURE; //Program terminates on return statement
  }
  //Otherwise, if there are no issues with the file, proceed
  
  //Read in initial data
  input >> height_of_image; //Read first line, which gives height of art
  read_data(input, symbols); //Call the read_data function to read the rest of the lines

  //Create art
  print_art(symbols, height_of_image); //Call the print_art function to create the art
  
  input.close(); //Close the file to prevent memory leak
  
  return EXIT_SUCCESS; //Terimate program
}

/*
OUTPUT 1: 
Enter the name of the file you want to be turned into art: mickey_mapped.txt
                            _____
                        .d88888888bo.
                      .d8888888888888b.
                      8888888888888888b
                      888888888888888888
                      888888888888888888
                       Y8888888888888888
                 ,od888888888888888888P
              .'`Y8P'```'Y8888888888P'
            .'_   `  _     'Y88888888b
           /  _`    _ `      Y88888888b   ____
        _  | /  \  /  \      8888888888.d888888b.
       d8b | | /|  | /|      8888888888d8888888888b
      8888_\ \_|/  \_|/      d888888888888888888888b
      .Y8P  `'-.            d88888888888888888888888
     /          `          `      `Y8888888888888888
     |                        __    888888888888888P
      \                       / `   dPY8888888888P'
       '._                  .'     .'  `Y888888P`
          `"'-.,__    ___.-'    .-'
         jgs  `-._````  __..--'`


--------------------------------
Process exited after 10.63 seconds with return value 0
Press any key to continue . . .




OUTPUT 2:
Enter the name of the file you want to be turned into art: homer_mapped.txt
                             __
                   _ ,___,-'",-=-.
       __,-- _ _,-'_)_  (""`'-._\ `.
    _,'  __ |,' ,-' __)  ,-     /. |
  ,'_,--'   |     -'  _)/         `\
,','      ,'       ,-'_,`           :
,'     ,-'       ,(,-(              :
     ,'       ,-' ,    _            ;
    /        ,-._/`---'            /
   /        (____)(----. )       ,'
  /         (      `.__,     /\ /,
 :           ;-.___         /__\/|
 |         ,'      `--.      -,\ |
 :        /            \    .__/
  \      (__            \    |_
   \       ,`-, *       /   _|,\
    \    ,'   `-.     ,'_,-'    \
   (_\,-'    ,'\")--,'-'       __\
    \       /  // ,'|      ,--'  `-.
     `-.    `-/ \'  |   _,'         `.
        `-._ /      `--'/             \
-hrr-      ,'           |              \
          /             |               \
       ,-'              |               /
      /                 |             -'


--------------------------------
Process exited after 4.116 seconds with return value 0
Press any key to continue . . .




OUTPUT 3:
Enter the name of the file you want to be turned into art: free_kashmir_mapped.txt
ERROR! File not found or could not be opened.

--------------------------------
Process exited after 25.94 seconds with return value 1
Press any key to continue . . .
*/