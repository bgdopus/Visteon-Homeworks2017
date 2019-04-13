//============================================================================
// Name        : 4-FirstNOddFiboNumbers-Visteon.cpp
// Author      : Daniel Georiev
// Version     :
// Copyright   : Your copyright notice
// Description : 4.	Write a program that calculates and outputs the first N odd Fibonacci numbers, separated by comma and space. N is entered from the standard input.
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n,
	i = 0,
	first = 0,
	second = 1,
	next;

	cin >> n;
	int counter = 0;


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

		if(next % 2 != 0)
		{
			cout << next << ", ";
			counter++;
		}
		i++;
	}

	return 0;
}
