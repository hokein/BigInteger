VPATH = ../src
OBJS = gtest.o BigInteger.o
elf = gtest 

$(elf):$(OBJS)
	$(CC) $(OBJS) -o $(elf) -lpthread -lgtest -lgtest_main

clean:
	rm -rf *.o $(elf) 

