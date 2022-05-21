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
/**
 * @brief Get the terminal width
 * 
 * @return unsigned int Terminal width
 */
unsigned int getTermWidth();
/**
 * @brief Get the terminal height
 * 
 * @return unsigned int Terminal height
 */
unsigned int getTermHeight();
/**
 * @brief Prints a specified amount of spaces
 * 
 * @param spaces amount of spaces I want to print 
 */
void printSpaces(int spaces);
/**
 * @brief Prints an amount of empty lines depending on the Terminal height and divisor
 * The amount of lines to print is calculated by getTermHeight()/divisor
 * @param divisor  
 */
void printLines(int divisor);
void printStars(int stars);
/**
 * @brief Prints an error massage and cin ignores until \\n if I tell it to.
 * 
 * @param ex Error message
 * @param shouldIgnore Should cin ignore until \\n 
 */
void printException(const string& ex, bool shouldIgnore);
void printDashes();
ifstream loadFile(const string& path);
string getLocalTime();
#endif