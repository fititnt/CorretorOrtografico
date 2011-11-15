#ifndef COHELPER_H_INCLUDED
#define COHELPER_H_INCLUDED

#include "lib/data/singlylinkedlist.h"
#include "cocore.h"

/**
 * Carrega um arquivo de dicionario para a memoria
 * @warning O arquivo deve ter sido testado para ver se e' possivel ler previamente
 * test with C:\Users\fititnt\github\fititnt\CorretorOrtografico\source\testes\en\texto1.txt
 *
 */
void cohCarregaDicionario( struct COInfo *Memoria, char * path )
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



#endif // COHELPER_H_INCLUDED
