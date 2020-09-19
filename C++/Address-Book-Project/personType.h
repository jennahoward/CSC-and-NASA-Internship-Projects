// personType.h

#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <string>

using namespace std;

class personType
{
public:
    // Getters and setters
    void setFirstName(string);
    void setLastName(string);
    string getFirstName() const;
    string getLastName() const;

    void print() const;
       //Postcondition: outputs the first name and last name
       //in the form firstName lastName.

    personType(string first = "", string last = "");
      //Constructor
      //Sets firstName and lastName according to the parameters.
      //The default values of the parameters are null strings.
      //Postcondition: firstName = first; lastName = last

 private:
    string firstName; //variable to store the first name
    string lastName;  //variable to store the last name
};

#endif
