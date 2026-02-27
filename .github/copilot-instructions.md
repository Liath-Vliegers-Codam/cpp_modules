# Copilot Instructions for C++11 Projects
<instructions>
# Copilot Instructions for C++11 Projects

## 🎯 Primary Goal
Generate C++ code that adheres to C++11 best practices and the specific guidelines outlined below.

## 📜 Core Language & Compiler Rules

1.  **C++ Standard:**
    *   All code **MUST** be C++11 compliant.
    *   Do NOT use features introduced after C++11 (no `std::format`, no structured bindings, no ranges, etc.).
2.  **Compiler:**
    *   The code will typically be compiled with a C++11-compatible compiler (e.g., g++, clang++).
    *   Compilation **MUST** succeed with flags like: `-Wall -Wextra -Werror -std=c++11`.
3.  **Standard Library:**
    *   Use the C++11 standard library (`<iostream>`, `<string>`, `<vector>`, `<map>`, etc.).
    *   Do NOT use features or headers introduced after C++11.
4.  **C-Style Functions:**
    *   Prefer C++ alternatives.
    *   For I/O, use `<iostream>` (`std::cout`, `std::cin`). Avoid `printf`, `scanf` unless necessary.
    *   For memory management, use RAII and containers. Avoid `malloc()`, `calloc()`, `realloc()`, and `free()`.
5.  **Namespace Usage:**
    *   Avoid `using namespace <ns_name>;` directives in header files.
    *   `using` declarations for specific symbols (e.g., `using std::cout;`) are acceptable in source (`.cpp`) files.
    *   In header files, always qualify names (e.g., `std::string`, `std::vector`).
6.  **STL Containers & Algorithms:**
    *   Use STL containers and algorithms as provided in C++98.

## 🏗️ Code Structure & Naming Conventions

1.  **File Naming:**
    *   Class files: `ClassName.hpp` for headers, `ClassName.cpp` for source files.
2.  **Class Naming:**
    *   Use `UpperCamelCase` for class names.
3.  **Header Files:**
    *   Use `#pragma once` at the beginning of all header files.
    *   Headers must include all their own direct dependencies.
    *   Headers should primarily contain declarations.
    *   Non-template function definitions belong in source (`.cpp`) files.

## 🛠️ Design Requirements

1.  **Resource Management & The Rule of Three:**
    *   Use RAII (Resource Acquisition Is Initialization).
    *   If a class manages a raw resource, implement:
        *   Destructor
        *   Copy Constructor
        *   Copy Assignment Operator
    *   Ensure deep copies are made when necessary.
2.  **Memory Management:**
    *   Prefer containers and smart pointers over raw pointers for ownership where appropriate.
    *   If using `new` and `delete`, ensure they are perfectly paired and managed within an RAII class.
    *   Avoid memory leaks.
3.  **Output:**
    *   All output messages to standard output **MUST** end with a newline character (prefer `'\n'` or `std::endl`).

## 📝 General Coding Style

1.  **Readability & Maintainability:**
    *   Prioritize clean, readable, understandable, and maintainable code.
    *   Use meaningful variable, function, and class names.
    *   Follow consistent formatting.
2.  **Makefile/Build System:**
    *   Assume a build system (e.g., Makefile).
    *   For Makefiles:
        *   Compiler: `CXX = c++`
        *   Flags: `CXXFLAGS = -Wall -Wextra -Werror -std=c++11`
        *   Common targets: `all`, `clean`, `fclean`, `re`.

## 🚨 Important Note
    **DO NOT EVER PUT COMMENTS ALL OVER THE CODE.**
    Comments should be used sparingly and only when necessary to clarify complex logic or design decisions. The code itself should be self-explanatory through clear naming and structure.

By following these instructions, you will help me produce high-quality, C++11 code.
