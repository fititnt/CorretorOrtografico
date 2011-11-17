/**
 * @file splaytree.h
 * @details ANSI-C Splay Tree Library
 *          Data: Integer
 * @version 0.1
 * @date 2011-11-13
 * @author Emerson Rocha Luiz
 * @copyright
 * @license GPL3. See license-gpl3.txt
 * @license MIT. See license-mit.txt
 */
#ifndef SPLAYTREE_H_INCLUDED
#define SPLAYTREE_H_INCLUDED

///                             Includes                                     ///
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


///                             Definitions                                  ///

/**
 * Define node as same type of SplayTreeStr
 */
struct SplayTree
{
    int data;
    struct SplayTree *left;
    struct SplayTree *right;
} SplayTreeInt; //Splay Tree String Node

///                             Functions Prototypes                         ///

//Initialize a new Tree
struct SplayTree* Initialize(int data);
//Insert data in the Tree (alias for Splay function)
struct SplayTree* Insert(struct SplayTree* root, int data);
//Insert a new node
struct SplayTree* NewNode(int data, struct SplayTree *left, struct SplayTree *right);
//Print Tree
void PrintSplayTree(struct SplayTree* tree, int level);
//Print one node of the Tree
int PrintSplayTreeNode(struct SplayTree* node);
//Rotate to right tree
struct SplayTree* RotationLeft(struct SplayTree* node);
//Rotate to right tree
struct SplayTree* RotationRight(struct SplayTree* node);
//Insert (and also after organize) tree
struct SplayTree* Splay(struct SplayTree* root, int data);
//Search for one data inside tree
struct SplayTree* Search(struct SplayTree* root, int data);
//Search each node of tree, recursively
struct SplayTree* SearchSplayTreeNodes(struct SplayTree* node, int data);
//Destroy entire tree
struct SplayTree* Destroy(struct SplayTree* root);



///                             Functions                                    ///


/**
 * Initialize a new Tree
 *
 * @param[in] int data Value of root node
 * @return SplayTreeStr*
 */
struct SplayTree* Initialize(int data)
{
    struct SplayTree *node = malloc(sizeof(SplayTreeInt));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * Initialize a new Tree node
 *
 * @param[in] int data Value of root node
 * @param[in,out] SplayTree* left Value of root node
 * @param[in,out] SplayTree* right Value of root node
 * @return SplayTreeStr*
 */
struct SplayTree* NewNode(int data, struct SplayTree *left, struct SplayTree *right)
{
    struct SplayTree *node = malloc(sizeof(SplayTreeInt));
    node->data = data;
    node->left = left;
    node->right = right;
    return node;
};

/**
 * Insert in the tree a new data. Alias to Splay() function
 *
 * @param[in] SplayTree* root Root of the tree
 * @param[in] int data Data to insert
 * @return SplayTreeStr* root Resultant root of the tree
 */
struct SplayTree* Insert(struct SplayTree* root, int data)
{
    return Splay(root,data);
}

/**
 * Insert in the tree a new data
 *
 * @param[in] SplayTree* tree Root of the tree
 * @param[in] int data Data to insert
 * @return SplayTreeStr* root Resultant root of the tree
 */
struct SplayTree* Splay(struct SplayTree* tree, int data)
{
    if (tree == NULL) return NewNode(data, NULL, NULL);
    if (data < tree->data)
    {
        if (tree->left == NULL) return NewNode(data, NULL, tree);
        if (data < tree->left->data)
        {
            tree->left->left = Splay(tree->left->left, data);
            tree = RotationRight(tree);
        }
        else
        {
            tree->left->right = Splay(tree->left->right, data);
            tree->left = RotationLeft(tree->left);
        }
        return RotationRight(tree);
    }
    else
    {
        if (tree->right == NULL) return NewNode(data, tree, NULL);
        if (tree->right->data < data)
        {
            tree->right->right = Splay(tree->right->right, data);
            tree = RotationLeft(tree);
        }
        else
        {
            tree->right->left = Splay(tree->right->left, data);
            tree->right = RotationRight(tree->right);
        }
        return RotationLeft(tree);
    }
}

/**
 * Rotate to right the node
 *
 * @param[in] SplayTree* node Node to rotate
 * @return SplayTreeStr* temp Resultant node of the tree
 */
struct SplayTree* RotationRight(struct SplayTree* node)
{
    struct SplayTree *temp = node->left;
    node->left = temp->right;
    temp->right = node;
    return temp;
};

/**
 * Rotate to left the node
 *
 * @param[in] SplayTree* node Node to rotate
 * @return SplayTreeStr* temp Resultant node of the tree
 */
struct SplayTree* RotationLeft(struct SplayTree* node)
{
    struct SplayTree *temp = node->right;
    node->right = temp->left;
    temp->left = node;
    return temp;
};


/**
 * Print all Splay tree, recursively
 *
 * @param[in] SplayTree* tree Node to print
 * @param[in] int level Current level of tree
 * @return SplayTreeStr* temp Resultant node of the tree
 */
void PrintSplayTree(struct SplayTree* tree, int level)
{
    int i;
    if (tree !=NULL)
    {
        for (i=1; i<=level; i++)
            printf("=");
        printf("%d \n", tree->data);
        if (tree->left != NULL) PrintSplayTree(tree->left, (level+1));
        if (tree->right != NULL) PrintSplayTree(tree->right, (level+1));
    }
    else
    {
        printf("Empty Tree");
    }
};

/**
 * Print one node of Splay Tree, and also return node data
 *
 * @param[in] SplayTree* tree Node to print
 * @return int node->data Value of node
 */
int PrintSplayTreeNode(struct SplayTree* node)
{
    printf("%i", node->data);
    return node->data;
}

/**
 * Search for one data inside tree
 *
 * @param[in] SplayTree* root
 * @param[in] int data
 * @return playTree* root
 */
struct SplayTree* Search(struct SplayTree* root, int data)
{
    if (root == NULL) return NULL;
    root = SearchSplayTreeNodes(root, data);
    return root;
};

/**
 * Search each node of tree, recursively
 *
 * @param[in] SplayTree* root
 * @param[in] int data
 * @return playTree* root
 */
struct SplayTree* SearchSplayTreeNodes(struct SplayTree* node, int data)
{
    if (node == NULL) return NULL;
    if (data < node->data)
    {
        if (node->left == NULL) return node;
        if (data < node->left->data)
        {
            node->left->left = SearchSplayTreeNodes(node->left->left, data);
            node = RotationRight(node);
            if (node->left == NULL) return node;
            else return RotationRight(node);
        }
        else if (node->left->data , data)
        {
            node->left->right = SearchSplayTreeNodes(node->left->right, data);
            if (node->left->right != NULL) node->left = RotationLeft(node->left);
            return RotationRight(node);
        }
        else return RotationRight(node);
    }
    else if(node->data < data)
    {
        if (node->right == NULL) return node;
        if (node->right->data < data)
        {
            node->right->right = SearchSplayTreeNodes(node->right->right, data);
            node = RotationLeft(node);
            if (node->right == NULL) return node;
            else return RotationLeft(node);
        }
        else if (data < node->right->data)
        {
            node->right->left = SearchSplayTreeNodes(node->right->left, data);
            if (node->right->left != NULL) node->right = RotationRight(node->right);
            return RotationLeft(node);
        }
        else return RotationLeft(node);
    }
    else
        return node;
};


#endif // SPLAYTREE_H_INCLUDED
