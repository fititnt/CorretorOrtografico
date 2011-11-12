#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED



/**
 * Retorna se um arquivo pode ser aberto para leitura
 * @example
 *    int resultado;
 *    resultado = debugFileOpen("file.txt");
 *    if ( resultado == 1 ){
 *        printf("O arquivo pode ser aberto");
 *    } else {
 *        printf("O arquivo nao pode ser aberto");
 *    }
 *
 * @param[in] char[] Local do arquivo
 * @return int 0 para nao, 1 para sim
 */
int debugFileOpen( char path[] )
{
    FILE *file = fopen ( path, "r" );
    if ( file != NULL)
    {
        return 1; //Arquivo pode ser aberto
    } else
    {
        return 0; //Arquvo nao pode ser aberto
    }
}

int debugFilePrint( char path[] ){

    FILE *file = fopen ( path, "r" );
    if ( file != NULL)
    {
        return 1; //Arquivo pode ser aberto
    } else
    {
        return 0; //Arquvo nao pode ser aberto
    }

    return 1;//Sucesso
}


#endif // DEBUG_H_INCLUDED
