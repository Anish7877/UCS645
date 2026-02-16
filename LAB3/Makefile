CXX ?= g++
STD = -std=c++23
OMPFLAG  = -fopenmp
CXXFLAGS = -O3 -Wall -Wextra -Wpedantic -march=native
TARGET ?= correlate_matrix

SOURCES ?= $(wildcard ./*.cpp)
OBJECTS ?= $(patsubst ./%.cpp, ./%.o, $(SOURCES))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@$(CXX) $(STD) $(CXXFLAGS) $(OMPFLAG) -o $@ $^

%.o: $(SOURCES)
	@echo "Compiling $<"
	@$(CXX) $(STD) $(OMPFLAG) -c -o $@ $<

clean:
	@echo "Cleaning..."
	@rm *.o
	@rm $(TARGET)

run:
	@./$(TARGET)

.PHONY: all clean run
