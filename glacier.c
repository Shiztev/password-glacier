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
 * Length of SPECIALS.
 */
#define SP_LEN 8


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
    int * indexs = (int *)malloc(l * sizeof(char));
    char pswrd[l];
    char ints[num];
    char special[sp]; 

    for (int i = 0; i < l; i++) {
        indexs[i] = i;
    }

    // check if l within max/min length
    if (!((l <= MAX_LEN) && (l >= MIN_LEN))) {
        fprintf(stderr, "Error: length of %d out of bounds. Length must be between %d and %d.", l, MIN_LEN, MAX_LEN);
        return NULL;
    
    // check params are valid (l >= (num + sp))
    } else if (!(l >= (num + sp))) {
        fprintf(stderr, "Error: number of special (%d) and numeric (%d) characters are greater than provided length (%d).",sp, num, l);
        return NULL;
    }

    // choose num numeric characters
    for (int i = 0; i < num; i++) {
        ints[i] = rand() % 10;
    }

    // choose sp special characters
    for (int i = 0; i < num; i++){
        special[i] = SPECIALS[rand() % SP_LEN];
    }

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
