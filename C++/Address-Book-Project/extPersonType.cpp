#include <iostream>
#include "extPersonType.h"
#include "addressType.h"
#include "dateType.h"

using namespace std;

void extPersonType::setPhoneNumber (string phoneNumber)
{
  number = phoneNumber;
}

string extPersonType::getPhoneNumber ()
{
  return number;
}

void extPersonType::setRelationship (string relationship)
{
  if (relationship == "Friend" || relationship == "Family" || relationship == "Business")
    dRelationship = relationship;
  else
    dRelationship = "None";
}

string extPersonType::getRelationship()
{
  return dRelationship;
}

int extPersonType::getBirthMonth()
{
  int birthMonth = birthdate.getMonth();
  return birthMonth;
}

void extPersonType::print()
{
  personType::print();
  cout << endl;
  address.print();
  cout << number << endl;
  cout << "Birthday: ";
  birthdate.print();
  cout << endl;
  cout << "Relationship: " << dRelationship << endl;
}

extPersonType::extPersonType (string first, string last, int month, int day, int year, string address, string city, string state, int zipcode, string phoneNumber, string relationship) : personType (first, last), address (address, city, state, zipcode), birthdate (month, day, year)
{
  number = phoneNumber;
  if (relationship == "Friend" || relationship == "Family" || relationship == "Business")
    dRelationship = relationship;
  else
    dRelationship = "None";
}