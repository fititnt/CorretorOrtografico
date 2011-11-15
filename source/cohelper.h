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



COMemType *cohInicializaMemoria( COMemType *Memoria)
{
    Memoria->dicionarios = NULL;
    Memoria->benchmarks = NULL;
    return Memoria;
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
 *
 */
int cohCarregaDicionario( COMemType *Memoria, char *path )
{
    char line[256];

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
        return 1; //Arquivo pode ser aberto
    }
    else
    {
        return -1;
    }

}



#endif // COHELPER_H_INCLUDED
