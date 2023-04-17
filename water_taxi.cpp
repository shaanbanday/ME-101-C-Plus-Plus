/*
Programmers: Shaan Banday and Saleem Mohammed Ali
Student #s: 20993610 and 21033947
Class: ME 101
Date: Wednesday, February 8th, 2023
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() //main function
{
  //Declare variables
  bool is_vip = false; //boolean to store whether the customer is a VIP
  int num_of_stops = 0, trip_number = 0; //number of stops and the trip number
  double old_x = 0.0, old_y = 0.0; //x and y-cordinates initialsed to (0,0)
  double customer_distance = 0.0, customer_cost = 0.0; //dist and $ for one trip
  double cumulative_distance = 0.0, cumulative_cost = 0.0; //Total dist and $
  double longest_trip = 0.0, cheapest_trip = 100000.0; //longest trip and less $
  
  //Declare Constants
  const int COST_PER_STOP = 15; //Integer constant for the price per stop
  const double COST_PER_KM = 2.6, DISCOUNT = 0.75; //distance price and discount
 
  //File IO
  ifstream input("taxi.txt"); //Read from text file
  ofstream output("taxi_output.txt"); //Output results to different text file
  
  //Decisions
  if (!input) //If the file cannot be opened or is not found
  {
    cout <<"ERROR! File not found or could not be opened." << endl; //Output
    return EXIT_FAILURE; //Program terminates on return statement
  }
  //Otherwise, if there are no issues with the file, proceed
  
  //Output to text file
  output << "trip#" << setw(6) << "VIP" << setw(8) << "stops" << setw(10)
         << "tripDist" << setw(12) << "tripCost" << setw(14) << "totalDist"
         << setw(14) << "totalCost" << endl; //All of the headings
  
  //Loops
  while (input >> is_vip >> num_of_stops) //So long as there are lines to read
  {
    trip_number++; //Increase the trip number increment
    
    //Reset variables for coordinates and distances for a singular trip
    old_x = 0.0, old_y = 0.0, customer_distance = 0.0, customer_cost = 0.0;
    
    //Declare temporary variables whose scope is limited to the loop
    double new_x = 0.0, new_y = 0.0; //temporary x and y-coordinate
    
    //Nested Loops
    for (int i = 0; i < num_of_stops; i++) //Start at 0 and run for every stop
    {
      input >> new_x >> new_y; //take in input for new coordinates
      
      //Calculate distance using cartesian plane distance formula [1]
      customer_distance += (sqrt(pow(new_x - old_x, 2) 
                        + pow(new_y - old_y, 2)));
      
      old_x = new_x; //Replace the old x-coordinate with the new one
      old_y = new_y; //Replace the old y-coordinate with the new one
    }
    
    //Calculate distance back to the main dock using pythagorean theorem [2]
    customer_distance += sqrt(pow(new_x, 2) + pow(new_y, 2));
    
    //Decisions
    if (is_vip) //If the customer is a VIP
    {
      //Calculate the cost and add a 25% discount (i.e. 75% of original price)
      customer_cost = ((COST_PER_STOP * num_of_stops)
                      + (COST_PER_KM * customer_distance)) * DISCOUNT;
    }
    
    else //Otherwise, if the customer is NOT a VIP
    {
      //Calculate the default cost at the non-discounted rate
      customer_cost = ((COST_PER_STOP * num_of_stops)
                      + (COST_PER_KM * customer_distance));
    }
    
    //If this current trip is longer than any previous run
    if (customer_distance > longest_trip) 
    {
      longest_trip = customer_distance; //update the longest trip 
    } 
    //Otherwise, if it is not longer, proceed
    
    //If this current trip is cheapter than any previous run
    if (customer_cost < cheapest_trip)
    {
      cheapest_trip = customer_cost; //update the cheapest trip 
    }
    //Otherwise, if it is not cheaper, proceed
    
    //Add the current trip distance and cost to the cumulative totals
    cumulative_distance += customer_distance;
    cumulative_cost += customer_cost;
    
    //If first 4 trips or any 10th number after that (14, 24, 34, etc.)
    if ((trip_number < 5) || ((trip_number % 10) == 4))
    {
      //Output to text file
      output << setw (5) << trip_number << setw(6) << is_vip << setw(8) 
             << num_of_stops << setw(10) << customer_distance << setw(12) 
             << customer_cost << setw(14) << cumulative_distance << setw(14) 
             << cumulative_cost << endl; //all information in line with headings
    }
  }
  //end of loop, whole file has been read
  
  //Output auxillary results to the text file. Set a precision of 2 decimals
  output << fixed << setprecision(2) << "\n\nThe total distance travelled this" 
         << " year: " << cumulative_distance << " km." << endl;
         
  //Output the total amount of money collected this year 
  output << "Total money collected this year: $" 
         << cumulative_cost << "." << endl;
  
  //Output the distance of the longest trip
  output << "The distance of the longest trip: " << longest_trip 
         << " km." << endl;
  
  //Output the cost of the cheapest trip
  output << "The cost of the cheapest trip: $" << cheapest_trip 
         << "." << endl;
  
  input.close(); //Close the file to prevent memory leak
  output.close(); //Close the file to prevent memory leak
  
  return EXIT_SUCCESS; //Terimate program
}
/*
Source 1: https://www.khanacademy.org/math/geometry/hs-geo-analytic-geometry/hs-
geo-distance-and-midpoints/a/distance-formula

Source 2: https://www.mathsisfun.com/pythagoras.html

Output Text File:
trip#   VIP   stops  tripDist    tripCost     totalDist     totalCost
    1     1       3     79.04     187.878         79.04       187.878
    2     1       2   31.7743     84.4598       110.814       272.338
    3     1       2   54.4844     128.744       165.299       401.082
    4     0       2   38.5364     130.195       203.835       531.277
   14     0       2   41.7669     138.594       779.706       2110.52
   24     1       2    23.382     68.0949       1164.26       3165.84
   34     1       3   47.7955     126.951       1611.53       4493.02
   44     1       1   30.4237     70.5762       1994.55       5514.79
   54     0       1      12.2       46.72       2350.84       6574.64
   64     1       2   59.3388     138.211       2741.71       7795.86
   74     1       2   45.4433     111.114       3334.51       9405.97
   84     0       3    62.217     206.764       3827.99       10848.4
   94     0       2   51.9282     165.013        4254.2       12236.9
  104     1       2   31.1584     83.2589       4573.17       13207.3
  114     1       2   21.6514     64.7202       5019.27       14419.6
  124     0       3   45.0124     162.032        5416.5       15732.1
  134     0       3   41.7533     153.559       5831.01       16937.3
  144     1       1    26.711     63.3365       6236.37       18076.8
  154     1       2   35.9468     92.5962       6590.45       19148.1
  164     0       2   28.1285     103.134       7040.69       20537.2
  174     1       2   47.6906     115.497       7446.53       21762.7
  184     1       3   68.9634     168.229       7862.67         23051
  194     0       2   29.7563     107.366       8216.36       24147.9
  204     0       2   24.7937     94.4636       8635.04       25413.1
  214     0       1    33.669     102.539       9052.65       26741.9
  224     0       1   25.4629     81.2036       9450.12       28081.1


The total distance travelled this year: 9560.80 km.
Total money collected this year: $28405.88.
The distance of the longest trip: 126.41 km.
The cost of the cheapest trip: $19.14.
*/