P=tests
OBJECTS=bisearch.tests.o ../bisearch.o
CFLAGS= -g -Wall -O3 -I/usr/local/include
LDFLAGS=-L/usr/local/lib
LDLIBS=-lcriterion -lm
CC=gcc
BISEARCH_PTRN= $(shell echo $(OBJECTS) | sed 's/[^ ]*bisearch[^ ]* *//g')

$(P):  $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LDFLAGS) $(LDLIBS) 
	@mkdir ./bin && mv *.o ../*.o ./bin/

bisearch_tests: $(filter-out $(BISEARCH_PTRN), $(OBJECTS))
	$(CC) $(CFLAGS) -o $@ $(filter-out $(BISEARCH_PTRN), $(OBJECTS)) $(LDFLAGS) $(LDLIBS) 
	@mkdir ./bin && mv *.o ../*.o ./bin/

clean:
	@rm -rv ./bin *tests
