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
int fileSave(){
    //
    return 1;
}


int getFileToArray( char path[], char **content )
{
    int i = 0;
    char line [ 256 ];

    FILE *file = fopen ( path, "r" );
    if ( file != NULL )
    {
        while ( fgets ( line, sizeof line, file ) != NULL )
        {
            strcpy(content[i], line);
            //printf("%s \n", content[i]);
            ++i;
        }
        fclose ( file );
    } else
    {
        return -1; // -1, cannot open file
    }
    return i;
}



 /**
 * Open a file and set its content for one 'string' (array of chars) to one
 * pointer, and return value of
 *
 * @param[in] path Path to file to save
 * @param[out] content Content of the file opened
 * @return number of lines read, or -2 in case of can'p open file, and -1 if
 *         can't read contents
 */
int getFileToString( char path[], char **content )
{
    int size = 0;
	FILE *fp = fopen( path, "r");
	if ( fp == NULL )
	{
		*content = NULL;
		return -2; // -2, cannot open file
	}
	fseek( fp, 0, SEEK_END );
	size = ftell( fp );
	fseek( fp, 0, SEEK_SET );
	*content = (char *)malloc(size+1);
	if (size != fread( *content, sizeof(char), size, fp ))
	{
		free(*content);
		return -2; // -1 means file reading fail
	}
    return 1;
}

 /**
 * Remove one file from disk
 *
 * @param[in] path Path to file to save
 * @return 1 for success, 0 for fail
 */
int fileRemove( char path[] ){
    //
    return 1;
}


#endif // FILESAVE_H_INCLUDED
