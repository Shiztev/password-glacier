/**
 * @file password.h
 * @brief Definitions for password generating functions.
 * 
 * @author Stevie Alvarez
 */

/**
 * Max number of characters constituting a password.
 */
#ifndef MAX_LEN
#define MAX_LEN 127
#endif


#ifndef PASSWORD_H
#define PASSWORD_H

/**
 * Generates a randomized password of length l consisting of num 
 * integers, sp special characters, and (l - num - sp) alphabetic 
 * characters.
 * 
 * @param l desired length of password
 * @return a randomized password, constituted of numbers, letters, and special chars
 */
char * password(int l);

#endif
