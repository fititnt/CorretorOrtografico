/**
 * @file cocore.h
 * @details Corretor Ortografico - Core
 * @version 0.1alpha
 * @author Emerson Rocha Luiz
 * @copyright MIT. See license.txt
 */


#ifndef COCORE_H_INCLUDED
#define COCORE_H_INCLUDED

#include <ctype.h> //isspace(c)
#include "lib/data/singlylinkedlist.h"
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
        printf("\n|---------------------GERAL----------------------|");
        printf("\n| 1 - Gerenciar dicionarios                      |");
        printf("\n| 2 - Gerenciar textos                           |");
        printf("\n| 3 - Alterar definicoes desde programa          |");
        printf("\n| 4 - Debug                                      |");
        printf("\n| 5 - Creditos                                   |");
        printf("\n| 0 - Encerra o programa                         |");
        printf("\n|------------------------------------------------|");
        printf("\n\n  GERAL> ");
        break;
    case 1:
        printf("\n|------------------DICIONARIO--------------------|");
        printf("\n| 1 - Adicionar dicionario                       |");
        printf("\n| 2 - Editar dicionario existente                |");
        printf("\n| 3 - Remover dicionario                         |");
        printf("\n| 0 - Volta ao menu anterior                     |");
        printf("\n|------------------------------------------------|");
        printf("\n\n  DICIONARIO> ");
        break;
    case 2:
        printf("\n|---------------------TEXTO----------------------|");
        printf("\n| 1 - Adicionar texto                            |");
        printf("\n| 2 - (Re)Analizar texto                         |");
        printf("\n| 3 - Editar texto                               |");
        printf("\n| 4 - Remover texto                              |");
        printf("\n| 0 - Volta ao menu anterior                     |");
        printf("\n|------------------------------------------------|");
        printf("\n\n  TEXTO> ");
        break;
    case 3:
        printf("\n|------------------DEFINICOES--------------------|");
        printf("\n| 0 - Volta ao menu anterior                     |");
        printf("\n|------------------------------------------------|");
        printf("\n\n  DEFINICOES> \n");
        break;
    case 4:
        printf("\n|---------------------DEBUG----------------------|");
        printf("\n| 0 - Volta ao menu anterior                     |");
        printf("\n|------------------------------------------------|");
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
 *
 *
 */
