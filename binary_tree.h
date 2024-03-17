#ifndef BINARY_TREE
#define BINARY_TREE

/**
 * @file binary_tree.c
 * @brief Implementation of a binary tree data structure.
 *
 * Provides functions for creating, inserting, traversing, searching, and
 * deleting nodes in a binary tree.
 *
 * @author Enes Talha Keleş
 * @date Sunday 17th March 2024
 */

/**
 * @brief Structure representing a node in the binary tree.
 */
typedef struct node
{
    int data;      /**< Integer data stored in the node. */
    char *message; /**< Message associated with the node. */
} Node;

/**
 * @brief Structure representing a binary tree.
 */
typedef struct binary_tree
{
    Node *root;                /**< Pointer to the root node of the tree. */
    struct binary_tree *left;  /**< Pointer to the left subtree. */
    struct binary_tree *right; /**< Pointer to the right subtree. */
} BTree;

/**
 * @brief Creates a new binary tree and allocates memory for it.
 *
 * Initializes the left and right subtrees to NULL and the root node to NULL.
 * Handles memory allocation errors and prints an error message if encountered.
 *
 * @return Pointer to the newly created binary tree, or NULL on failure.
 */
BTree *create_tree();

/**
 * @brief Inserts a node with a given data value and message into the binary tree.
 *
 * Recursively traverses the tree to find the appropriate position for insertion based
 * on the data value. Handles duplicate values and prints an error message.
 * Allocates memory for the new node and sets its data and message.
 *
 * @param tree Pointer to the binary tree.
 * @param v_data Integer data value to be inserted.
 * @param t_message Message associated with the node.
 */
void insert_BTree(BTree *tree, int v_data, char *t_message);

/**
 * @brief Performs a preorder traversal of the binary tree.
 *
 * Visits the root node first, then recursively traverses the left subtree
 * and then the right subtree. Prints the data value of each node visited.
 *
 * @param tree Pointer to the binary tree.
 */
void preorder_traversal(BTree *tree);

/**
 * @brief Performs an inorder traversal of the binary tree.
 *
 * Recursively traverses the left subtree first, then visits the root node,
 * and then traverses the right subtree. Prints the data value of each node visited.
 *
 * @param tree Pointer to the binary tree.
 */
void inorder_traversal(BTree *tree);

/**
 * @brief Performs a postorder traversal of the binary tree.
 *
 * Recursively traverses the left subtree first, then traverses the right subtree,
 * and finally visits the root node. Prints the data value of each node visited.
 *
 * @param tree Pointer to the binary tree.
 */
void postorder_traversal(BTree *tree);

/**
 * @brief Searches for a node with a given data value in the binary tree.
 *
 * Recursively traverses the tree based on the data value.
 * Returns the pointer to the node if found, or NULL if not found.
 * Prints an error message if the tree is empty.
 *
 * @param tree Pointer to the binary tree.
 * @param d_search Integer data value to be searched for.
 *
 * @return Pointer to the found node, or NULL if not found.
 */
Node *search_BTree(BTree *tree, int d_search);

/**
 * @brief Deletes a subtree rooted at a node with a given data value.
 *
 * Uses a recursive approach to find the subtree to be deleted.
 * Handles cases where the subtree has no children, one child, or two children.
 * Uses an inorder successor for deletion with two children.
 * Frees the memory allocated to the deleted node.
 * Prints an error message if the tree is empty or the subtree is not found.
 *
 * @param tree Pointer to the binary tree.
 * @param delete_value Integer data value of the node to be deleted.
 *
 * @return Pointer to the modified binary tree.
 */
BTree *delete_bsubtree(BTree *tree, int delete_value);

#endif