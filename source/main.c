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

#include <time.h>

/**
* Main function
*
*/
int main()
{
    clock_t start;

    start = tdbProfileStart();

    debugFilePrint("C:\\Users\\fititnt\\github\\fititnt\\CorretorOrtografico\\source\\dicionarios\\en.dic");

    tdbProfileEnd(start);

    return 0;
}
