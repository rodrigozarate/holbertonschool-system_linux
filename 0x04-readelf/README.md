# 0x04. C - ELF: readelf
## Learning Objectives

    What is the ELF format
    What kind of files are in the ELF format
    What are the different parts that constitute an ELF file
    What information are present in the file header
    What information are present in the sections header table
    What information are present in the program header table
    How to parse an ELF file using C structures

### Allowed Functions and System Calls

    Unless specified otherwise, you are allowed to use the C standard library
    You’re not allowed to use system(3)
    You’re not allowed to use exec*(2 and 3)

### Compilation

    You have to provide a Makefile in order to compile each task
    Make sure each task compiles on Ubuntu 14.04 LTS, with gcc 4.8.4
    You must compile each task using the flags -Wall -Werror -Wextra and -pedantic

### Tests

    Your program must be able to handle both 32-bit and 64-bit ELF files
    Your program must be able to handle both little and big endian ELF files
    Your program must be able to handle all types of ELF files

