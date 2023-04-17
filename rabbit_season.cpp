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
#include <iomanip>

using namespace std;

//function to convert time in 24-hour format (HHMM) to minutes after midnight
int time_to_midnight (int time_in_24) //integer parameter and int return type
{
  return ((time_in_24 / 100) * 60) + (time_in_24 % 100); //use formula
}

//function to find distance from x and y coordiates from the origin
double find_distance (int x_cord, int y_cord) //two int paramters
{
  return sqrt(pow(abs(x_cord), 2) + pow(abs(y_cord), 2)); //use pythagorean
  //use abs() to get positive only (absolute distance)
}

//function to find angle from x and y coordiates from the origin
double find_angle (int x_cord, int y_cord) //two int paramters
{
  //Declare variables witin the scope of this function only
  double angle = 0.0; //Initialise angle to be returned by function to 0
  
  //Decisions
  if (y_cord > 0) //If in first or second quadrant (positive y)
  {
    angle = 90 - (atan2(y_cord, x_cord) * 180 / M_PI); //set angle
  }
  
  else if ((y_cord < 0) && (x_cord > 0)) //Otherwise, if in fourth quadrant
  {
    angle = 90 + abs(atan2(y_cord, x_cord) * 180 / M_PI); //set angle
  }
  
  else //Otherwise, if in third quadrant
  {
    angle = abs(atan2(y_cord, x_cord) * 180 / M_PI) - 270; //set angle
  }
  
  return angle; //return the angle back to the main function
}

int main() //main function
{
  //Declare variables
  int time_24 = 0, time_from_midnight = 0, old_time = 0; //ints for time
  int x = 0, y = 0, rabbit_counter = 0; //int for (x, y) and the a counter
  int shortest_time = 24*60; //Initialise the shortest time to max (24 hours)
  double distance_from_origin = 0.0, heading = 0.0;
  
  ifstream input("wascally_wabbits.txt");
  ofstream output("wabbits_output.txt");
  
  if (!input) //If file cannot be opened
  {
    cout <<"ERROR!" << endl; //Output
    return EXIT_FAILURE; //terminate program
  }
  
  while (input >> time_24 >> x >> y)
  {
    rabbit_counter++; //Increment the counter by 1
    time_from_midnight = time_to_midnight(time_24); //convert the time to min
    distance_from_origin = find_distance (x, y); //find the distance
    heading = find_angle (x, y); //find the angle from (x, y)
    
    output << fixed << setprecision(2); //Set precision of 2 decimal places
    
    //Output to text file
    output << "Rabbit #" << rabbit_counter << ": " << distance_from_origin 
           << " meters and " << heading << "° from North." << endl; //message
    
    //Decisions
    if (rabbit_counter > 1) //So long as not first rabbit
    {
      //Nested decisions
      if (shortest_time > (time_from_midnight - old_time)) 
      {
        //If the old shortest time is greater than a new difference
        shortest_time = time_from_midnight - old_time; //Replace this value
      }
      //Otherwise, proceed
    }
    //Otherwise, proceed
    
    old_time = time_from_midnight; //Set a new old time
  }
  
  //Output to text file
  output << "\n\nThe shortest time between rabbits is " << shortest_time 
         << " minutes " << endl; //Output the shortest time
         
  input.close(); //Close the file to prevent memory leak
  output.close(); //Close the file to prevent memory leak
  
  return EXIT_SUCCESS; //Terimate program
}

/*
Output Text File:
Rabbit #1: 47.52 meters and -81.53° from North.
Rabbit #2: 148.66 meters and -42.27° from North.
Rabbit #3: 194.20 meters and 160.45° from North.
Rabbit #4: 118.87 meters and -137.05° from North.
Rabbit #5: 165.01 meters and -41.81° from North.
Rabbit #6: 108.45 meters and -32.96° from North.
Rabbit #7: 206.02 meters and -156.55° from North.
Rabbit #8: 129.71 meters and 25.58° from North.
Rabbit #9: 182.83 meters and 160.18° from North.
Rabbit #10: 62.82 meters and -103.82° from North.
Rabbit #11: 109.18 meters and -61.56° from North.
Rabbit #12: 95.27 meters and 39.04° from North.
Rabbit #13: 115.04 meters and -88.51° from North.
Rabbit #14: 196.70 meters and 137.06° from North.
Rabbit #15: 115.62 meters and -5.96° from North.
Rabbit #16: 109.29 meters and 94.20° from North.
Rabbit #17: 123.04 meters and 97.47° from North.
Rabbit #18: 158.67 meters and 38.60° from North.
Rabbit #19: 227.41 meters and -30.96° from North.
Rabbit #20: 89.54 meters and 159.74° from North.
Rabbit #21: 201.81 meters and 172.31° from North.
Rabbit #22: 119.02 meters and -179.04° from North.
Rabbit #23: 176.65 meters and -26.57° from North.
Rabbit #24: 167.17 meters and 48.39° from North.
Rabbit #25: 60.21 meters and -11.50° from North.
Rabbit #26: 137.24 meters and 161.30° from North.
Rabbit #27: 191.67 meters and -4.79° from North.
Rabbit #28: 128.04 meters and -91.34° from North.
Rabbit #29: 180.89 meters and 19.04° from North.
Rabbit #30: 105.99 meters and 76.36° from North.
Rabbit #31: 114.00 meters and 179.50° from North.
Rabbit #32: 47.07 meters and 167.74° from North.
Rabbit #33: 135.62 meters and 84.50° from North.
Rabbit #34: 166.44 meters and -24.87° from North.
Rabbit #35: 87.92 meters and -123.87° from North.
Rabbit #36: 129.84 meters and 168.00° from North.
Rabbit #37: 137.06 meters and -7.13° from North.
Rabbit #38: 74.65 meters and 50.98° from North.
Rabbit #39: 107.20 meters and -53.34° from North.
Rabbit #40: 61.61 meters and -144.25° from North.


The shortest time between rabbits is 13 minutes 
*/