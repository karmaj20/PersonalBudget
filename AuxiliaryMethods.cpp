#include "AuxiliaryMethods.h"

string AuxiliaryMethods::intToStringConverter(int number)
{
	ostringstream ss;
	ss << number;
	string str = ss.str();

	return str;
}

int AuxiliaryMethods::stringToIntConverter(string number)
{
	int intNumber;
	istringstream iss(number);
	iss >> intNumber;

	return intNumber;
}

float AuxiliaryMethods::stringToFloatConverter(string number)
{
	float intNumber;
	istringstream iss(number);
	iss >> intNumber;

	return intNumber;
}

string AuxiliaryMethods::loadLine()
{
	string entry = "";
	getline(cin >> ws, entry);
	
	return entry;
}

char AuxiliaryMethods::loadChar()
{
	string entry = "";
	char sign = { 0 };

	while (true){
		getline(cin >> ws, entry);

		if (entry.length() == 1) {
			sign = entry[0];
			break;
		}
		cout << "It is not single sign. Repeat." << endl;
	}
	
	return sign;
}

int AuxiliaryMethods::loadInteger()
{
	string entry = "";
	int number;

	while (true) {
		getline(cin >> ws, entry);

		stringstream myStream(entry);
		if (myStream >> number)
			break;
		cout << "It is not number. Repeat." << endl;
	}

	return number;
}

string AuxiliaryMethods::dateConverter(int number)
{
	string sign = "-";
	ostringstream ss;
	ss << number;
	string str = ss.str();
	str.insert(4, sign);
	str.insert(7, sign);

	return str;
}