# Data Structures and Algorithms in C

This repository contains a collection of C programs implementing various fundamental data structures and algorithms. It serves as a practical resource for understanding and applying common DSA concepts.

## Implementations

Here is a list of the data structures and algorithms implemented in this project:

### Data Structures

* **Arrays** (`arrays.c`)
    * Implements basic array operations: insert, delete, display, and search.
* **Stacks** (`stack-operations.c`)
    * Implements core stack operations (push, pop, etc.).
* **Circular Queues** (`circular-queue.c`)
    * Implements a circular queue with enqueue, dequeue, and display functions.
* **Linked Lists**
    * **Singly Linked List** (`sll-insertions.c`): Functions for various insertion operations.
    * **Doubly Linked List** (`dll-insertions.c`): Implementation with insertion and display functions.
    * **Circular Linked List** (`cll-insertions.c`): Implementation of a circular linked list.
* **Trees**
    * **Binary Search Tree** (`bst.c`): Implementation of a BST with different traversal methods.
* **Hash Tables** (`hashtables.c`)
    * A basic implementation of a hash table.

### Algorithms

* **Infix to Postfix Conversion** (`infix-postfix.c`)
    * A program to convert an infix expression to its postfix equivalent.
* **Dijkstra's Algorithm** (`dijkstra.c`)
    * An implementation of Dijkstra's single-source shortest path algorithm.

## Getting Started

### Prerequisites

To compile and run these programs, you will need a C compiler installed on your system (e.g., `gcc`).

### How to Compile and Run

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/your-username/your-repository-name.git](https://github.com/your-username/your-repository-name.git)
    cd your-repository-name
    ```

2.  **Compile a program:**
    Use `gcc` (or your preferred C compiler) to compile the desired `.c` file.

    ```bash
    # Example for the Binary Search Tree
    gcc bst.c -o bst
    
    # Example for Dijkstra's Algorithm
    gcc dijkstra.c -o dijkstra
    ```

3.  **Run the executable:**
    After compilation, run the generated executable file.

    ```bash
    # Example for the Binary Search Tree
    ./bst
    
    # Example for Dijkstra's Algorithm
    ./dijkstra
    ```

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request.

## License

This project is licensed under the terms specified in the `LICENSE` file.
