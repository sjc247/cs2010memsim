/* Author:	Matt W. Martin, 4374851
 *		kaethis@tasmantis.net
 *
 * Project:	CS2010, Lab #4
 *		        Computer Memory Simulation
 *
 * File:	driver.cpp */

#include "cmemory"

int main(){

	printf("                   __  __                                  \n");
	printf("                  |  \\/  | ___ _ __ ___   ___  _ __ _   _  \n");
	printf("                  | |\\/| |/ _ \\ '_ ` _ \\ / _ \\| '__| | | | \n");
	printf("                  | |  | |  __/ | | | | | (_) | |  | |_| | \n");
	printf("            ____  |_|  |_|\\___|_| |_| |_|\\___/|_|   \\__, | \n");
	printf("           / ___|(_)_ __ ___  _   _| | __ _| |_ ___ |___/  \n");
	printf("           \\___ \\| | '_ ` _ \\| | | | |/ _` | __/ _ \\| '__| \n");
	printf("            ___) | | | | | | | |_| | | (_| | || (_) | |    \n");
	printf("           |____/|_|_| |_| |_|\\__,_|_|\\__,_|\\__\\___/|_|    \n");
	printf("\n");

	/* ------------------------------------------------------------
	 *     W e l c o m e  t o  M E M O R Y  S I M U L A T O R !
	 * ------------------------------------------------------------
	 *  The following code demonstrates the functionality of the
	 *  Memory class.  See "cmemory" and "memory.cpp" for details
	 *  about how to use each function.
	 *  NOTE: In order NOT to overwhelm you (the user) with output,
	 *	  I've commented-out all but two dump calls by default;
	 *	  one of them demonstrates a block dump while the other
	 *	  demonstrates a complete Memory dump.  Comment-in/out
	 *	  code yourself as necessary.
	 * --------------------------------------------------------- */

	Memory *mem = new Memory();

//	mem -> dump();			// Dumps empty Memory. (AVAILABILITY = 512)

	mem -> set(1, 44);		// Set offset at 1 to value 00044.

	mem -> set(11, 8008135);	/* Set offset at 11 to value 80081.
					 * NOTE: WORDs are represented to 5th digit.
					 *	 Excess digits are ignored. */

	mem -> set(256, -9106);		/* Set offset at 256 to value 09106.
					 * NOTE: WORD values are UNSIGNED. */

	mem -> set(512, 1);		// ! ! ERROR ! ! (Offset out of bounds.)

//	mem -> dump();			// Dumps Memory. (AVAILABILITY = 509)

	mem -> insert(123456789);	// Inserts 12345 at next available address.

	mem -> insert(101);		// Inserts 00101 at "  "  "  "  "  "  "  ".

//	mem -> dump();			// Dumps Memory. (AVAILABILITY = 507)

	mem -> copy(3, 0);		// Copy into offset 3 value at 0 (12345).

	mem -> copy(2, 11);		/* "  "  "  "  "  " 2  "  "  " 11 (80081).
					 * NOTE: Because offset 2 is NOT empty, copy
					 *	 does not impact availability. */

	mem -> copy(20, 39, 0);		// Copy Memory block from [0,19] to [20,39].

	mem -> dump(1, 39);		/* Dump Memory block from offset 1 to 39.
					 * (AVAILABILITY = 501) */

	while(mem -> insert(44))
		;			// Inserts 00044 in ALL available Memory.

	mem -> dump();			// Dumps Memory. (AVAILABILITY = 0)

	mem -> clear(0);		// Clears value at offset 0.

	mem -> clear(11);		// "  "  "  "  "  "  "  " 11.

	mem -> clear(22);		// "  "  "  "  "  "  "  " 22.

	mem -> clear(0);		// ! ! ERROR ! ! (Offset already available.)

	mem -> clear(1024);		// ! ! ERROR ! ! (Offset out of bounds.)

//	mem -> dump();			// Dumps Memory. (AVAILABILITY = 3)

	int i = 0;
	while(mem -> set(i++, 66))
		;			// Sets ALL Memory addresses to value 00066.

//	mem -> dump();			// Dumps Memory. (AVAILABILITY = 0)

	mem -> clear();			// Clears ALL contents of Memory.

//	mem -> dump();			// Dumps empty Memory. (AVAILABILITY = 512)

	delete mem;
	
	return 0;
}
