CC = g++
WARNINGS = -ansi -pedantic -Wall -Wextra -D__USE_FIXED_PROTOTYPES__ -std=c++98
CFLAGS = $(WARNINGS)
OBJ = main.o
#LIBS = -lncurses
APPLICATION_NAME = cells

.PHONY : all rebuild clean

all : $(APPLICATION_NAME)

rebuild :
	make clean
	make all

$(APPLICATION_NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(APPLICATION_NAME) $(LIBS)

main.o : main.cpp
	$(CC) $(CFLAGS) -c main.cpp $(LIBS)

clean :
	rm -f $(APPLICATION_NAME) $(OBJ)
