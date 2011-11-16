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
#include "cohelper.h"




//
void coAjuda();
//
void coDebug(COMemType *Memoria);

//
void coCore();
//
void coCreditos();
//
void coDicionarioCarrega( COMemType *Memoria );
//
void coTextoCarrega( COMemType *Memoria );
//
int coDicionarioPalavraTolerada( char* termo );
//
int coDicionarioSimplesPalavraPertence( char** dicionario, char * termo );
//
void coInicio();
//
void coSaida();
//
int coQuestionaAcao();

/**
 * Questionario padrao de importacao de arquivo
 *
 * @param[out] path Local aonde se encontra o arquivo a ser carregado
 * @param[out] idioma Idioma do item carregado
 * @param[out] descricao Descricao adicional. Opcional, pode ser NULL
 * @return sucesso 1 se sucesso, 0 se falha
 * @private
 */
static int _coCarregaInformacoes( char *path , char *idioma, char *descricao)
{
    int sucesso = 1;
    char filename[255]; char extension[255];/* char name[255]*/;//Get path info

    printf("\n Insira caminho para o arquivo");
    printf("\n arquivo> ");
    fflush(stdin); //Limpar buffer
    fsGetStr( path );
    while( !fsFileOpen( path ) ){
        printf("\n O Arquivo nao foi encontrado, ou nao esta disponivel para leitura. Revise:");
        printf("\n arquivo> ");
        fsGetStr( path );
    }
    fsPathInfo( path, filename, descricao, extension);
    ///@todo Talvez implementar para o usuario a chance de sobrescrever a descricao
    printf("\n Aceito arquivo \"%s\" \n", descricao);
    printf("\n Informe o idioma desde arquivo:");
    printf("\n idioma> ");
    fsGetStr( idioma );
    return sucesso;
}

/**
 * Corretor Ortografico - Help
 *
 * @return void
 */
void coAjuda()
{
    //
}




void coCore()
{
    //
}



/**
 * Corretor Ortografico - Credits
 *
 * @return void
 */
void coCreditos()
{
    //
}

void coDicionarioCarrega( COMemType *Memoria )
{
    char path[255];
    char idioma[50];

    printf("\n Insira caminho para o arquivo");
    printf("\n arquivo> ");
    fsGetStr( path );
    while( !fsFileOpen( path ) ){ //@todo checar se arquivo existe e pode ser lido
        printf("\n O Arquivo nao foi encontrado, ou nao esta disponivel para leitura. Revise:");
        printf("\n arquivo> ");
        fsGetStr( path );
    }
    printf("\n Nome do idioma:");
    printf("\n idioma> ");
    fsGetStr( idioma );

    //Se o dicionario e' NULL, quer dizer que foi recentemente inicializado,
    //logo, precisa-se alocar mais espaco em memoria para alguns itens
    if ( Memoria->dicionarios == NULL ){
        //Memoria->dicionarios = cohInicializaDicionarios(Memoria->dicionarios);
    }

    cohCarregaDicionario( Memoria, path, idioma);

    /*
    FILE *file = fopen ( path , "r" );//C:/Users/fititnt/github/fititnt/CorretorOrtografico/source/dicionarios/en.dic
    if ( file != NULL)
    {
        while(!feof(file))
        {
            if( fgets(line, 256, file) ){
                line[strlen(line) -1] = '\0';//Remove linebreak
                printf("%s", line);

            }
        }
        return; //Arquivo pode ser aberto
    }
    else
    {
        printf("File cannot be opened");
    }
    */
    //cohCarregaDicionario( *Memoria, path );
}

void coDebug(COMemType *Memoria){
    printf("\n\n\n");
    printf("\n         **DEBUG**         \n");
    printf("Memoria: %i \n", sizeof(Memoria));
    printf("\n         **DEBUG**         \n");
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
 * Corretor Ortografico - Start
 *
 * @return void
 */
void coInicio()
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
    */
    printf("Inicio do Corretor Ortografico\n");

}
/*
static int coLoadToSinglyLinkedList(char * path, TypeSLLNode* node)
{

    return 0;
}
*/
/**
 * trata a entrada de usuario para um valor valido aceitavel
 *
 * @return void
 */
int coOpcaoQuestiona( int min, int max )
{
    int entrada;
    scanf("%i", &entrada);
    while ( !(entrada >= min) || !(entrada <=max) ){
        printf("\nResposta nao conforme Informe um valor valido entre %i e %i\n\n  Novo valor>", min, max);
        scanf("%i", &entrada);
    }
    return entrada;
}
/**
 * Imprime uma lista de altertivas, conforme a opcao fornecida
 *
 * @return void
 */
void coListarOpcoes( int opcao)
{
        switch ( opcao ){
            case 0:
                //printf("\n     OPCOES GERAIS");
                printf("\n 1 - Gerenciar dicionarios");
                printf("\n 2 - Gerenciar textos");
                printf("\n 3 - Alterar definicoes desde programa");
                printf("\n 4 - Debug");
                printf("\n 5 - Creditos");
                printf("\n 0 - Encerra o programa");
                printf("\n\n  Geral> ");
                break; //Fim acao 0
            case 1:
                //printf("\n     OPCOES DE DICIONARIO");
                printf("\n 1 - Adicionar dicionario");
                printf("\n 2 - Editar dicionario existente");
                printf("\n 3 - Remover dicionario");
                printf("\n 0 - Volta ao menu anterior");
                printf("\n\n  Dicionario> ");
                break; //Fim acao 1
            case 2:
                //printf("\n     OPCOES DE TEXTO");
                printf("\n 1 - Adicionar texto");
                printf("\n 2 - (Re)Analizar texto");
                printf("\n 3 - Editar texto");
                printf("\n 4 - Remover texto");
                printf("\n 0 - Volta ao menu anterior");
                printf("\n\n  Texto> ");
                break; //Fim acao 2
            case 4:
                //printf("\n     OPCOES DE TEXTO");
                printf("\n\n  Debug> ");
                break; //Fim acao 2
            case 5:
                //coCreditos();
                break; //Fim acao 2
            default:
                printf("\nErro logico n1\n");
                break; //Fim acao 3
        }
}




/**
 * Corretor Ortografico - End
 *
 * @return void
 */
void coSaida()
{
    printf("Fim de sessao do Corretor Ortografico\n");
}

void coTextoCarrega( COMemType *Memoria )
{
    char path[255];
    char idioma[255];
    char descricao[255];
    //char reservado //Array de opcoes reservadas
    _coCarregaInformacoes( path, idioma, descricao );
    cohTextoCarrega( Memoria, path, idioma, descricao );
}






#endif // COCORE_H_INCLUDED
