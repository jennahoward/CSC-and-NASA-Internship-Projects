#include <iostream>
#include "addressBookType.h"

using namespace std;

int main()
{
  int choice = 0;
  string relation;
  string lastName;
  int birthMonth;
  addressBookType newEntry;

  do
  {
    cout << "MAIN MENU" << endl;
    cout << endl;
    cout << "Select an option " << endl;
    cout << "1 - Get entries from data file" << endl;
    cout << "2 - Find entry by last name" << endl;
    cout << "3 - Find entry by birth month" << endl;
    cout << "4 - Find entry by relationship" << endl;
    cout << "5 - Print entire address book" << endl;
    cout << "6 - Quit" << endl;
    cin >> choice;

    switch (choice)
    {
      case 1:
        newEntry.initEntries();
        newEntry.sortEntries();
        break;
      case 2:
        cout << "Enter last name: ";
        cin >> lastName;
        newEntry.findPerson(lastName);
        break;
      case 3:
        cout << "Enter birth month: ";
        cin >> birthMonth;
        newEntry.findBirthdays(birthMonth);
        break;
      case 4:
        cout << "Enter relationship: ";
        cin >> relation;
        newEntry.findRelations(relation);
        break;
      case 5:
        newEntry.print();
        break;
      case 6:
        break;
      default:
        cout << "Invalid choice" << endl;
    }
  } while (choice != 6);




  return 0;
}

