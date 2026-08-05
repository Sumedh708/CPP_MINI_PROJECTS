# Browser History Simulator

A simple browser history simulator written in C++ using two stacks implemented with linked lists.

## Features

- Visit a new webpage
- Navigate Back
- Navigate Forward
- Automatically clears forward history when a new page is visited
- Interactive command-line interface

## Concepts Used

- C++
- Classes and Objects
- Constructors
- Encapsulation
- Singly Linked Lists
- Stack Data Structure
- Dynamic Memory Allocation (`new` / `delete`)

## How it Works

The browser maintains:

- Current webpage
- Back stack
- Forward stack

When a new webpage is visited:

- Current page is pushed onto the back stack.
- Forward history is cleared.

When navigating Back:

- Current page moves to the forward stack.
- Previous page becomes the current page.

When navigating Forward:

- Current page moves back to the back stack.
- Top page from the forward stack becomes the current page.

## Time Complexity

| Operation | Complexity |
|-----------|------------|
| Visit Website | O(k)* |
| Go Back | O(1) |
| Go Forward | O(1) |

*k = number of pages present in the forward history (clearing forward stack)

## Future Improvements

- Use separate header (`.h`) and source (`.cpp`) files
- Add browser tabs
- Store page titles
- Support bookmarks
- Implement history persistence using files