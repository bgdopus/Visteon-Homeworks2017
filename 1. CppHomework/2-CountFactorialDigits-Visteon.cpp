//============================================================================
// Name        : 2-CountFactorialDigits.cpp
// Author      : Daniel Georiev
// Version     :
// Copyright   : Your copyright notice
// Description : 2.	Write a program that counts and outputs the number of digits in N!
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Input number: " << endl;
	cin >> n;

	long long int factorial = 1;
	for (int i = 1; i <= n; i++)
	{
		factorial *= i;
	}

	cout << "Factorial number: " << endl;
	cout << factorial << endl;

	int digits = 0;
	while (factorial)
	{
		factorial /= 10;
	    digits++;
	}

	cout << "Number of digits: " << endl;
	cout << digits << endl; // prints !!!Hello World!!!
	return 0;
}
