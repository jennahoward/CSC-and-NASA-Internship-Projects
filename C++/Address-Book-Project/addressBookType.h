#ifndef ADDRESSBOOKTYPE_H_INCLUDED
#define ADDRESSBOOKTYPE_H_INCLUDED

#include "extPersonType.h"

class addressBookType
{
public:
  void addEntry(extPersonType, int&);
    //this function checks that the length has not exceeded the 
    //  maxLength, adds a new extPersonType entry to the addressList
    //this function should also call sortEntries function each time 
    //   a new entry is added to addressList
    //postcondition: length is incremented

  void findPerson(string);
    //this function finds a person entry given last name and prints 
    //   the entry for the person if found
    //postcondition: output the entry if found in addressList with 
    //  the given last name

  void findBirthdays(int);
    //this function finds a person entry given the month number and 
    //   prints the entry for each person found with that birthmonth
    //postcondition: output the entries found in adressList with the
    //  given birthmonth

  void findRelations(string);
    //this function finds a person entry given the relationship and 
    //   prints the entries for each person with that relationship
    //postconditon: output the entries found in addressList with the 
    //  given relationship

  void print();
    //this function prints all entries in the addressList array

  void sortEntries();
    //this function is called in addEntry and sorts the new entry
    //  compared to the other entries already in the addressList
    //postconditon: updates the location of the new entry

  void initEntries();
    //this function adds an entry to addressList from the file when
    //  called from the menu


private:
  extPersonType newEntry;
  personType person;
  addressType address;
  dateType birthdate;
  extPersonType addressList[500];
  int length;
  int maxLength;
};

#endif