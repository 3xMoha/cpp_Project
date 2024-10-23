# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Source files and output
SRCS = main.cpp sort.cpp sort_d.cpp complete_d.cpp complete_i.cpp task_comp.cpp task_comp_d.cpp compare.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = sorting_program

# Default target to build and run
all: $(EXEC)

# Compile the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Rule to compile object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cross-platform clean
clean:
ifeq ($(OS),Windows_NT)
	del /F /Q $(OBJS) $(EXEC).exe
else
	rm -f $(OBJS) $(EXEC)
endif

# Run the program after building
run: all
	./$(EXEC)
