CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
SRCDIR = src
INCLUDEDIR = include
BUILDDIR = build
MAIN_TARGET = $(BUILDDIR)/main
MYSTRING_TARGET = $(BUILDDIR)/MyStringTest
COMPLEX_TARGET = $(BUILDDIR)/ComplexTest
CLIENT_TARGET = $(BUILDDIR)/ClientTest

# Source files
MAIN_SRC = $(SRCDIR)/main.cpp
MYSTRING_SRC = $(SRCDIR)/MyString.cpp $(SRCDIR)/MyStringTest.cpp
COMPLEX_SRC = $(SRCDIR)/Complex.cpp $(SRCDIR)/ComplexTest.cpp
CLIENT_SRC = $(SRCDIR)/Client.cpp $(SRCDIR)/ClientTest.cpp

# Header files
HEADERS = $(INCLUDEDIR)/MyString.h $(INCLUDEDIR)/Complex.h $(INCLUDEDIR)/Client.h

# Default target - build all executables
all: $(MAIN_TARGET) $(MYSTRING_TARGET) $(COMPLEX_TARGET) $(CLIENT_TARGET)

# Create build directory if it doesn't exist
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Main program
$(MAIN_TARGET): $(MAIN_SRC) | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) -o $@ $<

# MyString test program
$(MYSTRING_TARGET): $(MYSTRING_SRC) | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) -o $@ $^

# Complex test program
$(COMPLEX_TARGET): $(COMPLEX_SRC) | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) -o $@ $^

# Client test program
$(CLIENT_TARGET): $(CLIENT_SRC) | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDEDIR) -o $@ $^

# Clean build files
clean:
	rm -rf $(BUILDDIR)/*

# Run the main program
run: $(MAIN_TARGET)
	$(MAIN_TARGET)

# Run individual test programs
run_mystring: $(MYSTRING_TARGET)
	$(MYSTRING_TARGET)

run_complex: $(COMPLEX_TARGET)
	$(COMPLEX_TARGET)

run_client: $(CLIENT_TARGET)
	$(CLIENT_TARGET)

.PHONY: all clean run run_mystring run_complex run_client 