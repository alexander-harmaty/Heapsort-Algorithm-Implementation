// (c) 2013-2020, David Gerstl, all rights reserved
// For the use of my C++ students to use as a base to implement
// various programs needed for their data structures class.

#include <vector>
#include <string>

#include <random>
#include <algorithm> // std::sort
#include <sstream> // for filling strings
#include <iomanip> // For filling strings
#include "farmingdaleHeapsort.h"


#ifndef TEMPLATED_HEAPSORT

void printTestMessages(std::ostream& theStream) {
	theStream << "This is the non-templated version of the mergesort tests: Make sure you do the template conversion and pass both tests" << std::endl;
	theStream << "You can switch these by uncommenting the #define for TEMPLATED_UNROLLED_LINKEDLIST at line " << TEMPLATED_HEADER_LINE << " of " << TEMPLATED_HEADER_FILE << std::endl;
}

int sortTest(){
	const int BIG_SIZE = 100000;
	int numWidth = static_cast<int>(log10(BIG_SIZE)) + 1;
	std::vector<std::string> theVector;
	std::string *theArray = new std::string[BIG_SIZE];
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> bigDis(INT_MIN, INT_MAX);
	int min = INT_MAX;
	int max = INT_MIN;
	for (int iteration = 0; iteration < BIG_SIZE; ++iteration) {
		int theNum = bigDis(gen);
		std::stringstream sStream;
		// Add leading zeros so we're always adding to the end
		sStream << std::setw(numWidth) << std::setfill('0') << theNum;
		std::string string1 = sStream.str();
		theVector.push_back(string1);
		theArray[iteration]=string1;
		if (theNum < min) {
			min = theNum;
		}
		if (theNum > max) {
			max = theNum;
		}
	}
	std::cout << "Testing Sort with a list of size " << theVector.size() << ". Min is " << min << " and max is " << max << std::endl;
	std::sort(theVector.begin(), theVector.end());
	heapsort(theArray, BIG_SIZE);
	for (int i = 0; i < BIG_SIZE; ++i) {
		if (theVector[i] != theArray[i]) {
			std::cerr << "Difference found on line " <<
				__LINE__ << "where i is " << i <<
				" theVector[i] is " << theVector[i] <<
				"and theArray[i] is " << theArray[i] << std::endl;
			delete[] theArray;
			return __LINE__;
		}
	}
	std::cout << "The two are the same. It's ALIVE!!!!" << std::endl;
	delete[] theArray;
	return 0;
}
int shortSimpleTest(){
	std::string theArray[] = { "992","252","432","223","992","252","432","223" };
	int theSize = sizeof(theArray) / sizeof(theArray[0]);
	// one vector ctor (iteratorFirst, iteratorLasT)
	std::vector<std::string>  theVector(theArray,theArray+theSize);
	// check they are identical
	for (int i = 0; i < theSize; ++i) {
		if (theVector[i] != theArray[i]) {
			std::cerr << "Difference found on line " <<
				__LINE__ << "where i is " << i <<
				" theVector[i] is " << theVector[i] <<
				"and theArray[i] is " << theArray[i] << std::endl;
			return __LINE__;
		}
	}
	heapsort(theArray, theSize);
	std::sort(theVector.begin(), theVector.end());
	// check they are identical
	for (int i = 0; i < theSize; ++i) {
		if (theVector[i] != theArray[i]) {
			std::cerr << "Difference found on line " <<
				__LINE__ << "where i is " << i <<
				" theVector[i] is " << theVector[i] <<
				"and theArray[i] is " << theArray[i] << std::endl;
			return __LINE__;
		}
	}


	return 0;
}


#else // TEMPLATED_HEAPSORT

void printTestMessages(std::ostream& theStream) {
	theStream << "This is the templated version of the mergesort tests: Make sure you also pass the non-template version and pass both tests" << std::endl;
	theStream << "You can switch these by uncommenting the #define for TEMPLATED_MERGESORT at line " << TEMPLATED_HEADER_LINE << " of " << TEMPLATED_HEADER_FILE << std::endl;
}


