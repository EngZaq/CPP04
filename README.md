# CPP04 - Object-Oriented Programming: Inheritance & Polymorphism

## Overview

CPP04 is a C++ project demonstrating fundamental Object-Oriented Programming (OOP) concepts including inheritance, polymorphism, virtual methods, abstract classes, and deep copy semantics. The project progresses through three exercises, each building on previous concepts with increasing complexity.

All code is written in **C++98** with strict compilation flags (`-Wall -Wextra -Werror`) to ensure code quality.

---

## Project Structure

```
CPP04/
├── ex00/               # Basic Inheritance & Polymorphism
│   ├── Animal.cpp      # Base class implementation
│   ├── Animal.hpp      # Base class header
│   ├── Dog.cpp         # Dog derived class
│   ├── Dog.hpp
│   ├── Cat.cpp         # Cat derived class
│   ├── Cat.hpp
│   ├── WrongAnimal.cpp # Non-virtual example
│   ├── WrongAnimal.hpp
│   ├── WrongCat.cpp    # Non-virtual example
│   ├── WrongCat.hpp
│   ├── main.cpp        # Test program
│   └── Makefile
│
├── ex01/               # Brain Attribute & Deep Copy
│   ├── Animal.cpp
│   ├── Animal.hpp
│   ├── Dog.cpp         # With private Brain*
│   ├── Dog.hpp
│   ├── Cat.cpp         # With private Brain*
│   ├── Cat.hpp
│   ├── Brain.cpp       # Brain class with ideas array
│   ├── Brain.hpp
│   ├── main.cpp        # Array of Animals + deep copy tests
│   └── Makefile
│
└── ex02/               # Abstract Classes & Full Deep Copy
    ├── Animal.cpp      # Abstract base class
    ├── Animal.hpp      # Pure virtual makeSound()
    ├── Dog.cpp         # Implements makeSound()
    ├── Dog.hpp
    ├── Cat.cpp         # Implements makeSound()
    ├── Cat.hpp
    ├── Brain.cpp       # Brain with content copying
    ├── Brain.hpp
    ├── main.cpp        # Abstract class + deep copy tests
    └── Makefile
```

---

## Exercise Details

### EX00: Basic Inheritance & Polymorphism

**Concepts:**
- Class inheritance (`public`)
- Virtual methods
- Virtual destructors
- Polymorphic behavior

**Key Classes:**
- `Animal` - Base class with virtual `makeSound()`
- `Dog` - Derived from Animal, overrides `makeSound()`
- `Cat` - Derived from Animal, overrides `makeSound()`
- `WrongAnimal` - Demonstrates non-virtual behavior (for comparison)
- `WrongCat` - Non-virtual derived class

**Features:**
- Virtual destructors ensure proper cleanup order
- Demonstrates why virtual methods are important
- Shows the difference between virtual and non-virtual inheritance

**Compilation:**
```bash
cd ex00
make
./polymorphism
```

---

### EX01: Brain Attribute & Deep Copy

**Concepts:**
- Member attributes (pointers)
- Deep copy vs shallow copy
- Copy constructors and assignment operators
- Memory management with `new`/`delete`

**Key Classes:**
- `Animal` - Base class (unchanged from ex00)
- `Dog` - Has private `Brain*` attribute
- `Cat` - Has private `Brain*` attribute
- `Brain` - Contains array of 100 ideas (strings)

**Features:**
- Each Dog/Cat allocates a Brain in constructor: `new Brain()`
- Each Dog/Cat deletes its Brain in destructor: `delete _brain`
- Copy constructors create NEW Brain instances (deep copy)
- Assignment operators copy Brain content
- Array of Animals demonstrates polymorphic cleanup
- **Deep copy verification tests included**

**Deep Copy Test Output:**
```
--- Testing deep copy for Dog ---
dog1 brain address: 0xda17300
dog2 brain address: 0xda17fd0
✓ Dog copy is a DEEP COPY (different Brain instances)

--- Testing deep copy for Cat ---
cat1 brain address: 0xda18ca0
cat2 brain address: 0xda19970
✓ Cat copy is a DEEP COPY (different Brain instances)
```

**Compilation:**
```bash
cd ex01
make
./polymorphism
```

---

### EX02: Abstract Classes & Full Deep Copy

**Concepts:**
- Pure virtual methods (abstract classes)
- Cannot instantiate abstract classes
- Mandatory implementation in derived classes
- Full deep copy with data content

**Key Classes:**
- `Animal` - Abstract base class with pure virtual `makeSound() = 0`
- `Dog` - Concrete class, implements all pure virtual methods
- `Cat` - Concrete class, implements all pure virtual methods
- `Brain` - Properly copied with content in copy operations

**Features:**
- Animal class CANNOT be instantiated
- Only Dog and Cat can be created
- Copy constructors create new Brain and copy all content
- Assignment operators copy both type and Brain content
- Demonstrates proper abstraction and interface design
- **Deep copy verification tests included**

