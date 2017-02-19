P=tests
OBJECTS=issort.tests.o qksort.tests.o mgsort.tests.o ctsort.tests.o ../issort.o ../qksort.o ../mgsort.o ../ctsort.o 
CFLAGS= -g -Wall -O3 -I/usr/local/include
LDFLAGS=-L/usr/local/lib
LDLIBS=-lcriterion
CC=gcc
ISSORT_PTRN= $(shell echo $(OBJECTS) | sed 's/[^ ]*issort[^ ]* *//g')
ISSORT_OBJ_PTRN= $(shell echo $(OBJECTS) | sed 's/[^ ]*issort.o[^ ]* *//g')
QKSORT_PTRN= $(shell echo $(OBJECTS) | sed 's/[^ ]*qksort[^ ]* *//g')
MGSORT_PTRN= $(shell echo $(OBJECTS) | sed 's/[^ ]*mgsort[^ ]* *//g')
CTSORT_PTRN= $(shell echo $(OBJECTS) | sed 's/[^ ]*ctsort[^ ]* *//g')

$(P):  $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LDFLAGS) $(LDLIBS) 
	@mkdir ./bin && mv *.o ../*.o ./bin/

issort_tests: $(filter-out $(ISSORT_PTRN), $(OBJECTS))
	$(CC) $(CFLAGS) -o $@ $(filter-out $(ISSORT_PTRN), $(OBJECTS)) $(LDFLAGS) $(LDLIBS) 
	@mkdir ./bin && mv *.o ../*.o ./bin/

qksort_tests: $(filter-out $(QKSORT_PTRN), $(OBJECTS)) $(filter-out $(ISSORT_OBJ_PTRN), $(OBJECTS))
	$(CC) $(CFLAGS) -o $@ $(filter-out $(QKSORT_PTRN), $(OBJECTS)) $(filter-out $(ISSORT_OBJ_PTRN), $(OBJECTS)) $(LDFLAGS) $(LDLIBS) 
	@mkdir ./bin && mv *.o ../*.o ./bin/

mgsort_tests: $(filter-out $(MGSORT_PTRN), $(OBJECTS))
	$(CC) $(CFLAGS) -o $@ $(filter-out $(MGSORT_PTRN), $(OBJECTS)) $(LDFLAGS) $(LDLIBS) 
	@mkdir ./bin && mv *.o ../*.o ./bin/

ctsort_tests: $(filter-out $(CTSORT_PTRN), $(OBJECTS))
	$(CC) $(CFLAGS) -o $@ $(filter-out $(CTSORT_PTRN), $(OBJECTS)) $(LDFLAGS) $(LDLIBS) 
	@mkdir ./bin && mv *.o ../*.o ./bin/

clean:
	@rm -rv ./bin *tests
