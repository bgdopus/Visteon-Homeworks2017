//============================================================================
// Name        : 1-FibonnacciNumber-Visteon.cpp
// Author      : Daniel Georiev
// Version     :
// Copyright   : Your copyright notice
// Description : 1.	Write a program that inputs a positive integer N and outputs the Fibonacci number F2N
//============================================================================

#include <iostream>
using namespace std;


int main() {
	int n,
		i = 1,
		first = 0,
		second = 1,
		next;

		cin >> n;
		int counter = 0;
		n *= 2;

		while(counter < n)
		{
			if ( i <= 1 )
			{
				next = i;
			}
			else
			{
				next = first + second;
				first = second;
				second = next;
			}

			counter++;
			i++;
		}

		cout << next << endl;
		return 0;
}
