/* Author:	Matt W. Martin, 4374851
 *		kaethis@tasmantis.net
 *
 * Project:	CS2010, Lab #4
 *		        Computer Memory Simulation
 *
 * File:	memory.cpp */

#include "cmemory"
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;
using std::vector;
using std::abs;

WORD Memory::get(int offset){
/* If offset is within range, this member functione returns the WORD value at the
 * offset into Memory.  If empty or NOT within range, function returns -1. */

	if((offset >= 0) && (offset < this -> size()))
	// If offset is within range, return WORD value at relative address.
		return ((*this -> address)[offset]);
				
	else
		return -1;
}

bool Memory::set(int offset, WORD value){
/* If within range, this member function sets the value at the specific offset in
 * Memory.  The function returns TRUE if the value was successfully set; otherwise,
 * it returns FALSE.
 * NOTE: An address in Memory is considered available (or empty) if it contains 0. */


	if((offset >= 0) && (offset < this -> size())){
	// If offset is within range:

		if(value == 0){
		// If value is 0 (otherwise, clearing the address):

			if((*this -> address)[offset] != 0){
			// If offset into Memory is NOT empty:

				// Clear relative Memory address.
				(*this -> address)[offset] = value;
				this -> avail++;	//INC avail
				return true;

			}else
			// If address is already empty, simply return.
				return true;

		}else{
		// If value is NOT 0 (otherwise, setting the value of the address):

			value = abs(value);	// WORD values are UNSIGNED.

			// Remove excess digits from input value:
			while(value > 99999)
				value = value / 10;

			if((*this -> address)[offset] != 0){
			// If offset into Memory is NOT available:

				// Set relative Memory address to value.
				(*this -> address)[offset] = value;
				return true;

			}else{
			// If offset into Memory is available:

				// Set relative Memory address to value.
				(*this -> address)[offset] = value;
				this -> avail--;	// DEC avail
				return true;	
			}
		}
	}else
		return false;
}

bool Memory::insert(WORD value){
/* If not full, this member function inserts the value at the next available (empty) 
 * address in Memory.  The function returns TRUE if the value was successfully
 * inserted; otherwise, it returns FALSE. */

	int offset = 0;		/* Represents displacement from base (zeroth) address
				 * in Memory. */


	if(!this -> isFull()){
	// If Memory is NOT full:

		while(offset < this -> size()){
		// While offset is within range...

			if((*this -> address)[offset] == 0)
			// If offset into Memory is available, insert value.
				return (this -> set(offset, value));
				
			else
				offset++;	// INC offset.
		}

	}else
		return false;
}

bool Memory:: copy(int dest, int source){
/* If not empty and within range, this member function copies the value from the
 * source address into the dest offset.  The function returns TRUE if the source
 * address was successfully copied; otherwise it returns FALSE. */


	if(!this -> isEmpty()){
	// If Memory is NOT empty:

		if(((source >= 0) && (source < this -> size())) &&
		  ((dest >= 0) && (dest < this -> size())))
		/* If source and destination are both within range, copy source value
		 * into destination address. */
			return (this -> set(dest, (*this -> address)[source]));
		else
			return false;

	}else
		return false;
}

bool Memory:: copy(int dest, int destMax, int source){
/* If not empty and within range, this member function copies the value starting from
 * the source address into the destination address to (and INCLUDING) destMax.  The
 * function returns TRUE if the source address was successfully copied; otherwise, it
 * returns FALSE.
 * NOTE: If source becomes out-of-bounds, function peforms an incomplete copy. */


	if(!this -> isEmpty()){
	// If Memory is NOT empty:

		if((destMax >= dest) && (destMax < this -> size()))
		// If destMax is within range:
			while(dest <= destMax)
			/* While within range of block copy, copy source value into
			 * destination address. */
				this -> copy(dest++, source++);	// INC dest, source.
			return true;

	}else
		return false;
}

bool Memory:: clear(){
/* If not full, this member function clears ALL stored WORD values in Memory.  The
 * function  returns TRUE if Memory was successfully cleared; otherwise, it returns
 * FALSE. */

	int offset = 0;	


	if(!this -> isEmpty()){
	// If Memory is NOT empty:

		while(offset < this -> size())
		// While offset is within range, clear relative address.
			this -> clear(offset++);	// INC offset.
		return true;

	}else
		return false;
}

bool Memory::clear(int offset){
/* If within range, this member function clears the relative address in Memory (i.e.,
 * sets value of offset to 0).  The function returns TRUE if address was successfully
 * cleared; otherwise, it returns FALSE. */


	if((offset >= 0) && (offset < this -> size()))
	// If offset is within range, clear relative address.
		return (this -> set(offset, 0));
	else
		return false;
}

bool Memory::dump(){
/* This member function displays ALL stored WORD values on a grid.  The function
 * returns TRUE if contents of Memory were successfully dumped; otherwise, it returns
 * FALSE. */

	return(this ->dump(0, this -> last()));
}

bool Memory::dump(int offset, int offsetMax){
/* If within range, this member function displays the stored WORD values on a grid
 * starting from the offset address to (and INCLUDING) offsetMax.  The function
 * returns TRUE if contents of Memory were successfully dumped; otherwise, it returns
 * FALSE. */

	int i, j = 0;		// (i.e. X-index, Y-index of grid.)
	int dumpCount;
	bool blockMode = false;	

	if(((offset >= 0) && (offset < this -> size())) &&
	  ((offsetMax >= offset && (offsetMax < this -> size())))){
	// If beginning offset and offsetMax are both within range:

		if(!((offset == 0) && (offsetMax == this -> last())))
		/* If NOT dumping ALL contents of Memory, blockMode flag is set.
		 * NOTE: "BLOCK MODE" describes dumping only a region of Memory
		 *	 within ALL Memory. */
			blockMode = true;

		printf("     ");

		for(i = 0; i < 10; i++)
			printf("_____%d", i);			// X-axis values.

		dumpCount = 0;

		while(offset <= offsetMax){
		// While offset is within range:

			// (Newline after every tenth value:)
			if(dumpCount % 10 == 0)
				printf("\n %3d| ", j++);	// Y-axis values.

			// Print five digit WORD value:
			printf("%0*d ", 5, this -> get(offset++));

			dumpCount++;		// INC dumpCount.
		}

		// Print availability vs. size of Memory:
		printf("\n   [AVAILABILITY: %d/%d] ", this -> avail, this -> size());

		if(blockMode)
		// If blockMode is set, display next to availability.
			printf("[BLOCK MODE]");

		printf("\n\n");

		return true;

	}else
		return false;
}
