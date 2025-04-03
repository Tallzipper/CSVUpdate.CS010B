#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
   
   vector<int> nums;
   int avg = 0;
   string line;
   char temp;

   string inputFile;
   string outputFile;
   
   if(argc != 3)
   {

      cout << "Incorrect number of files";
      return 1;

   }

   // Assign to inputFile value of 2nd command line argument
   // Assign to outputFile value of 3rd command line argument
      inputFile = argv[1];
      outputFile = argv[2];
   
   // Create input stream and open input csv file.
   ifstream inFS;

   cout << "File opening: " << argv[1] << endl;

   inFS.open(inputFile);

   // Verify file opened correctly.
   // Output error message and return 1 if file stream did not open correctly.
   
   if(!inFS.is_open())
   {

      cout << "File " << inputFile << " did not open" << endl;

   }

   // Read in integers from input file to vector.

   while(inFS.get(temp))
   {

      if(temp != ',')
      {

         line += temp;

      }
      else
      {
         
         nums.push_back(stoi(line));
         line = "";

      }

   }

   nums.push_back(stoi(line));
   
   // Close input stream.

   inFS.close();
   
   // Get integer average of all values read in.
      
   for(unsigned int i = 0; i < nums.size(); i++)
   {
      
      avg += nums.at(i);

   }

   avg /= nums.size();
   
   // Convert each value within vector to be the difference between the original value and the average.
   for(unsigned int i = 0; i < nums.size(); i++)
   {
      
      nums.at(i) = nums.at(i) - avg;

   }
   
   // Create output stream and open/create output csv file.

   ofstream ofFS;

   // Verify file opened or was created correctly.

   ofFS.open(outputFile);

   // Output error message and return 1 if file stream did not open correctly.

      if(!ofFS.is_open())
   {

      cout << "File " << outputFile << " did not open" << endl;

   }
   
   // Write converted values into ouptut csv file, each integer separated by a comma.

   for(unsigned int i = 0; i < nums.size()-1; i++)
   {

      ofFS << nums.at(i) << ",";
      cout << nums.at(i) << ",";

   }

      ofFS << nums.back();
      cout << nums.back();

   ofFS.close();
   
   return 0;
}