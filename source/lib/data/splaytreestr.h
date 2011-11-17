/**
 * @file splaytreestr.h
 * @details ANSI-C Splay tree (ST) Library
 *          String (255 chacaters, via STRMAX constant)
 * @see http://en.wikipedia.org/wiki/Splay_tree
 * @version
 * @author Emerson Rocha Luiz
 * @copyright MIT. See license.txt
 */
#ifndef SPLAYTREE_H_INCLUDED
#define SPLAYTREE_H_INCLUDED

///                             Includes                                     ///
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
///                             Constants                                    ///
///Definitions
#define STRMAX 255


///                             Definitions                                  ///

/**
 * Define node as same type of SplayTreeStr
 */
struct SplayTreeStr
{
    char *data; //char data[STRMAX];
    struct SplayTreeStr *left;
    struct SplayTreeStr *right;
} SplayTreeSN; //Splay Tree String Node

///                             Functions                                    ///
//Initialize a new Tree
struct SplayTreeStr* Initialize(char *data);
//Insert data on Tree (alias to function Splay)
//struct SplayTreeStr* Insert(struct SplayTreeStr* root, char *data);
//Rotate to right tree
struct SplayTreeStr* RotationLeft(struct SplayTreeStr* node, struct SplayTreeStr* root);
//Rotate to right tree
struct SplayTreeStr* RotationRight(struct SplayTreeStr* node, struct SplayTreeStr* root);
//Insert (and also after organize) tree
struct SplayTreeStr* Splay(struct SplayTreeStr* root, char data[STRMAX]);
//Search for one data inside tree
struct SplayTreeStr* Search(struct SplayTreeStr* root, char data[STRMAX]);
//Destroy entire tree
struct SplayTreeStr* Destroy(struct SplayTreeStr* root);

///Debug functions
void PrintSplayTreeStrNode(struct SplayTreeStr* node);

/**
 * Initialize a new Tree
 *
 * @param[in] char* data[STRMAX]
 * @param[in,out] SplayTreeStr* left
 * @param[in,out] SplayTreeStr* right
 * @return SplayTreeStr*
 */
struct SplayTreeStr* Initialize(char *data)
{
    struct SplayTreeStr *node = malloc(sizeof(SplayTreeSN));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
/*
struct SplayTreeStr* Insert(struct SplayTreeStr* root, char *data){
    return Splay(data, root);
}
struct SplayTreeStr* Splay(struct SplayTreeStr* root, char data[STRMAX]){

}
*/
/*
PtNodo* Novo(int key, PtNodo* esq, PtNodo* dir)
{
  PtNodo* x = (PtNodo*) malloc(sizeof(PtNodo));
  x->key = key; x->esq = esq; x->dir = dir;
  return x;
};
*/

///Debug functions
void PrintSplayTreeStrNode(struct SplayTreeStr* node){
    printf("%s", node->data);
}



#endif // SPLAYTREE_H_INCLUDED
