#ifndef COHELPER_H_INCLUDED
#define COHELPER_H_INCLUDED

#include "lib/data/singlylinkedlist.h"
#include "cocore.h"



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
 * @param idioma[50] Nome do idioma
 * @param quantia Numero de definicoes (palavras) que contem
 * @param definicoes Palavras contidas no dicionario
 * @param cacheDefinidas Cache com termos frequentes e definidos no dicionario
 * @param cacheIndefinidas Cache com termos frequentes, porem nao definidos
 * @param proximo Ponteiro para o proximo item
 *
 */
struct Dicionarios
{
    char idioma[50];
    double quantia;
    TypeSLLNode *definicoes;
    //TipoDeCache cacheDefinidas
    //TipoDeCache cacheIndefinidas
    struct Dicionarios *proximo;
};

typedef struct Dicionarios DicionariosType;

/**
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
struct COMem
{
    struct Benchmarks *benchmarks;
    struct Dicionarios *dicionarios;

};

typedef struct COMem COMemType;


/**
 * Inicializa COMemType
 *
 *
 */
COMemType *cohInicializaMemoria( COMemType *Memoria)
{
    Memoria->dicionarios = NULL;
    Memoria->benchmarks = NULL;
    return Memoria;
}

/**
 * Aloca memoria para DicionariosType (um novo item de dicionario)
 * Aloca espaco na memoria para os objetos
 *
 * @param[in,out] dicionarios Poteiro para DicionariosType
 * @return dicionario
 */
DicionariosType *cohAlocaDicionarios( DicionariosType * dicionario)
{
    //dicionario->definicoes = malloc(sizeof(TypeSLLNode*));
    dicionario->definicoes = initializeSLL();
    //dicionario->idioma = malloc(sizeof(char)*50);//char idioma[50]
    //dicionario->proximo = malloc(sizeof(DicionariosType*));
    //dicionario->quantia = malloc(sizeof(double));
    return dicionario;
}

/**
 * Inicializa DicionariosType (um novo item de dicionario)
 * Inicializa com valor inicial NULL
 *
 * @param[in,out] dicionarios Poteiro para DicionariosType
 * @return dicionario
 */
DicionariosType *cohInicializaDicionarios( DicionariosType * dicionario)
{
    dicionario->definicoes = NULL;
    //dicionario->idioma = NULL;
    dicionario->proximo = NULL;
    //dicionario->quantia = NULL;
    return dicionario;
}


/*
int cohDicionarioAdiciona( COMemType *Memoria, )
{
    Memoria->dicionarios = NULL;
    Memoria->benchmarks = NULL;
    return Memoria;
}
*/
/**
 * Carrega um arquivo de dicionario para a memoria
 * @warning O arquivo deve ter sido testado para ver se e' possivel ler previamente
 * test with C:\Users\fititnt\github\fititnt\CorretorOrtografico\source\testes\en\texto1.txt
 * @warning Ira adicionar mais de um dicionario com o mesmo idioma. Caso seja decejado o contrario, trate esse erro antes
 *
 */
int cohCarregaDicionario( COMemType *Memoria, char *path, char *idioma )
{
    char line[256];
    double i = 0;
    TypeSLLData definicao;

    if (Memoria->dicionarios == NULL){
        Memoria->dicionarios = malloc(sizeof(DicionariosType));
    }

    Memoria->dicionarios->definicoes = initializeSLL();
    //Memoria->dicionarios->quantia = 2.0;

    FILE *file = fopen ( path , "r" );//C:/Users/fititnt/github/fititnt/CorretorOrtografico/source/dicionarios/en.dic
    if ( file != NULL)
    {
        while(!feof(file))
        {
            if( fgets(line, 256, file) ){
                line[strlen(line) -1] = '\0';//Remove quebra de linha
                strcpy(definicao.item, line);
                Memoria->dicionarios->definicoes = insertSLLNode( Memoria->dicionarios->definicoes, definicao );
                //printf("%s ,", line);
            }
            ++i;
        }
        Memoria->dicionarios->quantia = (double)i;
        printf("\n %g - %g\n", i, Memoria->dicionarios->quantia);
        return i; //Retorna a quantidade de linhas adicionadas
    }
    else
    {
        return -1;//Erro de abertura
    }

}



#endif // COHELPER_H_INCLUDED
