# Universal Makefile for single C++ program with X11

########## Variables ##########

CXX = g++                              # Compiler (use g++ if preferred and available)
CXXFLAGS = -std=c++20 -g -Wall -Werror=vla -MMD  # Compiler flags
LDFLAGS = -L/opt/X11/lib -lX11            # Linker flags (add X11 library path and linking)
INCLUDES = -I/opt/X11/include             # Include directories for X11 headers
MAKEFILE_NAME = ${firstword ${MAKEFILE_LIST}}  # Makefile name

SOURCES = $(wildcard *.cpp)                # Source files (*.cc)
OBJECTS = ${SOURCES:.cpp=.o}               # Object files from sources
DEPENDS = ${OBJECTS:.o=.d}                # Dependency files (*.d)
EXEC = mnist                             # Executable name

########## Targets ##########

.PHONY: clean                             # Declare phony target

# Link object files into the final executable
${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} ${LDFLAGS} -o $@

# Compile C++ source files into object files (Make's implicit rule with modifications)
%.o: %.cpp
	${CXX} ${CXXFLAGS} ${INCLUDES} -c $< -o $@

# Include dependency files for automatic rebuilds
-include ${DEPENDS}

# Clean up generated files
clean:
	rm -f ${DEPENDS} ${OBJECTS} ${EXEC}
