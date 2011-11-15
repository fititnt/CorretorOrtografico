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


#define DICIONARIO_PATH C:\\Users\\fititnt\\github\\fititnt\\CorretorOrtografico\\source\\dicionarios\\en.dic

/**
 * Struct para conter bemchmark de uma acao
 * @todo implementar uma lista duplamente encadeada
 *
 * @param id Identificacao unica de uma acao
 * @param descricao Descricao da acao realizada
 * @param InicioDeAcao Tempo inicial de excecussao de uma acao
 * @param FinalDeAcao Tempo final de excecucao de uma acao
 * @param TempoDeExcecucao Tempo computado de escecucao de uma acao, em segundos
 * @param proximo Ponteiro para o proximo benchmark
 *
 */
struct Benchmarks
{
    int id;
    char descricao[100];
    time_t InicioDeAcao;
    time_t FinalDeAcao;
    float TempoDeExcecucao;
    struct Benchmarks *proximo;
};


/**
 *
 * @param idioma[20] Nome do idioma
 * @param quantia Numero de definicoes (palavras) que contem
 * @param definicoes Palavras contidas no dicionario
 * @param cacheDefinidas Cache com termos frequentes e definidos no dicionario
 * @param cacheIndefinidas Cache com termos frequentes, porem nao definidos
 * @param proximo Ponteiro para o proximo item
 *
 */
struct Dicionarios
{
    char idioma[20];
    double quantia;
    //TipoDeDicionario definicoes
    //TipoDeCache cacheDefinidas
    //TipoDeCache cacheIndefinidas
    struct Dicionarios *proximo;
};


/**
 *
 *
 *
 *
 */
struct Palavras
{
    //
};

/**
 * Estrutura que define a reuniao de informacoes sobre analise ortografica de
 * um texto especifico
 *
 * @todo Refletir se nao e` melhor fundir com o struct Textos
 *
 *
 *
 *
 */
struct AnaliseOrtografica
{
    //
};
/**
 * Reune os textos usados e testados
 *
 * @note Poderia ter sido adicionado em vez de diretamente o ponteiro para o
 *       dicionario, simplesmente o nome do dicionario, mas e` mais eficiente
 *       definir o quanto antes direto o ponteiro em vez de realizar buscas
 *       adicionais
 *
 * @param palavras Ponteiro para lista de palavras do texto
 * @param dicionario Ponteiro para um dicionario especifico
 *
 */
struct Textos
{
    struct Palavras *palavras;
    struct Dicionarios *dicionario;
    struct AnaliseOrtografica *analise;

};
/**
 * Struct para conter informacoes pertinentes a respeito do CorretorOrtografico
 * @
 * @param ListaDebenchmark Ponteiro para uma lista de benchmarks
 *
 */
struct COInfo
{
    struct Benchmarks benchmarks;
    struct Dicionarios dicionarios;

}COInfoType;

//
void coAjuda();
//
void coCore();
//
void coCreditos();
//
void coDicionarioCarrega();
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

/**
 *
 *
 *
 */
void coDicionarioCarrega( struct COInfo *Memoria )
{
    char path[255];
    printf("\n Insira caminho para o arquivo");
    printf("\n arquivo> ");
    fsGetStr( path );
    while( !fsFileOpen( path ) ){ //@todo checar se arquivo existe e pode ser lido
        printf("\n O Arquivo nao foi encontrado, ou nao esta disponivel para leitura. Revise:");
        printf("\n arquivo> ");
        fsGetStr( path );
    }
    char line[128];

    FILE *file = fopen ( path , "r" );//C:/Users/fititnt/github/fititnt/CorretorOrtografico/source/testes/br/texto5.txt
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
    //cohCarregaDicionario( *Memoria, path );
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
                printf("\n 4 - Creditos");
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






#endif // COCORE_H_INCLUDED
