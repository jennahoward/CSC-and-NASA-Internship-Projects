//Jenna Howard
//Main Input: user input: side lengths; constants: enum triangleType
//    (scalene, isosceles, equilateral, noTriangle)
//    Processing: define enum triangleType; getShape(); printShape()

#include <iostream>

using namespace std;

enum triangleType {scalene, isosceles, equilateral, noTriangle};

//getShape input: input parameters side lengths; processing: 
//    isTriangle(); determine if triangle is scalene, isosceles, 
//    equilateral; output: postcondition return triangleType shape
triangleType getShape (double, double, double);

//isTriangle input: input parameters side lengths; processing: check
//    if 2 sides add up to be greater than 3rd side, return true; if 
//    not, return false; output: postcondition return bool
bool isTriangle (double, double, double);

//printShape input: input parameter triangleType; output: type of 
//    triangle
void printShape (enum triangleType);

int main() 
{
  triangleType shape;
  double side1;
  double side2;
  double side3;
  cout << "Enter three side lengths: ";
  cin >> side1 >> side2 >> side3;

  shape = getShape(side1, side2, side3);
  printShape (shape);
 return 0;
}

triangleType getShape (double side1, double side2, double side3)
{
  triangleType found;
  if (isTriangle (side1, side2, side3) == false)
    found = noTriangle;
  else if (side1 == side2 & side2 == side3)
    found = equilateral;
  else if (side1 == side2 or side2 == side3)
    found = isosceles;
  else
    found = scalene;
  return found;
}

bool isTriangle (double side1, double side2, double side3)
{
  if (((side1 + side2) > side3) & ((side2 + side3) > side1) & ((side1 + side3) > side2))
    return true;
  else
    return false;
}

void printShape (triangleType shape)
{
  if (shape == scalene)
    cout << "The triangle is scalene" << endl;
  else if (shape == isosceles)
    cout << "The triangle is isosceles" << endl;
  else if (shape == equilateral)
    cout << "The triangle is equilateral" << endl;
  else if (shape == noTriangle)
    cout << "this is not a triangle" << endl;
  else 
    cout << "error" << endl;
}