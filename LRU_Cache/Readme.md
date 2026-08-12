# LRU Cache

A custom implementation of an **LRU (Least Recently Used) Cache** in C++ using a doubly linked list and `std::unordered_map`.

## How It Works

The cache stores key-value pairs and keeps track of how recently each entry was accessed.

- The **Least Recently Used (LRU)** entry is removed when the cache reaches its capacity.
- Accessing an existing entry moves it to the **Most Recently Used (MRU)** position.
- Adding an existing key updates its value and makes it the MRU entry.

## Data Structures Used

### Doubly Linked List

The doubly linked list maintains the order of usage:

```text
LRU <-> ... <-> MRU