#!/bin/bash

# Compile the .c files into object files
gcc -Wall -pedantic -Werror -Wextra -c *.c

# Create the static library using ar
ar -rc liball.a *.o
