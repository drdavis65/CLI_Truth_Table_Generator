# Truth Table Generator

A command-line program written in C that takes a boolean expression as input and outputs its corresponding truth table.

## Features

- Supports the following boolean operators:
  - `*` for AND
  - `+` for OR
  - `=>` for IMPLICATION
  - `~` for NOT
- Handles expressions with up to 26 unique variables (lowercase letters from `a` to `z`).

## Getting Started

### Prerequisites

- A C compiler (like `gcc`).

### Compiling

To compile the program, use the provided Makefile:

```bash
make
```

### Usage

To run the program:

```bash
./truth_table "a+b*(c=>d)"
```

Note: Ensure that your boolean expression is enclosed in quotes to handle special characters in the shell.

### Sample Output

```bash
a b c d | Result
--------|------
0 0 0 0 | 0
1 0 0 0 | 1
0 1 0 0 | 1
...     | ...
```
