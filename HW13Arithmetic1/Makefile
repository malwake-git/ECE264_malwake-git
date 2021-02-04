# ***
# *** DO NOT modify this file 
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 

TESTFALGS = -DTEST_READLIST -DTEST_DELETELIST -DTEST_DELETENODE -DTEST_ADDNODE -DTEST_CALCULATE

VALGRIND = valgrind --tool=memcheck --verbose --log-file=memcheck.txt --leak-check=full

SRCS = main.c list.c calculate.c
OBJS = $(SRCS:%.c=%.o)

hw13: $(OBJS) 
	$(GCC) $(TESTFALGS) $(OBJS) -o hw13

.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c 

testall: test1 test2 test3 test4 test5 test6

test1: hw13
	 ./hw13 inputs/test1 > output1
	diff output1 expected/expected1

test2: hw13
	./hw13 inputs/test2 > output2
	diff output2 expected/expected2

test3: hw13
	./hw13 inputs/test3 > output3
	diff output3 expected/expected3

test4: hw13
	./hw13 inputs/test4 > output4
	diff output4 expected/expected4

test5: hw13
	./hw13 inputs/test5 > output5
	diff output5 expected/expected5

test6: hw13
	./hw13 inputs/test6 > output6
	diff output6 expected/expected6

memoryall: memory1 memory2 memory3 memory4 memory5 memory6

memory1: hw13
	 $(VALGRIND) ./hw13 inputs/test1
memory2: hw13
	 $(VALGRIND) ./hw13 inputs/test2
memory3: hw13
	 $(VALGRIND) ./hw13 inputs/test3
memory4: hw13
	 $(VALGRIND) ./hw13 inputs/test4
memory5: hw13
	 $(VALGRIND) ./hw13 inputs/test5
memory6: hw13
	 $(VALGRIND) ./hw13 inputs/test6

clean: # remove all machine generated files
	rm -f hw13 *.o output?


