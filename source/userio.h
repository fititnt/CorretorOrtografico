/**
 * @file userio.h
 * @details Corretor Ortografico - User IO
 * @version 0.1alpha
 * @author Emerson Rocha Luiz
 * @copyright MIT. See license.txt
 */

#ifndef USERIO_H_INCLUDED
#define USERIO_H_INCLUDED

 /**
 * Get pressed key
 *
 * @return Value of pressed key, as a char
 */
char getKey()
{
    char key;
    key = getchar();
    return key;
}

#endif // USERIO_H_INCLUDED
