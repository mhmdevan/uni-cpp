# Task 4: Operator Overloading and Key-Value Database

This project implements two major C++ tasks:

## Task 1: Point Class with Operator Overloading

A `Point` class that demonstrates:

- Private data members with public accessors
- Multiple constructors (default, parameterized, copy)
- Operator overloading using both member functions and friend functions
- Implementation of chained operations

### Operators Implemented:

- `+=` operator as a member function:
  - `p1 += p2` (adding two points)
  - `p1 += numeric_value` (adding a number to both coordinates)
  - Chained operations: `p1 += p2 += numeric_value`

- `-=` operator as a friend function:
  - `p1 -= p2` (subtracting two points)
  - `p1 -= numeric_value` (subtracting a number from both coordinates)
  - Chained operations: `p1 -= p2 -= numeric_value`

- Binary `+` operator as a member function:
  - `p1 + p2` (adding two points)
  - `p1 + numeric_value` (adding a number to both coordinates)

- Binary `-` operator as a friend function:
  - `p1 - p2` (subtracting two points)
  - `p1 - numeric_value` (subtracting a number from both coordinates)
  - `numeric_value - p1` (subtracting point coordinates from a number)

## Task 2: Key-Value Database

An employer database using the key-value pattern with:

- `MyString` class for string handling
- `Data` class with:
  - position (MyString)
  - age (int)
  - gender (enum MALE/FEMALE)
  - salary (double)
- `Dictionary` class that:
  - Stores key (MyString surname) and value (Data)
  - Provides operations:
    - Insert new entries
    - Print all objects with keys and values
    - Delete objects by key

### Key Classes:

- `MyString`: Custom string class with overloaded operators
- `Data`: Employee data container
- `Entry`: Key-value pair structure
- `Dictionary`: The database implementation

## Directory Structure

- `include/`: Header files
- `src/`: Implementation files
- `build/`: Compiled binaries
- `Makefile`: Build automation

## Building and Running

```bash
# Build all tests
make

# Run all tests
make run

# Clean build artifacts
make clean
```

## Author

Created as a university C++ programming assignment. 