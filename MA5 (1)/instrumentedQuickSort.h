/***************************************************************************
 *instrumentedQuickSort.h
 *  Sorting algorithms and counting work - Quicksort algorithm
 *   Aaron S. Crandall, 2017 <acrandal@gmail.com>
 *   For Educational use only
 *
 *  This .h provides an instrumented quicksort
 *
 */

#ifndef __INSTRUMENTEDQS_H
#define __INSTRUMENTEDQS_H

#include <vector>
#include "main.h"   // For SortStats struct definiton

using namespace std;
using std::swap;
 
 
void swapping(int &one, int &two)
{
	int swaps = one; //swap function
	one = two;
	two = swaps;
}

int partition(vector<int>& b, int begin, int end, int first, SortStats & stats) {
	int i = 0;
	for (i = begin; i < end; ++i) {//partitions a
		if (b[i] <= first) {
			stats.moves++;
			swapping(b[i], b[begin]); //swaps elements smaller than first 
			begin++;
		}
	}
	begin = begin - 1;
	return begin; //returns element <= to first
}

void quickSortHelper(vector<int>& c, int begin, int end, SortStats & stats) {
	
	if (begin < end)
	{
		int middle = begin + (end - begin) / 2;
		swapping(c[middle], c[begin]); //switch begin and middle element
		stats.moves++;
		int partit = partition(c, begin, end, middle, stats);//index partition
		swapping(c[begin], c[partit]); 
		stats.moves++;
		quickSortHelper(c, begin, partit, stats);  // recursively quicksort elements before the part
		quickSortHelper(c, partit + 1, end, stats); // same thing for elements after the part
	}
	 
}

void instrumentedQuickSort(vector<int> & a, SortStats & stats)
{
	int low = 0;
	int high = a.size();
	quickSortHelper(a, low, high, stats);

}

#endif


