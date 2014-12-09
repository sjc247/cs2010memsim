memsim:
	g++ ./memory_simulator/memory.cpp ./memory_simulator/driver.cpp -o memsim
clean:
	rm memsim
archive:
	tar cvf ../CS2010_4374851_Lab04.tar .
