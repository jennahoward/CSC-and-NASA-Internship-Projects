//Jenna Howard

//Implementation file date

#include <iostream>
#include "dateType.h"

using namespace std;

void dateType::setDate(int month, int day, int year)
{
  if (year >= 1900)
    dYear = year;
  else
    dYear = 1900;

  if (1 <= month && month < 12)
    dMonth = month;
  else 
    dMonth = 1;
  
  if (1 <= day && day <= 28)
  {
    dDay = day;
  }
  else if (day == 29)
  {
    if (month == 2 && isLeapYear(year))
      dDay = day;
    else if (month != 2)
      dDay = day;
    else
      dDay = 1;
  }
  else if ((day == 30) && ((month == 4) || (month == 5) || (month == 6) || (month == 9) || (month == 11)))
  {
    dDay = day;
  }
  else if ((day == 31) && ((month == 1) || (month == 3) || (month == 7) || (month == 8) || (month == 10) || (month == 12)))
  {
    dDay = day;
  }
  else 
    dDay = 1; 
}

int dateType::getDay() const
{
    return dDay;
}

int dateType::getMonth() const
{
    return dMonth;
}

int dateType::getYear() const
{
    return dYear;
}

void dateType::print() const
{
    cout << dMonth << "-" << dDay << "-" << dYear;
}

bool dateType::isLeapYear(int year)
{
  if ((year % 4 == 0) && (year %100 == 0))
    return true;
  else if ((year %100 == 0) && (year %400 == 0))
    return true;
  else if (year %400 == 0)
    return true;
  else
    return false;
}

//Constructor with parameters
dateType::dateType(int month, int day, int year)
{
  dateType::setDate(month, day, year);
  dMonth = month;
  dDay = day;
  dYear = year;

}

