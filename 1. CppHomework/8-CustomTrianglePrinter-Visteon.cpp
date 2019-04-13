//============================================================================
// Name        : 8-CustomTrianglePrinter-Visteon.cpp
// Author      : Daniel Georiev
// Version     :
// Copyright   : Your copyright notice
// Description : 8.	The same triangle as previous, but having height and symbol input by the user.
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int size;
	cin >> size;

	char symbol;
	cin >> symbol;
	for (int i=1; i<size*2; i += 2)
	{
		for (int k=0; k < (size - i / 2); k++)
		{
			cout << " ";
		}

		for (int j=0; j<i; j++)
		{
			cout << symbol;
		}

		cout << "" << endl;
	}
	return 0;
}
