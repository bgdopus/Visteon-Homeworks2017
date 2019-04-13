//============================================================================
// Name        : 9-NNaturalNumbersInRectangle-Visteon.cpp
// Author      : Daniel Georiev
// Version     :
// Copyright   : Your copyright notice
// Description : 9.	Write a program that outputs the first N natural numbers in a rectangle with a given width (W). Numbers are printed in ascending order sequentially in horizontal direction until line is complete and the sequence continues on the next line, etc. The text on the console shall look as a rectangular block (the last line may be incomplete). N and W are entered by the user.
//============================================================================


#include<iostream>
using namespace std;


// Prints rectangle with correct formating up to 4 digit numbers
int main()
{
   int n;
   cout << "Enter n:" << endl;
   cin >> n;
   int w;
   cout << "Enter w:" << endl;
   cin >> w;
   int counter = 0;
   for (int i = 1; i <= n; i++)
   {
	 if ( counter == w)
	 {
		 cout << endl;
		 counter = 0;
	 }

	 if(i < 10)
	 {
		 cout << i << "     ";
		 counter ++;
	 }
	 else if(i < 100)
	 {
		 cout << i << "    ";
		 counter ++;
	 }
	 else if(i < 1000)
	 {
		 cout << i << "   ";
		 counter ++;
	 }
	 else
	 {
		 cout << i << "  ";
		 counter ++;
	 }
   }
}
