//============================================================================
// Name        : 7-PrintTriangle-Visteon.cpp
// Author      : Daniel Georiev
// Version     :
// Copyright   : Your copyright notice
// Description : 7.	Write a program that outputs the following triangle (height = 11):
//============================================================================

#include <iostream>
using namespace std;

int main() {

	for (int i=1; i<22; i += 2)
	{
	    for (int k=0; k < (11 - i / 2); k++)
	    {
	        cout << " ";
	    }
	    for (int j=0; j<i; j++)
	    {
	        cout << "*";
	    }
	    cout << "" << endl;
	}
	return 0;
}
