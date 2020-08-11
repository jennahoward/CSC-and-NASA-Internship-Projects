#include <iostream>
#include "intLinkedList.h"

using namespace std;

void intLinkedList:: splitEvensOddsList(intLinkedList &evensList, intLinkedList &oddsList)
{ 
  nodeType<int> *current, *evensFirst, *evensLast, *oddsFirst, *oddsLast;
  current = first;
  first = first->link;


  
  while (current != nullptr)
  {
    if (current->info %2 != 0)
    {
      if (oddsList.first == nullptr)
      {
        oddsList.first = current;
        oddsList.last = current;
        oddsList.count ++;
        oddsList.last->link = nullptr;
      }
      else
      {
        oddsList.last->link = current;
        oddsList.last = current;
        oddsList.count ++;
        oddsList.last->link = nullptr;
      }
    }
    else if (current->info%2 == 0)
    {
      if (evensList.first == nullptr)
      {
        evensList.first = current;
        evensList.last = current;
        evensList.count ++;
        evensList.last->link = nullptr;
      }
      else
      {
        evensList.last->link = current;
        evensList.last = current;
        evensList.count ++;
        evensList.last->link = nullptr;
      }
    }
    current = first;
    if (first == nullptr)
    {
      break;
    }
    first = first->link;
  }

  cout << "Evens List: ";
  evensList.print();
  cout << endl;
  cout << "Odds list: ";
  oddsList.print();
  
}

intLinkedList::intLinkedList()
{
  first = nullptr;
  nodeType<int> *last = nullptr;
  nodeType<int> *current = first;
  int count = 0;
};