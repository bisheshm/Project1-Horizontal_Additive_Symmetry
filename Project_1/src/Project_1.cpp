// CS 1337.010 Project 1 <bxm170330> <Bishesh Manandhar>

#include <iostream>
#include <fstream>	// Header file for input file
#include <string>	// string header file
#include <iomanip>
#include <algorithm> // header file for swap function

using namespace std;

bool checkSymmetry(double array[], int elements);	// function prototype for checkSymmetry

// Main function
int main() {

	double readFile;	// Used to read values from input file

	bool processNewFile = true; 	// flag to check whether user wants to process another file

	while (processNewFile == true)
	{
		// Getting user input for input file
		string fileName;
		cout << "Enter the filename: ";
		cin >> fileName;

		// Opening input file. File is currently in generic project folder.
		ifstream infile;
		//infile.open("src/" + fileName); -----> Code if file is in source folder
		infile.open(fileName);

		// If file not opened correctly, error. Else, proceed
		if (!infile)
		{
			cout << "The file did not open correctly. Please restart program." << endl;
		}
		else
		{
			// Reading in number of rows
			infile >> readFile;
			const int NUM_ROWS = readFile;

			// Reading in number of columns
			infile >> readFile;
			const int NUM_COLS = readFile;

			// Creating array with numbers from input file
			double arrayNums[NUM_ROWS][NUM_COLS];
			for (int i = 0; i < NUM_ROWS; i++)
			{
				for(int j = 0; j < NUM_COLS && !infile.eof(); j++)
				{
					infile >> readFile;
					arrayNums[i][j] = readFile;
				}
			}

			// Close input file
			infile.close();

			// Creating array to hold the sum of the rows
			double rowArray[NUM_ROWS];
			int rowCount = 0;
			for (int i = 0; i < NUM_ROWS; ++i)
			{
				double rowSum = 0;
				for (int j = 0; j < NUM_COLS; ++j)
				{
					rowSum += arrayNums[i][j];
				}
				rowArray[rowCount] = rowSum;
				rowCount++;
			}

			// Checking to see if there is horizontal additive symmetry
			if (checkSymmetry(rowArray, NUM_ROWS) == true)
			{
				cout << "horizontal additive symmetry" << endl;
			}
			else
			{
				cout << "no horizontal additive symmetry" << endl;
			}

			// Sorting array using selection sort
			// This algorithm will sort every row individual from highest to lowest value
			int maxPosition;
			double temp;
			for (int i = 0; i < NUM_ROWS; ++i)
			{
				for (int j = 0; j < NUM_COLS - 1; ++j)
				{
					maxPosition = j;

					for (int k = j+1; k < NUM_COLS; ++k)
					{
						if (arrayNums[i][k] > arrayNums[i][maxPosition])
						{
							maxPosition = k;
						}
					}

					if (maxPosition != j)
					{
						temp = arrayNums[i][j];
						arrayNums[i][j] = arrayNums[i][maxPosition];
						arrayNums[i][maxPosition] = temp;
					}
				}
			}


			// Printing out values of newly sorted array
			for (int i = 0; i < NUM_ROWS; ++i)
			{
				for(int j = 0; j < NUM_COLS; ++j)
				{
					cout << setw(8) << right << arrayNums[i][j];
				}

				cout << endl;
			}

			// Creating variable for user input on whether or not to
			// process new input file
			char userAnswer;
			cout << endl;
			cout << "Would you like to process another file?" << endl;
			cout << "Enter Y or y to process another file:  ";
			cin >> userAnswer;

			// If user wants to process new input file,
			// set flag to true. Else, false.
			if (userAnswer == 'Y' || userAnswer == 'y')
			{
				processNewFile = true;
				cout << endl;
			}
			else
			{
				processNewFile = false;
			}
		}
	}
	return 0;
}	// End of function main()


/************************************************************************
 *	Function:		bool checkSymmetry(double array[], int elements)
 *	Description:    This function will check if the array has horizontal
 *					additive symmetry
 *	Parameters:		double array[], int elements
 *	Return:			true or false - depending on if there is horizontal
 *					additive symmetry
 ************************************************************************/
bool checkSymmetry(double array[], int elements)
{
	// Creating variables to hold start and end indexes
	int start = 0;
	int end = elements - 1;

	// If there an even number of elements (rows in 2d matrix),
	// check if there is horizontal additive symmetry
	if (elements % 2 == 0)
	{
		// Checking to see if there is symmetry and moving index positions
		// as it checks through array
		while (array[start] == array[end] && end != start + 1)
		{
			start += 1;
			end -= 1;
		}

		// By the end of checking array, if there is horizontal additive
		// symmetry, then return true. Else, return false
		if (array[start] == array[end] && end == start + 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	// If there are an odd number of elements (rows in 2d matrix)
	// then check to see if there is horizontal additive symmetry
	else if (elements % 2 == 1)
	{
		// Checking array elements and moving index positions
		while(array[start] == array[end] && start != end)
		{
			start += 1;
			end -= 1;
		}

		// Once done checking array, if there is horizontal additive
		// symmetry, then return true. Else, return false.
		if (start == end)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}	// End of function checkSymmetry()
