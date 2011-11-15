/**
 * @file filesys.h
 * @details Corretor Ortografico - Filesystem
 * @version 0.1alpha
 * @author Emerson Rocha Luiz
 * @copyright MIT. See license.txt
 */

#ifndef FILESYS_H_INCLUDED
#define FILESYS_H_INCLUDED


#include <stdio.h>
#include <string.h>


/**
 * Save data to a file
 *
 * @return 1 for success, 0 for fail
 */
int fsFileSave()
{
    //
    return 1;
}

/**
 * Get contents of one file to one variable. Each file line will be one line of
 * the resultant array
 * Array limit have one hard limit! Win7 x64 supports at least content[65000]
 *
 * @param[in] char* path
 * @param[in,out] char** content
 * @return int
 */
int fsFileToArray( char path[], char *content[] )
{
    int i = 0;
    //int size = 0;
    char line [ 256 ];

    FILE *fp = fopen ( path, "r" );
    if ( fp == NULL )
    {
        //printf("Cannot open the file");
        return -2; // -1, cannot open file
    }
    //printf("File could be opened");
    ///Get file size
    //fseek(fp, 0, SEEK_END);//Go to end of file
    //size = ftell(fp); //Get position where file poiinter is (the file size)
    //fseek(fp, 0, SEEK_SET);//Reset file pointer to start of file

    ///Check if file could be read
    //if (size != fread(*content, sizeof(char), size, fp))
    //{
    //	free(*content);//Free memory usage of var
    //	return -1; // Return that cannot read the file
    //}

    while ( fgets ( line, sizeof(line), fp ) != NULL )
    {
        //@todo Solve bug when trying to copy contents
        //strcpy(content[i], line);
        //printf("%s \n", line);
        ++i;
    }
    fclose ( fp );


    /*
        FILE *fp = fopen ( path, "r" );
        if ( fp != NULL )
        {
            while ( fgets ( line, sizeof line, fp ) != NULL )
            {
                strcpy(content[i], line);
                //printf("%s \n", content[i]);
                ++i;
            }
            fclose ( fp );
        } else
        {
            return -1; // -1, cannot open file
        }
        */
    return i;
}

/**
* Open a file and set its content for one 'string' (array of chars) to one
* pointer, and return value of
*
* @param[in] path Path to file to save
* @param[out] content Content of the file opened
* @return leigth of content, or -2 if cannot open file or -1 if cannot read it
*/
int fsFileToString( char path[], char **content )
{
    int size = 0;
    FILE *fp = fopen(path, "rb");
    if (fp == NULL)
    {
        *content = NULL;
        return -2; // Return that cannot open the file
    }
    fseek(fp, 0, SEEK_END);//Go to end of file
    size = ftell(fp); //Get position where file poiinter is (the file size)
    fseek(fp, 0, SEEK_SET);//Reset file pointer to start of file
    *content = (char *)malloc(size+1);
    if (size != fread(*content, sizeof(char), size, fp))
    {
        free(*content);//Free memory usage of var
        return -1; // Return that cannot read the file
    }
    fclose(fp);
    (*content)[size] = 0;
    return size;
    return 0;
}

/**
* Remove one file from disk. One alias for ansi-C command remove()
*
* @param[in] path Path to file to save
* @return 1 for success, 0 for fail
*/
int fsRemove( char path[] )
{
    if ( remove(path) == 0 ){
        return 0;
    } else {
        return 1;
    }
}


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
int fsFileOpen( char path[] )
{
    FILE *file = fopen ( path, "r" );
    if ( file != NULL)
    {
        return 1; //Arquivo pode ser aberto
    }
    else
    {
        return 0; //Arquvo nao pode ser aberto
    }
}
/**
 * Return String from command line input
 * Replacement of starndart gets() and its problems with buffer overflow
 * @todo make some check to verify alocate leigth of str and set to fgets
 * @example
 * @code
 *    leigth = fsGetStr(str);
 *    printf("%s (%d)", str, leigth);
 *    if ( strcmp( str,"teste") == 0 ) {
 *        printf("%s", "\n Equals\n");
 *    }
 *   else {
 *        printf("%s", "\n Diferent\n");
 *    }
 * @endcode
 * @param[in,out] str Pointer to string to return the input
 * @return leigth leigth of string
 */
int fsGetStr( char *str )
{
    fgets (str, 255, stdin);
    int FinalLeigth = strlen(str) -1;
    str[FinalLeigth] = '\0';//Just set to \0 will mark as array end
    return FinalLeigth;
    //gets(str);
    //printf(str);
    /*
    //
    int i;
    char input[255];
    fgets (input, 255, stdin);
    int leigth = strlen(input);
    ///@todo Check best way (performance, security) way to remove last \0 char
    //*(str + leigth) = NULL;
    input[leigth-1] = '\0';
    strcpy(str , input);
    //str = str[leigth-1];//
    //memmove (str+leigth, str+(leigth-1), (leigth-1));
    //for( i = 0; i < (leigth - 1);  )
    //memmove( str+leigth, input, leigth -1 );
    leigth = strlen(str);
    return leigth;
    */
}



#endif // FILESAVE_H_INCLUDED
