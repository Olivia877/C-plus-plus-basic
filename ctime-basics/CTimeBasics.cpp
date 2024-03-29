// reference used: http://www.cplusplus.com/reference/ctime/time/
// reference used: http://stackoverflow.com/questions/15092504/c-how-to-time-a-function-in-milliseconds-without-boosttimer

/*
Title: CTimeBasics.cpp
Description: Creates a const whose value is determined at runtime by reading the time 
	     when the program starts. In a separate function, creates two arrays of 
	     10 000 doubles. Initializes the first array with sequential integral values 
	     starting with 100, and initializes the second array with the same numbers, 
	     but in reverse order.  Loops through both arrays using a single loop, 
	     multiplying the corresponding array elements from each array together, and 
	     displays the result. Reads the time when the program completes the 
	     multiplication, then computes and displays the elapsed time.
Date: March 19th, 2015
Author: Dan Bonham
Version: 1.0
Copyright: 2015 Daniel R. Bonham
*/

// Program written using information from "Thinking in C++" by Bruce Eckel
#include <ctime> // used to get time and calculate difference between start/end times
#include <iostream> // Stream declarations
using namespace std;

class ExecutionTime {
	const time_t startTime; // stores program start time as a const
	time_t endTime; // stores computation end time
	double sequentialArray[10000]; // used to hold 10,000 sequential #'s from 100
	double reverseArray[10000]; // used to hold 10,000 reverse #'s from 10099
public:
	ExecutionTime(time_t current); // constructor
	time_t getEndTime(); // function to get end time
	void createArrays(); // function to create arrays and perform necessary calculations/display result
	void performCalculation(); // function to calculate product of array elements
	double timeDifference(); // calculates length of execution
}; // class ExecutionTime

ExecutionTime::ExecutionTime(time_t current) : startTime(current) {}

time_t ExecutionTime::getEndTime() {
	endTime = time(0); // returns current time as a time_t value
} // endTime()

void ExecutionTime::createArrays() {
	for (int i = 0; i < 10000; i++) { // loops through and populates arrays
		sequentialArray[i] = 100 + i; // populates sequential array
		reverseArray[i] = 10099 - i; // populates reverse array
	} // for
} // createArrays()

void ExecutionTime::performCalculation() {
	for (int i = 0; i < 10000; i++) { // loops through arrays and performs calculations
		cout << "result[" << i << "]: " << sequentialArray[i] * reverseArray[i] << endl;
	} // for
} // performCalculation()

double ExecutionTime::timeDifference() {
	return difftime(endTime, startTime); // determines/returns time difference between start/end
} // timeDifference()

int main() {
	ExecutionTime et(time(0)); // creates new ExecutionTime instance with current time
	et.createArrays(); // calls createArrays to perform calculations
	et.performCalculation(); // calculates array elements products and displays
	et.getEndTime(); // stores computation end time as const
	// displays length of program execution
	double length = et.timeDifference();
	cout << "Elapsed time = " << length << " seconds." << endl;
} // main()