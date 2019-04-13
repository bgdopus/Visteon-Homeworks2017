//============================================================================
// Name        : 11-RStatmentCalculator-Visteon.cpp
// Author      : Daniel Georiev
// Version     :
// Copyright   : Your copyright notice
// Description : 11.	Write a program that calculates the following: R = p1 - 2p2 + 3p3 - 4p4… NpN where pi is i-th prime number. N is input by the user.
//============================================================================

#include <iostream>
using namespace std;

int getNextPrimeNumber(int prevPrime)
{
	int nextNum = prevPrime;
	bool isPrime = true;
	while(true)
	{
		for(int i = 2; i <= nextNum / 2; ++i)
		{
			if(nextNum % i == 0)
			{
				isPrime = false;
			}
		}

		if(isPrime)
		{
			return nextNum;
		}
		else
		{
			nextNum++;
			isPrime = true;
		}
	}

	return 0;
}

int main() {
	int n;
	cin >> n;
	int r = 0;
	int nextPrime = 2;

	for (int j = 1; j <= n; j++)
	{
		nextPrime = getNextPrimeNumber(nextPrime);
		if (j % 2 != 0)
		{
			r += j * nextPrime;
		}
		else
		{
			r -= j * nextPrime;
		}

		nextPrime++;
	}

	cout << "R = " << r << endl;
	return 0;
}
