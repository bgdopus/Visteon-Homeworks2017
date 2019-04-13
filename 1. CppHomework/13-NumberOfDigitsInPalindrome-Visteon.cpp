//============================================================================
// Name        : 13-NumberOfDigitsInPalindrome-Visteon.cpp
// Author      : Daniel Georiev
// Version     :
// Copyright   : Your copyright notice
// Description : 13.	Write a program to print the number of digits in the Nth palindromic prime number.
//============================================================================

#include <iostream>
using namespace std;

bool isPalindromic(int number)
{
	 int prevNumber = number;
	 int reversedNumber = 0;
	 while (number > 0)
	 {
	      int digit = number % 10;
	      reversedNumber = reversedNumber * 10 + digit;
	      number = number / 10;
	 }

	 if(reversedNumber == prevNumber)
	 {
		 return true;
	 }

	 return false;
}

bool isPrimeNumber(int number)
{
	if(number <= 1)
	{
		return false;
	}

	for(int i = 2; i <= number / 2; ++i)
	{
		if(number % i == 0)
		{
			return false;
		}
	}

	return true;
}

int getNumberOfDigits(int number)
{
	int counter = 0;
	while (number > 0)
	{
		      int digit = number % 10;
		      number -= digit;
		      number = number / 10;
		      counter++;
	}

	return counter;
}

int main() {

	int n;
	int i = 0;
	cout << "Enter N:" << endl;
	cin >> n;

	int counter = 0;
	int finalPal = 0;
	while(counter < n)
	{
		if(isPalindromic(i) && isPrimeNumber(i))
		{
			finalPal = i;
			counter++;
		}

		i++;
	}

	cout << finalPal << " has " << getNumberOfDigits(finalPal) << " digits." << endl;
	return 0;
}
