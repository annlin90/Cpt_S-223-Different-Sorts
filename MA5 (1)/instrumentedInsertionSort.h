/***************************************************************************
 *instrumentedInsertionSort.h
 *  Sorting algorithms and counting work - Insertion sort algorithm
 *   Aaron S. Crandall, 2017 <acrandal@gmail.com>
 *   For Educational use only
 *
 *  This .h provides an instrumented insertionsort
 *
 */

#ifndef __INSTRUMENTEDIS_H
#define __INSTRUMENTEDIS_H

#include <vector>
#include "main.h"   // For SortStats struct definiton

using namespace std;

void instrumentedInsertionSort( vector<int> & a, SortStats & stats )
{
	// MA TODO: implement insertion sort plus logging compares, moves/swaps
	int j, temp, le = a.size();

	for (int i = 0; i < le; i++) {
		j = i; //if while loop is broken then set j to i
		while (stats.compares++ && stats.compares++ && j > 0 && a[j-1] > a[j]) { 
			//compare both index j-1 and j with each other. if j has not reached the beginning and j-1 is bigger than j then swap
			stats.moves++;
			temp = a[j-1];
			a[j-1] = a[j];
			a[j] = temp;
			j--;
		} 
	}
}




#endif


