# Copilot Instructions for Modern C++ Projects (C++23 Standard)

## 🎯 Primary Goal
Generate C++ code that adheres to modern C++23 best practices and the specific guidelines outlined below.

## 📜 Core Language & Compiler Rules

1.  **C++ Standard:**
    *   All code **MUST** be C++23 compliant.
    *   Utilize modern C++ features where appropriate (e.g., concepts, ranges, coroutines, modules if project setup allows, `std::format`, smart pointers, move semantics, etc.).
2.  **Compiler:**
    *   The code will typically be compiled with a modern C++ compiler (e.g., g++, clang++).
    *   Compilation **MUST** succeed with flags like: `-Wall -Wextra -Werror -std=c++23` (or the equivalent for your compiler, like `-std=c++2b`).
3.  **Standard Library:**
    *   You **CAN** and **SHOULD** use the C++23 standard library extensively.
    *   Prioritize C++ standard library features (e.g., `std::cout`, `std::format`, `std::string`, `std::vector`, `std::map`, algorithms, smart pointers) over older C-style approaches or manual implementations where the library provides a robust solution.
4.  **C-Style Functions:**
    *   **Strongly prefer C++ alternatives.**
    *   For I/O, use `<iostream>` (`std::cout`, `std::cin`) or `<format>` (`std::format`). Avoid `printf`, `scanf` unless there's a compelling, specific reason.
    *   For memory management, use RAII, smart pointers (`std::unique_ptr`, `std::shared_ptr`, `std::make_unique`, `std::make_shared`), and containers. Avoid `malloc()`, `calloc()`, `realloc()`, and `free()`.
5.  **Namespace Usage:**
    *   **Avoid `using namespace <ns_name>;` directives in header files** to prevent namespace pollution.
    *   `using` declarations for specific symbols (e.g., `using std::cout;`) are acceptable in source (`.cpp`) files where they improve readability.
    *   In header files, always qualify names (e.g., `std::string`, `std::vector`).
6.  **`friend` Keyword:**
    *   The `friend` keyword can be used where appropriate for granting specific, limited access to class internals (e.g., for helper functions, specific classes in a library design). Use it judiciously and with clear justification.
7.  **STL Containers & Algorithms:**
    *   **Fully encouraged.** Use STL containers and algorithms as they are fundamental to modern C++ development for writing efficient, readable, and maintainable code.

## 🏗️ Code Structure & Naming Conventions

1.  **File Naming:**
    *   Class files: `ClassName.hpp` for headers, `ClassName.cpp` for source files.
    *   For template classes, implementations are typically in the header file (`.hpp`) or a separate template implementation file (`.tpp`) included by the header.
2.  **Class Naming:**
    *   Use `UpperCamelCase` for class names (e.g., `MyAwesomeClass`).
3.  **Header Files:**
    *   **Include Guards:** Use `#pragma once` at the beginning of all header files.
        ```cpp
        #pragma once

        // ... other includes ...
        // ... class definition / declarations ...
        ```
    *   **Self-Sufficiency:** Headers must include all their own direct dependencies.
    *   **Declarations vs. Definitions:**
        *   Headers should primarily contain declarations (class definitions, function declarations, template definitions).
        *   Non-template function definitions and non-inline member function definitions belong in source (`.cpp`) files.
        *   Inline functions and template definitions (both class and function templates) are typically placed in header files.

## 🛠️ Design Requirements

1.  **Resource Management & The Rule of Zero/Three/Five:**
    *   **Emphasize RAII (Resource Acquisition Is Initialization).** Resources (memory, file handles, locks, etc.) should be managed by objects.
    *   **Strive for the Rule of Zero:** If a class solely uses RAII types (like `std::string`, `std::vector`, smart pointers) for resource management and doesn't directly manage raw pointers or other complex resources, it often doesn't need custom copy/move constructors, assignment operators, or a destructor. The compiler-generated ones will do the right thing.
    *   **Rule of Three/Five:** If a class *does* manage a raw resource directly (e.g., a raw pointer acquired with `new`), you will likely need to implement:
        *   Destructor
        *   Copy Constructor
        *   Copy Assignment Operator
        *   (And for modern C++, also consider) Move Constructor
        *   Move Assignment Operator
    *   Ensure deep copies are made when necessary and that move operations correctly transfer ownership and leave the moved-from object in a valid (though unspecified) state.
2.  **Memory Management:**
    *   **Prefer smart pointers** (`std::unique_ptr`, `std::shared_ptr`) over raw pointers for ownership.
    *   If using `new` and `delete` (or `new[]` and `delete[]`) directly, ensure they are perfectly paired and managed within an RAII class or follow the Rule of Three/Five.
    *   Avoid memory leaks.
3.  **Output:**
    *   All output messages to standard output **MUST** end with a newline character (prefer `'\n'` for performance-sensitive console output, or `std::endl` if an explicit flush is needed, though often `'\n'` is sufficient as `std::cout` is often line-buffered).
    *   Consider using `std::format` (C++20/23) for complex output formatting.

## 📝 General Coding Style

1.  **Readability & Maintainability:**
    *   Prioritize clean, readable, understandable, and maintainable code.
    *   Use meaningful variable, function, and class names.
    *   Follow consistent formatting (e.g., using a tool like ClangFormat if desired).
2.  **Makefile/Build System:**
    *   Assume a build system (e.g., Makefile, CMake).
    *   For Makefiles:
        *   Compiler: `CXX = c++` (or `g++`, `clang++`)
        *   Flags: `CXXFLAGS = -Wall -Wextra -Werror -std=c++23` (or appropriate standard version)
        *   Common targets: `all`, `clean`, `fclean`, `re`.

## 💡 When Assisting

*   **Embrace Modern C++:** Suggest and use C++23 features and idioms.
*   **Adhere Strictly:** Follow these guidelines, especially regarding the C++23 standard, header structure, and resource management.
*   **Explain Choices:** Briefly explain design choices, especially when they relate to modern C++ best practices (e.g., RAII, Rule of Zero, choice of smart pointer).
*   **Provide Complete & Correct Snippets:** When providing class code, try to include both header (`.hpp`) and source (`.cpp`) parts where appropriate, respecting declaration/definition separation.
*   **Focus on Safety and Efficiency:** Guide towards solutions that are memory-safe and performant, leveraging the standard library.

## 🚨 Important Note
    **DO NOT EVER PUT COMMENTS ALL OVER THE CODE.**
    Comments should be used sparingly and only when necessary to clarify complex logic or design decisions. The code itself should be self-explanatory through clear naming and structure.

By following these instructions, you will help me produce high-quality, modern C++23 code.