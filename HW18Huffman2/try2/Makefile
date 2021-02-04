CFLAGS = -g -Wall -Wshadow
GCC = gcc $(CFLAGS)
SRCS = main.c encode.c freq.c tree.c list.c utility.c
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --leak-check=full --tool=memcheck --verbose --log-file

testall: hw18 test1 test2 test3 test4 test5

hw18: $(OBJS) 
	$(GCC) $(OBJS) -o hw18

test1: hw18
	./hw18 inputs/test1 output1
	diff output1 expected/expected1
	$(GCC) $(OBJS) -o hw18

test2: hw18
	./hw18 inputs/test2 output2
	diff expected/expected2 output2
	$(GCC) $(OBJS) -o hw18

test3: hw18
	./hw18 inputs/test3 output3
	diff output3 expected/expected3

	$(GCC) $(OBJS) -o hw18

test4: hw18
	./hw18 inputs/test4 output4
	diff output4 expected/expected4
	$(GCC) $(OBJS) -o hw18

test5: hw18
	./hw18 inputs/test5 output5
	diff output5 expected/expected5

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c 

clean:
	rm -f *.o a.out code compress? log*



