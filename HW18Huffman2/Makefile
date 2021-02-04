# Makefile
TARGET = hw18
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

TESTFLAGS = -DTEST_MAIN -DTEST_READHEADER -DTEST_DECODE -DTEST_MERGELIST -DDO_NOT_MODIFY

SRCS = main.c huffman.c
OBJS = $(SRCS:%.c=%.o)

VALGRIND = valgrind --tool=memcheck --verbose --log-file=memcheck.txt --leak-check=full

$(TARGET): $(OBJS)
	$(GCC) $(OBJS) -o $(TARGET)

.c.o:
	$(GCC) -c $*.c

testall: test1 test2 test3 test4 test5

testadd: $(TARGET)
	test1
	test2
	test3
	test4
	test5

memory:	$(TARGET)
	$(VALGRIND) ./hw18 inputs/test1 output1

hw18: huffman.c main.c huffman.h
	gcc -g -std=c99 -Wall -Wshadow -Wvla -pedantic -lm huffman.c main.c huffman.h -o hw18
	rm -f *.txt


test1: $(TARGET)
	./hw18 inputs/test1 output1
	rm -f *.txt
	diff output1 expected/expected1

test2: $(TARGET)
	./hw18 inputs/input2 output2 > output12.txt
	diff output2 expected/expected2

test3: $(TARGET)
	./hw18 inputs/input3 output3
	diff output3 expected/expected3

test4: $(TARGET)
	./hw18 inputs/input4 output4
	diff output4 expected/expected4

test5: $(TARGET)
	./hw18 inputs/input5 output5
	diff output5 expected/expected5

clean:
	rm -f $(OBJS) $(TARGET)
	rm -f *.txt
