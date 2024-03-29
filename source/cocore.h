/**
 * @file cocore.h
 * @details Corretor Ortografico - Core
 * @version 0.3beta
 * @author Emerson Rocha Luiz
 * @copyright MIT. See license.txt
 */


#ifndef COCORE_H_INCLUDED
#define COCORE_H_INCLUDED

#include <ctype.h> //isspace(c)
#include "lib/data/singlylinkedlist.h"
#include "lib/data/singlylinkedlist2.h"
#include "cohelper.h"



//Questionario padrao de importacao de arquivo
static int _coCarregaInformacoes( char *path , char *idioma, char *descricao);
//Tela de ajuda
void coAjuda();
//Interface com o usuario que exibe informacoes pertinetnes de debug
void coDebug(COMemType *Memoria);
//Retorna se uma palavra pertente a um dicionario do tipo Simples,
int coDicionarioSimplesPalavraPertence( char** dicionario, char * termo );
//Creditos do programa
void coCreditos();
//Interface com o usuario que viabiliza carregar um dicionario
void coDicionarioCarrega( COMemType *Memoria );
//Informacoes exibidas na inicializacao do programa
void coInicio();
//Informacoes exibidas ao final da excecucao do programa
void coSaida();
//Trata a entrada de usuario para um valor numerico valido aceitavel
int coOpcaoQuestiona( int min, int max );
//Interface com o usuario que viabiliza carregar um texto
void coTextoCarrega( COMemType *Memoria );

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
    char filename[255];
    char extension[255];/* char name[255]*/;//Get path info

    printf("\nCorretorOrtografico: Insira caminho para o arquivo");
    printf("\n arquivo> ");
    fflush(stdin); //Limpar buffer
    fsGetStr( path );
    while( !fsFileOpen( path ) )
    {
        printf("\nCorretorOrtografico: O Arquivo nao foi encontrado, ou nao esta disponivel para leitura. Revise:");
        printf("\n arquivo> ");
        fsGetStr( path );
    }
    fsPathInfo( path, filename, descricao, extension);
    ///@todo Talvez implementar para o usuario a chance de sobrescrever a descricao
    printf("\nCorretorOrtografico: Aceito arquivo \"%s\"", descricao);
    printf("\nCorretorOrtografico: Informe o idioma desde arquivo:");
    printf("\n idioma> ");
    fsGetStr( idioma );
    return sucesso;
}

/**
 * Tela de ajuda
 *
 * @return void
 */
void coAjuda()
{
    //
}

/**
 * Creditos do programa
 *
 * @return void
 */
void coCreditos()
{
    printf("\nAutor: Emerson Rocha Luiz");
    printf("\nContato: emerson@webdesign.eng.br");
    printf("\nSite: http://fititnt.org");
    printf("\nRepositorio: https://github.com/fititnt/CorretorOrtografico\n\n");
}

/**
 * Interface com o usuario que viabiliza carregar um dicionario
 * Intermedia com a funcao cohCarregaDicionario() do cohelper.h
 *
 * @param[in,out] Memoria Memoria Objeto global de memoria
 * @return void
 */
void coDicionarioCarrega( COMemType *Memoria )
{
    char path[255];
    char idioma[50];

    printf("\nCorretorOrtografico: Insira caminho para o arquivo");
    printf("\n arquivo> ");
    fsGetStr( path );
    while( !fsFileOpen( path ) )  //@todo checar se arquivo existe e pode ser lido
    {
        printf("\nCorretorOrtografico: O Arquivo nao foi encontrado, ou nao esta disponivel para leitura. Revise:");
        printf("\n arquivo> ");
        fsGetStr( path );
    }
    printf("\nCorretorOrtografico: Nome do idioma:");
    printf("\n idioma> ");
    fsGetStr( idioma );

    //Se o dicionario e' NULL, quer dizer que foi recentemente inicializado,
    //logo, precisa-se alocar mais espaco em memoria para alguns itens
    if ( Memoria->dicionarios == NULL )
    {
        //Memoria->dicionarios = cohInicializaDicionarios(Memoria->dicionarios);
    }

    cohCarregaDicionario( Memoria, path, idioma);
}


