//Jenna Howard

#include <iostream>
#include <iomanip>        //for setw in display
#include <cstdlib>        //for randomizer
#include <ctime>         //for randomizer
#include <stdlib.h>      //for sysclr
#include <unistd.h>     //for usleep

using namespace std;

const int row = 4;           //change this value to change board size
struct cardType
{
  int value;            //list of values, set of 2
  int isFull;           // either 0 (has no value) or 1 (has value)
  int state;            //either 0 (face down) or 1 (face up)
};


void displayRules();
cardType initializeBoard(cardType [][row]);
cardType faceUp(cardType [][row]);
cardType faceDown(cardType [][row]);
void displayBoard(cardType [][row]);
void convert(char, int, char, int, int[], int[]);
bool verifyMatch(cardType[][row], int[], int[]);
cardType dummyBoard(cardType[][row]);
cardType getUserInput(cardType [][row], int&); 
bool verifyOver(cardType[][row]);


int main() {  
  cardType board[row][row];
  int player1pts = 0;
  int player2pts = 0;
  
  displayRules();
  //dummyBoard(board);
  initializeBoard(board);
  //faceUp(board);
  //displayBoard(board);
  //board[2][2].state = 0;
  //board[3][3].state = 0;
  faceDown(board);
  displayBoard(board);
  bool gameOver = verifyOver(board);

  while (gameOver == false)
  {
    cout << "Player 1: ";
    getUserInput(board, player1pts);
    cout << "Player 2: ";
    getUserInput(board, player2pts);
    cout << "Player 1 points: " << player1pts << "  Player 2 points: " << player2pts << endl;
    gameOver = verifyOver(board);

  }

  if (player1pts > player2pts)
    cout << "Player 1 wins!" << endl;
  else if (player1pts == player2pts)
    cout << "It's a tie!" << endl;
  else
    cout << "Player 2 wins!" << endl;
  
  return 0;
}

void displayRules()
{
  cout << "MEMORY GAME " << endl;
  cout << endl;
  cout << "To play this game: " << endl;
  cout << "Each player can select 2 cards. To select each card, enter the location of the cards, separated by a space (for example: A1 B3).  If there is a match, you get 1 point. If not, the cards are turned back over and no points are added or removed. Try to remember the cards that have been displayed, especially when they were wrong pairs!" << endl;
  cout << "The player with the most correct matches wins the game! " << endl;
  cout << endl;
}

cardType initializeBoard(cardType board [][row])
{
  int numCards = row * row;
  int pairs = numCards/2;

  for (int x = 0; x < row; x++)           //initalize board to empty
    for (int y = 0; y < row; y++)
      board[x][y].isFull = 0;

  srand(time(0));

  for (int num = 1; num <= pairs; num ++)     //initalize random board
  {
    int i = rand() % row;      //get random row & col numbers to                                   place num from 1-8 into
    int j = rand() % row; 

    if (board[i][j].isFull == 0)
    {
      board[i][j].value = num;
      board[i][j].isFull = 1;
    }
    else
    {
      while (board[i][j].isFull == 1)
      {
        i = rand() % row;
        j = rand() % row;
        if (board[i][j].isFull == 0)
        {
          board[i][j].value = num;
          board[i][j].isFull = 1;
          break;
        }
      }
    }
  }

  for (int num = 1; num <= pairs; num ++)     //2nd loop for 2nd pair
  {
    int i = rand() % row; 
    int j = rand() % row; 

    if (board[i][j].isFull == 0)
    {
      board[i][j].value = num;
      board[i][j].isFull = 1;
    }
    else
    {
      while (board[i][j].isFull == 1)
      {
        i = rand() % row;
        j = rand() % row;
        if (board[i][j].isFull == 0)
        {
          board[i][j].value = num;
          board[i][j].isFull = 1;
          break;
        }
      }
    }
  }


  return board[row-1][row-1];
}


cardType faceUp(cardType board [][row])      //use to display board w/ cards up
{
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < row; j++)
      board[i][j].state = 1;
  }
  return board[row-1][row-1];
}


