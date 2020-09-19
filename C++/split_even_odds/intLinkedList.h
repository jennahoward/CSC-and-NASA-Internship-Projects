#ifndef H_intLinkedList
#define H_intLinkedList

#include "unorderedLinkedList.h"

#include <iostream>

using namespace std;

class intLinkedList: public unorderedLinkedList<int>
{
  public:
    void splitEvensOddsList (intLinkedList &evensList, intLinkedList &oddsList);
    //This function rearranges the nodes of the linked list so that 
    //    evensList consists of even integers and oddsList consists of
    //    odd integers
    //Postcondition: evensList consists of even integers. oddsList 
    //    consists of odd integers. The original list is empty.

    intLinkedList();
    //constructor

   
};
#endif
