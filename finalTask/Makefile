CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -I include
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include
DATA_DIR = data

# Find all cpp files in src directory
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Main executable
TARGET = $(BUILD_DIR)/blockchain

# Create build and data directories
directories:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(DATA_DIR)

# Compile main executable
$(TARGET): $(OBJS) directories
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Compile object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp directories
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(BUILD_DIR)/*

# Run the program
run: $(TARGET)
	./$(TARGET)

# Default target
all: $(TARGET)

.PHONY: all clean run directories 