//============================================================================
// Name        : 6-RectangleOverlapChecker-Visteon.cpp
// Author      : Daniel Georiev
// Version     :
// Copyright   : Your copyright notice
// Description : 6.	Write a program that checks and prints whether two rectangles overlap.
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int recOneTopX,
		recOneTopY,
		recOneBottonX,
		recOneBottomY,
		recTwoTopX,
		recTwoTopY,
		recTwoBottonX,
		recTwoBottomY;

	cout << "Enter x and y separated by space for rectangle ONE top left corner:" << endl;
	cin >> recOneTopX >> recOneTopY;
	cout << "Enter x and y separated by space for rectangle ONE bottom right corner:" << endl;
	cin >> recOneBottonX >> recOneBottomY;
	cout << "Enter x and y separated by space for rectangle TWO top left corner:" << endl;
	cin >> recTwoTopX >> recTwoTopY;
	cout << "Enter x and y separated by space for rectangle TWO bottom right corner:" << endl;
	cin >> recTwoBottonX >> recTwoBottomY;

	   if (recOneTopX > recTwoBottonX || recTwoTopX > recOneBottonX)
	   {

		   cout << "Rectangles don't overlap" << endl;

	   }
	   else if (recOneTopY < recTwoBottomY || recTwoTopY < recOneBottomY)
	   {
		   cout << "Rectangles don't overlap" << endl;
	   }
	   else
	   {
		   cout << "Rectangles overlap" << endl;
	   }

	return 0;
}
