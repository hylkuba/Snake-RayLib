#    @author Jakub Hýl <hylkuba@gmail.com>
#    @date 11.01.2024

# Compiler and flags
CXX = g++
CXXFLAGS = -O2 -Wall -Wno-missing-braces
INCLUDES = -I../include/
LIBS = -L../lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

# Source files
SRCS = $(wildcard ../src/*.cpp)
OBJS = $(addprefix bin/,$(notdir $(SRCS:.cpp=.o)))  # Store .o files in the bin folder

# Executable name
EXEC = Snake.exe

# Build rule
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)

# Compilation rule for object files
bin/%.o: ../src/%.cpp
	@mkdir -p bin  # Create the bin folder if it doesn't exist
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

# Compile target
compile: $(EXEC)

# Run target
run: compile
	./$(EXEC)

# Clean rule
clean:
	rm -rf bin $(EXEC)

# All
all: compile run clean

.PHONY: all