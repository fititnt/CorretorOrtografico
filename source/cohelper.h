/**
 * @file cohelper.h
 * @details Corretor Ortografico - Core
 * @version 0.3beta
 * @author Emerson Rocha Luiz
 * @copyright MIT. See license.txt
 */

#ifndef COHELPER_H_INCLUDED
#define COHELPER_H_INCLUDED

#include "lib/data/singlylinkedlist.h"
#include "cocore.h"
#include <time.h>
#include "lib/db/debug.h"

/**
 *
 */
typedef struct Benchmarks BenchmarkType;

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
 */
typedef struct Dicionarios DicionariosType;

/**
 *
 * @param idioma[50] Nome do idioma
 * @param quantia Numero de definicoes (palavras) que contem
 * @param definicoes Palavras contidas no dicionario
 * @param cacheDefinidas Cache com termos frequentes e definidos no dicionario
 * @param cacheIndefinidas Cache com termos frequentes, porem nao definidos
 * @param proximo Ponteiro para o proximo item
 */
struct Dicionarios
{
    char idioma[50];
    double quantia;
    TypeSLLNode *definicoes;
    //TipoDeCache cacheDefinidas
    //TipoDeCache cacheIndefinidas
    DicionariosType *proximo;
};

/**
 *
 * linha linha da respectiva palavra
 * item Todas as palavras
 */
struct Palavras {
    //int errado;
    int linha;
    //char *termo;
    struct NodeSLL* item;//
};

struct linhas {
    int linha;
    struct linhas* proxima;
};

struct PalavraExplicada{
    int ordem;
    int tamanho;
    //int linha;
    char termo[100];
    struct linhas* linhas;
    struct PalavraExplicada *anterior;
    struct PalavraExplicada *proxima;
}tPalavraExplicada;

struct GrupoPalavras {
    int errado;
    int quantidade;
    struct linhas* linhas;
    char termo[100];
    struct GrupoPalavras* proximo;
};

/**
 * Estrutura que define a reuniao de informacoes sobre analise ortografica de
 * um texto especifico
 *
 * @todo Refletir se nao e` melhor fundir com o struct Textos
 */
struct AnaliseOrtografica
{
    struct Palavras* palavras;//struct NodeSLL *palavras;
    struct GrupoPalavras* termosAnalizados;
    int qtdPalavras;
};

typedef struct Textos TextoType;

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
    //struct Palavras *palavras;
    struct Dicionarios *dicionario;
    struct AnaliseOrtografica *analise;
    char *completo; //2560000
    char *idioma; //50
    char *titulo; //50
    int tamanho;
    TextoType *proximo;
};



/**
 *
 */
typedef struct COMem COMemType;

/**
 * Struct para conter informacoes pertinentes a respeito do CorretorOrtografico
 * @
 * @param ListaDebenchmark Ponteiro para uma lista de benchmarks
 *
 */
struct COMem
{
    BenchmarkType *benchmarks;
    DicionariosType *dicionarios;
    TextoType *textos;

};



/**
 * Inicializa COMemType
 *
 * @param Memoria Objeto global de memoria
 * @return Memoria Objeto global de memoria
 */
