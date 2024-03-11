# Password-generator
Password generator using dictonaries coded in C

This program generates a random password by choosing a random combination of words from several files. The main file (ETR_Password.c) includes a set of functions from the second file (Functions.c), which handles the file input/output and generates random numbers.

The code begins by defining the required functions, including a function to animate printing and generate random numbers, and several functions that read from files of different word lengths (4, 5, 6, and 7 letters). The read_from_* functions return special address that points to a memory space that contains a random line from the corresponding file.

The Random_file function randomly selects a file (4, 5, 6, or 7) and returns a pointer to a buffer containing a random word from that file. The Correct_Parameter function checks the user input for the number of words and ensures that it is within the required range.

Finally, in the main function, the program calls the Intro function to print an ASII art, then calls the Generate_Password function to generate the password. 

The computer system being used is running the Linux Ubuntu operating system. The IDE being used is Visual Studio Code. To compile the code, the GCC compiler is being used through the terminal.