int sortTest(){
	const int BIG_SIZE = 100000;
	int numWidth = static_cast<int>(log10(BIG_SIZE)) + 1;
	std::vector<std::string> theVector;
	std::string *theArray = new std::string[BIG_SIZE];
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> bigDis(INT_MIN, INT_MAX);
	int min = INT_MAX;
	int max = INT_MIN;
	for (int iteration = 0; iteration < BIG_SIZE; ++iteration) {
		int theNum = bigDis(gen);
		std::stringstream sStream;
		// Add leading zeros so we're always adding to the end
		sStream << std::setw(numWidth) << std::setfill('0') << theNum;
		std::string string1 = sStream.str();
		theVector.push_back(string1);
		theArray[iteration]=string1;
		if (theNum < min) {
			min = theNum;
		}
		if (theNum > max) {
			max = theNum;
		}
	}
	std::cout << "Testing Sort with a list of size " << theVector.size() << ". Min is " << min << " and max is " << max << std::endl;
	std::sort(theVector.begin(), theVector.end());
	heapsort(theArray, BIG_SIZE);
	for (int i = 0; i < BIG_SIZE; ++i) {
		if (theVector[i] != theArray[i]) {
			std::cerr << "Difference found on line " <<
				__LINE__ << "where i is " << i <<
				" theVector[i] is " << theVector[i] <<
				"and theArray[i] is " << theArray[i] << std::endl;
			delete[] theArray;
			return __LINE__;
		}
	}
	std::cout << "The two are the same. It's ALIVE!!!!" << std::endl;
	delete[] theArray;
	return 0;
}
int shortSimpleTest(){
	std::string theArray[] = { "992","252","432","223","992","252","432","223" };
	int theSize = sizeof(theArray) / sizeof(theArray[0]);
	// one vector ctor (iteratorFirst, iteratorLasT)
	std::vector<std::string>  theVector(theArray,theArray+theSize);
	// check they are identical
	for (int i = 0; i < theSize; ++i) {
		if (theVector[i] != theArray[i]) {
			std::cerr << "Difference found on line " <<
				__LINE__ << "where i is " << i <<
				" theVector[i] is " << theVector[i] <<
				"and theArray[i] is " << theArray[i] << std::endl;
			return __LINE__;
		}
	}
	// Note: you can (but dont have to) use 	heapsort<std::string>(theArray, theSize);

	heapsort(theArray, theSize);
	std::sort(theVector.begin(), theVector.end());
	// check they are identical
	for (int i = 0; i < theSize; ++i) {
		if (theVector[i] != theArray[i]) {
			std::cerr << "Difference found on line " <<
				__LINE__ << "where i is " << i <<
				" theVector[i] is " << theVector[i] <<
				"and theArray[i] is " << theArray[i] << std::endl;
			return __LINE__;
		}
	}
	// now with ints:
	int theIntArray[] = { 992,252,432,223,992,252,432,223 };
	int theIntSize = sizeof(theIntArray) / sizeof(theIntArray[0]);
	// one vector ctor (iteratorFirst, iteratorLasT)
	std::vector<int>  theIntVector(theIntArray,theIntArray+theSize);
	// check they are identical
	for (int i = 0; i < theIntSize; ++i) {
		if (theIntVector[i] != theIntArray[i]) {
			std::cerr << "Difference found on line " <<
				__LINE__ << "where i is " << i <<
				" theIntVector[i] is " << theIntVector[i] <<
				"and theIntArray[i] is " << theIntArray[i] << std::endl;
			return __LINE__;
		}
	}
	heapsort(theIntArray, theIntSize);

	std::sort(theIntVector.begin(), theIntVector.end());
	// check they are identical
	for (int i = 0; i < theIntSize; ++i) {
		if (theIntVector[i] != theIntArray[i]) {
			std::cerr << "Difference found on line " <<
				__LINE__ << "where i is " << i <<
				" theIntVector[i] is " << theIntVector[i] <<
				"and theIntArray[i] is " << theIntArray[i] << std::endl;
			return __LINE__;
		}
	}

	return 0;
}




#endif // TEMPLATED_HEAPSORT
