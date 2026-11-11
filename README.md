# ASSIGNMENT 2 – C++ Programming

## Student Details
- **Name:** Shri Harshini Devi A
- **Register Number:** 192524104
- **Repository:** DSA01-192524104-Assignment2

## Compiler Details
- **Compiler:** GNU G++ (MSYS2)
- **Version:** g++.exe 16.2.0
- **Standard:** C++17
- **Editor:** Visual Studio Code

## How to Compile and Run

Open the VS Code terminal in the main assignment folder.

Example for Task 1:

```bash
g++ -std=c++17 -Wall -Wextra Task01/task01.cpp -o Task01/task01
```

Run on Windows PowerShell:

```powershell
.\Task01\task01.exe
```

Repeat the same process for the other tasks by changing the folder and filename.

## Task Details and Results

### Task 01 – Functions
- Demonstrated call by value, call by reference and call by pointer.
- Implemented functions and default arguments.
- **Result:** Successfully executed.

### Task 02 – Return by Reference
- Demonstrated returning references and copies.
- Used const references.
- Examined the problem of returning a reference to a local variable.
- **Result:** Successfully executed.

### Task 03 – Function Overloading
- Implemented overloaded functions for different parameter types.
- Demonstrated default arguments and a Parcel structure.
- **Result:** Successfully executed.

### Task 04 – Classes and Arrays
- Implemented a SavingsAccount class.
- Stored account transactions using an array.
- Implemented deposit, withdrawal and mini-statement functions.
- **Result:** Successfully executed.

### Task 05 – Static Members and Arrays of Objects
- Demonstrated static data members and static member functions.
- Implemented token generation and bus ticket allocation.
- **Result:** Successfully executed.

### Task 06 – Friend and Inline Functions
- Implemented friend functions to compare Time objects.
- Tested inline and non-inline functions.
- Measured execution time using -O0 and -O2.
- **Result:** Successfully executed and timing results recorded.

### Task 07 – Diagnose, Redesign and Validate
- Identified the shifting limitation in the original transaction array.
- Redesigned the program using a circular array.
- Tested both versions using 12 deposits.
- Both versions produced the same final balance and latest 10 transactions.
- **Result:** Circular array successfully avoided shifting elements during insertion.

## Conclusion

All seven tasks were implemented and tested