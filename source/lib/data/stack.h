/**
 * @file stack.h
 * @details Stack
 * @version 0.1
 * @date 2011-11-13
 * @author Emerson Rocha Luiz
 * @copyright
 * @license GPL3. See license-gpl3.txt
 * @license MIT. See license-mit.txt
 */

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define STK_MAX 100


/**
 * Define the StackType
 * Change here for change entire strure at once
 */
 /*
typedef struct
{
    double data; ///Type double
} StackType;
*/
/**
 * Basic struct of the Stack
 */
typedef struct
{
    double data[STK_MAX]; //StackType data[STK_MAX];
    int top;
} Stack;

/**
 * Prototypes
 */
void push(Stack *Stk, double value);//void push(Stack *Stk, StackType value);
double pop(Stack *Stk);//StackType pop(Stack *Stk);
void initialize(Stack *Stk);
int full(Stack *Stk);
void StackPrint(Stack *Stk);

/**
 * Push values to stack
 *
 * @param[in,out] Stack Stk
 * @param[in] StackType value
 * @return void
 */
void push(Stack *Stk, double value)
{
    Stk->data[ Stk->top ] = value;
   (Stk->top)++;
}

/**
 * Pop values from stack
 *
 * @param[in,out] Stack Stk
 * @return StackType
 */
double pop(Stack *Stk)
{
    (Stk->top)--;
    return (Stk->data[Stk->top]);
}

/**
 * Initialize stack
 *
 * @param[in,out] Stack Stk
 * @return void
 */
void initialize(Stack *Stk)
{
    Stk->top = 0;
}

/**
 * Return if stak is full
 *
 * @param[in,out] Stack Stk
 * @return int Number of top or -1 if is full
 */
int full(Stack *Stk)
{
    if (Stk->top >= STK_MAX){
        return Stk->top;
    } else {
        return -1;
    }
}
/**
 * Print Stack
 *
 * @param[in] Stack Stk
 * @return void
 */
void StackPrint(Stack *Stk)
{
    int i;
    if (Stk->top != 0){
       for (i=0; i<Stk->top; i++)
       {
          printf("%g  a",Stk->data[i]);
       }
       printf("\n");
    } else {
        printf("Empty\n");
    }
}

#endif // STACK_H_INCLUDED
