//============================================================================
// Name        : 10-PrimeNumberChecker-Visteon.cpp
// Author      : Daniel Georiev
// Version     :
// Copyright   : Your copyright notice
// Description : 10.	Write a program that inputs an integer and checks whether it is a prime number.
//============================================================================

#include <iostream>
using namespace std;

int main()
{
  int n;

  cout << "Enter integer: ";
  cin >> n;

  if(n <= 1)
  {
	  cout << "Number must be bigger than 1!" << endl;
	  return 0;
  }

  for(int i = 2; i <= n / 2; ++i)
  {
      if(n % i == 0)
      {
    	  cout << "This is NOT a prime number";
    	  return 0;
      }
  }

  cout << "This IS a prime number";


  return 0;
}
