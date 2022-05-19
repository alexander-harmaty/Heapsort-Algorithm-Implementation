// (c) 2013-2020 David Gerstl, all rights reserved
// For the use of my C++ students to use as a base to implement
// dynamic arrays, exceptions and operator overloading, and templates


// Class farmingdale::stack: General std::string stack implementation based on array. 
// We will add dynamic arrays (for unlimited size), templates (to allow multiple types) etc.

// note: This is not thread safe--there are no mutexes or locks on the indexes.

// like #pragma once but more portable
#ifndef H_FARMINGDALESORTTEST
#define H_FARMINGDALESORTTEST

#include <iostream>

void printTestMessages(std::ostream &);
// a place for students to write a simpler test for debugging their code
int studentTest();
int shortSimpleTest();
int sortTest();

#endif // H_FARMINGDALESORTTEST
