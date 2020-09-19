//Jenna Howard
//main input: none; Processing: declare arrays runnerNames and
//    runnerData, call getNamesMiles, getTotalAverage, 
//    printTable; Output: labels for table


#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

//getNamesMiles input: input file "RunnerData.txt" input 
//    parameters: runnerData, runnerNames; Processing: open 
//    inData file, for each row go into each column and get 
//    input into runnerNames and runnerData
//    Output: postconditions: runnerData and runnerNames updated
void getNamesMiles(int [][9], string []);

//getTotalAverage input: input parameters runnerData; processing: 
//    for each row, add the values for each column to sum, add to 8th
//    value of runnerData, calculate average and store in 9th column of
//    each row; output: postcondition: runnerData updated
void getTotalAverage(int [][9]);

//printTable input: input parameters: runnerData, runnerNames; 
//    Processing: for each row, print runnerNames and runnerData for
//    each column, make sure rows are aligned
//    Output: formatted table
void printTable(int [][9], string[]);

int main() {
  int runnerData[5][9];
  string runnerNames [5];

  getNamesMiles(runnerData, runnerNames);
  getTotalAverage(runnerData);
  cout << "Runner Names       Miles Run Each Day 1-7";
  cout <<  "   Total  Average" << endl;
  printTable(runnerData, runnerNames);

  return 0;
}


void getNamesMiles(int runnerData[][9], string runnerNames[])
{
  ifstream inData;
  inData.open ("RunnerData.txt");

  for (int i = 0; i < 5; i ++)
  {
    inData >> runnerNames[i];
    for (int j = 0; j < 7; j ++)
      inData >> runnerData[i][j];
  }
  inData.close();
}

void getTotalAverage(int runnerData[][9])
{
  int sum;
  for (int i = 0; i < 5; i++)
  {
    sum = 0;
    for (int j = 0; j < 7; j++)
      sum = sum + (runnerData[i][j]);
    runnerData[i][7] = sum;
    int average = sum/7;
    runnerData[i][8] = average;
  }
}


void printTable(int runnerData[][9], string runnerNames[])
{
  for (int i = 0; i < 5; i ++)
  {
    cout << setw(8) << runnerNames[i];
    for (int j = 0; j < 9; j ++)
    {
      cout << setw(5) << runnerData[i][j];
    }
    cout << endl;
  }
}