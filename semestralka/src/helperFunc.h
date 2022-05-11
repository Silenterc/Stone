#pragma once
#ifndef HELP
#define HELP
#include <list>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <sys/ioctl.h> 
#include <unistd.h> 
#include <ctime>
using namespace std;
unsigned int getTermSize();
unsigned int getTermWidth();
void printSpaces(int spaces);
void printLines(int divisor);
ifstream loadFile(const string& path);
string getLocalTime();
#endif