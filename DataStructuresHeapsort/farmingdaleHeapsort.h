// (c) 2013-2020 David Gerstl, all rights reserved
// For the use of my C++ students to use as a base to implement
// dynamic arrays, exceptions and operator overloading, and templates


// Class farmingdale::stack: General std::string stack implementation based on array. 
// We will add dynamic arrays (for unlimited size), templates (to allow multiple types) etc.

// note: This is not thread safe--there are no mutexes or locks on the indexes.

// like #pragma once but more portable
#ifndef H_FARMINGDALEHEAPSORT
#define H_FARMINGDALEHEAPSORT


// Note to students. It's OK to #include in a library header (inside the guards). 
// but DO NOT add a "using" directive inside a library header
#include <iostream>
#include <deque>
#include "farmingdaleStatus.h"


// Two consts for student messages
const std::string TEMPLATED_HEADER_FILE = (std::string(__FILE__).substr(std::string(__FILE__).find_last_of("\\/") + 1));
const int TEMPLATED_HEADER_LINE = (__LINE__ + 3);
// Please set these before you start on the relevant project: 
// Uncomment this to test a templated version of the stack code.
// #define TEMPLATED_HEAPSORT


#ifndef TEMPLATED_HEAPSORT // note NDEF
void heapsort(std::string theArray[], int length);
#else  // TEMPLATED_HEAPSORT
// The templated code goes here.






#endif // TEMPLATED_HEAPSORT

#endif // H_FARMINGDALEHEAPSORT