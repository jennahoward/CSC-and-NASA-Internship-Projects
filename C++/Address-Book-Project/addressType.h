#ifndef ADRESSTYPE_H_INCLUDED
#define ADRESSTYPE_H_INCLUDED

using namespace std;

class addressType
{
public:
  void setAddress (string address);
    //this function sets the address
    //postcondition: dAddress = address
    
  void setCity (string city);
    //this function sets the city
    //postcondition: dCity = address
  
  void setState (string state);
    //this function sets the state, checking for valid value length
    //postcondition: dState = state

  void setZipcode (int zipcode);
    //this function sets the zipcode, checking for valid input value
    //postcondition: dZipcode = zipcode

  string getAddress();
    //this function returns the address
    //postcondition: the value of dAddress is returned

  string getCity ();
    //this function returns the city
    //postcondition: the value of dCity is returned

  string getState ();
    //this function returns the state
    //postconditon: the value of dState is returned

  int getZipcode ();
    //this function returns the value of zipcode
    //postcondition: the value of dZipcode is returned

  void print ();
    //function to output the address on line one, and on the next line
    //output the city, state zipcode in that format

  addressType (string address = "", string city = "", string state = "XX", int zipcode = 10000);
    //this is the constructor with default values assigned
    //postcondition: if no values are given for dAddress, dCity, 
    //  dState, or dZipcode, the default values will be set

private:
  string dAddress;      //variable to store the address
  string dCity;         //variable to store the city
  string dState;        //variable to store the state
  int dZipcode;         //variable to store the zipcode
};

#endif // ADRESSTYPE_H_INCLUDED