COMemType *cohInicializaMemoria( COMemType *Memoria)
{
    Memoria->dicionarios = NULL;
    Memoria->benchmarks = NULL;
    Memoria->textos = NULL;
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
 * @param[in,out] Memoria Objeto global de memoria
 * @param[in] path Local aonde se encontra o arquivo a ser carregado
 * @param[in] idioma Idioma do item carregado
 * @return int
 */
int cohCarregaDicionario( COMemType *Memoria, char *path, char *idioma )
{
    char line[256];
    double i = 0;
    clock_t start;

    TypeSLLData definicao;

    if (Memoria->dicionarios == NULL)
    {
        Memoria->dicionarios = malloc(sizeof(DicionariosType));
    }

    Memoria->dicionarios->definicoes = initializeSLL();
    //Memoria->dicionarios->quantia = 2.0;

    FILE *file = fopen ( path , "r" );//C:/Users/fititnt/github/fititnt/CorretorOrtografico/source/dicionarios/en.dic
    if ( file != NULL)
    {
        start = dbProfileStart();

        while(!feof(file))
        {
            if( fgets(line, 256, file) )
            {
                line[strlen(line) -1] = '\0';//Remove quebra de linha
                strcpy(definicao.item, line);
                Memoria->dicionarios->definicoes = insertSLLNode( Memoria->dicionarios->definicoes, definicao );
                //printf("%s ,", line);
            }
            ++i;
        }
        Memoria->dicionarios->quantia = (double)i;
        //printf("\n %g - %g\n", i, Memoria->dicionarios->quantia);

        printf("\nTempo de carregamento do dicionario:\n   ");
        dbProfileEnd( start );

        return i; //Retorna a quantidade de linhas adicionadas
    }
    else
    {
        return -1;//Erro de abertura
    }
}

int cohCarregaDicionarioOtimizada( COMemType *Memoria, char *path, char *idioma )
{
    //char line[256];
    char *string;
    double i = 0;
    clock_t start;
    int len = 0, amount;


    //TypeSLLData definicao;

    if (Memoria->dicionarios == NULL)
    {
        Memoria->dicionarios = malloc(sizeof(DicionariosType));
    }

    Memoria->dicionarios->definicoes = initializeSLL();
    //Memoria->dicionarios->quantia = 2.0;

    FILE *file = fopen ( path , "r" );//C:/Users/fititnt/github/fititnt/CorretorOrtografico/source/dicionarios/en.dic
    if ( file != NULL)
    {

        start = dbProfileStart();
        fseek(file, 0, SEEK_END);
        len = ftell(file);
        fseek(file, 0, SEEK_SET);

        string  = (char*)malloc(len*sizeof(char));

        fread(string, sizeof(char), len, file);
        importStringSLL(Memoria->dicionarios->definicoes, string, len, &amount);
        free(string);

        printf("\nTempo de %i termos carregados do do dicionario:\n   ", amount);
        dbProfileEnd( start );

        return i; //Retorna a quantidade de linhas adicionadas
    }
    else
    {
        return -1;//Erro de abertura
    }
}


/**
 *
 * @param[in,out] Memoria Objeto global de memoria
 * @param[in] path Local aonde se encontra o arquivo a ser carregado
 * @param[in] idioma Idioma do item carregado
 * @param[out] descricao Descricao adicional. Opcional, pode ser NULL
 * @return tamanho do texto, ou -2 se nao conseguir abrir o arquivo, -1 se nao puder ler
 */
int cohTextoCarrega( COMemType *Memoria, char *path, char *idioma , char *descricao)
{
    int tamanho;
    char *content;
    tamanho = fsFileToString(path, &content);

    if (tamanho < 0)
    {
        printf("\nCorretorOrtografico: ERRO! Arquivo nao foi encontrado");
        return -1;
    }

    //Caso ainda nao haja textos, inicializar
    if (Memoria->textos == NULL)
    {
        Memoria->textos = malloc(sizeof(TextoType));
        //Memoria->textos->palavras
        Memoria->textos->tamanho = tamanho;
        Memoria->textos->analise = NULL;
        Memoria->textos->completo = NULL;
        Memoria->textos->dicionario = NULL;
        Memoria->textos->proximo = NULL;
        //Memoria->textos->
    }
    //Com os textos inicializados, checar se o objeto atual tem um texto carregado
    if (Memoria->textos->completo == NULL)
    {
        Memoria->textos->idioma = malloc(sizeof(char)*50);
        Memoria->textos->titulo = malloc(sizeof(char)*50);
        Memoria->textos->completo = malloc(sizeof(char)*2560000);
        Memoria->textos->tamanho = tamanho;

        strcpy(Memoria->textos->idioma, idioma);
        strcpy(Memoria->textos->titulo, descricao);
        strcpy(Memoria->textos->completo, content);
    }
    else
    {
        //O Objeto atual de texto esta preenchido. Carregar o proximo
        TextoType *newItem;
        TextoType *last = NULL;
        TextoType *aux = Memoria->textos;
        newItem = malloc(sizeof(TextoType));
        newItem->proximo = malloc(sizeof(TextoType));
        newItem->idioma = malloc(sizeof(char)*50);
        newItem->titulo = malloc(sizeof(char)*50);
        newItem->completo = malloc(sizeof(char)*2560000);
        newItem->tamanho = tamanho;
        strcpy(newItem->completo, content);
        strcpy(newItem->idioma, idioma);
        strcpy(newItem->titulo, descricao);

        while (( aux != NULL ) && ( strcmp(aux->completo, newItem->completo ) < 0 ))
        {
            last = aux;
            aux = aux->proximo;
        }
        if (last == NULL)
        {
            //If last does not exist, insert at start of the list
            newItem->proximo = Memoria->textos;
            Memoria->textos = newItem;
        }
        else
        {
            //Last exist, so insert at middle of list
            newItem->proximo = last->proximo;
            last->proximo = newItem;
        }
    }
    return tamanho;
}



#endif // COHELPER_H_INCLUDED
