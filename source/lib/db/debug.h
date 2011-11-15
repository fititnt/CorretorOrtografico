/**
 * @file debug.h
 * @details Corretor Ortografico - Debug
 * @version 0.1alpha
 * @author Emerson Rocha Luiz
 * @copyright MIT. See license.txt
 */

#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED

#include <stdio.h>
#include <time.h>

/**
 * Retorna se um arquivo pode ser aberto para leitura
 * @example
 *    int resultado;
 *    resultado = debugFileOpen("file.txt");
 *    if ( resultado == 1 ){
 *        printf("O arquivo pode ser aberto");
 *    } else {
 *        printf("O arquivo nao pode ser aberto");
 *    }
 *
 * @param[in] char[] Local do arquivo
 * @return int 0 para nao, 1 para sim
 */
int dbFileOpen( char path[] )
{
    FILE *file = fopen ( path, "r" );
    if ( file != NULL)
    {
        return 1; //Arquivo pode ser aberto
    }
    else
    {
        return 0; //Arquvo nao pode ser aberto
    }
}
/**
 * Print file contents
 *
 *
 */
void dbFilePrint( char path[] )
{
    char line[128];

    FILE *file = fopen ( path, "r" );
    if ( file != NULL)
    {
        while(!feof(file))
        {
            if(fgets(line, 128, file)) printf("%s", line);
        }
        return; //Arquivo pode ser aberto
    }
    else
    {
        printf("File cannot be opened");
    }
}
/**
 * Return current excecution time of program
 * @see tdbProfileEnd() function
 *
 * @return clock_t
 */
clock_t dbProfileStart()
{
    return clock();
}

/**
 * Print time diferente, in second, since tdbProfileStart was called
 * @example
 *          clock_t start;
 *          start = tdbProfileStart();
 *          //Your code...
 *          tdbProfileEnd(start);
 *
 * @todo Make it return the value, instead of print the falue. Still witout
 *       precision when try to return it.
 *
 * @param[in] clock_t start Start time
 * @return clock_t total_time Total time since the start time
 */
clock_t dbProfileEnd( clock_t start )
{
    clock_t end , total_time;
    end = clock() - start;
    printf ("%.6f\n",(double)( (end + 0.0) / CLOCKS_PER_SEC) ); //Print
    total_time = (double)( (end + 0.0) / CLOCKS_PER_SEC);
    return total_time;
}

/**
 * Dump some useful information about one array
 * - String Representation
 * - Leigth
 * - ASCII format
 * - Hexadecimal format
 * - Deximal
 * - Octa
 * @example
 * @code
 *      fsArrayDump("My String");
 * @endcode
 *
 * @param[in] array Array to dump
 * @return void
 */
void fsArrayDump(char *array)
{
    int i, itens;
    itens = sizeof(array)/sizeof(array[0]);
    printf("String: %s \n", array);
    printf("Leigth: %i \n", itens);
    printf(" ASCII |   HEX    |   DEC     |   OCT\n");
    for (i=0; i < itens ; i++){
        printf("   %c   |   %3.x    | %8.u  | %8.o \n", array[i], array[i], array[i], array[i]);
    }
}


#endif // DEBUG_H_INCLUDED
