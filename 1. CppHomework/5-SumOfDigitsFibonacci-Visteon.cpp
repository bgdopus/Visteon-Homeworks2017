//============================================================================
// Name        : 5-SumOfDigitsFibonacci-Visteon.cpp
// Author      : Daniel Georiev
// Version     :
// Copyright   : Your copyright notice
// Description : 5.	Write a program that calculates and outputs the total sum of the digits of the first N Fibonacci numbers.
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int n,
	first = 0,
	second = 1,
	next,
	sum = 0;


	   cin >> n;


	   for (int i = 1 ; i <= n ; i++ )
	   {
	      if ( i <= 1 )
	         next = i;
	      else
	      {
	         next = first + second;
	         first = second;
	         second = next;
	      }

	      cout << next << endl;
	      while (next > 0)
	      {
	    	  sum = sum + next % 10;
	      	  next = next / 10;
	      }

	   }
	   cout << "The sum is:" << endl;
	   cout << sum << endl;
		return 0;
}
