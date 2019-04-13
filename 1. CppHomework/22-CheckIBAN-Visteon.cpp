//============================================================================
// Name        : 22-CheckIBAN-Visteon.cpp
// Author      : Daniel Georiev
// Version     :
// Copyright   : Your copyright notice
// Description : Write a program that inputs an IBAN number and calculates whether it is a valid Bulgarian IBAN.
//============================================================================

#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
	string input = "BG80 BNBG 9661 1020 3456 78";

	//string input = "GE29NB0000000101904917";
	//string input = "DE89370400440532013000";
	//string input = "IE29AIBK93115212345678";
	//string input = "ME25505000012345678951";
	//string input = "MU17BOMM0101101030300200000MUR";

	string noSpaceIban = "";
	for(auto letter : input)
	{
		if(letter != ' ')
		{
			noSpaceIban += letter;
		}
	}

	regex integer("BG[0-9]{2}[A-Z]{4}[0-9]{4}[0-9]{2}[A-Z0-9]{8}");

	if(regex_match(noSpaceIban,integer))
	{
		cout<<"The IBAN is valid!"<<endl;
	}
	else
	{
		cout<<"The IBAN is INVALID!"<<endl;
 	}

	return 0;
}