**Deep Copy Test Output:**
```
--- Testing deep copy for Dog ---
dog1 brain address: 0xd44bf00
dog2 brain address: 0xd44cbd0
✓ Dog copy is a DEEP COPY (different Brain instances)

--- Testing deep copy for Cat ---
cat1 brain address: 0xd44d8a0
cat2 brain address: 0xd44e570
✓ Cat copy is a DEEP COPY (different Brain instances)
```

**Compilation:**
```bash
cd ex02
make
./polymorphism
```

---

## Key Features & Compliance

### C++98 Standards
- ✅ No C++11/14/17 features
- ✅ Proper `std::` namespace usage
- ✅ Strict compiler flags: `-Wall -Wextra -Werror -std=c++98`

### Memory Management
- ✅ No memory leaks (verified with Valgrind)
- ✅ All `new` allocations paired with `delete`
- ✅ Proper cleanup order in destructors

### Object-Oriented Design
- ✅ Virtual methods and virtual destructors
- ✅ Const correctness (const methods, const parameters)
- ✅ Proper access specifiers (private, protected, public)
- ✅ Copy semantics (deep copy)

### Code Quality
- ✅ Clean, readable code
- ✅ Comprehensive error handling
- ✅ Proper encapsulation
- ✅ Deep copy verification tests

---

## Building the Project

### All Exercises
```bash
# Build all
make -C ex00 && make -C ex01 && make -C ex02

# Clean all
make -C ex00 fclean && make -C ex01 fclean && make -C ex02 fclean
```

### Individual Exercise
```bash
cd ex00  # or ex01, ex02
make     # Build
make run # Run
make re  # Rebuild
make clean   # Remove object files
make fclean  # Remove all generated files
```

---

## Testing

### Run All Exercises
```bash
cd ex00 && ./polymorphism && cd ../ex01 && ./polymorphism && cd ../ex02 && ./polymorphism
```

### Memory Leak Testing
```bash
valgrind --leak-check=full ./polymorphism
```

### Compilation Verification
```bash
# All exercises compile with strict flags
c++ -Wall -Wextra -Werror -std=c++98
```

---

## Learning Outcomes

After completing CPP04, you understand:

1. **Inheritance** - Creating derived classes from base classes
2. **Polymorphism** - Virtual methods and dynamic dispatch
3. **Virtual Destructors** - Proper cleanup in inheritance hierarchies
4. **Abstract Classes** - Using pure virtual methods to define interfaces
5. **Deep Copy** - Proper implementation of copy constructors and assignment operators
6. **Memory Management** - Allocating and deallocating dynamic memory
7. **Encapsulation** - Using access specifiers to hide implementation details
8. **Const Correctness** - Marking methods and parameters appropriately

---

## Key Concepts Demonstrated

### Virtual Functions
```cpp
class Animal {
public:
    virtual void makeSound() const;  // Can be overridden
    virtual ~Animal();                // Always virtual in base classes
};

class Dog : public Animal {
public:
    void makeSound() const;  // Overrides parent
};
```

### Abstract Classes (EX02)
```cpp
class Animal {
public:
    virtual void makeSound() const = 0;  // Pure virtual, must implement
    virtual ~Animal();
};

// Cannot create: Animal a;  ERROR!
// Must create: Dog d;       OK!
```

### Deep Copy
```cpp
Dog::Dog(const Dog& other) : Animal(other) {
    this->_brain = new Brain(*other._brain);  // Copy content, not pointer
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        *(_brain) = *(other._brain);  // Copy Brain content
    }
    return *this;
}
```

---

## Compilation Output Example

```
$ cd ex01 && make clean && make
rm -f main.o Animal.o Dog.o Cat.o Brain.o
c++ -Wall -Wextra -Werror -std=c++98 -c main.cpp -o main.o
c++ -Wall -Wextra -Werror -std=c++98 -c Animal.cpp -o Animal.o
c++ -Wall -Wextra -Werror -std=c++98 -c Dog.cpp -o Dog.o
c++ -Wall -Wextra -Werror -std=c++98 -c Cat.cpp -o Cat.o
c++ -Wall -Wextra -Werror -std=c++98 -c Brain.cpp -o Brain.o
c++ -Wall -Wextra -Werror -std=c++98 main.o Animal.o Dog.o Cat.o Brain.o -o polymorphism
```

**Result:** ✅ No errors, no warnings

---

## Status

✅ **All exercises complete and fully functional**
- ✅ No compilation errors or warnings
- ✅ No memory leaks (verified with Valgrind)
- ✅ All deep copy tests pass
- ✅ Proper destructor cleanup order
- ✅ C++98 compliant
- ✅ Production ready

---

## Author

CPP04 Project - C++ Learning Series
