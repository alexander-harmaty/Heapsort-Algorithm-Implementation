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
#define TEMPLATED_HEAPSORT


#ifndef TEMPLATED_HEAPSORT // note NDEF
void heapsort(std::string theArray[], int length);
#else  // TEMPLATED_HEAPSORT
// The templated code goes here.

template <class CL> void heapsort(CL theArray[], int length);

template <class CL> void maxHeapify(CL theArray[], int length, int indexOfOutOfOrderElement) {
	//Step 1: check which is indexOfOutOfOrderElement, left child (if it exists) and right child (if it exists) is the largest.
		//If the largest is indexOfOutOfOrderElement, then you are done.

	int max = indexOfOutOfOrderElement;
	int leftChild = 2 * indexOfOutOfOrderElement + 1;
	int rightChild = 2 * indexOfOutOfOrderElement + 2;

	if (leftChild < length && theArray[leftChild] > theArray[max])
		max = leftChild;

	if (rightChild < length && theArray[rightChild] > theArray[max])
		max = rightChild;

	//Step 2: if that isn't the largest of the three,
	if (max != indexOfOutOfOrderElement) 
	{
		//Step 2a: swap the largest with indexOfOutOfOrderElement
		std::swap(theArray[indexOfOutOfOrderElement], theArray[max]);

		//Step 3: its not possible that we've move the old [indexOfOutOfOrderElement] but its sitll out of order,
			//so call ourself recursively, with indexOfOutOfOrderElement replaced by the new position of that element
		maxHeapify(theArray, length, max);
	}
}

template <class CL> void heapsort(CL theArray[], int length) {
	//Step 1: make the array into a heap
	//Step 1a: start at the end of the array (element[length-1]) go to 0
		//call maxheapify()
	for (int i = length / 2 - 1; i >= 0; i--)
		maxHeapify(theArray, length, i);

	//Step 2: loop un til heap length ==1
	for (int i = length - 1; i >= 0; i--) 
	{
		//Step 2a: swap the last element in the heap with [0]
		std::swap(theArray[0], theArray[i]);

		//Step 2b: make the heap shorter
		//Step 2c: call maxheapify on the array with the outOfOrder element being the root [0]
		maxHeapify(theArray, i, 0);
	}
}



#endif // TEMPLATED_HEAPSORT

#endif // H_FARMINGDALEHEAPSORT