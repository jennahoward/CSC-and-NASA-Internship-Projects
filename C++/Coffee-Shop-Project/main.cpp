//Jenna Howard
//Main input: User choice from main menu 
//    Processing: while selection is not quit, get selections
//    Output: None

#include <iostream>

using namespace std;

//showMainMenu inputs: none; processing: display menu and prompt
//    output: display menu and prompt
void showMainMenu();

//buyCoffee input: accumulator variables for total small, medium, 
//    large cups sold; precoditions: cost of cup sizes are global
//    Processing: get coffee size and number until select quit, 
//    accumulate counter for each size
//    Output: number of coffees per size requested; postconditions: 
//    update accumulators for size
void buyCoffee (int&, int&, int&);

//showReceipt inputs: number of coffees per size for transaction
//    Preconditions: cost of coffee sizes global; Processing:
//    calculate total per size, then add to total for whole order
//    Output: formatted receipt for current transaction
void showReceipt(int, int, int);

//cupsSold inputs: accumulated totals for each cup size
//    Processing: write the total sold for each size 
//    Output: total sold for each size
void cupsSold (int, int, int);

//coffeeSold inputs: accumulated totals for each cup size;
//    preconditions: number of ounces per size is global
//    Procesing: calculate ounces of each size sold an add to total
//    sold for the day; output: total ounces sold
void coffeeSold (int, int, int);

//totalAmount inputs: accumulated totals for each cup size; 
//    preconditions: cost of each cup size is global
//    processing: calculate total per size and add to total money
//    made today; output: total revenue for the day
void totalAmount (int, int, int);

//Global variable declarations
  const double smallCost = 1.75;
  const double mediumCost = 1.9;
  const double largeCost = 2.0;
  const int smallSize = 9;
  const int mediumSize = 12;
  const int largeSize = 15; 

int main() 
{
  int selection;
  int totalSmall = 0;
  int totalMedium = 0; 
  int totalLarge = 0;

  while (selection != 5)
  {
    showMainMenu();
    cin >> selection; 
    if (selection == 1)
      buyCoffee(totalSmall, totalMedium, totalLarge);
    else if (selection == 2)
      cupsSold(totalSmall, totalMedium, totalLarge);
    else if (selection == 3)
      coffeeSold(totalSmall, totalMedium, totalLarge);
    else if (selection == 4)
      totalAmount(totalSmall, totalMedium, totalLarge);
    else
      cout << "select a number from the menu " << endl;
  }
  return 0;
}

void showMainMenu()
{
  cout << "Main menu: " << endl;
  cout << "1. Buy Coffee (cashier)" << endl;
  cout << "2. Show cups sold (manager)" << endl;
  cout << "3. Show coffee sold in ounces (manager)" << endl;
  cout << "4. Show money made  (manager)" << endl;
  cout << "5. Quit" << endl << endl;
  cout << "Select a number from the menu" << endl;
}

void buyCoffee (int& totalSmall, int& totalMedium, int& totalLarge)
{
  int numSmall = 0;             //for this transaction
  int numMedium = 0;
  int numLarge = 0;
  int coffeeSize = 0;

  while (coffeeSize != 4)
  {
    cout << "1. Small coffee (9 oz.) ............... $1.75" << endl;
    cout << "2. Medium coffee (12 oz.) ............. $1.90" << endl;
    cout << "3. Large coffee (15 oz.) .............. $2.00" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter coffee size: ";
    cin >> coffeeSize;
    if (coffeeSize == 1)
    {
      cout << "Enter number of small coffees:";
      cin >> numSmall;
      totalSmall = totalSmall + numSmall;
    }
    else if (coffeeSize == 2)
    {
      cout << "Enter number of medium coffees: ";
      cin >> numMedium;
      totalMedium = totalMedium + numMedium;
    }
    else if (coffeeSize == 3)
    {
      cout << "Enter the number of large coffees: ";
      cin >> numLarge;
      totalLarge = totalLarge + numLarge;
    }
    else if (coffeeSize == 4)
      break;
    else
      cout << "Enter coffee size: ";
  }
  showReceipt(numSmall, numMedium, numLarge);
}

void showReceipt(int numSmall, int numMedium, int numLarge)
{
  float total = 0;
  float lineItem = 0;
  if (numSmall > 0)
  {
    lineItem = numSmall * smallCost;
    total = total + lineItem;
    cout << numSmall << " small coffees   $" << lineItem << endl;
  }
  if (numMedium > 0)
  {
    lineItem = numMedium * mediumCost;
    total = total + lineItem;
    cout << numMedium << " medium coffees  $" << lineItem << endl;
  }
  if (numLarge > 0)
  {
    lineItem = numLarge * largeCost;
    total = total + lineItem;
    cout << numLarge << " large coffees $" << lineItem << endl;
  }
  cout << "Transaction total: $" << total << endl;
}

void cupsSold (int totalSmall, int totalMedium, int totalLarge)
{
  cout << "Total small coffees sold: " << totalSmall << endl;
  cout << "Total medium coffees sold: " << totalMedium << endl;
  cout << "Total large coffees sold: " << totalLarge << endl;
}

void coffeeSold (int totalSmall, int totalMedium, int totalLarge)
{
  int totalOz = 0;
  totalOz = (totalSmall * smallSize) + (totalMedium * mediumSize) + (totalLarge * largeSize);
  cout << "Total amount of coffee sold: "<< totalOz << " ounces" << endl;
}

void totalAmount (int totalSmall, int totalMedium, int totalLarge)
{
  float totalMoney = 0;
  totalMoney = (totalSmall * smallCost) + (totalMedium * mediumCost) + (totalLarge * largeCost);
  cout << "Total money made today: $" << totalMoney << endl;
}
