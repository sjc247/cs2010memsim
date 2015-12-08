/* Author: sheldon cook. 4360730
* most code is here, 
*
* Project: CS2010, Lab #4
* Computer Memory Simulation
*
* File: driver.cpp */
#include "cmemory"
int main(){
printf(" memory simuolator \n");



printf("\n");

	Memory *mem = new Memory();
// mem -> dump(); // Dumps empty Memory. (AVAILABILITY = 512)
	mem -> set(1, 44); // Set offset at 1 to value 00044.
	mem -> set(11, 8008135); 
	
	
mem -> set(512, 1); // ! ! ERROR ! ! (Offset out of bounds.)
// mem -> dump(); // Dumps Memory. (AVAILABILITY = 509)

mem -> insert(123456789); // Inserts 12345 at next available address.
mem -> insert(101); // Inserts 00101 at " " " " " " " ".
// mem -> dump(); // Dumps Memory. (AVAILABILITY = 507)


mem -> copy(3, 0); // Copy into offset 3 value at 0 (12345).
mem -> copy(2, 11);
*

mem -> copy(20, 39, 0); // Copy Memory block from [0,19] to [20,39].
mem -> dump(1, 39); 


while(mem -> insert(44))
; // Inserts 00044 in ALL available Memory.


mem -> dump(); // Dumps Memory. (AVAILABILITY = 0)


mem -> clear(0); // Clears value at offset 0.
mem -> clear(11); // " " " " " " " " 11.
mem -> clear(22); // " " " " " " " " 22.
mem -> clear(0); // ! ! ERROR ! ! (Offset already available.)
mem -> clear(1024); // ! ! ERROR ! ! (Offset out of bounds.)
// mem -> dump(); // Dumps Memory. (AVAILABILITY = 3)
int i = 0;


	while(mem -> set(i++, 66))
;		 // Sets ALL Memory addresses to value 00066.
		// mem -> dump(); // Dumps Memory. (AVAILABILITY = 0)

mem -> clear(); // Clears ALL contents of Memory.
		// mem -> dump(); // Dumps empty Memory. (AVAILABILITY = 512)

delete mem;
return 0;
}
