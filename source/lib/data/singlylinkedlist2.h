/**
 * @details Singly Linked List
 * @see http://en.wikipedia.org/wiki/Linked_list
 * @version 0.1beta2
 * @author Emerson Rocha Luiz
 * @copyright MIT. See license.txt
 */

#ifndef SINGLYLINKEDLIST2_H_INCLUDED
#define SINGLYLINKEDLIST2_H_INCLUDED

//Struct of data do hold information
/**
 * Struct that hold data especification
 * Change this struct for change witch tipe of data will be stored
 *
 * @param item[100] String data used on this class
 */
struct DataSLL2
{
    int quantidade;
	char item[100];
} ;

/**
 * Define TypeSLL2Data as Type of DataSLL2
 */
typedef struct DataSLL2 TypeSLL2Data; //Define one Type of this element

//Struct of node used on list
/**
 * Struct that hold node especification
 *
 * @param data Data that this node hold
 * @param next pointer for next node. NULL if this is last node
 */
struct NodeSLL2
{
    TypeSLL2Data data;
    struct NodeSLL2* next;
};

/**
 * Define TypeSLLNode as Type of NodeSLL2
 */
typedef struct NodeSLL2 TypeSLL2Node;  //Define one Type of this element

//initializeSLL2 Node (set to NULL)
struct NodeSLL2* initializeSLL2(void);
//Insert one new value to the list
struct NodeSLL2* insertSLL2Node (struct NodeSLL2* list, TypeSLL2Data data);
//Print all elements of one list
void printSLL2List(struct NodeSLL2* list);
//Remove entire list, i.e., free memory usage of all elements
struct NodeSLL2* removeSLL2List(struct NodeSLL2* list, TypeSLL2Data data);
//Remove one node with one respective data value and return resultant list
struct NodeSLL2* removeSLL2List(struct NodeSLL2* list, TypeSLL2Data data);
//Search for one data in one list
struct NodeSLL2* searchSLL2Node( struct NodeSLL2* list, TypeSLL2Data data);

/**
 * initializeSLL2 Node (set to NULL)
 *
 * @return NULL
 */
struct NodeSLL2* initializeSLL2(void)
{
    return NULL;
}

/**
 * Insert one new value to the list
 *
 * @param[in] list List to search
 * @param[in] data Data for insert
 * @return TypeSLLNode list: Resultant list
 */
struct NodeSLL2* insertSLL2Node (struct NodeSLL2* list, TypeSLL2Data data)
{
    struct NodeSLL2* newItem;
    struct NodeSLL2* last = NULL;
    struct NodeSLL2* aux = list;
    newItem = malloc(sizeof(TypeSLL2Data));
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
 * @param[in] list List to print
 * @return void
 */
void printSLL2List(struct NodeSLL2* list)
{
    struct NodeSLL2* aux;

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
 * @param[in] list List to search
 * @return void
 */
void removeSL2LList(struct NodeSLL2* list)
{
    struct NodeSLL2* aux;
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
 * @param[in] list List to search
 * @param[in] data Data for search to remove
 * @return list Resultant list
 */
struct NodeSLL2* removeSLL2List(struct NodeSLL2* list, TypeSLL2Data data)
{
    struct NodeSLL2* last = NULL;
    struct NodeSLL2* aux = list;

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
 * @code
 * strcpy( data.item, "item to search");
 * if ( searchSLLNode( list, data ) != NULL ){
 *     printf("\n%s found \n", data.item);
 * }
 * @endcode
 *
 * @param[in] list List to search
 * @param[in] data Data for search
 * @return aux Node if find, NULL if not find element
 */
struct NodeSLL2* searchSLL2Node( struct NodeSLL2* list, TypeSLL2Data data)
{
    struct NodeSLL2* last = NULL;
    struct NodeSLL2* aux = list;

    while (aux !=NULL && (strcmp(aux->data.item, data.item)))
    {
        last = aux;
        aux = aux->next;
    }
    return aux;
}

#endif // ASINGLYLINKEDLIST2_H_INCLUDED
