# GKWAssignment8
Grayer Warren's assignment 8

Author: Grayer Warren, UMC Student. 4/19/2025 - 11:34
Purpose: C and C++ Librarys to perform matrix calculations.
Files: the .c file contains the source code for the C library, and the .cpp file contains the source code for the C++ library.

Build instructions: 
C++ file: the library is oriented around a created Matrix class. To create a matrix, you need to pass in a 2d matrix, the length, and the hight of the matrix. After this, you can then utilize any of the provided functions.

C file: the library is oriented around a matrix struct. The structure contains a 2D array, and an int for length and hight respectively. The CreateMatrix function will create an empty matrix struct with the dimensions provided, and that structure can then be utilized in any of the given functions to perform their operations.

Testing methodology: I tested each functions with random matricies, utilizeing a displayMatrix function that both library's contain. I then tested combinations of different functions to make sure they perform as expected.

Additional information:
Each file still contains a main file, even if there is nothing in it. this is entirely for the convienence of the tester should they decide to use it. On a simular note, a displayMatrix function has been put into each library that when called, will display the given matrix. This was created to assist with debuging, and was left in to help users with their own debugging. each library requires that the hight and length of the matricy is entered before any opperations can be performed.
Additionaly, no text is displayed upon calculateing the results of each opperation. The screenshots displayed are from my testing, and show how it should display along with how i call everything.
