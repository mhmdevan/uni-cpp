CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -I include
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include

# Find all cpp files in src directory
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Main targets
all: directories account_test shape_test person_test

# Create build directory
directories:
	mkdir -p $(BUILD_DIR)

# Compile main executables
account_test: $(BUILD_DIR)/Account.o $(BUILD_DIR)/AccountTest.o
	$(CXX) $(CXXFLAGS) $^ -o $(BUILD_DIR)/$@

shape_test: $(BUILD_DIR)/Shape.o $(BUILD_DIR)/ShapeTest.o
	$(CXX) $(CXXFLAGS) $^ -o $(BUILD_DIR)/$@

person_test: $(BUILD_DIR)/Person.o $(BUILD_DIR)/main.o
	$(CXX) $(CXXFLAGS) $^ -o $(BUILD_DIR)/$@

# Compile object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(BUILD_DIR)/*

# Run all tests
run: all
	@echo "\n=== Running Account Test ==="
	@$(BUILD_DIR)/account_test
	@echo "\n=== Running Shape Test ==="
	@$(BUILD_DIR)/shape_test
	@echo "\n=== Running Person Test ==="
	@$(BUILD_DIR)/person_test

.PHONY: all clean run directories 