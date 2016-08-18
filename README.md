# Win32Toys
some small code pieces for windows

# drawCPU.cpp
Make the use rate curve of each CPU core a sine curve. 

This demo works on a 4-core CPU with a 3.2GHz frequency. You may need to modify the value of constant integer FREQUENCY in the
run() function, which depends on the frequency of your CPU, change the number of threads and write your own SetThreadAffinityMask()
sets to assure it works properly on your machine.
