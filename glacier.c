/**
 * @file glacier.c
 * @brief
 * 
 * Compile: gcc -Wall -Wextra -pedantic -ggdb -std=c99 -c glacier.c
 * @author Stevie Alvarez
 */

#include <stdio.h>
#include <stdlib.h>

#include "glacier.h"


/**
 * Generates a password with respect to parameters.
 */
char * password(int l, int num, int sp) {
    // declare (and initialize) variables
    char pswrd[l];

    // check params are valid (l >= (num + sp))

    // do some stuff to pswrd

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
