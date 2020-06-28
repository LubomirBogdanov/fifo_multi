Description  
===================================================================   
The project is a standard C implementation of a multi-channel FIFO  
buffer with blocking read and blocking write.  
A blocking read means that if there are no data in the buffer the  
read function will return 1.  
A blocking write means that if the FIFO is full and a new write  
is attempted, then the write function will return 1 and the element  
won't be pushed.  


INSTALL  
===================================================================
You will need a C compiler to build the example. The Makefile is set  
for GCC by default.  
On Ubuntu 18.04 type the following in a terminal:  

sudo apt install build-essential  

then enter the fifo_multi directory and type:  

make  

The executable will be in ./gcc and the filename is 'main'. This is  
an example main program to test the functions in fifo_multi.c. To run  
it type:  

./gcc/main  

  
Example usage  
===================================================================
Include the source file "fifo_multi.c" and the header "fifo_multi.h" in  
your project. Set your compiler's include path to point to where fifo_multi.h  
is and include the source fifo_multi.c to the list of your object files. This  
way your project may now use the FIFOs. Don't forget to include:  

#include "fifo_multi.h"  

in your source file. You can now start using the APIs.

