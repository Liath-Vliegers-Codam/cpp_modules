# PmergeMe

This project is my implementation of the 42 CPP09 exercise. It sorts a list of positive integers using a merge-insertion style approach inspired by the Ford-Johnson algorithm.

## What the program does

The executable:

1. Reads a sequence of positive integers from the command line.
2. Splits the values into pairs and keeps track of the larger and smaller element in each pair.
3. Sorts the larger values first.
4. Inserts the smaller values back in the correct order using binary insertion and a Jacobsthal-based insertion order.
5. Prints the input, the sorted result, the processing time for `std::vector` and `std::deque`, and the number of comparisons used by the vector run.

The implementation accepts duplicate values.

## Input format

The program expects only positive integers.

Examples of valid input:

```bash
./PmergeMe 3
./PmergeMe 3 3
./PmergeMe 3 5 9 7 4
./PmergeMe "3 5 9 1 7"
./PmergeMe 10 "20 30" 40
./PmergeMe "3" "5" "9" "7" "4"
./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
```

Invalid input is rejected, including:

- negative numbers
- alphabetic tokens
- mixed tokens such as `42a`
- values that overflow `int`

```bash
./PmergeMe "-1" "2"
./PmergeMe -1 2
./PmergeMe 6 8 7 9 a 7
./PmergeMe 6 8 5 9 7.5 
./PmergeMe 6 8 5 9 2147483648
```
## Build

```bash
make
```

To remove build artifacts:

```bash
make clean
```

To remove everything, including the executable:

```bash
make fclean
```

## Run

```bash
./PmergeMe 8 3 5 1 9 2 7 4
or
./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
```

The program prints:

- `Before:` followed by the original sequence
- `After:` followed by the sorted sequence
- the processing time for `std::vector`
- the processing time for `std::deque`
- `comparisons` followed by the comparison count used for the vector sort

## Notes on the implementation

This version uses a template-based sorter and keeps both a `std::vector` and a `std::deque` representation of the input so their performance can be compared. The comparison counter is included in the output for testing and debugging.

## Project structure

- `main.cpp` handles argument validation and launches the sort.
- `parser.hpp` and `parser.tpp` validate and parse the command-line input.
- `PmergeMe.hpp` and `PmergeMe.tpp` contain the sorting logic.
- `Makefile` builds the executable named `PmergeMe`.

## Fort Johnson algorithm explanation
The Ford-Johnson algorithm is a comparison-based sorting method that minimizes the number of comparisons needed to sort a list. It works by:
1. Pairing elements and comparing them to identify the larger and smaller in each pair.
2. Sorting the larger elements first, which reduces the number of comparisons needed to insert the smaller elements back into the sorted order.
3. Using a specific insertion order based on Jacobsthal numbers to further optimize the number of comparisons during the insertion phase.

The goal is to achieve a sorting process that makes the fewest comparisons possible, which is particularly beneficial for large datasets.



For more details on the Fort Johnson algorithm and the Jacobsthal sequence and its role in the insertion order, see the [CPP09 README by leske42](
https://github.com/leske42/CPP09/blob/main/README.md#what-is-the-purpose-of-the-jacobstahl-sequence ). This Readme helped me understand the algorithm and implement it correctly. They also provide a helpfull tester.
