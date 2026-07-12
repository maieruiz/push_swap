# push_swap
# *This project has been created as part of the 42 curriculum by amarlaska and mairuiz.*

# Push Swap

## Description

Push Swap is a 42 project whose objective is to sort a stack of integers using the smallest possible number of operations. The project focuses on algorithm design, data structures, and complexity analysis rather than simply producing a sorted result.

The program receives a list of integers as command-line arguments, validates the input, builds an internal representation of the stack, and sorts it using only the operations allowed by the subject.

In addition to producing the required sequence of operations, the project also includes multiple sorting strategies with different theoretical time complexities and an optional benchmark mode that provides performance statistics.

---

## Instructions

### Compilation

Clone the repository and compile the project using:

```bash
make
```

To remove object files:

```bash
make clean
```

To remove object files and the executable:

```bash
make fclean
```

To rebuild the project:

```bash
make re
```

---

### Usage

Sort a list of integers:

```bash
./push_swap 3 2 5 1 4
```

Run the benchmark mode:

```bash
./push_swap --bench 3 2 5 1 4
```

Select a specific sorting strategy (simple, medium, complex, adaptive):

```bash
./push_swap --strategy 3 2 5 1 4
```
Select the benchmark mode and a specific sorting strategy:

```bash
./push_swap --bench --strategy 3 2 5 1 4
```
---

## Selected Algorithms

The project implements several sorting strategies, each designed for a different level of input complexity.

### Simple Strategy — O(n²)

A simple insertion-based sorting algorithm is used for very small inputs. Although its theoretical complexity is quadratic, it performs efficiently on small datasets due to its low overhead.

**Why it was chosen**

* Easy to implement and debug.
* Efficient for small stacks.
* Produces a reasonable number of operations for small inputs.

---

### Intermediate Strategy — O(n√n)

The intermediate strategy divides the input into √n chunks. Elements are moved between stacks according to their value ranges and later reconstructed in sorted order.

**Why it was chosen**

* Reduces the number of unnecessary operations.
* Performs significantly better than quadratic algorithms on medium-sized inputs.
* Maintains a relatively simple implementation.

---

### Complex Strategy — O(n log n)

The main algorithm is based on Radix Sort using indexed values.

Instead of sorting the original integers directly, every number is first assigned an index corresponding to its position in the sorted sequence. The algorithm then sorts these indices bit by bit using only the allowed stack operations.

**Why it was chosen**

* Excellent theoretical complexity.
* Predictable number of operations.
* Widely considered one of the most suitable algorithms for the Push Swap project.

---

### Adaptive Strategy

The adaptive mode automatically selects the most appropriate algorithm depending on the characteristics of the input.

The decision is based on factors such as input size and disorder level, allowing the program to balance execution efficiency and operation count.

---

## Project Structure

```
push_swap/
│
├── src/
├── includes/
├── libft/
├── Makefile
└── README.md
```

---

## Resources

### Documentation

* The GNU C Library Documentation
* Linux Manual Pages (`man`)
* 42 Project Subject
* GeeksforGeeks (data structures and algorithms)
* cppreference.com (general C reference)

### Artificial Intelligence Usage

Artificial intelligence was used as a learning and documentation aid during the development of this project.

It was primarily used for:

* Understanding algorithmic concepts and complexity analysis.
* Clarifying C language concepts such as linked lists, pointers, and memory management.
* Reviewing implementation ideas and discussing possible design decisions.
* Improving the documentation and writing of this README.

All implementation decisions, architecture, debugging, and final code were developed and validated manually.
