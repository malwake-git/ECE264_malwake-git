# Makefile
TARGET = hw17
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

TESTFLAGS = -DTEST_MAIN -DTEST_READHEADER -DTEST_DECODE -DTEST_MERGELIST -DDO_NOT_MODIFY

SRCS = main.c decode.c list.c tree.c utility.c
OBJS = $(SRCS:%.c=%.o)

VALGRIND = valgrind --tool=memcheck --verbose --log-file=memcheck.txt --leak-ch\
eck=full

$(TARGET): $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testall: test1 test2 test3 test4 test5

testadd: $(TARGET)
	test1
	test2
	test3
	test4
	test5

memory:	$(TARGET)
	$(VALGRIND) ./hw17 inputs/input1 > output1

test1: $(TARGET)
	./hw17 inputs/input1 > output1
	diff output1 expected/expected1
test2: $(TARGET)
	./hw17 inputs/input2 > output2
	diff output2 expected/expected2

test3: $(TARGET)
	./hw17 inputs/input3 > output3
	diff output3 expected/expected3

test4: $(TARGET)
	./hw17 inputs/input4 > output4
	diff output4 expected/expected4

test5: $(TARGET)
	./hw17 inputs/input5 > output5
	diff output5 expected/expected5

clean:
	rm -f $(OBJS) $(TARGET)
