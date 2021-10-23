/**
 * @file glacier.c
 * @brief Generates passwords built around user specifications.
 * 
 * Compile: gcc -Wall -Wextra -pedantic -ggdb -std=c99 -c glacier.c
 * @author Stevie Alvarez
 */

#include <stdio.h>
#include <stdlib.h>

#include "glacier.h"


/* Initial implementation with hardcoded options. Look for ways to expand
    to a more calculating way of generating characters (could use ascii, 
    but special characters get weird). */


/**
 * Max number of characters constituting password.
 */
#define MAX_LEN 128


/**
 * Minimum number of characters constituting password.
 */
#define MIN_LEN 4


/**
 * Array of possible numeric characters.
 */
const char * NUMBERS = "1234567890";


/**
 * Array of possible special characters.
 */
const char * SPECIALS = "!@#$%^&*";


/**
 * Array of possible upper-case alphabetic characters.
 */
const char * UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


/**
 * Array of possible lower-case alphabetic characters.
 */
const char * LOWER = "abcdefghijklmnopqrstuvwxyz";


/**
 * Generates a password with respect to parameters.
 */
char * password(int l, int num, int sp) {
    // declare (and initialize) variables
    char pswrd[l];

    // check if l within max/min length

    // check params are valid (l >= (num + sp))

    // choose num numeric characters

    // choose sp special characters

    // choose l - num - sp alphabetic characters

    // randomly insert characters into string such that
    // they are not inserted on a used index

    return pswrd;
}



/**
 * Allows the user to specify how they would like their 
 * password formated.
 * 
 * @param argc number of command line arguments passed in
 * @param argv string array of command line arguments
 * @return 0 if successful, 1 otherwise
 */
int main(int argc, char * argv[]) {
    // if user provides args from command line, utilize those 
    // to generate a password, print the password, then exit.

    // otherwise, loop, gathering user input, and produce 
    // passwords w/r/t user input. Exit on EOF or dedicated 
    // quit statement.


    return 0;
}
