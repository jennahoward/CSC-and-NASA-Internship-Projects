#include <iostream>
#include "unorderedArrayListType.h"


using namespace std;

int main() {
  int unorderedArray [12] = {1, 3, 5, 7, 9, 11, 13, 15, 7, 17, 7, 19};
  unorderedArrayListType newList;
  for (int i = 0; i < 12; i++)
  {
    newList.insertEnd (unorderedArray[i]);
  }
  cout << "Testing list is filled properly:  ";
  newList.print();

  cout << endl;

  //testing retrieveAt function
  int length = newList.listSize();
  int location = 3;
  int item =  newList.retrieveAt (location);
  cout << "Testing retrieveAt return value (in bounds, loc. 3): " << location << "   " << item << endl;
  cout << endl;
  cout << "Testing retrieveAt return value (out of bounds): ";
  //commented out to continue testing
  // item = newList.retrieveAt (15);  
  // cout << location << " " << item;     
  cout << endl;


  //testing removeAt function
  //newList.removeAt(3);
  //cout << "Test to removeAt location 3: ";
  //newList.print();
  
  //testing removeAll function
  newList.removeAll(7);
  cout << "Test to remove all 7s from list: ";
  newList.print();

  cout << endl;
  newList.removeAll(2);
  cout << "Test removeAll function, not in list: ";
  newList.print();

 return 0; 
}