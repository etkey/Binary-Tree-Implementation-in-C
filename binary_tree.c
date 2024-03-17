#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

BTree *create_tree()
{
    BTree *new_tree = (BTree *)malloc(sizeof(BTree));
    if (new_tree == NULL)
    {
        printf("Memory allocation failed for BTree.\n");
        return NULL;
    }
    new_tree->left = (BTree *)malloc(sizeof(BTree));
    if (new_tree->left == NULL)
    {
        printf("Memory allocation failed for left subtree.\n");
        free(new_tree);
        return NULL;
    }
    new_tree->right = (BTree *)malloc(sizeof(BTree));
    if (new_tree->right == NULL)
    {
        printf("Memory allocation failed for right subtree.\n");
        free(new_tree);
        return NULL;
    }
    new_tree->root = NULL;
    new_tree->left = NULL;
    new_tree->right = NULL;
    return new_tree;
}

void insert_BTree(BTree *tree, int v_data, char *t_message)
{
    if (tree->root == NULL)
    {
        Node *new_node = (Node *)malloc(sizeof(Node));
        if (new_node == NULL)
        {
            printf("Memory allocation failed for node.\n");
            return;
        }
        new_node->data = v_data;
        new_node->message = t_message;
        tree->root = new_node;
        return;
    }
    else
    {
        if (v_data == tree->root->data)
        {
            printf("Duplicates cannot be inserted in Binary Tree. \n");
            return;
        }
        else if (v_data > tree->root->data)
        {
            if (tree->right == NULL)
            {
                tree->right = create_tree(); // allocates memory for the right subtree if it is null
            }
            insert_BTree(tree->right, v_data, t_message);
        }
        else if (v_data < tree->root->data)
        {
            if (tree->left == NULL)
            {
                tree->left = create_tree(); // allocates memory for the left subtree if it is null
            }
            insert_BTree(tree->left, v_data, t_message);
        }
    }
}

void preorder_traversal(BTree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        printf("%d ", tree->root->data);
        preorder_traversal(tree->left);
        preorder_traversal(tree->right);
    }
}

void inorder_traversal(BTree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        inorder_traversal(tree->left);
        printf("%d ", tree->root->data);
        inorder_traversal(tree->right);
    }
}

void postorder_traversal(BTree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        postorder_traversal(tree->left);
        postorder_traversal(tree->right);
        printf("%d ", tree->root->data);
    }
}

Node *search_BTree(BTree *tree, int d_search)
{
    if (tree == NULL)
    {
        printf("Tree is empty or the value doesn't exist in the tree.");
        return NULL;
    }
    else
    {
        if (tree->root->data == d_search)
        {
            return tree->root;
        }
        else if (tree->root->data > d_search)
        {
            return search_BTree(tree->left, d_search);
        }
        else if (tree->root->data < d_search)
        {
            return search_BTree(tree->right, d_search);
        }
    }
}

BTree *delete_bsubtree(BTree *tree, int delete_value)
{
    if (tree == NULL)
    {
        printf("Tree does not exist.\n");
        return NULL;
    }
    BTree *d_tree = NULL;
    BTree *p_tree = NULL;
    BTree *traversal = tree;

    while (traversal != NULL)
    {
        if (traversal->root->data == delete_value)
        {
            d_tree = traversal;
            break;
        }
        else if (traversal->root->data > delete_value)
        {
            p_tree = traversal;
            traversal = traversal->left;
        }
        else if (traversal->root->data < delete_value)
        {
            p_tree = traversal;
            traversal = traversal->right;
        }
    }
    if (d_tree == NULL)
    {
        printf("Deletion failed, subtree does not exist. \n");
        return NULL;
    }

    if (d_tree->right == NULL && d_tree->left == NULL)
    {
        if (p_tree->left == d_tree)
        {
            p_tree->left = NULL;
        }
        else if (p_tree->right == d_tree)
        {
            p_tree->right = NULL;
        }
        free(d_tree);
        return tree;
    }

    if (d_tree->right == NULL || d_tree->left == NULL)
    {
        if (p_tree->left == d_tree)
        {
            if (d_tree->right == NULL)
            {
                p_tree->left = d_tree->left;
            }
            else
            {
                p_tree->left = d_tree->right;
            }
        }
        else if (p_tree->right == d_tree)
        {
            if (d_tree->right == NULL)
            {
                p_tree->right = d_tree->left;
            }
            else
            {
                p_tree->right = d_tree->right;
            }
        }

        return tree;
    }

    if (d_tree->right != NULL && d_tree->left != NULL)
    {
        BTree *inorder_successor = d_tree->right;
        BTree *inorder_successor_parent = d_tree;
        while (inorder_successor->left != NULL)
        {
            inorder_successor_parent = inorder_successor;
            inorder_successor = inorder_successor->left;
        }
        d_tree->root->data = inorder_successor->root->data;
        d_tree->root->message = inorder_successor->root->message;
        if (inorder_successor_parent->right == inorder_successor)
        {
            if (inorder_successor->right == NULL)
            {
                inorder_successor_parent->right = NULL;
            }
            else
            {
                inorder_successor_parent->right = inorder_successor->right;
            }
        }
        else if (inorder_successor_parent->left == inorder_successor)
        {
            inorder_successor_parent->left = NULL;
        }
        free(inorder_successor);
        return tree;
    }
}

void destroy_tree(BTree *tree)
{
    if (tree == NULL)
    {
        return;
    }
    destroy_tree(tree->left);
    destroy_tree(tree->right);
    free(tree);
}