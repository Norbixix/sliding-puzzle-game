A simple 4x4 Sliding Puzzle Game written in C++ with randomized solvable board generation and keyboard-based movement.
# Sliding Puzzle 4x4 Game

A simple console-based **4x4 Sliding Puzzle Game** written in **C++**.  
The objective is to arrange the numbered tiles from **1 to 15** in the correct order, leaving the empty space in the **bottom-right corner**.

## Features

- 4x4 sliding puzzle board
- Randomized but **solvable** tile generation
- Keyboard controls:
  - `w` – up
  - `a` – left
  - `s` – down
  - `d` – right
  - `q` – quit
- Win condition detection
- Clean object-oriented implementation using a `Board` class
- No external libraries required

## How It Works

When the game starts, the board is shuffled into a valid configuration that can always be solved.  
The player moves tiles using the keyboard and tries to restore the correct order of all numbers.

## Technologies Used

- **C++**
- **STL (Standard Template Library)**

## Compilation

Compile the program using a standard C++ compiler, for example:

```bash
g++ -o SlidingPuzzleGame main.cpp
