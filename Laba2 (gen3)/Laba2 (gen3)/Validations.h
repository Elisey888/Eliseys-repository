#pragma once
#include <string.h>
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

void validationForVar(int& x);
bool validationForFile(ifstream& file);
bool fileCheck(ifstream& file);
bool fileNotEmpty(ifstream& file);
bool checkCommentsForChar(char charArr[100], int k);
bool checkCommentsForString(string str);
