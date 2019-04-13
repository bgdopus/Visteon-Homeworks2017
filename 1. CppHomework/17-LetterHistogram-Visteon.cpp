//============================================================================
// Name        : 17-LetterHistogram-Visteon.cpp
// Author      : Daniel Georiev
// Version     :
// Copyright   : Your copyright notice
// Description : 17.	Write a program that measures and displays the histogram of how many times each letter is used in a text entered by the user
//============================================================================


#include <iostream>
#include <string>
#include <map>
#include <locale>

using namespace std;

int main ()
{
	locale loc;
	string text;
	getline (cin,text);

	map<char,int> lettersCount;
	map<char,int>::key_compare mycomp = lettersCount.key_comp();

	int textCount = text.size();
	for (int i = 0; i < textCount ; i++)
	{
		lettersCount[tolower(text[i],loc)] += 1;
	}

	cout << "Histogram :\n";
	char highest = lettersCount.rbegin()->first;
	map<char,int>::iterator it = lettersCount.begin();

	do
	{
		if ((it->first <= 'z' && it->first >= 'a') || (it->first <= 'Z' && it->first >= 'A'))
		{
			cout << "("<<it->first << ")";
			int repeats = it->second;
			for (int i = 0; i < repeats; i++)
			{
				cout << "*";
			}

			cout << endl;
		}

	} while ( mycomp((*it++).first, highest) );

  return 0;
}
