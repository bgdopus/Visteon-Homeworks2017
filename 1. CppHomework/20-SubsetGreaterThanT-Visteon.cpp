//============================================================================
// Name        : 20-SubsetGreaterThanT-Visteon.cpp
// Author      : Daniel Georiev
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<long long int> numbers;

	long long int t;
	cout << "Entet T:" << endl;
	cin >> t;

	int n;
	cout << "Entet N:" << endl;
	cin >> n;

	cout << "Input the set:" << endl;
	long long int nums[n];
	for(int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}


	int maxI = 1;
	for(int i = 1; i <= n; i++)
	{
		maxI *= 2;
	}

	maxI -=1;

	int count = 0;

	for(int i = 1; i <= maxI; i++)
	{
		//long long int currentSum = 0;
	    for(int j = 0; j < n; j++)
	    {
	    	int mask = 1 << j;
	    	int nAndMask = i & mask;
	    	int bit = nAndMask >> j;

	    	if (bit == 1)
	    	{
	    		//currentSum += nums[j];
	    		numbers.push_back(nums[j]);
	    	}
	    }

	    long long int currentSum = 0;
	    for(auto n : numbers)
	    {
	    	currentSum += n;
	    }
	    //cout << "sum ="<< summ << endl;

	    if (currentSum > t)
	    {
	    	for(auto n : numbers)
	    	{
	    		cout << n << " ";
	    	}
	    	cout<< endl;
	    	count++;
	    		    //Console.WriteLine(nums[j]);
	    }
	    numbers.clear();
	}

	cout << "Found: " << count << " subsets.";
	return 0;
}