void coDicionarioCarregaOtimizada( COMemType *Memoria )
{
    char path[255];
    char idioma[50];

    printf("\nCorretorOrtografico: Insira caminho para o arquivo");
    printf("\n arquivo> ");
    fsGetStr( path );
    while( !fsFileOpen( path ) )  //@todo checar se arquivo existe e pode ser lido
    {
        printf("\nCorretorOrtografico: O Arquivo nao foi encontrado, ou nao esta disponivel para leitura. Revise:");
        printf("\n arquivo> ");
        fsGetStr( path );
    }
    printf("\nCorretorOrtografico: Nome do idioma:");
    printf("\n idioma> ");
    fsGetStr( idioma );

    //Se o dicionario e' NULL, quer dizer que foi recentemente inicializado,
    //logo, precisa-se alocar mais espaco em memoria para alguns itens
    if ( Memoria->dicionarios == NULL )
    {
        //Memoria->dicionarios = cohInicializaDicionarios(Memoria->dicionarios);
    }

    cohCarregaDicionarioOtimizada( Memoria, path, idioma);
}

/**
 * Interface com o usuario que exibe informacoes pertinetnes de debug
 *
 * @param[in,out] Memoria Objeto global de memoria
 * @return void
 */
void coDebug(COMemType *Memoria)
{
    printf("\n");
    printf("\n|-------------------DEBUG------------------------|\n");
    printf("Memoria: %i \n", sizeof(Memoria));
    printf("\n|------------------------------------------------|\n");
}


/**
 * Retorna se uma palavra pertente a um dicionario do tipo Simples, isto e', um
 * dicionario que contem apenas um array de palavras
 *
 * @deprecated
 * @param[in] char** dicionario Dicionario base para a pesquisa
 * @param[in] char* termo Termo a ser pesquisado
 * @return int 1 se pertence (exato), 0 se termo tolerado e -1 se termo estranho
 */
int coDicionarioSimplesPalavraPertence( char** dicionario, char * termo )
{
    int tolerancia = 1;
    //tolerancia = coDicionarioPalavraTolerada(termo);
    //@todo ...
    return tolerancia;
}


/**
 * Informacoes exibidas na inicializacao do programa
 *
 * @return void
 */
void coInicio()
{
    printf("Inicio do Corretor Ortografico\n");
}

/**
 * Trata a entrada de usuario para um valor numerico valido aceitavel
 *
 * @return void
 */
