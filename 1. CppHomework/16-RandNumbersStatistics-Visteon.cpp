//============================================================================
// Name        : 16-RandNumbersStatistics-Visteon.cpp
// Author      : Daniel Georiev
// Version     :
// Copyright   : Your copyright notice
// Description : 16.	Write a program that makes simple quality test of the rand() library function. More precisely, it shall test how uniformly the generated random numbers are distributed. The guidelines for the program are the following
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <map>

using namespace std;

int main()
{
    int m;
    do{
    	cout << "Enter m:" << endl;
    	cin >> m;
    }while(m < 10 || 50 < m);

    int n;
    do{
    	cout << "Enter n:" << endl;
    	cin >> n;
    }while(n < (10 * m) || (40 * m) < n);

    int rangeMin = 0;
    int rangeMax = m-1;

    map<int, int> numbersCount;
    for(int i = 0; i < n; i++)
    {
		int number = rangeMin + (rand() % (int)(rangeMax - rangeMin + 1));
		numbersCount[number] += 1;
    }

    for(int j = 0; j <= rangeMax; j++)
    {
    	if(j < 10)
    	{
    		cout << "( " << j << ")";
    	}
    	else
    	{
    		cout << "(" << j << ")";
    	}
    	int count = numbersCount[j];

    	for (int f = 0; f <= count; f++)
		{
    		cout << "*";
		}
    	cout << endl;
    }
}
