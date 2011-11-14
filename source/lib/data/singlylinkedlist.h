/**
 * @file singlylinkedlist.h
 * @details SinglyLinkedList
 * @see http://en.wikipedia.org/wiki/Linked_list
 * @version 0.1beta
 * @author Emerson Rocha Luiz
 * @copyright MIT. See license.txt
 */

#ifndef SINGLYLINKEDLIST_H_INCLUDED
#define SINGLYLINKEDLIST_H_INCLUDED

//Struct of data do hold information
struct Data
{
    char item[100];
} ;
typedef struct Data TypeData; //Define one Type of this element

//Struct of node used on list
struct Node
{
    TypeData data;
    struct Node* next;
};
typedef struct Node TypeNode;  //Define one Type of this element

//Initialize Node (set to NULL)
struct Node* initialize(void);
//Insert one new value to the list
struct Node* insertNode (struct Node* list, TypeData data);
//Print all elements of one list
void printList(struct Node* list);
//Remove entire list, i.e., free memory usage of all elements
void removeList(struct Node* list);
//Remove one node with one respective data value and return resultant list
struct Node* removeNode(struct Node* list, TypeData data);
//Search for one data in one list
struct Node* searchNode( struct Node* list, TypeData data);

/**
 * Initialize Node (set to NULL)
 *
 * @return NULL
 */
struct Node* initialize(void)
{
    return NULL;
}

/**
 * Insert one new value to the list
 *
 * @param[in] TypeNode list: List to search
 * @param[in] TypeData data: Data for insert
 * @return TypeNode list: Resultant list
 */
struct Node* insertNode (struct Node* list, TypeData data)
{
    struct Node* newItem;
    struct Node* last = NULL;
    struct Node* aux = list;
    newItem = malloc(sizeof(TypeData));
    newItem->data = data;

    while (( aux != NULL ) && ( strcmp(aux->data.item, data.item ) < 0 ))
    {
        last = aux;
        aux = aux->next;
    }
    if (last == NULL)
    {
        //If last does not exist, insert at start of the list
        newItem->next = list;
        list = newItem;
    }
    else
    {
        //Last exist, so insert at middle of list
        newItem->next = last->next;
        last->next = newItem;
    }
    return list;
}

/**
 * Print all elements of one list
 *
 * @param[in] TypeNode list: List to print
 * @return void
 */
void printList(struct Node* list)
{
    struct Node* aux;

    if (list == NULL)
    {
        puts("Empty List");
    }
    else
    {
        for ( aux=list; aux!=NULL; aux=aux->next)
        {
            printf("Item: %s\n", aux->data.item);
        }
    }
}


/**
 * Remove entire list, i.e., free memory usage of all elements
 *
 * @param[in] TypeNode list: List to search
 * @return void
 */
void removeList(struct Node* list)
{
    struct Node* aux;
    while (list != NULL)
    {
        aux = list;
        list = list->next;
        free(aux);
    }
    free(list);
}

/**
 * Remove one node with one respective data value and return resultant list
 *
 * @param[in] TypeNode list: List to search
 * @param[in] TypeData data: Data for search to remove
 * @return TypeNode list: Resultant list
 */
struct Node* removeNode(struct Node* list, TypeData data)
{
    struct Node* last = NULL;
    struct Node* aux = list;

    while (aux !=NULL && (strcmp(aux->data.item, data.item)))
    {
        last = aux;
        aux = aux->next;
    }
    if (aux == NULL)
    {
        return list;
    }

    if (last == NULL)
    {
        list = aux->next;
    }
    else
    {
        last->next = aux->next;
    }

    free(aux);
    return list;
}

/**
 * Search for one data in one list, return NULL does not found untill end of
 * list, or respective node if found
 *
 * @example
 *      strcpy( data.item, "item to search");
 *      if ( searchNode( list, data ) != NULL ){
 *          printf("\n%s found \n", data.item);
 *      }
 *
 * @param[in] TypeNode list: List to search
 * @param[in] TypeData data: Data for search
 * @return TypeNode aux: Node if find, NULL if not find element
 */
struct Node* searchNode( struct Node* list, TypeData data)
{
    struct Node* last = NULL;
    struct Node* aux = list;

    while (aux !=NULL && (strcmp(aux->data.item, data.item)))
    {
        last = aux;
        aux = aux->next;
    }
    return aux;
}

#endif // ASINGLYLINKEDLIST_H_INCLUDED
