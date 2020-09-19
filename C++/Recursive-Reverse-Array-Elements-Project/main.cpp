#include <iostream>

using namespace std;

int reverseArray(int[], int, int, int);
//function that reverses the elements of the array between the low
//  and high indices


int main() {
  int length = 10;
  int intArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int low = 3;
  int high = 9;

  //original list printed
  for (int i = 0; i < length; i++)
  {
    cout << intArray[i];
  }
  cout << endl;

  reverseArray(intArray, low, high, length);
  //testing array properly reversed
  for (int i = 0; i < length; i++)
  {
    cout << intArray[i];
  }


  return 0;
}

int reverseArray(int intArray[], int low, int high, int length)
{
  if (intArray[low] == intArray[high])
  {
    return 0;
  }
  else
  {
    int tempInt = intArray[low];
    intArray[low] = intArray[high];
    intArray[high] = tempInt;
    low++;
    high--;
    return reverseArray(intArray, low, high, length);
  }
  
}