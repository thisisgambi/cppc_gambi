
CXX=g++
CFLAGS=-std=c++11 -Wall -Wextra -pedantic
LDFLAGS=-pthread ~/opt/gtest/lib/libgtest.a

INCLUDES=-I/home/g4mb1/opt/gtest/include -I../

OBJS = 		testsuite.o \
			list_test.o

.DEFAULT: all
all: $(OBJS) testsuite.bin

run: clean testsuite.bin
	./testsuite.bin

%.o: %.c
	$(CXX) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.cc
	$(CXX) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.bin: $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

.PHONY: clean
clean:
	-rm -f *.o
	-rm -f *.a
	-rm -f *.bin
	-rm -f ../solution/*.o
	-rm -f ../solution/*.a

