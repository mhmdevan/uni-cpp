CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
SRCDIR = src
INCLUDEDIR = include
BUILDDIR = build
MAIN_TARGET = $(BUILDDIR)/main
VECTOR_TARGET = $(BUILDDIR)/VectorTest
MYSTRING_TARGET = $(BUILDDIR)/MyStringTest
RECTANGLE_TARGET = $(BUILDDIR)/RectangleTest
GALON_TARGET = $(BUILDDIR)/GalonTest

# Source files
MAIN_SRC = $(SRCDIR)/main.cpp
VECTOR_SRC = $(SRCDIR)/Vector.cpp $(SRCDIR)/VectorTest.cpp
MYSTRING_SRC = $(SRCDIR)/MyString.cpp $(SRCDIR)/MyStringTest.cpp
RECTANGLE_SRC = $(SRCDIR)/Rectangle.cpp $(SRCDIR)/RectangleTest.cpp
GALON_SRC = $(SRCDIR)/Galon.cpp $(SRCDIR)/GalonTest.cpp

# Header files
HEADERS = $(INCLUDEDIR)/Vector.h $(INCLUDEDIR)/MyString.h $(INCLUDEDIR)/Rectangle.h $(INCLUDEDIR)/Galon.h

# Default target - build all executables
all: $(MAIN_TARGET) $(VECTOR_TARGET) $(MYSTRING_TARGET) $(RECTANGLE_TARGET) $(GALON_TARGET)

# Create build directory if it doesn't exist
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Main program
$(MAIN_TARGET): $(MAIN_SRC) | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) -o $@ $<

# Vector test program
$(VECTOR_TARGET): $(VECTOR_SRC) | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) -o $@ $^

# MyString test program
$(MYSTRING_TARGET): $(MYSTRING_SRC) | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) -o $@ $^

# Rectangle test program
$(RECTANGLE_TARGET): $(RECTANGLE_SRC) | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) -o $@ $^

# Galon test program
$(GALON_TARGET): $(GALON_SRC) | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) -o $@ $^

# Clean build files
clean:
	rm -rf $(BUILDDIR)/*

# Run the main program
run: $(MAIN_TARGET)
	$(MAIN_TARGET)

# Run individual test programs
run_vector: $(VECTOR_TARGET)
	$(VECTOR_TARGET)

run_mystring: $(MYSTRING_TARGET)
	$(MYSTRING_TARGET)

run_rectangle: $(RECTANGLE_TARGET)
	$(RECTANGLE_TARGET)

run_galon: $(GALON_TARGET)
	$(GALON_TARGET)

.PHONY: all clean run run_vector run_mystring run_rectangle run_galon 