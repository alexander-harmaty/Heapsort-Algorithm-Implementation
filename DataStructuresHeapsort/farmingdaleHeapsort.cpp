// (c) 2013-2020, David Gerstl, all rights reserved
// For the use of my C++ students to use as a base to implement
// various programs needed for their data structures class.

#include <string>
#include <algorithm>
#include "farmingdaleHeapsort.h"

#ifndef TEMPLATED_HEAPSORT



int studentTest(){
	return 0;
}

void maxHeapify(int theArray[], int length, int indexOfOutOfOrderElement) {
	//Step 1: check which is indexOfOutOfOrderElement, left child (if it exists) and right child (if it exists) is the largest.
		//If the largest is indexOfOutOfOrderElement, then you are done.
	//Step 2: if that isn't the largest of the three, swap the largest with indexOfOutOfOrderElement
	//Step 3: its not possible that we've move the old [indexOfOutOfOrderElement] but its sitll out of order, so call ourself 
		//recursivlkey, with indexOfOutOfOrderElement replaced by the new position of that element
}


void heapsort(int[], int length) {
	//Step 1: make the array into a heap
	//Step 1a: start at the end of the array (element[length-1]) go to 0
		//call maxheapify()

	//we now have a heap

	//Step 2: loop un til heap length ==1
	//Step 2a: swap the last element in the heap with [0]
	//Step 2b: make the heap shorter
	//Step 2c: call maxheapify on the array with the outOfOrder element being the root [0]
}


#else // TEMPLATED_HEAPSORT
// Templated version



int studentTest(){
	return 0;
}


#endif // TEMPLATED_HEAPSORT