/***************************************************************************
 *
 *  Sorting algorithms and counting work - Merge sort algorithm
 *   Aaron S. Crandall, 2017 <acrandal@gmail.com>
 *   For Educational use only
 *
 *  This .h provides an instrumented mergesort
 *instrumentedMergeSort.h
 */

#ifndef __INSTRUMENTEDMS_H
#define __INSTRUMENTEDMS_H
//#D_SCL_SECURE_NO_WARNINGS

#include <vector>
#include "main.h"   // For SortStats struct definiton

using namespace std;


void mergeSortHelper(vector<int> & a, vector<int> & b,
	int firstHalf, int oHalf, int end, SortStats & stats)  
{
	int begin = oHalf - 1; //right half begin
	int temps = firstHalf; //leftmost index
	int number = end - firstHalf + 1;

	// Main loop
	while (stats.compares++ && firstHalf <= begin && oHalf <= end) {
		if (stats.compares++ && a[firstHalf] <= a[oHalf]) {
			b[temps++] = std::move(a[firstHalf++]);  //sorting both halves loop
			stats.moves++;
		}
		else {
			b[temps++] = std::move(a[oHalf++]);
			stats.moves++;
		}
	}
	while (stats.compares++ && firstHalf <= begin) { // getting and copying left half into temp array
		b[temps++] = std::move(a[firstHalf++]);
		stats.moves++;
		}

	while (stats.compares++ && oHalf <= end) { // same thing for the right array
		b[temps++] = std::move(a[oHalf++]);
	stats.moves++;
	}

	for (int i = 0; i < number; ++i, --end) {
		a[end] = std::move(b[end]); //then copying the temp array back into orignal array
	}
	
}


void secondMerge(vector<int> &b, vector<int> &c, int begin, int end, SortStats & stats ) {
	if (begin < end)
		{
		int middle = (begin + end) / 2;
		secondMerge(b, c, begin, middle, stats);
		secondMerge(b, c, middle + 1, end, stats); //recursively call for both halves
		mergeSortHelper(b, c, begin, middle + 1, end, stats); //then merge together
		}

		 
}

void instrumentedMergeSort(vector<int> & a, SortStats & stats)
{
	// MA TODO: Implement Merge Sort plus logging compares and moves/swaps

	vector<int> first(a.size());
	secondMerge(a, first, 0, a.size() - 1, stats);
}

 
#endif
