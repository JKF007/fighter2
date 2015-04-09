#ifndef ASSORTED
#define ASSORTED

#include <string>
#include <fstream>
#include <cstdlib>

using std::string;

string int_toStr(int input);

int str_toInt(const string& input);

bool isNumeric(const string& input);

bool checkRange(const string& input, int min, int max);

#endif
