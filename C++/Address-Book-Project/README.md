This project was made in my CSC 202 course which focused on Object-Oriented methodologies as well as data structures in the C++ language. This project shows an understanding of encapsulation, inheritance, ADT's, data structures, and utilization of white box, unit, and integration testing techniques. The process that I was advised to use for this project involved creating small sections of the project on a weekly basis, checking that I was on the right track, and building on top of what I had created correctly to make a well-rounded final product. 

The address book project is exactly what it sounds like: I made an address book program that includes name, address, phone number, birth date, and relationship. Each person has an individual entry in the address book list, which is in alphabetical order and can be searched. The main view for the client is menu-driven, with a full entry being printed when results are found. Below is a breakdown of how I created this project and a general idea of how different aspects of the program were made. 


As a review and a way to ease into OOP, I started out with 3 basic structs: address, name, and birthdate. As I got comfortable with object-oriented methodologies, I started making each struct into an ADT class. Each had member functions for setting, getting, and properly formatted printing. For example, the address print function needed to print in the format:

address<br>
city, state zipcode

I also had to pay close attention to things like state (2 characters with a default of XX) and zipcode (an integer between 11111 and 99999 with a default of 10000), and even remember to account for leap years. Test cases were initially given by my professor to ensure that the basics of OOP were being understood. Once I created the header and implementation files for personType (for the first and last name), dateType (for the birth date), and addressType, I was able to move onto the class for extPersonType. 

The extPersonType class uses composition (where object variables from one class can be used as private member variables of another class) for the dateType and AddressType, as well as inheritance for the personType. Here is the inheritance diagram:

![image](https://user-images.githubusercontent.com/44952046/113038868-0665ee80-9165-11eb-8877-ed62b6a95fba.png)


This class also has set and get functions for phoneNumber and relationship, as well as a function to get the birth month from the dateType function (used later in the next section for searching). The print function for extPersonType had to access the print functions of personType, dateType, and addressType to appropriately display each entry. The output would have to look like this: 

![image](https://user-images.githubusercontent.com/44952046/113039029-344b3300-9165-11eb-9b2d-1a337e5374d4.png)


I had to make sure that the constructor was properly initialized with instance variables from the base class (for personType) and instance object variables (address and birthdate). 


Finally I got to put it all together. The addressBookType class is a container class. This is the inheritance diagram: 

![image](https://user-images.githubusercontent.com/44952046/113040870-4f1ea700-9167-11eb-9188-f78b4d8ca4dd.png)


Within the addressBookType class, I made an array called addressList for the extPersonType objects to be kept as separate entries. To add to this array, I made a modifier function addEntry that took as input an extPersonType object and added to the end of the list. Next I used an algorithm for insertion sorting to create a sortEntries function that would sort the whole addressList each time a new entry was added.  

I then created accessor functions to find people/entries by their last name, birth month, and/or relationship. These functions print all entries found to be a match. There is also a separate print function that prints all entries in addressList in a sorted list. 

The main program, and what the client would see, needed to be menu driven and was supposed to simulate event-driven processing while mouse/keyboard presses were still out of the scope of the class. I used do-while and switch case statements to create this. 

That's basically it! This was a fun, challenging project to do and it's great to look back on as an early but really educational Object-Oriented Programming project. 