int coOpcaoQuestiona( int min, int max )
{
    int entrada;
    scanf("%i", &entrada);
    while ( !(entrada >= min) || !(entrada <=max) )
    {
        fflush ( stdin );//Garante que e' menor que o minimo para resetar esta variavel
        printf("\nCorretorOrtografico: Resposta nao conforme Informe um valor valido entre %i e %i\n\n  Novo valor>", min, max);
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
    switch ( opcao )
    {
    case 0:
        printf("\n -------------------------------------GERAL----------------------------------- ");
        printf("\n| 1 - Gerenciar dicionarios                                                   |");
        printf("\n| 2 - Gerenciar textos                                                        |");
        printf("\n| 3 - Alterar definicoes desde programa                                       |");
        printf("\n| 4 - Debug                                                                   |");
        printf("\n| 5 - Creditos                                                                |");
        printf("\n| 0 - Encerra o programa                                                      |");
        printf("\n ----------------------------------------------------------------------------- ");
        printf("\n\n  GERAL> ");
        break;
    case 1:
        printf("\n|-----------------------------------DICIONARIO--------------------------------|");
        printf("\n| 1 - Adicionar dicionario                                                    |");
        printf("\n| 2 - Editar dicionario existente                                             |");
        printf("\n| 3 - Remover dicionario                                                      |");
        printf("\n| 0 - Volta ao menu anterior                                                  |");
        printf("\n|-----------------------------------------------------------------------------|");
        printf("\n\n  DICIONARIO> ");
        break;
    case 2:
        printf("\n|-------------------------------------TEXTO-----------------------------------|");
        printf("\n| 1 - Adicionar texto                                                         |");
        printf("\n| 2 - (Re)Analizar texto                                                      |");
        printf("\n| 3 - Editar texto                                                            |");
        printf("\n| 4 - Remover texto                                                           |");
        printf("\n| 0 - Volta ao menu anterior                                                  |");
        printf("\n|-----------------------------------------------------------------------------|");
        printf("\n\n  TEXTO> ");
        break;
    case 3:
        printf("\n|-----------------------------------DEFINICOES---------------------------------|");
        printf("\n| 0 - Volta ao menu anterior                                                   |");
        printf("\n|------------------------------------------------------------------------------|");
        printf("\n\n  DEFINICOES> \n");
        break;
    case 4:
        printf("\n|-------------------------------------DEBUG------------------------------------|");
        printf("\n| 0 - Volta ao menu anterior                                                   |");
        printf("\n|-----------------------------------D------------------------------------------|");
        printf("\n\n  DEBUG> ");
        break;
    case 5:
        //coCreditos();
        break; //Fim acao 2
    default:
        printf("\nCorretorOrtografico: Erro logico n1\n");
        break; //Fim acao 3
    }
}




/**
 * Informacoes exibidas ao final da excecucao do programa
 *
 * @return void
 */
void coSaida()
{
    printf("CorretorOrtografico: Fim de sessao do Corretor Ortografico\n");
    coCreditos();
}


/**
 *
 * @see http://www.chemie.fu-berlin.de/chemnet/use/info/libc/libc_4.html
 * @todo Analiza e' com z, nao com s.
 *
 */
int coTextoAnalisa( COMemType *Memoria, char *content)
{
    int tmp = 0;
    clock_t start;
    if (Memoria->textos->analise == NULL)
    {
        Memoria->textos->analise = (struct AnaliseOrtografica*)malloc(sizeof(struct AnaliseOrtografica));
        Memoria->textos->analise->palavras = NULL;
    }
    if (Memoria->textos->analise->palavras == NULL)
    {
        Memoria->textos->analise->palavras = (struct Palavras*)malloc(sizeof(struct Palavras));
    }
    if (Memoria->textos->analise->palavras->item == NULL)
    {
        Memoria->textos->analise->palavras->item = (TypeSLLNode*)malloc(sizeof(TypeSLLNode));
        Memoria->textos->analise->palavras->item = NULL;
    }
    TypeSLLData data;

    int i, letras = 0, palavras = 0, quebraDePalavra = 0, linha = 1;
    char buffer[100];
    int tamanho = strlen(content);
    int numerodeerros = 0;
    printf("\n\n\n\n Insira o numero K:\n  >");
    numerodeerros = coOpcaoQuestiona(0, 100);

    struct NodeSLL* Nodo = initializeSLL();
    struct NodeSLL* NodoAgrupado = initializeSLL();

    struct PalavraExplicada* gPalavraRoot = (struct PalavraExplicada*)malloc(sizeof(struct PalavraExplicada));
    gPalavraRoot->linhas = (struct linhas*)malloc(sizeof(struct linhas));
    gPalavraRoot->linhas->linha = (int)malloc(sizeof(int));
    struct PalavraExplicada* gPalavra = (struct PalavraExplicada*)malloc(sizeof(struct PalavraExplicada));
    gPalavra->linhas = (struct linhas*)malloc(sizeof(struct linhas));
    gPalavra->linhas->linha = (int)malloc(sizeof(int));

    gPalavra = gPalavraRoot;

    start = dbProfileStart();
    /// Obtem termos
    for(i=0; i<=tamanho; ++i)
    {
        if (content[i] == '\n')
        {
            ++linha;
            //printf("\n%i", linha);
        }
        if( (isspace(content[i]) && !content[i] != '\'') || i==tamanho)// '  ',\f ,\n ,\r, \t, \v
        {
            if(letras == 0)
            {
                continue;//Sem palavras vazias, por favor
            }
            buffer[letras] = '\0';//Fecha string
            strcpy( data.item , buffer);
            Memoria->textos->analise->palavras->item = (struct NodeSLL*) malloc(sizeof(struct NodeSLL) );
            //Memoria->textos->analise->palavras->item = insertSLLNode(Memoria->textos->analise->palavras->item, data);
            Nodo = insertSLLNode(Nodo, data);
            //Memoria->textos->analise->palavras->linha = linha;
            ++palavras;
            letras = 0;
            quebraDePalavra = 1;
            //printf("Palavra %4.i, Tamanho:%2.i, Linha: %2.i, Termo:%s\n",palavras, strlen(buffer), linha, data.item );
            gPalavra->ordem = palavras;
            gPalavra->tamanho = strlen(buffer);
            gPalavra->linhas->linha = linha;
            gPalavra->linhas->proxima = (struct linhas*)malloc(sizeof(struct linhas));
            gPalavra->linhas->proxima->linha = (int)malloc(sizeof(int));
            strcpy(gPalavra->termo, data.item);
            //printf("Palavra %4.i, Tamanho:%2.i, Linha: %2.i, Termo:%s\n",palavras, strlen(buffer), linha, data.item );
            //Inicializa proximo
            gPalavra->proxima = (struct PalavraExplicada*)malloc(sizeof(struct PalavraExplicada));
            gPalavra->proxima->linhas = (struct linhas*)malloc(sizeof(struct linhas));
            gPalavra->proxima->linhas->linha = (int)malloc(sizeof(int));
            //gPalavra->proxima = NULL;

            gPalavra = gPalavra->proxima;
        }
        if(isalnum(content[i]) || content[i] == '\'')//Se for alfanumerico
        {
            buffer[letras]= tolower( content[i] );
            ++letras;
        }
    }
    gPalavra = NULL;
    //strcpy(gPalavra->termo, "\0");
    //printSLLList(Nodo);

    //Remove lixo
    /*
    for(i =0 ; i<palavras; i++, gPalavra = gPalavra->proxima){
        gPalavra = gPalavra->proxima;
        if (i<palavras-2){
            char tmp2[100]={};
            gPalavra->proxima->termo = (char*)'';//NULL;
            gPalavra->proxima->linhas = NULL;
            gPalavra->proxima->tamanho = NULL;
            break;
        }
    }
    */

    //gPalavra->ordem = -1;

    //printf("Palavra %4.i, Tamanho:%2.i, Linha: %2.i, Termo:%s\n",gPalavraRoot->ordem, gPalavraRoot->tamanho, gPalavraRoot->linha, gPalavraRoot->termo );
    gPalavra = gPalavraRoot;
    /*
    while (gPalavra != NULL && --letras != 5){
        printf("Palavra %4.i, Tamanho:%2.i, Linha: %2.i, Termo:%s\n",gPalavra->ordem,gPalavra->tamanho,
               gPalavra->linhas->linha,
               gPalavra->termo );
        if (gPalavra != NULL){
            gPalavra = gPalavra->proxima;
        }
    }
    */

    //printSLLList(Nodo);
    //Insere o Nodo novamente na memoria
    Memoria->textos->analise->palavras->item = Nodo;
    //Utiliza o Nodo para obter outros calculos

    /// Agrupa Termos
    TypeSLLData procurado;
    struct NodeSLL* last;// = NULL;
    last = NULL;
    struct NodeSLL* aux;// = list;

    printSLLList(Nodo);

    while(Nodo != NULL){
        procurado = Nodo->data;
        NodoAgrupado = insertSLLNode(NodoAgrupado, procurado);
        do {
            //aux = Nodo;
            //printf("%i %s,%s \n",++tmp, aux->data.item, procurado.item);

            //Nodo = removeSLLNode(Nodo, procurado);

            struct NodeSLL* last;
            last = NULL;
            struct NodeSLL* aux = Nodo;

            while (aux !=NULL && (strcmp(aux->data.item, procurado.item)))
            {
                last = aux;
                aux = aux->next;
                //printf("%i %s,%s \n",++tmp, aux->data.item, procurado.item);
            }

            if(aux == NULL){
                break;
            }
            if (last == NULL)
            {
                Nodo = aux->next;
            }
            else
            {
                last->next = aux->next;
            }



            /*
            while (aux !=NULL && (strcmp(aux->data.item, procurado.item)))
            {
                last = aux;
                aux = aux->next;

            }
            if (aux == NULL)
            {
                break;
            }

            if (last == NULL)
            {
                Nodo = aux->next;
            }
            else
            {
                printf("Removido 1 (%s)", procurado.item);
                last->next = aux->next;
            }
            */
            //printf(">%i %s,",++tmp, procurado.item);
            ++tmp;
        } while ( Nodo != NULL && searchSLLNode(Nodo, procurado)!= NULL);
        //printf("%i %s,\n",tmp, procurado.item);
        tmp = 0;
        if (Nodo != NULL){
            Nodo = Nodo->next;
        }
    }

    printSLLList(NodoAgrupado);
    //return;
    struct GrupoPalavras* GPalavrasAnalizadas = (struct GrupoPalavras*)malloc(sizeof(struct GrupoPalavras));
    GPalavrasAnalizadas->linhas = (struct linhas*)malloc(sizeof(struct linhas));
    GPalavrasAnalizadas->linhas->linha = (int)malloc(sizeof(int));
    Memoria->textos->analise->termosAnalizados = GPalavrasAnalizadas;//Palavras ja agrupadas
    gPalavra = gPalavraRoot;//Todas as palavras detalhadamente explicadas
    while(NodoAgrupado != NULL){
        tmp = palavras;
        GPalavrasAnalizadas->errado = 0;
        strcpy(GPalavrasAnalizadas->termo, NodoAgrupado->data.item);
        //Memoria->textos->analise->termosAnalizados->linhas;

        gPalavra = gPalavraRoot;
        while(gPalavra != NULL && tmp != 0){
            --tmp;
            //printf("\n a: %s b: %s , (%i)\n", gPalavra->termo, NodoAgrupado->data.item, tmp);
            if ( strcmp( gPalavra->termo, NodoAgrupado->data.item) == 0 ){
                GPalavrasAnalizadas->linhas->linha = gPalavra->linhas->linha;
                GPalavrasAnalizadas->proximo = (struct GrupoPalavras*)malloc(sizeof(struct GrupoPalavras));
                GPalavrasAnalizadas->proximo->linhas = (struct linhas*)malloc(sizeof(struct linhas));
                GPalavrasAnalizadas->linhas = GPalavrasAnalizadas->proximo->linhas;
                //GPalavrasAnalizadas->proximo->linhas->linha = (int)malloc(sizeof(int));

                //printf("Igual!");
                //return 1;
            }
            //printf("\n %s \n",GPalavrasAnalizadas->termo);
            gPalavra = gPalavra->proxima;
        }
        /*
        if (GPalavrasAnalizadas != NULL){
            GPalavrasAnalizadas->proximo = (struct GrupoPalavras*)malloc(sizeof(struct GrupoPalavras));
            GPalavrasAnalizadas->proximo->linhas = (struct linhas*)malloc(sizeof(struct linhas));
            GPalavrasAnalizadas->proximo->linhas->linha = (int)malloc(sizeof(int));
            GPalavrasAnalizadas->proximo->errado = (int)malloc(sizeof(int));
            GPalavrasAnalizadas = GPalavrasAnalizadas->proximo;
        }
        */
        if (NodoAgrupado != NULL){
            NodoAgrupado = NodoAgrupado->next;
        }
    }


    GPalavrasAnalizadas = Memoria->textos->analise->termosAnalizados;

    printf("\n");
    printf("|-------------------------------------------------------|\n");
    printf("  NUMERO (K) |  FREQUENCIA  |   ERRO      | LINHAS      \n");

    while(GPalavrasAnalizadas != NULL){

        printf("    x        %i          %s                %i       \n",
               GPalavrasAnalizadas->quantidade,
               GPalavrasAnalizadas->termo ,
               GPalavrasAnalizadas->linhas->linha);
        break;
        GPalavrasAnalizadas = GPalavrasAnalizadas->proximo;
    }



    printf("|-------------------------------------------------------|\n");

    /// Recheca linhas
    /*
    char* word;
    while (Memoria->textos->analise->palavras->item != NULL){

        word = strtok (content," ,.\t");

        while(word != NULL)
        {
            if (strcmp(Memoria->textos->analise->palavras->item->data.item, word)<0){
                Memoria->textos->analise->palavras->linha = linha;
            }
            printf("\n%s", word);
            word = strtok (NULL," ,.\t");
            if (word!= NULL){
                break;
            }
        }
    }
    */



    return 1;
}

//void _coPalavraMonta

/**
 * Interface com o usuario que viabiliza carregar um texto
 * Intermedia com a funcao cohTextoCarrega() do cohelper.h
 *
 * @param[in,out] Memoria Memoria Objeto global de memoria
 * @return void
 */
void coTextoCarrega( COMemType *Memoria )
{
    char path[255];
    char idioma[255];
    char descricao[255];
    //char reservado //Array de opcoes reservadas
    _coCarregaInformacoes( path, idioma, descricao );
    cohTextoCarrega( Memoria, path, idioma, descricao );
}

void coTextoOpcoes( COMemType *Memoria )
{
    if (Memoria->dicionarios == NULL)
    {
        printf("\nCorretorOrtografico> Aviso: nenhum dicionario carregado");
    }
    if (Memoria->textos == NULL)
    {
        printf("\nCorretorOrtografico> Alerta: nenhum texto carregado!");
        printf("\nCorretorOrtografico> Insira testo para continuar");
        printf("\n");
        return;
    }
    if ( Memoria->textos->completo != NULL)
    {
        TextoType *aux;

        printf("\nTextos Carregados\n");
        for ( aux = Memoria->textos; aux!=NULL; aux=aux->proximo)
        {
            printf("%s: %s\n", aux->idioma, aux->titulo);
            //printf("\n\n\%s \n\n\n", aux->completo);
        }
    }
    coTextoAnalisa(Memoria, Memoria->textos->completo );
}

#endif // COCORE_H_INCLUDED
