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


/**
 * Save data to a file
 *
 * @return 1 for success, 0 for fail
 */
int fileSave(){
    //
    return 1;
}


 /**
 * Open a file
 *
 * @param[in] path Path to file to save
 * @param[out] content Content of the file opened
 * @return 1 for success, 0 for fail
 */
int fileOpen( char path[], char *content[] ){
    //
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
