//Jenna Howard

#include <iostream>
#include "addressType.h"

using namespace std;

void addressType::setAddress (string address)
{
  dAddress = address;
}

void addressType::setCity (string city)
{
  dCity = city;
}

void addressType::setState (string state)
{
  if (state.length() > 2)
    dState = "XX";
  else
    dState = state;
}

void addressType::setZipcode (int zipcode)
{
  if (11111 <= zipcode && zipcode <= 99999)
    dZipcode = zipcode;
  else
    dZipcode = 10000;
}

string addressType::getAddress ()
{
  return dAddress;
}

string addressType::getCity()
{
  return dCity;
}

string addressType::getState()
{
  return dState;
}

int addressType::getZipcode()
{
  return dZipcode;
}

void addressType::print()
{
  cout << dAddress << endl;
  cout << dCity << ", " << dState << " " << dZipcode << endl;
}

//constructor with paramaters
addressType::addressType (string address, string city, string state, int zipcode)
{
  dAddress = address;
  dCity = city;

  if (state.length() > 2)
    dState = "XX";
  else
    dState = state;

  if (11111 <= zipcode && zipcode <= 99999)
    dZipcode = zipcode;
  else
    dZipcode = 10000;
}