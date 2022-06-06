PROG0=0-hreadelf
CC=gcc
FLAGS=-Wall -Werror -Wextra -pedantic
0-hreadelf:
	$(CC) $(PROG0).c freewilli.c getfileheader.c \
	initvars.c openfile.c printfileheader.c \
	errorhandler.c equivalences.c $(FLAGS) -o $(PROG0)
all: 0-hreadelf

clean:
	rm -f $(PROG0)