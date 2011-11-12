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

 /**
 * Main function
 *
 */
int main()
{
    //coUserCL();

    int resultado;
    resultado = debugFileOpen("C:\\Users\\fititnt\\github\\fititnt\\CorretorOrtografico\\source\\dicionarios\\en.dic");
    if ( resultado == 1 ){
        printf("O arquivo pode ser aberto");
    } else {
        printf("O arquivo nao pode ser aberto");
    }
    return 0;
}
