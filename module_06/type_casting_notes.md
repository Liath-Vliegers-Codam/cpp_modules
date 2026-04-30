# C++ Casting Notes

A practical guide to the three casts we use in this project:
- `static_cast`
- `dynamic_cast`
- `reinterpret_cast`

## Quick Summary

- `static_cast`: normal explicit conversions with compile-time checks.
- `dynamic_cast`: runtime-checked cast for polymorphic inheritance.
- `reinterpret_cast`: low-level bit/pointer reinterpretation; most dangerous.

## How This Module Uses Them

- ex00 uses `static_cast` to convert between scalar types like `char`, `int`, `float`, and `double`.
	this is because these conversions are well-defined and safe when done explicitly.
- ex01 uses `reinterpret_cast` to turn a `Data*` into a `uintptr_t` and back again, so the pointer value can be stored as an integer without changing the actual data.
	this is a common use case for `reinterpret_cast` when you need to treat a pointer as an integer for storage or transmission, but it should be done with caution.
- ex02 uses `dynamic_cast` to check the real type of a `Base*` or `Base&` at runtime and identify whether the object is `A`, `B`, or `C`.
	this is a classic use case for `dynamic_cast` when you have a polymorphic class hierarchy and need to safely determine the actual derived type of an object at runtime.

In short:
- `static_cast` = safe explicit conversion when the type you want is already known.
- `reinterpret_cast` = raw pointer/value reinterpretation.
- `dynamic_cast` = runtime type check for polymorphic classes.

## Side-by-Side Comparison

| Aspect | `static_cast` | `dynamic_cast` | `reinterpret_cast` |
|---|---|---|---|
| Main purpose | Regular explicit conversion | Safe downcast in polymorphic hierarchies | Low-level reinterpretation of bits/pointers |
| Compile-time checks | Yes (type compatibility) | Yes (cast validity in hierarchy) | Minimal |
| Runtime checks | No | Yes (RTTI) | No |
| Typical use | Numeric conversion, upcast, known-safe downcast | Downcast when real runtime type is uncertain | Systems code, pointer/integer conversion, ABI work |
| Inheritance required | Not required | Yes | Not required |
| Polymorphic base required | No | Yes (base needs at least one `virtual` function) | No |
| Pointer cast failure | No automatic failure signal | Returns `nullptr` on failure | No failure signal |
| Reference cast failure | No automatic failure signal | Throws `std::bad_cast` on failure | No failure signal |
| Runtime cost | None / negligible | Higher (RTTI lookup) | None / negligible |
| Safety if misused | Medium risk | Lowest risk of these three for downcasts | Highest risk (easy UB) |

## 1) `static_cast`

Use when the conversion is logically valid and explicit.

### Good use cases
- Numeric conversions (`double` -> `int`, `int` -> `double`)
- Upcasting (`Derived*` -> `Base*`)
- Downcasting only when you are certain of the real object type
- Converting `void*` back to the original pointer type

### Example
```cpp
double d = 3.14;
int i = static_cast<int>(d); // i == 3 (truncation)
```

### Notes
- Fast and explicit.
- Can still produce wrong behavior if your assumption is wrong (especially unsafe downcasts).

## 2) `dynamic_cast`

Use for safe runtime casting across polymorphic class hierarchies.

### Requirement
Your base class must be polymorphic, typically by having at least one virtual function.

### Example (pointer cast)
```cpp
struct Base {
    virtual ~Base() {}
};

struct Derived : Base {};

Base* b = new Derived();
Derived* d = dynamic_cast<Derived*>(b);
if (d) {
    // success
}
```

### Behavior
- Pointer cast failure: returns `nullptr`
- Reference cast failure: throws `std::bad_cast`

### Notes
- Best choice for uncertain downcasts.
- Has runtime overhead.

## 3) `reinterpret_cast`

Use only for low-level memory/pointer reinterpretation.

reinterpret_cast is a compile-time cast.

It tells the compiler to treat the bits as a different type, but it does not perform a runtime type check like dynamic_cast. So there is no runtime safety check, and misuse can lead to undefined behavior even though it compiles.

### Typical use cases
- Pointer <-> integer conversions (e.g., logging addresses)
- Interfacing with hardware/ABI boundaries
- Specialized systems programming scenarios


### Example
```cpp
#include <cstdint>

void* ptr = /* ... */;
std::uintptr_t addr = reinterpret_cast<std::uintptr_t>(ptr);
```

### Notes
- Does not do semantic conversion; it reinterprets representation.
- Very easy to trigger undefined behavior (aliasing, alignment, lifetime issues).
- Avoid unless you have a strong low-level reason.

## Decision Guide

1. Is this a normal explicit conversion? Use `static_cast`.
2. Are you downcasting in a polymorphic hierarchy and unsure of runtime type? Use `dynamic_cast`.
3. Are you intentionally reinterpreting raw memory/pointer representation? Use `reinterpret_cast` with caution.

## Common Mistakes

- Using `static_cast` for uncertain downcasts.
- Using `dynamic_cast` without a polymorphic base class.
- Using `reinterpret_cast` as a shortcut for regular conversions.
- Assuming code is safe just because the cast compiles.

## Rule of Thumb

Use the safest cast that matches intent:
1. `static_cast` (default for explicit conversions)
2. `dynamic_cast` (when runtime type safety is needed)
3. `reinterpret_cast` (only for unavoidable low-level tasks)



summary of 