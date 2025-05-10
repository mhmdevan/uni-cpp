CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -I include
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include

# Find all cpp files in src directory
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Main targets
all: directories point_test dictionary_test

# Create build directory
directories:
	mkdir -p $(BUILD_DIR)

# Compile main executables
point_test: $(BUILD_DIR)/Point.o $(BUILD_DIR)/PointTest.o
	$(CXX) $(CXXFLAGS) $^ -o $(BUILD_DIR)/$@

dictionary_test: $(BUILD_DIR)/MyString.o $(BUILD_DIR)/Data.o $(BUILD_DIR)/Dictionary.o $(BUILD_DIR)/DictionaryTest.o
	$(CXX) $(CXXFLAGS) $^ -o $(BUILD_DIR)/$@

# Compile object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(BUILD_DIR)/*

# Run all tests
run: all
	@echo "\n=== Running Point Test ==="
	@$(BUILD_DIR)/point_test
	@echo "\n=== Running Dictionary Test ==="
	@$(BUILD_DIR)/dictionary_test

.PHONY: all clean run directories 