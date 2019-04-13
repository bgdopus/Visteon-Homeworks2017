//============================================================================
// Name        : 21-FillSpiralMatrix-Visteon.cpp
// Author      : Daniel Georiev
// Version     :
// Copyright   : Your copyright notice
// Description : Write a program that outputs the first N natural numbers in a square spiral of size S like that:
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	int size;
	cin >> size;
	int row = 0;
	int col = 0;
	int matrix[size][size];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = 0;
		}
	}

	int matrixLength = size * size;
	string direction = "right";

	for (int i = 1; i <= matrixLength; i++)
	{
		if (direction == "right" && (col > size - 1 || matrix[row][col] != 0))
		{
			direction = "down";
			col--;
			row++;
		}

	    if (direction == "down" && (row > size - 1 || matrix[row][col] != 0))
	    {
	    	direction = "left";
	        row--;
	        col--;
	    }

	    if (direction == "left" && (col < 0 || matrix[row][col] != 0))
	    {
	    	direction = "up";
	        col++;
	        row--;
	    }

	    if (direction == "up" && (row < 0 || matrix[row][col] != 0))
	    {
	    	direction = "right";
	        row++;
	        col++;
	    }

	    matrix[row][col] = i;

	    if (direction == "right")
	    {
	    	col++;
	    }

	    if (direction == "down")
	    {
	    	row++;
	    }

	    if (direction == "left")
	    {
	    	col--;
	    }

	    if (direction == "up")
	    {
	    	row--;
	    }
	}

	for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if(matrix[i][j] < 10)
				{
					cout<< matrix[i][j] << "  ";
				}
				else
				{
					cout<< matrix[i][j] << " ";
				}
			}
			cout << endl;
		}

	return 0;
}
