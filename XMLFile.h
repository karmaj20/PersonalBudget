#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>

#include "Markup.h"

using namespace std;

class XMLFile {
	const string FILENAME;
public:
	XMLFile(string filename) : FILENAME(filename) {}

	string getFilename();
};
#endif

