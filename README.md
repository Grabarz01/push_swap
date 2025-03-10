# push_swap - Warsaw 42

## Description

The `push_swap` project is a sorting algorithm challenge developed as part of the Warsaw 42 curriculum. The goal of the project is to sort a stack of integers with the fewest possible moves using a set of predefined operations. The operations include pushing elements between two stacks, swapping the top elements, rotating the stacks, and reverse rotating the stacks.

### Key Features

- **Sorting Operations**:
  - `pa`: Push the top element from stack B to stack A.
  - `pb`: Push the top element from stack A to stack B.
  - `sa`: Swap the top two elements of stack A.
  - `sb`: Swap the top two elements of stack B.
  - `ra`: Rotate stack A (the first element becomes the last).
  - `rb`: Rotate stack B (the first element becomes the last).
  - `rr`: Rotate both stacks A and B simultaneously.
  - `rra`: Reverse rotate stack A (the last element becomes the first).
  - `rrb`: Reverse rotate stack B (the last element becomes the first).
  - `rrr`: Reverse rotate both stacks A and B simultaneously.

- **Sorting Algorithms**:
  - The project includes different sorting algorithms tailored for stacks of various sizes, ensuring efficient sorting with minimal moves.
  - Special handling for stacks of sizes 2, 3, and 4, with optimized sorting methods.

- **Input Validation**:
  - The project includes input validation to ensure that the provided stack of integers is valid and does not contain duplicates.

### Usage

To use the `push_swap` project, compile the source code using the provided `Makefile` and run the executable with a list of integers as arguments. The program will output the sequence of operations required to sort the stack.

### License

This project is licensed under the [CC BY 4.0](https://creativecommons.org/licenses/by/4.0/) license.

### Contact Information

For any questions or inquiries, please contact me via [LinkedIn][(https://www.linkedin.com](https://www.linkedin.com/in/filip-grabowski-3a1a35223/)).
