#ifndef extPersonType_H
#define extPersonType_H

#include "personType.h"
#include "addressType.h"
#include "dateType.h"

class extPersonType: public personType
{
  public:
    void setPhoneNumber (string phoneNumber);
      //this function sets the phone number
      //postcondition: number = phoneNumber
    
    string getPhoneNumber ();
      //this function returns the phone number
      //postcondition: the value of phoneNumber is returned

    void setRelationship (string relationship);
      //this function sets the relationship
      //postcondition: dRelationship = relationship
    
    string getRelationship();
      //this function returns the relationship
      //postcondition: the value of relationship is returned

    int getBirthMonth ();
      //this function gets birth month from dateType function
      //postcondition: the value of birthMonth is returned

    void print();
      //This function prints the values for name (first last)
      //birthdate (mm-dd-yyyy), address (address /n city, state 
      //zipcode), phone number (XXX-XXX-XXXX), and relationship

    extPersonType (string first = "", string last = "", int month = 1, int day = 1, int year = 1900, string address = "", string city = "", string state = "XX", int zipcode = 10000, string phoneNumber = "None", string relationship = "None");

  private: 
    addressType address;
    dateType birthdate;
    string number;
    string dRelationship;

};

#endif