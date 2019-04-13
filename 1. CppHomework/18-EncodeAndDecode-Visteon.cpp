//============================================================================
// Name        : 18-EncodeAndDecode-Visteon.cpp
// Author      : Daniel Georiev
// Version     :
// Copyright   : Your copyright notice
// Description : 18.	Write functions encode and decode that implement Run-length Encoding on byte buffers (not strings!).
//============================================================================


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void encode(char *pArray, char arraySize, vector<char> *encodeData, char maxSize)
{
	int counter = 1;

	if ((int)arraySize == 1)
	{
		(*encodeData).push_back( pArray[0]);
		(*encodeData).push_back(counter);
	}
	else if((int)arraySize < 1)
	{
		cout << "Sequence cannot be zero!";
		return;
	}


	for (int i = 0; i < arraySize - 1 ; i++)
	{
		char element = pArray[i];

		if(pArray[i] == pArray[i+1])
		{
			counter ++;
		}
		else
		{
			(*encodeData).push_back(element);
			(*encodeData).push_back(counter);
			 counter = 1;

		}

		if (i+ 1 == arraySize - 1)
		{
			(*encodeData).push_back(element);
			(*encodeData).push_back(counter);
		}
	}
}

void decode(vector<char> *encodeData, vector<char> *decodeData)
{
	int encodeDataSize = (*encodeData).size();

	for (int i = 0; i < encodeDataSize ; i+=2)
	{
		int number = (int)(*encodeData)[i] ;
		int repeats = (int)(*encodeData)[i + 1];
		for (int j = 0; j < repeats; j++)
		{
			cout << number << " ";
		}
	}

	cout << endl;
}

void print (char i)
{
	cout << (int)i << " " ;
}

int main() {
	char array[] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8, 8, -56, 0, 0, 0, 0, 0, 0};

	char arraySize = sizeof(array)/sizeof(*array);
	char *pArray = array;
	int maxSize = 255;

	vector<char> *encodeData = new vector<char>();
	encode(pArray, arraySize, encodeData, maxSize);
	cout << "Encoded:" << endl;
	for_each ((*encodeData).begin(), (*encodeData).end(), print);
	cout << endl;

	vector<char> *decodeData = new vector<char>();
	cout << "Decoded:" << endl;
	decode(encodeData, decodeData);

	cout << "Original input:" << endl;
	for (int i = 0; i < arraySize; i++)
	{
		cout << (int)array[i] << " ";
	}
	cout << endl;

	return 0;
}
