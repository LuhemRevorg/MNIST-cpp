########## Variables ##########

CXX = g++-15
CXXFLAGS = -std=c++20 -O3 -Wall -Werror=vla -fopenmp -MMD
LDFLAGS = -fopenmp
EXEC = mnist

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
DEPENDS = $(OBJECTS:.o=.d)

########## Targets ##########

.PHONY: clean

# Default target: build the executable
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) -o $@

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include dependency files
-include $(DEPENDS)

# Clean build artifacts
clean:
	rm -f $(EXEC) $(OBJECTS) $(DEPENDS)