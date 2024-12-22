# Project Description: Implementation of `bi_ring` Data Structure and Associated Functions

This project focuses on the design and implementation of a class called `bi_ring`, which represents a collection of bidirectionally linked elements containing key-value pairs (Key and Info). The `bi_ring` class not only serves as a flexible data structure for managing pairs of related data but also incorporates functionality for enhanced data manipulation through iterator support and various external function templates.

## Designing the `bi_ring` Class

In the first part of this project, the primary objective is to create a robust class named `bi_ring`, which acts as a doubly linked list. The class is expected to include:

- **Iterator Classes**: Design both an `iterator` and a `const_iterator` class for traversing the elements within the `bi_ring`. The `const_iterator` should prevent any modifications to the ring while providing access to the data.
  
- **Member Functions**: Implement various member functions that allow for dynamic interaction with the ring, including:
  - Constructors and destructors to handle object lifecycle management.
  - `push_front()`: To insert a new element at the front of the ring.
  - `pop_front()`: To remove and return the first element.
  - `insert()`: To add elements at specified positions.
  - `erase()`: To remove elements from given positions.

The design should also consider the overall interface and utility of the `bi_ring` class, shaping it to facilitate the implementation of additional function templates that provide more complex operations on the data structure.

## Implementing Additional Function Templates

The second part of the project is focused on creating external function templates that operate on the `bi_ring`. These templates are designed to perform specific operations on instances of `bi_ring`, enhancing its usability:

1. **Filtering**: 
   - A template function to generate a new `bi_ring` which only contains key-value pairs meeting a specified predicate.

2. **Joining**: 
   - A function that combines two `bi_ring` instances by summing the `Info` values of common keys, creating a new `bi_ring` with unique keys.

3. **Unique**: 
   - This function removes duplicate keys from a `bi_ring`, aggregating values of repeated keys with a provided aggregation function.

4. **Shuffle**: 
   - A custom operation that allows interleaving elements from two separate `bi_ring` instances based on specified counts and repetitions, while cycling through the collections as needed.

Each template function is crafted to ensure ease of implementation by utilizing the capabilities of the `bi_ring` class.
