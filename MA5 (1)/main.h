/***************************************************************************
 *
 *  Sorting algorithms and couting work 
 *   Aaron S. Crandall, 2017 <acrandal@gmail.com>
 *   For Educational use only
 *
 *  This .h provides general structs and stuff for main
 */

#ifndef __MAIN_H
#define __MAIN_H

#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

/**
 *  Structs to accumulate some stats about our sorting
 */
struct SortStats {
	unsigned long int compares = 0;  // How many *compares* a sort does
	unsigned long int moves = 0;     // How many *moves/swaps* a sort does
	int comparesPct = 0;
	int movesPct = 0;
};

struct SortingStats {
	SortStats bubblesort;
	SortStats insertionsort;
	SortStats mergesort;
	SortStats quicksort;
};

/**
 *  Print out a single sorting stats struct
 */
void print_SortingStats( SortingStats * stats )
{
	if( stats->bubblesort.compares )
	{
		stats->bubblesort.comparesPct = 
			100 * stats->bubblesort.compares / stats->bubblesort.compares;
		stats->insertionsort.comparesPct = 
			100 * stats->insertionsort.compares / stats->bubblesort.compares;
		stats->mergesort.comparesPct = 
			100 * stats->mergesort.compares / stats->bubblesort.compares;
		stats->quicksort.comparesPct = 
			100 * stats->quicksort.compares / stats->bubblesort.compares;
	}

	if( stats->bubblesort.moves )
	{
		stats->bubblesort.movesPct = 
			100 * stats->bubblesort.moves / stats->bubblesort.moves;
		stats->insertionsort.movesPct = 
			100 * stats->insertionsort.moves / stats->bubblesort.moves;
		stats->mergesort.movesPct = 
			100 * stats->mergesort.moves / stats->bubblesort.moves;
		stats->quicksort.movesPct = 
			100 * stats->quicksort.moves / stats->bubblesort.moves;
	}

	cout << "   [#] Sorting stats dump - pct vs BS: " << endl;
	cout << setw(26) << "        Sort algorithm -- " 
			<< setw(21) << right << "Compares         : " 
			<< setw(10) << right << "Moves" << endl;
	cout << setw(26) << left << "    [#] Bubble sort    -- " 
			<< setw(10) << right << stats->bubblesort.compares 
			<< " (" << setw(4) << stats->bubblesort.comparesPct << "%)" << " : " 
			<< setw(10) << right << stats->bubblesort.moves
			<< " (" << setw(4) << stats->bubblesort.movesPct << "%)" << endl;
	cout << setw(26) << left << "    [#] Insertion sort -- " 
			<< setw(10) << right << stats->insertionsort.compares 
			<< " (" << setw(4) << stats->insertionsort.comparesPct << "%)" << " : " 
			<< setw(10) << right << stats->insertionsort.moves
			<< " (" << setw(4) << stats->insertionsort.movesPct << "%)" << endl;
	cout << setw(26) << left << "    [#] Merge sort     -- " 
			<< setw(10) << right << stats->mergesort.compares 
			<< " (" << setw(4) << stats->mergesort.comparesPct << "%)" << " : " 
			<< setw(10) << right << stats->mergesort.moves
			<< " (" << setw(4) << stats->mergesort.movesPct << "%)" << endl;
	cout << setw(26) << left << "    [#] Quick sort     -- " 
			<< setw(10) << right << stats->quicksort.compares
			<< " (" << setw(4) << stats->quicksort.comparesPct << "%)" << " : " 
			<< setw(10) << right << stats->quicksort.moves
			<< " (" << setw(4) << stats->quicksort.movesPct << "%)" << endl;
}

#endif
