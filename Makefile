CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -Wextra -O2

PROG ?= main
OBJS = main.o StdSort.o QuickSelect1.o QuickSelect2.o CountingSort.o

all: $(PROG)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(PROG): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	rm -rf $(EXEC) *.o *.out main 

rebuild: clean all
