#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H
#include <iostream>
#include <sstream>

using namespace std;

class AuxiliaryMethods {
public:
	static string intToStringConverter(int number);
	static string dateConverter(int number);
	static int stringToIntConverter(string number);
	static float stringToFloatConverter(string number);
	static string loadLine();
	static char loadChar();
	static int loadInteger();
};

#endif