int coTextoAnalisa( COMemType *Memoria, char *content)
{
    printf("\ncoTextoAnalisa\n");

    TypeSLLNode *Node = initializeSLL();
    TypeSLLData data;
    int i, letras = 0, palavras = 0, quebraDePalavra = 0;
    char buffer[100];
    int tamanho = strlen(content);

    for(i=0; i<=tamanho; ++i)
    {
        if( (isspace(content[i]) && !content[i] != '\'') || i==tamanho)// '  ',\f ,\n ,\r, \t, \v
        {
            if(letras == 0)
            {
                continue;//Sem palavras vazias, por favor
            }
            buffer[letras] = '\0';//Fecha string
            strcpy( data.item , buffer);
            Node = insertSLLNode(Node,data);
            ++palavras;
            letras = 0;
            quebraDePalavra = 1;
            printf("Palavra %i (%i): %s, >%s (%i)< \n",palavras, strlen(buffer), buffer, data.item, strlen(data.item) );
        }
        if(isalnum(content[i]) || content[i] == '\'')//Se for alfanumerico
        {
            buffer[letras]= tolower( content[i] );
            ++letras;
        }
    }
    printSLLList(Node);

    printf("quantidade %i\n\n", palavras);


    //Reorganiza lista
    int j = 0, k = 0, l = 0;
    //struct NodeSLL* noAuxiliar = initializeSLL();//Criado no auxiliar
    struct DataSLL procurado, proximo;
    char aliasprocurado[100];
    strcpy( procurado.item, Node->data.item);//Primeiro procurado
    strcpy( aliasprocurado, Node->data.item);
    strcpy( proximo.item, Node->data.item);
    //Procurar o proximo

    while (j < palavras || Node != NULL){
        while( searchSLLNode( Node, procurado )!= NULL ){
            Node = removeSLLNode( Node, procurado );//Remove encontrado
            ++k;
            ++l;
            ++j;
            //printf("i %i, ", ++j);
        }

        printf("\n %s :(%i) vezes\n", procurado.item, l);
        l=0;
        if (Node != NULL){
            strcpy( procurado.item, Node->data.item);
        }
        printf(" k %i, ", ++k);
        getch();
    }



    // i = numero de itens

    /*
    TypeSLLData *removerNo;
    strcpy( removerNo->item , "your");
    Node = removeSLLNode(Node, removerNo);
    printSLLList(Node);
    */
    //struct NodeSLL* list = initializeSLL();


    /*
    struct NodeSLL* noAuxiliar = initializeSLL();//Criado no auxiliar
    struct DataSLL procurado, proximo;
    char aliasprocurado[100];
    strcpy( procurado.item, Node->data.item);//Primeiro procurado
    strcpy( aliasprocurado, Node->data.item);
    strcpy( proximo.item, Node->data.item);
    //Procurar o proximo

    //struct NodeSLL* last = NULL;
    struct NodeSLL* aux = Node;
    int encontrados = 0, ultimavolta = 0, removidos = 0;

    while(Node != NULL || removidos < i)
    {
        strcpy( aliasprocurado, procurado.item);
        printf("\nPonto 1 inicio , Node != NULL");
        noAuxiliar = Node;
        while(noAuxiliar != NULL)
        {
            printf("\nPonto 2, noAuxiliar != NULL ");
            noAuxiliar = searchSLLNode( noAuxiliar, procurado );//procura
            if (noAuxiliar != NULL)  //Aha! voce ta ai!
            {
                printf("\nPonto 3, searchSLLNode( noAuxiliar, procurado ) != NULL");
                printf("Encontrado o %s\n", noAuxiliar->data.item);
                noAuxiliar = removeSLLNode( noAuxiliar, procurado );//Remove encontrado
                //Node = noAuxiliar;
                ++removidos;
                ++encontrados;
            }
        }
        printf("\nPonto 4 meio");
        while(Node != NULL /*&& aux->next != NULL && strcmp(aliasprocurado, proximo.item) == 0)
        {
            printf("\nPonto 5, troca troca strcmp(aliasprocurado, proximo.item) == 0)");
            aux = aux->next;
            if( strcmp(procurado.item, aux->data.item ) != 0 )
            {
                strcpy( proximo.item,  aux->data.item);
            }
        }
        printf("\nPonto 6 quase final");
        //printf("Encontrado %i '%s' (proximo %s) \n", encontrados, procurado.item , proximo.item);
        if( Node != NULL && aux->next != NULL){
            printf("\nPonto 7, fim, Node != NULL && aux->next != NULL");
            strcpy( procurado.item, proximo.item);
        }
        encontrados = 0;
        printf("Encontrado %i, total %i \n", encontrados, i);

        Node = searchSLLNode( noAuxiliar, procurado );//procura
        getch();
    }
    printf("FIM. Encontrado %i, total %i \n", encontrados, i);
    */
    /*
    Node = removeSLLNode( Node, data2 );
    Node = removeSLLNode( Node, data2 );
    Node = removeSLLNode( Node, data2 );
    Node = removeSLLNode( Node, data2 );
    Node = removeSLLNode( Node, data2 );
    Node = removeSLLNode( Node, data2 );
    Node = removeSLLNode( Node, data2 );
    Node = removeSLLNode( Node, data2 );
    Node = removeSLLNode( Node, data2 );
    Node = removeSLLNode( Node, data2 );
    Node = removeSLLNode( Node, data2 );
    Node = removeSLLNode( Node, data2 );
    Node = removeSLLNode( Node, data2 );
    Node = removeSLLNode( Node, data2 );
    Node = removeSLLNode( Node, data2 );
    printSLLList(Node);
    */
    /*
    TypeSLLNode *aux = Node;
    TypeSLLNode *sequinte = NULL;
    char * procurado;
    int encontratos = 1;


    while(Node != NULL)
    {
        strcpy(procurado, Node->data.item);
        while( Node != NULL )
        {
            if( strcmp(Node->data.item, procurado) == 0 ){
                Node = removeSLLNode(Node);
                ++encontratos;
            } else if ( ){

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
