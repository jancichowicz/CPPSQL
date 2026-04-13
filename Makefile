CC = g++

CFLAGS += -O2 -Wall -pedantic -c 
LDFLAGS += 

all: main.o LexicalAnalyser.o
	$(CC) $(LDFLAGS) ./*.o -o siema.elf 
main.o: src/main.cc 
	$(CC) $(CFLAGS) src/main.cc 
LexicalAnalyser.o: src/LexicalAnalyser.cc src/LexicalAnalyser.h 
	$(CC) $(CFLAGS) src/LexicalAnalyser.cc

clean:
	rm ./*.o 
.PHONY: clean
