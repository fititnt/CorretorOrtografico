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
int fileSave()
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
int getFileToArray( char path[], char *content[] )
{
    int i = 0, size = 0;
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
int getFileToString( char path[], char **content )
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
int fileRemove( char path[] )
{
    if ( remove(path) == 0 ){
        return 0;
    } else {
        return 1;
    }
}


#endif // FILESAVE_H_INCLUDED
