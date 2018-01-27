/***************************************************************************
 *
 *  Sorting algorithms and counting work - BS algorithm
 *   Aaron S. Crandall, 2017 <acrandal@gmail.com>
 *   For Educational use only
 *
 *  This .h provides an instrumented bubblesort
 *
 */

#ifndef __INSTRUMENTEDBS_H
#define __INSTRUMENTEDBS_H

#include <vector>
#include "main.h"   // For SortStats struct definiton

using namespace std;

void instrumentedBubbleSort( vector<int> & a, SortStats & stats )
{
	bool swapp = true;
	while(swapp){
		swapp = false;
		for (size_t i = 0; i < a.size()-1; i++) {
			if ( stats.compares++ && a[i] > a[i+1] ) {  // Log the comparison
				stats.moves++;             // Log that we swapped (moved)
				a[i] += a[i+1];
				a[i+1] = a[i] - a[i+1];
				a[i] -= a[i+1];
         	swapp = true;
			}
		}
	}
}




#endif
