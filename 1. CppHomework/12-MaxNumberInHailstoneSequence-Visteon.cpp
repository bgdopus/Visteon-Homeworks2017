//============================================================================
// Name        : 12-MaxNumberInHailstoneSequence-Visteon.cpp
// Author      : Daniel Georiev
// Version     :
// Copyright   : Your copyright notice
// Description : 12.	Write a program that prints the maximum number in a hailstone sequence, given the seed N. The seed is entered from the standard input.
//============================================================================

# include <iostream>
# include <vector>

using namespace std;

int main()
{
    vector<int> hailstoneSeq;

    int n;
    cout << "Enter N: " << endl;;
    cin >> n;

    while(n != 1)
    {
        if(n % 2 != 0 )
        {
            n = n * 3 + 1;
            hailstoneSeq.push_back(n);
        }
        else
        {
            n /= 2;
            hailstoneSeq.push_back(n);
        }
    }

    int vectorCount = hailstoneSeq.size();
    int maxNumber = 1;
    for(int i = 0; i < vectorCount; i++ )
    {
        if (hailstoneSeq[i] > maxNumber)
        {
        	maxNumber = hailstoneSeq[i];
        }
    }

    cout << maxNumber;

    return 0;
}
