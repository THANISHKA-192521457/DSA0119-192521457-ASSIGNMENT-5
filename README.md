# ASSIGNMENT 5 – CO5
## Reliable Software with Runtime Polymorphism and Exceptions

### Student Details

- **Name:** S. Thanishka
- **Register Number:** 192521457
- **Course Outcome:** CO5
- **Repository Name:** DSA01-192521457-Assignment5
- **Programming Language:** C++

---

## 1. Introduction

This assignment focuses on developing reliable C++ applications using virtual functions, runtime polymorphism, abstract classes, and exception handling.

The project uses a hospital billing and insurance claim system. It handles different types of hospital bills and payment methods while ensuring correct calculations and safe error handling.

## 2. Objectives

- Understand runtime polymorphism and virtual functions.
- Design abstract classes and derived classes.
- Implement hospital billing calculations.
- Apply exception handling using try, catch and throw.
- Understand virtual destructors and RAII.
- Compare virtual functions, switch statements and exceptions.
- Measure program performance and analyze results.
- Develop reliable and error-resilient C++ applications.

## 3. Technologies Used

- C++ Programming Language
- g++ Compiler
- C++17 Standard
- Git and GitHub
- AddressSanitizer
- Visual Studio Code

## 4. Task Description

### PART A – DESIGN

**Task A1 – Design the Polymorphic Bill Hierarchy**
- Identify the common interface.
- Design the abstract Bill class.
- Create derived bill classes.
- Prepare UML diagrams and pseudocode.
- Analyze time and space complexity.

**Task A2 – Understand Runtime Binding**
- Explain early and late binding.
- Design virtual table diagrams.
- Understand virtual destructors.
- Predict and verify program output.

**Task A3 – Design with Abstract Classes**
- Create an abstract Payer class.
- Implement SelfPay, Insurance and GovernmentScheme.
- Demonstrate how a new payer can be added without modifying existing classes.

**Task A4 – Design the Exception Strategy**
- Identify possible billing errors.
- Design an exception class hierarchy.
- Use appropriate exception handling.
- Explain noexcept and destructor safety.

**Task A5 – Design Recovery and Rethrowing**
- Implement catch and rethrow mechanisms.
- Understand stack unwinding.
- Apply RAII for resource management.
- Predict and verify program output.

### PART B – IMPLEMENTATION AND EXPERIMENTAL INVESTIGATION

**Task B1 – Implement and Validate the Polymorphic Billing**
- Implement different bill types.
- Test each bill with different payers.
- Verify billing totals.
- Demonstrate runtime binding and virtual destructors.

**Task B2 – Engineer Error Conditions**
- Test negative charges.
- Handle claims exceeding policy cover.
- Handle unknown package codes.
- Handle invalid numeric input.
- Test memory allocation errors.
- Implement exception rethrowing.

**Task B3 – Virtual Functions vs Switch vs Exceptions**
- Compare virtual functions and switch statements.
- Test the same 10 bills using both approaches.
- Measure execution time for different data sizes.
- Compare exception handling and return-code approaches.
- Analyze performance results.

**Task B4 – Final Engineering Decision**
- Add a new bill type.
- Add a new payer type.
- Test resource safety using AddressSanitizer.
- Evaluate the suitability of the design for the hospital group.

## 5. Compilation and Execution

Compile the C++ programs using:

```bash
g++ -std=c++17 -Wall -Wextra filename.cpp -o output
```

Run the program:

```bash
./output
```

For AddressSanitizer testing:

```bash
g++ -std=c++17 -Wall -Wextra -fsanitize=address -fno-omit-frame-pointer filename.cpp -o output
```

Run the sanitizer program:

```bash
./output
```

For performance testing:

```bash
g++ -std=c++17 -Wall -Wextra -O2 benchmark.cpp -o benchmark
```

## 6. Expected Folder Structure

```text
DSA01-192521457-Assignment5/
│
├── README.md
│
├── Task01/
│   ├── pseudocode.txt
│   └── UML_Diagram.png
│
├── Task02/
│   ├── vtable_demo.cpp
│   └── vtable_diagram.png
│
├── Task03/
│   ├── payer_demo.cpp
│   └── payer_diagram.png
│
├── Task04/
│   ├── exceptions_demo.cpp
│   └── exception_hierarchy.png
│
├── Task05/
│   ├── raii_rethrow.cpp
│   └── output.png
│
├── Task06/
│   ├── billing.cpp
│   └── output.png
│
├── Task07/
│   ├── claim.cpp
│   └── test_cases.png
│
├── Task08/
│   ├── benchmark.cpp
│   └── results.txt
│
└── Task09/
    ├── extension.cpp
    └── output.png
```

## 7. Testing and Validation

All programs should be compiled and executed using the C++17 standard.

Testing includes:
- Normal billing calculations.
- Different bill and payer combinations.
- Invalid input conditions.
- Exception handling and rethrowing.
- Memory safety testing.
- Performance comparison.

Actual output screenshots, benchmark measurements and sanitizer reports should be added after executing the programs.

## 8. Conclusion

This assignment demonstrates how runtime polymorphism and exception handling can be used to develop reliable C++ applications. The hospital billing system supports different bill types and payment methods through abstract classes and virtual functions.

Exception handling helps identify and manage errors safely, while RAII ensures proper resource management. Performance testing helps evaluate different implementation approaches.

The project demonstrates the importance of extensibility, correctness, performance and resource safety in software development.

---

**Submitted by:** S. Thanishka  
**Register Number:** 192521457  
**Repository:** DSA01-192521457-Assignme
