#include <iostream>
#include "unorderedLinkedList.h"
#include "intLinkedList.h"

using namespace std;

int main() 
{
  intLinkedList mainList, evensList, oddsList;

  int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


  for (int i = 0; i < 10; i ++)
  {
    int item = values[i];
    mainList.insertLast(item);
  }

  cout << "Main list after initiating: ";
  mainList.print();
  cout << endl;

  mainList.splitEvensOddsList(evensList, oddsList);
  cout << endl;
  cout << "Main list after processing: ";
  mainList.print();
  



  return 0;
}



