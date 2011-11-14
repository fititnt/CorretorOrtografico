/**
 * @file cocore.h
 * @details Corretor Ortografico - Core
 * @version 0.1alpha
 * @author Emerson Rocha Luiz
 * @copyright MIT. See license.txt
 */


#ifndef COCORE_H_INCLUDED
#define COCORE_H_INCLUDED

#include "lib/data/singlylinkedlist.h"


#define DICIONARIO_PATH C:\\Users\\fititnt\\github\\fititnt\\CorretorOrtografico\\source\\dicionarios\\en.dic

void coUserCL();
void coStart();
void coGodbye();
void coHelp();
void coCredits();
int coDicionarioPalavraTolerada(char * termo);
int coDicionarioPalavraPertence(char * dicionario, char * termo);

/**
 * Corretor Ortografico User Command Line
 *
 * @return void
 */
void coUserCL()
{
    coStart();
    coGodbye();
}

/**
 * Corretor Ortografico - Start
 *
 * @return void
 */
void coStart()
{
    /*
    char *content;
    int i, linhas;

    linhas = getFileToArray( "DICIONARIO_PATH", &content);

    for( i = 0; i < linhas;  ++i)
    {
        printf("%s \n", (content + i) );
    }

    printf("%i \n", linhas);

    printf("Inicio do Corretor Ortografico\n");
    */
}

/**
 * Corretor Ortografico - End
 *
 * @return void
 */
void coGodbye()
{
    printf("Fim de sessao do Corretor Ortografico\n");
}

/**
 * Corretor Ortografico - Help
 *
 * @return void
 */
void coHelp()
{
    //
}

/**
 * Corretor Ortografico - Credits
 *
 * @return void
 */
void coCredits()
{
    //
}
/**
 * Retorna se uma palavra pertente a um dicionario do tipo Simples, isto e', um
 * dicionario que contem apenas um array de palavras
 *
 * @param[in] char** dicionario Dicionario base para a pesquisa
 * @param[in] char* termo Termo a ser pesquisado
 * @return int 1 se pertence (exato), 0 se termo tolerado e -1 se termo estranho
 */
int coDicionarioSimplesPalavraPertence( char** dicionario, char * termo )
{
    int tolerancia;
    tolerancia = coDicionarioPalavraTolerada(termo);
    //@todo ...
    return tolerancia;
}
/**
 * Retorna se uma palavra pertente a um dicionario
 *
 * @param[in] char* termo Termo a ser pesquisado
 * @return int 2 se palavra livremente aceita, 1 se tolerada e 0 se intolerada
 */
int coDicionarioPalavraTolerada( char* termo )
{
    //@todo ...
    return 1;
}


int coLoadToSinglyLinkedList( char * path, struct Node* node)
{

}


#endif // COCORE_H_INCLUDED
