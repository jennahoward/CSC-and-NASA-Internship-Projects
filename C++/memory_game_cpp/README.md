<h2>Overview</h2>

This project was made in my CSC 201 course which focused on introducing algorithms and problem-solving methods in the C++ language. This project shows an understanding of elementary data structures such as records (structs) and arrays, as well as utilization of unit and integration testing techniques. The development workflow that I used for this project was oriented around getting feedback quickly and iterating over small sections of the project. I built on top of what I had created to make a well-rounded final product. 

<h2>Project Description</h2>

This Memory Game Project is based on the children's game where a deck of cards, containing sets of matching pairs, is shuffled and placed face down on a table. The players take turns flipping over two cards at a time. If the cards match, they are left face up. If they don't match, the cards are flipped back over. As players choose their pairs of cards, they should be trying to use their memory to remember the configuration of the board. The game ends when all of the cards are face up. 

In my implementation of this game, I have the game set to allow for two players, and I keep track of the number of correct guesses each player makes. A winner is announced at the end of the game. I used a two-dimensional array of 4 rows and 4 columns for a deck of 16 cards with 8 matching pairs. The cards are marked with numbers 1 through 8. The main tasks for creating this project are to:
<ol>
  <li>Start the game:
    <ol>
    <li>Display the rules</li>
    <li>Initialize the game board with cards placed at random</li>
      <li>Display the initialized game board, with all cards face down</li>
    </ol>
  </li>
<li>Play the game:
  <ol>
    <li>Get and validate player input</li>
    <li>Temporarily update the state of each card</li>
    <li>Temporarily display the updated game board for 3 seconds</li>
    <li>Verify a match and update the permanent state of the game board</li>
    <li>Display the permanent game board</li>
    <li>Update the points for the players</li>
    <li>Determine if the game is over</li>
  </ol>
  </li>
<li>End the game:
  <ol>
    <li>Display the total points for each player and specify the winner</li>
  </ol>
  </li>
  </ol>

The approach to create this project had four parts: 
1. Initialize and display the game board (plus unit test)
2. Get and validate user input, check temporary state of the board, transition to permanent state of the board (plus unit test)
3. Check scoring and game over (plus unit test)
4. Put these components together and perform integration test

<h2>Walk-through of Project Creation</h2>

<h3>Part 1: Initialize and display the game board</h3>

The computer needs to keep track of at least two pieces of information about each card: the value of the card (an integer between 1 and 8) and its state (face up or face down). Because of this, I created an array that utilized a struct with at least these two fields. The approach that I used to initialize the board was to loop twice through the 8 values and generate random row and column indexes. If the generated location is unoccupied, then it stores the values and the loop ends. Otherwise, the loop continues until an unoccupied location is randomly generated. For this reason, I added a third field to the struct that contained a value indicating if the location is occupied or not. 

Another function that I created at this stage was <code>displayBoard</code>. To ensure that the board could be displayed in both it's face down and face up states, I created functions for each that could change the state of each card accordingly. I also needed to pay close attention to how the board would look to the end-user. To make the board easier to view and make calls to specific locations, I used formatting techniques to have the columns labeled with letters and the rows labeled with numbers. I also chose to display the face-down cards as an asterisk (*). 

I also created the <code>displayRules</code> function which explained the game play and rules to the players. 

Unit testing for this part of the project involved creating a driver that would initialize the board, utilize the display function to show the values in the array face up, and allow for the board to be displayed as either face up or face down. This tests that the board can be initialized randomly, can display properly, and that the board can be displayed all face down as necessary as well. 

<h3>Part 2: Get and validate user input, update state of board</h3>

This section mainly focused on getting user input, validating that it was within the bounds of the board, and updating the state of the board. Each input should include two card locations that are within bounds. If the input is out of bounds or invalid (e.g. the card is already face up), a validation loop is employed to inform the user of the problem and ask the user to re-enter the input until the input is acceptable. A <code>convert</code> function is used to change the user input from the A1, A2 format to proper computer indexing format (locations [0][0] and [0][1]). 

A harder part of the section was figuring out the temporary and permanent updates to the state of the board. A match was determined using the bool-returning <code>verifyMatch</code> function. If a match was found, the players were notified of the match and the state of the cards was changed to face up. If a match was not found, “no match” was displayed, and the state of the cards was changed to face up for only three seconds before clearing the screen. Once the temporary board was cleared, the state of the cards was changed back to face down and the updated permanent state of the board was displayed. 

The unit testing for this part involved initializing the board to a dummy board configuration of my creation. This allowed me to test several cases while knowing where all of the cards are. I made sure to test for input that was out of bounds, cards that were already face up, multiple invalid entries in a row (testing the validation loop), cards that match and cards that do not match. 

<h3>Part 3: Check scoring and game over</h3>

This section determines when the game is over by checking if all cards are face up. It also introduces the scoring for the two-player game. The scoring keeps track of the score throughout the game and is printed after each round. It is also printed at the end of the game with a simple comparison made to determine the winner of the game. 

The <code>verifyOver</code> function iterates through and checks the state of each card location and returns true only if all cards are set to a face up state. If any card is face down still, it returns false and the game continues. This section also introduces the back-and-forth nature of the game, where players each take turns to enter input until the game is over. 

Unit testing in this section involved utilizing the <code>faceUp</code> function to test that the game will end properly when all cards are face up (should say “it's a tie” if initialized to faceUp without any game play). I also manually changed the state of a couple of cards so I could test the <code>verifyOver</code> function with a partially complete game board. The unit testing for scoring involved creating a play-through to test that the scores would be correct. This meant writing out each player's input, then the output I expected for each turn. In the actual program, I used the predefined inputs to make sure that the outputs and final score matched. 

<h3>Part 4: Putting it all together and performing integration</h3>

The final part of the project was putting it all together and doing the integration test. I kept all of my unit tested functions in the final code, and also added integration tests that would test for multiple different types of input. I did several full play-throughs to ensure that all aspects of the game worked properly. Finally I changed the configuration from integration testing to player mode so that the board wouldn't display after initialization anymore. After several more rounds of play-through, the game was considered ready to turn in! 
