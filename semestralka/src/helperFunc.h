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
extern list<string> battlecryIDtoString(int ID);
extern unsigned int getTermSize();
extern void printSpaces(int spaces);
extern ifstream loadFile(const string& path);
#endif