# Truth Table Generator

A command-line program written in C that takes a boolean expression as input and outputs its corresponding truth table.

## Features

- **Recursive Descent Parser**: The program utilizes a recursive descent parsing technique to process boolean expressions.
- Supports the following boolean operators:
  - `*` for AND
  - `+` for OR
  - `=>` for IMPLICATION
  - `~` for NOT
- Handles expressions with up to 26 unique variables (lowercase letters from `a` to `z`).

### Backus-Naur Form (BNF) for the language:

```
<expression>  ::= <term> { "+" <term> }
<term>        ::= <factor> { "*" <factor> }
<factor>      ::= <base> | "~" <base>
<base>        ::= <variable> | "(" <expression> ")" | <variable> "=>" <expression>
<variable>    ::= "a" | "b" | ... | "z"
```

## Getting Started

### Prerequisites

- A C compiler (like `gcc`).

Note: If you want to use a different compiler, you will have to change the makefile.

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
