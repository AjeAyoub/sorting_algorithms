# Sorting Algorithms

This repository contains C implementations of various sorting algorithms. The sorting algorithms are designed to work with arrays of integers and doubly linked lists.

## Table of Contents

- [Introduction](#introduction)
- [Sorting Algorithms](#sorting-algorithms)
- [How to Use](#how-to-use)
- [File Descriptions](#file-descriptions)
- [Compilation](#compilation)
- [Tests](#tests)
- [Contributing](#contributing)
- [Authors](#authors)
- [License](#license)

## Introduction

This project implements sorting algorithms in C, focusing on both array and doubly linked list implementations. The goal is to provide clear and efficient implementations of common sorting algorithms.

## Sorting Algorithms

1. [Bubble Sort](0-bubble_sort.c): Sorts an array of integers in ascending order using the Bubble sort algorithm.

<!-- Add additional sorting algorithms as you implement them -->

## How to Use

To use the sorting algorithms in your project, follow these steps:

1. Clone the repository: `git clone https://github.com/your-username/sorting_algorithms.git`
2. Include the necessary header file in your code: `#include "sort.h"`
3. Compile your code along with the sorting algorithm implementation files.

## File Descriptions

- `sort.h`: Header file containing function prototypes and the definition of the `listint_t` structure.

<!-- Add descriptions for each sorting algorithm file -->

## Compilation

All files in this repository should be compiled on Ubuntu 20.04 LTS using `gcc` with the following options:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o your_executable_name

