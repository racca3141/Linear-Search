// Emerson Racca
// 10/18/2021
// Lab 7e - Linear Search

/*
Populate a 10-element char array with random chars from a-z lowercase.

1. Build a function that takes in this array and searches for the first instance of the char 'a' that it finds.  This function should return the index where it found the 'a' or -1 if it did not find an 'a'.

For testing purposes... in the main print the array and the result of the search.

2. Extend the function to search for any letter, not just 'a'.

3.  For the User Interface:

  A. Print the random array of chars to the screen for the user to see.
  B. Ask the user what char to linear search for.
  C. Find the char and print the index to the screen for the user to see.
  D. Ask the users if they would like to search for another char in the same array.
*/

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void populateCharArray(char aArg[], int size);
void displayCharArray(char aArg[], int size);
int findIndexOfChar(char aArg[], int size, char f);

int main(void) {

	const int s = 10;
	char a[s];

	char findChar;
	int c; // Index of the searched char.

	cout << "Linear Search\n";
	cout << "This app locates the index of the first occurence of a chosen char in an array.\n\n";

	populateCharArray(a, s);
	displayCharArray(a, s);

	// For Part 1, findIndexOfChar(a, s) was used, and char 'a' was hardcoded in the function.

	char goAgain;
	do {
		cout << "\nWhat char would you like to linear search? ";
		cin >> findChar;

		c = findIndexOfChar(a, s, findChar);

		if (c == -1)
			cout << "Char '" << findChar << "' was not found in the array." << endl;
		else {
			cout << "The first occurence of char '" << findChar << "' is found at index ";
			cout << c << " ." << endl;
		}

		cout << "\nWould you like to search for another char (y or n)? ";
		cin >> goAgain;

	} while (goAgain == 'y');

	return 0;
}

void populateCharArray(char aArg[], int size) {
	srand((unsigned int)time(0));

	for (int i = 0; i < size; i++) {
		aArg[i] = char(97 + rand() % 26);
	}
}

void displayCharArray(char aArg[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "Element a[" << i << "] value:\t" << aArg[i] << endl;
	}
}

int findIndexOfChar(char aArg[], int size, char f) {
	int i = 0;
	do {
		if (aArg[i] == f)
			return i;
		i++;
	} while (i < size);

	return -1;
}



