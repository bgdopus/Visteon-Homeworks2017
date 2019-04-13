//============================================================================
// Name        : 3-SidesOfTriangle-Visteon.cpp
// Author      : Daniel Georiev
// Version     :
// Copyright   : Your copyright notice
// Description : 3.	Write a program that inputs three real numbers and outputs whether they can be sides of a triangle.
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int a;
	int b;
	int c;
	cout << "Input a, b and c separated by space:" << endl;
	cin >> a >> b >> c;

	if ((a + b) > c)
	{
		if (a < (b + c))
		{
			if (b < (a + c))
			{
				cout << "Triangle could be made."<< endl;
			}
			else
			{
				cout << "Triangle could not be made."<< endl;
			}
		}
		else
		{
			cout << "Triangle could not be made."<< endl;
		}
	}
	else
	{
		cout << "Triangle could not be made."<< endl;
	}

	return 0;
}
