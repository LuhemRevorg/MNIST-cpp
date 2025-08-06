########## Variables ##########

CXX = g++
CXXFLAGS = -std=c++20 -g -Wall -Werror=vla -MMD
EXEC = mnist

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
DEPENDS = $(OBJECTS:.o=.d)

########## Targets ##########

.PHONY: clean

# Default target: build the executable
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include dependency files
-include $(DEPENDS)

# Clean build artifacts
clean:
	rm -f $(EXEC) $(OBJECTS) $(DEPENDS)