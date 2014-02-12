Assignment 3 Design
===================


Data Structures
---------------

The primary data stucture for this project will be a global dynamically-
allocated array of integers. Each '0' in this array will represent a
"dead" cell, and each '1' in this array will represent a "live" cell.


Functions
---------

The major function of this program will be `int getNextStatus(int index)`.
This function takes as input the index of a cell in the global array, and
returns the value that cell should have for the next generation, following
a basic set of two rules:

* A live cell dies

* A dead cell with exactly one live neighbor lives

This function will be encapsulated in `void nextGeneration(void)`. This
function will create a new dynamic array of the same size of the global
array, and then populate this new array with the values determined by
running getNextStatus() on each cell of the global array. Finally, this
function will free the global array and replace it with the newly
calculated next generation.

A function `void printGeneration(void)` will also be created to display
the current generation to stdout.

A function `void usage(char* name)` will be created to print a message
detailing how to run the application when an invalid set of arguments are
supplied from the command line.


Estimated Time
--------------

3 hours.
