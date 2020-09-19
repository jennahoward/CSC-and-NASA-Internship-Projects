#include <iostream>
#include <fstream>
#include "addressBookType.h"
#include "extPersonType.h"

using namespace std;



void addressBookType::initEntries()
{
  int length = 0;
  ifstream inData;
  inData.open("AddressBookData.txt");
  string name1, name2, address1, address2, address3, phoneNum, relation;
  int zip, bday1, bday2, bday3;

  while (!inData.eof())
  {
    inData >> name1 >> name2;
    inData >> bday1 >> bday2 >> bday3;
    inData.get();
    getline (inData, address1);
    getline (inData, address2);
    inData >> address3;
    inData >> zip;
    inData.get();
    getline (inData, phoneNum);
    inData >> relation;
    extPersonType newEntry (name1, name2, bday1, bday2, bday3, address1, address2, address3, zip, phoneNum, relation);
  
    addEntry(newEntry, length);
  }
  inData.close();
}


void addressBookType::addEntry(extPersonType newEntry, int &length)
{
  maxLength = 500;

  if (length < maxLength)
  {
    addressList[length] = newEntry;
    length ++;
  }
  else
    cout << "Address book full " << endl;
}

void addressBookType::print()
{
  for (int i = 0; i < 6; i++)
  {
    addressList[i].print();
    cout << endl;
  }
}

void addressBookType::findPerson(string lastName)
{
  for (int i = 0; i < 6; i++)
  {
    string foundName = addressList[i].getLastName();
    if (foundName == lastName)
    {
      addressList[i].print();
      cout << endl;
    }
  }
}

void addressBookType::findBirthdays(int month)
{
  for (int i = 0; i < 6; i++)
  {
    int foundMonth = addressList[i].getBirthMonth();
    if (foundMonth == month)
    {
      addressList[i].print();
      cout << endl;
    }
  }
}

void addressBookType::findRelations(string relation)
{
  for (int i = 0; i < 6; i++)
  {
    string foundRelation = addressList[i].getRelationship();
    if (foundRelation == relation)
    {
      addressList[i].print();
      cout << endl;
    }
  }
}

void addressBookType::sortEntries()
{
  int current = 1;
  while (current < 6)
  {
    int index = current;
    bool placeFound = false;
    while (index > 0 && !placeFound)
    {
      if (addressList[index].getLastName() < addressList[index-1].getLastName())
      {
        extPersonType temp = addressList[index];
        addressList[index] = addressList[index-1];
        addressList[index-1] = temp;
        index --;
      }
      else
        placeFound = true;
    }
    current ++;
  }
}



