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

void maxHeapify(std::string theArray[], int length, int indexOfOutOfOrderElement) {
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

void heapsort(std::string theArray[], int length) {
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


#else // TEMPLATED_HEAPSORT
// Templated version



int studentTest(){
	return 0;
}


#endif // TEMPLATED_HEAPSORT