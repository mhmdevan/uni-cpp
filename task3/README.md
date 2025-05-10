# Task 3: Multilevel and Multiple Inheritance in C++

This project demonstrates multilevel and multiple inheritance in C++ through a person census system.

## Class Hierarchy

The project implements a comprehensive class hierarchy with several levels of inheritance:

### Base Class
- `Person`: Represents a generic person with common attributes (name, address, phone)

### First Level of Inheritance (Multilevel Inheritance)
- `NaturalPerson`: Represents individual human beings (inherits from Person)
- `LegalPerson`: Represents legal entities like companies (inherits from Person) 
- `GovernmentEntity`: Represents government organizations (inherits from Person)

### Second Level of Inheritance (Multilevel Inheritance)
- `Employer`: Represents a working individual (inherits from NaturalPerson)
- `Supervisor`: Represents a managerial individual (inherits from NaturalPerson)
- `Ltda`: Represents a limited company (inherits from LegalPerson)
- `SA`: Represents a corporation (inherits from LegalPerson)

### Third Level of Inheritance (Multiple Inheritance)
- `PublicCompany`: Represents a publicly owned company (inherits from both SA and GovernmentEntity)

## Features Demonstrated

1. **Multilevel Inheritance**:
   - Class hierarchies with multiple levels
   - Inheritance of attributes and methods
   - Method overriding

2. **Multiple Inheritance**:
   - A class inheriting from two parent classes
   - Handling of the "diamond problem"
   - Disambiguation of inherited attributes and methods

3. **Polymorphism**:
   - Virtual methods
   - Base class pointers with derived class objects
   - Runtime method resolution

## File Structure

- `include/Person.h`: Contains all class declarations
- `src/Person.cpp`: Contains all class implementations
- `src/main.cpp`: Test program demonstrating inheritance features
- `CMakeLists.txt`: Build configuration file

## Building and Running

```bash
cd task3
mkdir build
cd build
cmake ..
make
./task3
```

## Analysis

The program includes analysis of advantages and disadvantages of both multilevel and multiple inheritance patterns in C++. 