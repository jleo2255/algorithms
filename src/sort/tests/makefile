P=tests
OBJECTS=issort.tests.o ../sort.o
CFLAGS= -g -Wall -O3 -I/usr/local/include
LDFLAGS=-L/usr/local/lib
LDLIBS=-lcriterion
CC=clang

$(P):  $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LDFLAGS) $(LDLIBS) 
	@mv *.o ../*.o ./bin/

clean:
	@rm -v ./bin/* tests