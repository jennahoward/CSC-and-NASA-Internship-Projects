<h2>Project Overview for Set Template </h2>

This project was made in my CSC 202 course which focused on Object-Oriented methodologies as well as data structures in the C++ language. This project shows an understanding of templates, operator overloading, inheritance, data structures, and utilization of white box, unit, and integration testing techniques. The process that I used to create this project involved creating an Unordered List project first. That project is also found on my GitHub <a href="https://github.com/jennahoward/CSC-and-NASA-Internship-Projects/tree/master/C%2B%2B/Unordered-List" title="Unordered List Project">here</a>, and includes the original classes of <code>arrayListType</code> and <code>unorderedArrayListType</code>. Once perfected, I was then able to use them as base classes for this project. 

<h3>Project Description </h3>

This Set Template project is intended to convert lists to sets. A list and a set are both collections of elements of the same type. The difference between these two collections is that lists can contain duplicates, whereas a set has distinct elements. Once the lists were converted to sets, I would be able to compare different sets using union and intersection operations. This is where operator overloading came in, overloading the operators + and – to allow sets to be compared easily. 

The next part of the project involved creating and refactoring previously made classes as templates. As a way to avoid function overloading, I learned about templates, where a single code body is used for a set of related functions (function template) and related classes (class template). Function templates are used here to avoid having to repeat the code tests with different types, in this case testing for int as well as string types. To support class templates, the compiler generates separate instructions for the run time system to use to activate member functions for all the parameterized types the client program will use. 

<ul>
<li>This means that header files are no longer enough to create the run-time code – it also needs the implementation files for the class templates. For this reason, the header and implementation files are combined in the header files for the template classes.</li>
</ul>

<h3>Walk-through of Project Creation </h3>

To create this project, I started with classes that I had previously made: <code>arrayListType</code> and <code>unorderedArrayListType</code>. The <code>arrayListType</code> had functions to do the following: 
<ul>
  <li><code>retrieveAt</code>: returns the element retrieved at a certain index location in the list.</li>
  <li><code>removeAt</code>: removes elements from the list while also adjusting the length of the list. Because this was an unordered list this was achieved by swapping with the last element and decrementing the length of the list.</li>
  <li><code>remove</code>: removes only the first occurrence of an element.</li>
  <li><code>removeAll</code>: removes all occurrences of an element. This was done by using a sequential search function, and then utilizing the <code>removeAt</code> function, then looping through the sequential search function until all instances of the element are deleted from the list. </li>
</ul>

At the point of creation for these classes, I was only using lists of integers to test the program. To allow for testing on any data type, I began implementing templates. 

First I needed to derive an <code>unorderedSetType</code> template class from the <code>unorderedArrayList</code> template class. I needed to override the <code>insertAt</code>, <code>insertEnd</code>, and <code>replaceAt</code> functions. These functions had to be overridden because I needed to verify that the item to be added was not already in the set. I used the <code>sequentialSearch</code> function from the base class to ensure that there were no duplicates. If the item was not already in the list, I would be able to use the base class functions to perform the actual operation. This meant using the <code>this</code> pointer to access the protected base class instance variables in the derived class.

Next, I created functions within the <code>unorderedSetType</code> class that would act on sets to do unions and intersections of two sets. The union of two sets would result in a third set which contained all elements of both sets, with no duplicates. The intersection of two sets would result in a third set that contained only elements that were found in both sets, with no duplicates. I used operator overloading member functions to have the + operator perform set union operations and the – operator perform the set intersection operation. 

<h3>Testing</h3>

The template class would need to work with sets of both integer and string type, and so I created test cases in the client program to show that my template could correctly handle either type of set. I also needed to confirm that different functions would work on them, such as <code>insertEnd</code>, <code>insertAt</code>, and <code>replaceAt</code>, which all needed to allow unique but not duplicate elements to be added to each type of set. Finally I tested to make sure that the operator overloading worked for the union and intersection operations. 
