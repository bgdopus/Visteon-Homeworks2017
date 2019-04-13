//============================================================================
// Name        : 19-IsPrimeWithProgress-Visteon.cpp
// Author      : Daniel Georiev
// Version     :
// Copyright   : Your copyright notice
// Description : 19.	Write a program that demonstrates callback functionality using function pointers. Here are the requirements/guidelines for the program:
//============================================================================

#include <iostream>
using namespace std;

void printStatus(unsigned long start, unsigned long end){
	cout << "Checking divisor "<< start << " of " << end << endl;
}

bool isPrimeNumber(unsigned long int  number, void (*status)(unsigned long, unsigned long))
{
	if(number <= 1)
	{
		return false;
	}

	for(unsigned long int  i = 2; i <= number / 2; ++i)
	{
		status(i, number/2);
		if(number % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main() {
	int n;
	cin >> n;

	void (*getStatus)(unsigned long, unsigned long);
	getStatus = &printStatus;

	bool isPrime = isPrimeNumber(n, getStatus);

	if(isPrime)
	{
		cout<< n << " is prime.";
	}
	else
	{
		cout<< n << " is not prime.";
	}
	return 0;
}
