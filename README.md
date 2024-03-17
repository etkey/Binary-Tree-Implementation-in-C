# Binary-Tree-Implementation-in-C

This document describes a C library for implementing a binary tree data structure. The library provides functions for creating, inserting, traversing, searching, and deleting nodes in the tree.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Implementation](#implementation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This C program demonstrates the implementation of a binary tree data structure. It includes functionalities to create a binary tree, insert nodes with associated data and messages, perform various traversals, search for specific nodes, and delete subtrees.

## Features

- Creates and manages binary trees.
- Inserts nodes with data and associated messages.
- Performs preorder, inorder, and postorder traversals.
- Searches for nodes based on data value.
- Deletes subtrees rooted at a specific data value.

##Implementation

### `Compiling as a Library`:

Use the gcc compiler with appropriate flags to compile the code:
```bash
gcc -c binary_tree.c
```

To create archive library:
```bash
ar rcs libbtree.a binary_tree.o
```
This command will create an archive library named libbtree.a (or your chosen name) containing the compiled code from binary_tree.c. 
This library can now be linked with other C programs that need to use the binary tree functionality.

### `Using the Library in Another Program`:

In your main program, include binary_tree.h.
Link the library during compilation using the -l flag:
```bash
gcc your_program.c -L. -lbtree -o your_program
```

## Usage

This library is designed to be used as a reusable component in other C programs. Here's a basic outline for using the library:

-`Include the header file`:
```c
#include "binary_tree.h"
```

`Create a binary tree`:
```c
BTree* my_tree = create_tree();
```

- `Insert nodes`:
```c
insert_BTree(my_tree, 50, "Root Node");
insert_BTree(my_tree, 30, "Left Child");
```

- `Perform operations`:
```c
preorder_traversal(my_tree);
inorder_traversal(my_tree);
postorder_traversal(my_tree);

int search_value = 60;
Node* found_node = search_BTree(my_tree, search_value);

// ... (delete subtree if needed)
```
`Free the memory`


Note: Remember to link the library during compilation using the -l flag with the appropriate library name (refer to the Implementation section for details).

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, feel free to open an issue or create a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
