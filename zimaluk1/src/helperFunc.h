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
 * @file helperFunc.h
 * Helper functions used across the program.
 */

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
/**
 * @brief Prints dashes in the centre of the Terminal.
 * Prints dashes everywhere on the line except for the first and last 1/10th of Terminal.
 * 
 */
void printDashes();
/**
 * @brief loads a File and returns it's stream.
 * Throws an exception if it could not open the File.
 * 
 */
ifstream loadFile(const string& path);
/**
 * @brief Get the local time in "%d-%m-%Y,%H-%M-%S" format.
 * 
 * @return string formatted time 
 */
string getLocalTime();
#endif