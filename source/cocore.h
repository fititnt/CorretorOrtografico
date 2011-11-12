/**
 * @file cocore.h
 * @details Corretor Ortografico - Core
 * @version 0.1alpha
 * @author Emerson Rocha Luiz
 * @copyright MIT. See license.txt
 */


#ifndef COCORE_H_INCLUDED
#define COCORE_H_INCLUDED


#define DICIONARIO_PATH C:\\Users\\fititnt\\github\\fititnt\\CorretorOrtografico\\source\\dicionarios\\en.dic

void coUserCL();
void coStart();
void coGodbye();
void coHelp();
void coCredits();

/**
 * Corretor Ortografico User Command Line
 *
 * @return void
 */
void coUserCL()
{
    coStart();
    coGodbye();
}

/**
 * Corretor Ortografico - Start
 *
 * @return void
 */
void coStart()
{

    char *content;
    int i, linhas;

    linhas = getFileToArray( "DICIONARIO_PATH", &content);

    for( i = 0; i < linhas;  ++i)
    {
        printf("%s \n", (content + i) );
    }

    printf("%i \n", linhas);

    printf("Inicio do Corretor Ortografico\n");

}

/**
 * Corretor Ortografico - End
 *
 * @return void
 */
void coGodbye()
{
    printf("Fim de sessao do Corretor Ortografico\n");
}

/**
 * Corretor Ortografico - Help
 *
 * @return void
 */
void coHelp()
{
    //
}

/**
 * Corretor Ortografico - Credits
 *
 * @return void
 */
void coCredits()
{
    //
}

#endif // COCORE_H_INCLUDED
