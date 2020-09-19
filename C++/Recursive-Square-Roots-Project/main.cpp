#include <iostream>
#include <cmath>

using namespace std;

float testRoot (float, float, float);
//recursive test function for square root using Newton's method

int main() {
  float x;
  float a;
  float epsilon = 0.0005;


  //tests for testRoot function
  x = 37;
  a = 5;
  a = testRoot(x, a, epsilon);
  cout << a << " is the square root of " << x << endl;

  x = 4;
  a = 2;
  a = testRoot(x, a, epsilon);
  cout << a << " is the square root of " << x << endl;



  
  return 0;
}

float testRoot (float x, float a, float epsilon)
{

  if (x >= 0 && (abs(pow(a, 2)-x) <= epsilon))
  {
    return a;
  }
  else
  {
    //cout << "testing rounds " << endl;
    return testRoot(x, ((pow(a, 2)+x)/(2*a)), epsilon);
  }
}