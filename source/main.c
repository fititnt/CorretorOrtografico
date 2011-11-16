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

int main()
{
    int acao, subacao;
    COMemType *Memoria = malloc(sizeof(COMemType));
    Memoria = cohInicializaMemoria(Memoria);

    cohTextoCarrega(Memoria, "C:/Users/fititnt/github/fititnt/CorretorOrtografico/source/testes/en/texto1.txt", "en", "texto1.txt");
    cohTextoCarrega(Memoria, "C:/Users/fititnt/github/fititnt/CorretorOrtografico/source/testes/en/texto2.txt", "en", "texto2.txt");
    cohTextoCarrega(Memoria, "C:/Users/fititnt/github/fititnt/CorretorOrtografico/source/testes/en/texto6.txt", "en", "texto6.txt");

    coInicio();

    do
    {
        coListarOpcoes( 0 );
        acao = coOpcaoQuestiona(0, 5);

        switch ( acao )
        {
            //Gerenciar dicionarios   // Opcao geral 1: inicio
        case 1:
            coListarOpcoes( 1 );
            subacao = coOpcaoQuestiona(0, 3);
            switch ( subacao )
            {
            case 1: //Adicionar dicionario
                coDicionarioCarrega( Memoria );
                break;
            case 2: //Editar dicionario existente
                //coDicionarioGerencia();
                break;
            case 3: //Remover dicionario
                //coDicionarioEstatisticas();
                break;
            default: //Voltar menu
                continue;
            }
            break;                                      // Opcao geral 1: fim
        case 2:                 //Gerenciar textos      // Opcao geral 2: inicio
            coListarOpcoes( 2 );
            subacao = coOpcaoQuestiona(0, 4);
            switch ( subacao )
            {
            case 1: //Adicionar texto
                coTextoCarrega( Memoria );
                break;
            case 2: //Re)Analizar texto
                coTextoOpcoes( Memoria );
                break;
            }
            break;                                      // Opcao geral 2: fim
        case 3:  //Alterar definicoes desde programa    // Opcao geral 3: inicio
            coListarOpcoes( 3 );
            break;                                      // Opcao geral 3: fim
        case 4:                       //Debug           // Opcao geral 4: inicio
            coListarOpcoes( 4 );
            coDebug(Memoria);
            break;                                      // Opcao geral 4: fim
        case 5:                       //Creditos        // Opcao geral 5: inicio
            coListarOpcoes( 5 );
            coCreditos();
            break;                                      // Opcao geral 5: fim
        }
    }
    while ( acao > 0 );

    coSaida();

    return 1;
}
