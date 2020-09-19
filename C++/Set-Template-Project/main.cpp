#include <iostream>
#include "unorderedSetType.h"

using namespace std; 

int main()
{
  int unorderedInt [12] = {1, 3, 5, 7, 9, 11, 13, 15, 7, 17, 7, 19};
  int unorderedInt2 [12] = {2, 4, 6, 8, 9, 10, 12, 14, 15, 16, 18, 20};
  int unorderedInt3[100];
  string unorderedStr [6] = {"Jenna", "Lindsay", "Howard", "Nova", "Chris", "Howard"};
  string unorderedStr2 [6] = {"Nova", "Welker", "Nala", "Becky", "Luna", "Mia"};
  string unorderedStr3 [100];


  //testing for insertEnd/filling sets
  unorderedSetType<int> newIntSet;
  for (int i = 0; i < 12; i++)
  {
    newIntSet.insertEnd(unorderedInt[i]);
  }
  cout << "Testing insertEnd function for no duplicates (integers): " << endl;
  newIntSet.print();
  cout << endl;
  
  unorderedSetType<int> newIntSet2;
  for (int i = 0; i < 12; i ++)
  {
    newIntSet2.insertEnd(unorderedInt2[i]);
  }
  cout << "Testing integer set 2: " << endl;
  newIntSet2.print();
  cout << endl;

  unorderedSetType<int> newIntSet3;
  
  //testing for integer set union

  newIntSet3 = newIntSet + newIntSet2;
  cout << "Integer set union: " << endl;
  newIntSet3.print();
  cout << endl;

  //testing for integer set intersection
  newIntSet3 = newIntSet - newIntSet2;
  cout << "Integer set intersection: " << endl;
  newIntSet3.print();
  cout << endl;
  

  //testing for string insertEnd/filling sets
  unorderedSetType<string> newStringSet;
  for (int i = 0; i < 6; i ++)
  {
    newStringSet.insertEnd(unorderedStr[i]);
  }
  cout << "Testing insertEnd function for no duplicates (strings): " << endl;;
  newStringSet.print();
  cout << endl;

  unorderedSetType<string> newStringSet2;
  for (int i = 0; i < 6; i ++)
  {
    newStringSet2.insertEnd(unorderedStr2[i]);
  }
  cout << "Testing string set 2: " << endl;
  newStringSet2.print();
  cout << endl;

  //testing for string set union
  unorderedSetType <string> newStringSet3;
  newStringSet3 = newStringSet + newStringSet2;
  cout << "String set union test: " << endl;
  newStringSet3.print();
  cout << endl;

  //testing for string set intersection
  newStringSet3 = newStringSet - newStringSet2;
  cout << "String set intersection test: " << endl;
  newStringSet3.print();
  cout << endl;

    
  //testing insertAt unique item, duplicate item (Integers)
  newIntSet.insertAt(3, 21);
  cout << "Testing insertAt function (non-duplicate, integer 21 in 3): " << endl;
  newIntSet.print();
  cout << endl;
  newIntSet.insertAt(1, 7);
  cout << "Testing insertAt function (duplicate, integer 7 in 1): " << endl;
  newIntSet.print();
  cout << endl;

  //testing insertAt unique item, duplicate item (strings)
  newStringSet.insertAt(1, "Robert");
  cout << "Testing insertAt function (non-duplicate, string robert in 1): " << endl;
  newStringSet.print();
  cout << endl;
  newStringSet.insertAt(3, "Jenna");
  cout << "Testing insertAt function (duplicate, string jenna in 3): " << endl;
  newStringSet.print();
  cout << endl;

  //testing replaceAt unique and duplicate items (integers)
  newIntSet.replaceAt(2, 81);
  cout << "Testing replaceAt function (unique, int 81 in 2): " << endl;
  newIntSet.print();
  cout << endl;
  newIntSet.replaceAt(8, 21);
  cout << "Testing replaceAt function (duplicate, int 21 in 8): " << endl;
  newIntSet.print();
  cout << endl;

  //testing replaceAt function for unique and duplicate items (string)
  newStringSet.replaceAt(0, "Loren");
  cout << "Testing replaceAt function (unique, string loren in 0)" << endl;
  newStringSet.print();
  cout << endl;
  newStringSet.replaceAt(2, "Nova");
  cout << "Testing replaceAt function (duplicate, string nova in 2): " << endl;
  newStringSet.print();
  cout << endl;
  



	return 0;
}
