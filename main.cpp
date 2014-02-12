/* main.cpp
 *
 * CS 121 Bolden         g++ (GCC) 4.4.7       Mason Fabel
 * 02/12                 x86_64 GNU/Linux      fabe0940@vandals.uidaho.edu
 *
 * Description of program
 * 1-Dimentional Game of Life
 * This is a simple game of life based on the following rules:
 * - Live cells die
 * - Dead cells with exactly one live neigbor are revived
 *-----------------------------------------------------------------
 */

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void usage(char* name);
void error(char* msg);
void printGeneration(void);
void initializeGeneration(void);
void nextGeneration(void);
int getNextStatus(int index);
int validIndex(int index);
int exclusiveOr(int a, int b);

int* generation = NULL;
int size = 0;

/* Run a 1D game of life */
int main(int argc, char** argv) {
	int gameLength;
	int turn;

	/* Check for proper inputs */
	if(argc != 3) {
		usage(argv[0]);
	}

	/* Set game parameters */
	size = atoi(argv[1]);
	gameLength = atoi(argv[2]);

	/* Initialize game */
	initializeGeneration();
	printGeneration();

	/* Run game */
	for(turn = 0; turn < gameLength; turn++) {
		nextGeneration();
		printGeneration();
	}

	exit(0);
}

/* Print usage information */
void usage(char* name) {
	cout << "Usage: " << name << " size length" << endl;

	exit(0);
}

/* Print an error message and exit */
void error(char* msg) {
	cerr << "Error: " << msg << " - exiting." << endl;

	exit(1);
}

/* Print the contents of the current generation */
void printGeneration(void) {
	int i;

	/* Make sure a current generation exists */
	if(generation == NULL) error("printGeneration() No current generation");

	/* Print the generation */
	for(i = 0; i < size; i++) {
		cout << generation[i] << " ";
	}
	cout << endl;

	return;
}

/* Create a random generation */
void initializeGeneration(void) {
	int i;
	int* newGeneration = new int[size];

	/* Seed the RNG */
	srand(time(NULL));

	/* Initialize the new generation */
	for(i = 0; i < size; i++) {
		newGeneration[i] = rand() % 2;
	}

	/* Assign the new generation to the current generation */
	delete generation;
	generation = newGeneration;
		
	return;
}

/* Evolve the game into the next generation */
void nextGeneration(void) {
	int i;
	int* nextGeneration = new int[size];

	/* Make sure a current generation exists */
	if(generation == NULL) error("nextGeneration() No current generation");

	/* Calculate the next generation */
	for(i = 0; i < size; i++) {
		nextGeneration[i] = getNextStatus(i);
	}

	/* Assign the new generation to the current generation */
	delete generation;
	generation = nextGeneration;

	return;
}

/* Find the next value of a given cell */
int getNextStatus(int index) {
	int result;
	int left;
	int right;

	if(!validIndex(index)) error("getNextStatus() invalid cell index");

	/* Calculate next value */
	switch(generation[index]) {
		/* Cell is currently dead */
		case 0:
			left = validIndex(index - 1) ? generation[index - 1] : 0;
			right = validIndex(index + 1) ? generation[index + 1] : 0;
			result = exclusiveOr(left, right);
			break;
		/* Cell is currently alive */
		case 1:
			result = 0;
			break;
		default:
			error("getNextStatus() invalid cell value");
	}

	return result;
}

/* Check if a given index is valid */
int validIndex(int index) {
	int result;

	/* Check for invalid indexes */
	result = 1;
	if(index < 0 || index >= size) result = 0;

	return result;
}

/* Exclusively OR a and b */
int exclusiveOr(int a, int b) {
	return ((a || b) && !(a && b));
}
