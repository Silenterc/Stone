#pragma once
#ifndef HELP
#define HELP
#include <list>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <sys/ioctl.h> 
#include <unistd.h> 
using namespace std;
list<string> battlecryIDtoString(int ID);
unsigned int getTermSize();
unsigned int getTermWidth();
void printSpaces(int spaces);
ifstream loadFile(const string& path);
#endif