/**
 * @file gui.h
 * @details Corretor Ortografico - Graphical User Interface Helper
 *          Few common rotines on showing data to user
 * @version 0.3beta
 * @author Emerson Rocha Luiz
 * @copyright MIT. See license.txt
 */


#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED


/**
 * Print one matrix
 *
 * @todo Maybe implement strlen() for check if line is not complet for print
 * @param[in] int heigth Heigth of the matrix
 * @param[in] int width Width of the matrix
 * @return void
 */
void guiPrintMatrix( char ** matrix, int heigth , int width)
{
    int i, j;
    for( i=0 ; i<heigth ; ++i )
    {
        for ( j=0 ; j<width ; ++j )
        {
            printf("%c", matrix[j][i]);
        }
        printf("\n");
    }
}


void guiPringString( char * str)
{
    printf("%s", str);
}

 /**
 * Get pressed key
 *
 * @return Value of pressed key, as a char
 */
char uioGetKey()
{
    char key;
    key = getchar();
    return key;
}



#endif // GUI_H_INCLUDED
