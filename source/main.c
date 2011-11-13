/**
 * @file main.c
 * @details Corretor Ortografico - Main file
 * @version 0.1alpha
 * @author Emerson Rocha Luiz
 * @copyright MIT. See license.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include "filesys.h"
#include "userio.h"
#include "cocore.h"
#include "debug.h"
#include "gui.h"

#include <time.h>

/**
* Main function
*
*/
int main()
{
    clock_t start;
    start = tdbProfileStart();

    /// Print file contents
    //char * content;
    //getFileToString("C:\\Users\\fititnt\\github\\fititnt\\CorretorOrtografico\\source\\dicionarios\\en.dic", &content);
    //guiPringString(content);

    ///
    //char* content;
    //content = malloc(300000*sizeof(char));
    char* content[65000];
    int i = -3;
    i = getFileToArray("C:\\Users\\fititnt\\github\\fititnt\\CorretorOrtografico\\source\\testes\\en\\texto1.txt", content);
    //guiPringString(&content);
    //printf("\n getFileToArray result: >%i< \n", i);

    tdbProfileEnd(start);
    return 0;
}