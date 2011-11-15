/**
 * @file main.c
 * @details Corretor Ortografico - Main file
 * @version 0.1alpha
 * @author Emerson Rocha Luiz
 * @copyright MIT. See license.txt
 * @mainpage
 * Estrutura do programa
 * /main.c
 * /cocore.h            - Rotinas intimamente ligadas a este aplicativo
 * /cohelper.h          - Camada que intermedia o arquivo anterior com os demais
 * /cotests.h           - Arquivo com rotinas de testes e debug
 * /userio.h            - Tornar deprecated
 * /lib/data/           - Serie de bibliotecas lidadas a estrutura de dados
 * /lib/db/debug.h      - Boblioteca de suporte a debbug
 * /lib/fs/filesys.h    - Biblioteda com rotinas ligadas ao sistema de arquivos
 * /lib/gui/gui.h       - Biblioteca ligada a interface com o usuario
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "lib/fs/filesys.h"
#include "cocore.h"
#include "lib/db/debug.h"
#include "lib/gui/gui.h"
#include "lib/data/singlylinkedlist.h"

#include <time.h>

/**
* Main function
*
*/
int main()
{
    int acao, subacao;
    COMemType *Memoria = malloc(sizeof(COMemType));
    Memoria = cohInicializaMemoria(Memoria);

    clock_t start;
    start = dbProfileStart();

    coInicio();


    do
    {

        coListarOpcoes( 0 );
        acao = coOpcaoQuestiona(0, 4);

        switch ( acao )
        {
        case 1:
            /**
             * Opcao que define acoes gerais relativas aos dicionarios carregados
             */
            coListarOpcoes( 1 );
            subacao = coOpcaoQuestiona(0, 4);
            switch ( subacao )
            {
            case 1:
                coDicionarioCarrega( Memoria );
                break;
            case 2:
                coListarOpcoes( 2 );
                subacao = coOpcaoQuestiona(0, 4);
                //coDicionarioGerencia();
                break;
            case 3:
                coListarOpcoes( 3 );
                subacao = coOpcaoQuestiona(0, 4);
                //coDicionarioEstatisticas();
                break;
            case 4:
                //coDicionarioRemove();
                break;
            }
            break; //Fim acao 1
        case 2:
            /**
             * Opcao que define acoes gerais relativas aos dicionarios carregados
             */
            coListarOpcoes( 2 );
            subacao = coOpcaoQuestiona(0, 4);
            switch ( subacao )
            {
            case 1:

                break;
            case 2:
                break;
            }

            break; //Fim acao 2
        case 3:
            break; //Fim acao 3
        case 4:
            /**
             * Exibe creditos
             */
            coCreditos();
            break; //Fim acao 4
        }

    }
    while ( acao > 0 );


    /// Print file contents
    //char * content;
    //fsFileToString("C:\\Users\\fititnt\\github\\fititnt\\CorretorOrtografico\\source\\dicionarios\\en.dic", &content);
    //guiPringString(content);

    ///
    //char* content;
    //content = malloc(300000*sizeof(char));
    //char* content[65000];
    //int i = -3;
    //i = fsFileToArray("C:\\Users\\fititnt\\github\\fititnt\\CorretorOrtografico\\source\\testes\\en\\texto1.txt", content);
    //guiPringString(&content);
    //printf("\n getFileToArray result: >%i< \n", i);

    coSaida();

    dbProfileEnd(start);
    return 0;
}
