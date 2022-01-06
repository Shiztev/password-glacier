/**
 * @file glacier.c
 * @brief Generates passwords built around user specifications.
 * 
 * Compile: gcc -Wall -Wextra -pedantic -ggdb -std=c99 -c glacier.c
 * @author Stevie Alvarez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "password.h"


/* Initial implementation with hardcoded options. Look for ways to expand
    to a more calculating way of generating characters (could use ascii, 
    but special characters get weird). */

/* rand() is not secure. An improvement would be to utilize a more secure
    random number generator (e.g. randombytes API) */
    // libsodium: https://github.com/jedisct1/libsodium
    // urandom


/**
 * Default password length.
 */
#define DEF_LEN 20


/**
 * Default number of special characters.
 */
#define DEF_SP 4


/**
 * Default number of integers.
 */
#define DEF_INTS 4


/**
 * Number of 'parts' of the password that can be customized. 
 */
#define PARTS 3


/**
 * List of prompts for user input, with respect to a 'part' of the password.
 */
char ** PROMPTS = {"Passowrd Length: ", "Number of Integers: ", "Number of Special Characters: "};


/**
 * @brief Allows the user to specify how they would like their 
 * password formated.
 * 
 * @param argc number of command line arguments passed in
 * @param argv string array of command line arguments
 * @return 0 if successful, 1 otherwise
 */
int main(int argc, char * argv[]) {
    /**
     * Lengths of password elements.
     *      Order: PASSWORD LENGTH, NUMBER OF INTS, NUMBER OF SPECIAL CHARS
     */
    int lengths[] = {DEF_LEN, DEF_INTS, DEF_SP};

    // ----- CLI INPUT --------------------------------------------------------
    for (int i = 1; i < argc; ++i) {
        lengths[i - 1] = strtol(argv[i], NULL, 10);
    }

    // to generate a password, print the password, then exit.
    printf("%s\n", password(lengths[0], lengths[1], lengths[2]));
    // ------------------------------------------------------------------------

    // otherwise, loop, gathering user input, and produce 
    // passwords w/r/t user input. Exit on EOF or dedicated 
    // quit statement.
    // ----- STD INPUT---------------------------------------------------------
    while(1) {  // FINISH CONDITIONAL
        for (int i = 0; i < PARTS; ++i) {
            printf("%s\n", PROMPTS[i]);

        }
    }


    return 0;
}
