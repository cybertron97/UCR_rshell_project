CC = g++
CC_FLAGS = -Wall -Werror -ansi -pedantic
all:main Exec AAnd OOr cSemi
		mkdir -p bin
			$(CC) $(CCFLAGS) main.o Exec.o AAnd.o OOr.o cSemi.o -o ./bin/rshell
main:
		$(CC) $(CCFLAGS) -c ./src/main.cpp
Exec:
		$(CC) $(CCFLAGS) -c ./src/Exec.cpp
AAnd:
		$(CC) $(CCFLAGS) -c ./src/AAnd.cpp 
OOr:
		$(CC) $(CCFLAGS) -c ./src/OOr.cpp 
cSemi:
		$(CC) $(CCFLAGS) -c ./src/cSemi.cpp 
clean:
		rm -r *.o
