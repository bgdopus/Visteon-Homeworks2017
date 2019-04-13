//============================================================================
// Name        : 15-SumOfNMersennePrimes-Visteon.cpp
// Author      : Daniel Georiev
// Version     :
// Copyright   : Your copyright notice
// Description : 15.	Write a program that calculates the sum of the first N Mersenne primes and prints it to the standard output. N is input by the user.
//============================================================================

#include <iostream>
#include <math.h>

using namespace std;

bool isPrimeNumber(unsigned long long int number)
{
	if(number <= 1)
	{
		return false;
	}

	for(unsigned long long int i = 2; i <= number / 2; ++i)
	{
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

	if(n > 10)
	{
		cout <<  "Long Long cannot make calculations with such a big number!";
		return 0;

	}

	unsigned long long int sum = 0;
	int base = 2;
	int counter = 0;
	int i = 1;
	while(n > counter)
	{
		unsigned long long int result = pow(base, i) - 1;

		if(isPrimeNumber(result))
		{
			sum += result;
			cout << result << endl;
			counter++;
		}
		i++;
	}
	cout << sum << endl; // prints !!!Hello World!!!
	return 0;
}