cardType faceDown(cardType board[][row])    //use to display board w/ cards face down
{
  for (int i = 0; i < row; i++)
    for (int j = 0; j < row; j++)
      board[i][j].state = 0;
  return board[row-1][row-1];
}

void displayBoard(cardType board[][row])     //write board
{
  cout << " " << setw(5) << "A" << setw(5) << "B" << setw(5) << "C" << setw(5) << "D" << endl;
  for (int i = 0; i < row; i++)
  {
    cout << i + 1;
    for (int j = 0; j < row; j++)
    {
      if (board[i][j].state == 0)
        cout << setw(5) << "*";
      else
        cout << setw(5) << board[i][j].value;
    }
    cout << endl;
  }
}


cardType getUserInput(cardType board[][row], int& player1pts)
{
  char card1col, card2col;
  int card1row, card2row;
  int card1[2];
  int card2[2];
  bool match;

  cout << "Enter the locations of the two cards you want to see: ";
  cin >> card1col >> card1row >> card2col >> card2row;

  convert(card1col, card1row, card2col, card2row, card1, card2);

  while (card1[0] > 3 or card1[1] > 3 or card2[0] > 3 or card2[1] > 3)
  {
    cout << "Invalid entry, enter the locations of the two cards you want to see: ";
    cin >> card1col >> card1row >> card2col >> card2row;
    convert (card1col, card1row, card2col, card2row, card1, card2);
  }

  while (board[card1[0]][card1[1]].state ==1 or board[card2[0]][card2[1]].state == 1)
  {
    cout << "Invalid entry, enter the locations of the two cards you want to see: ";
    cin >> card1col >> card1row >> card2col >> card2row;
    convert (card1col, card1row, card2col, card2row, card1, card2);
  }

  match = verifyMatch(board, card1, card2);
  if (match == false)
  {
    board[card1[0]][card1[1]].state = 1;
    board[card2[0]][card2[1]].state = 1;
    displayBoard(board);
    cout << "NO MATCH" << flush;
    usleep(3000000);
    system ("clear");
    board[card1[0]][card1[1]].state = 0;
    board[card2[0]][card2[1]].state = 0;
    displayBoard(board);
  }
  else 
  {
    board[card1[0]][card1[1]].state = 1;
    board[card2[0]][card2[1]].state = 1;
    displayBoard(board);
    cout << "THEY MATCH" << endl;
    player1pts++;
  }

  return board[row-1][row-1];
}



void convert(char card1col, int card1row, char card2col, int card2row, int card1[], int card2[])
{
  if (card1col == 'A')
    card1[1]=0;
  else if (card1col == 'B')
    card1[1] = 1;
  else if (card1col == 'C')
    card1[1] = 2;
  else if (card1col == 'D')
    card1[1] = 3; 
  else 
    card1[1] = 4;

  card1[0] = card1row - 1;

   if (card2col == 'A')
    card2[1] = 0;
  else if (card2col == 'B')
    card2[1] = 1;
  else if (card2col == 'C')
    card2[1] = 2;
  else if (card2col == 'D')
    card2[1] = 3; 
  else
    card2[1] = 4;

  card2[0] = card2row - 1; 
}

bool verifyMatch (cardType board[][row], int card1[], int card2[])
{
  bool match;
  if (board[card1[0]][card1[1]].value == board[card2[0]][card2[1]].value)
    match = true;
  else
    match = false;
  return match;
}


cardType dummyBoard(cardType board[][row])
{
  board[0][0].value = 1;
  board[0][1].value = 1;
  board[0][2].value = 2;
  board[0][3].value = 2;
  board[1][0].value = 3;
  board[1][1].value = 3;
  board[1][2].value = 4;
  board[1][3].value = 4;
  board[2][0].value = 5;
  board[2][1].value = 5;
  board[2][2].value = 6;
  board[2][3].value = 6;
  board[3][0].value = 7;
  board[3][1].value = 7;
  board[3][2].value = 8;
  board[3][3].value = 8;


  return board[row-1][row-1];
}


bool verifyOver(cardType board[][row])
{
  for (int i = 0; i < row; i ++)
  {
    for (int j = 0; j < row; j ++)
    {
      if (board[i][j].state == 0)
        return false;
    }  
  }
  return true;
}
