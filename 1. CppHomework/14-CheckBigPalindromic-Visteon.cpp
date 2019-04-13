//============================================================================
// Name        : 14-CheckBigPalindromic-Visteon.cpp
// Author      : Daniel Georiev
// Version     :
// Copyright   : Your copyright notice
// Description : 14.	Write a program that is capable of inputting very long (i.e. 40-digit) numbers from the standard input and checks whether the number is a palindrome. The program shall write “Palindromic” or “Not palindromic” to the standard output.
//============================================================================

#include <iostream>
#include <string>

using namespace std;

int main() {

	string input;
	getline (cin,input);
	string reversedInput = string(input.rbegin(), input.rend());
	if (input == reversedInput) {
	    cout <<  "Palindromic";
	}
	else
	{
		cout <<  "Not palindromic";
	}

	return 0;
}
