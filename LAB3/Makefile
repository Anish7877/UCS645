CXX ?= g++
STD = -std=c++23
OMPFLAG = -fopenmp
CXXFLAGS = -O3 -Wall -Wextra -Wpedantic -march=native
TARGET ?= correlate_matrix
ARGS ?= 1000 1000

SOURCES ?= $(wildcard ./*.cpp)
OBJECTS ?= $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "Linking $@"
	@$(CXX) $(STD) $(CXXFLAGS) $(OMPFLAG) -o $@ $^

%.o: %.cpp
	@echo "Compiling $<"
	@$(CXX) $(STD) $(CXXFLAGS) $(OMPFLAG) -c -o $@ $<

clean:
	@echo "Cleaning..."
	@rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	@./$(TARGET) $(ARGS)

.PHONY: all clean run
