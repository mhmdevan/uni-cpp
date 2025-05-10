CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
INCLUDE_DIR = include
SRC_DIR = src
BUILD_DIR = build
TARGET = $(BUILD_DIR)/data_structures

# Source files
SOURCES = $(SRC_DIR)/main.cpp \
          $(SRC_DIR)/BinaryTree.cpp \
          $(SRC_DIR)/LinkedList.cpp \
          $(SRC_DIR)/DoubleLinkedList.cpp

# Object files
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compiling
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)

# Run the program
run: $(TARGET)
	$(TARGET)

.PHONY: all clean run 