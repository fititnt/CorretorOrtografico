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
    //Memoria->dicionarios = NULL;
    //Memoria->dicionarios = malloc(sizeof(DicionariosType));
    //Memoria->dicionarios->definicoes = NULL;
    //int tamanho;
    //char *content;
    //tamanho = fsFileToString("C:/Users/fititnt/github/fititnt/CorretorOrtografico/source/dicionarios/en.dic", &content);
    //printf("%i, %s", tamanho, content);

    char path[255] = "C:/Users/fititnt/github/fititnt/CorretorOrtografico/source/dicionarios/en.dic";
    char filename[255]; char extension[255]; char name[255];
    fsPathInfo( path, filename, name, extension);
    /*
    int i, j = 0, k = 0, l = 0, dot = 0;
    for( i=strlen(path); i > 0; --i){
        if( path[i]=='\0'){
            continue;
        }
        if( path[i]=='.'){
            dot = 1;
        }
        if(  (char)path[i]=='\\' || (char)path[i] == '/'){
            break;
        }
        if (dot == 0){
            extension[j] = path[i];
            ++j;
        } else {
            if( path[i]!='.'){
            name[k] = path[i];
            ++k;
            }
        }
        filename[l] = path[i];
        ++l;
    }
    extension[j] = '\0';
    name[k] = '\0';
    filename[l] = '\0';
    strrev(extension);
    strrev(name);
    strrev(filename);
*/
    printf("\nPath: %s \nFilename: %s \nName: %s \nExtension: %s \n",path, filename, name, extension);



    clock_t start;
    start = dbProfileStart();

    coInicio();


    do
    {

        coListarOpcoes( 0 );
        acao = coOpcaoQuestiona(0, 5);

        switch ( acao )
        {                     //Gerenciar dicionarios   // Opcao geral 1: inicio
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
                break;
            }
            break;                                      // Opcao geral 2: fim
        case 3:  //Alterar definicoes desde programa    // Opcao geral 3: inicio
            break;                                      // Opcao geral 3: fim
        case 4:                       //Debug           // Opcao geral 4: inicio
            coDebug(Memoria);
            break;                                      // Opcao geral 4: fim
        case 5:                       //Creditos        // Opcao geral 5: inicio
            coCreditos();
            break;                                      // Opcao geral 5: fim
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
