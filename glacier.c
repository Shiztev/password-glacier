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
static const char ** PROMPTS = {"Passowrd Length: ", "Number of Integers: ", "Number of Special Characters: "};


/**
 * Defualt lengths of password elements.
 *      Order: PASSWORD LENGTH, NUMBER OF INTS, NUMBER OF SPECIAL CHARS
 */
static const int DEFAULTS[] = {DEF_LEN, DEF_INTS, DEF_SP};


/**
 * @brief Gets lengths for password elements from standard input.
 */
static void get_lengths(int * lengths) {
    char * tmp;
    for (int i = 0; i < PARTS; ++i) {
        printf("%s\n", PROMPTS[i]);
        scanf("%s", tmp);

        if (!strcmp(tmp, "\0")) {  // if input isn't empty (EOF/New line? just hits enter)
            lengths[i] = (int)strtol(tmp, NULL, 10);

        } else {
            lengths[i] = DEFAULTS[i];
        }
    }
}


/**
 * @brief Allows the user to specify how they would like their 
 * password formated.
 * 
 * @param argc number of command line arguments passed in
 * @param argv string array of command line arguments
 * @return 0 if successful, 1 otherwise
 */
int main(int argc, char * argv[]) {
    /// Length of lengths array
    int l_len = 3;
    /**
     * Lengths of password elements.
     *      Order: PASSWORD LENGTH, NUMBER OF INTS, NUMBER OF SPECIAL CHARS
     */
    int lengths[] = (int *)malloc(l_len * sizeof(int));
    lengths[0] = DEF_LEN;
    lengths[1] = DEF_INTS;
    lengths[2] = DEF_SP;

    /// Temporary storage for input.
    char* tmp;

    /// Boolean determining if previous settings should be reused.
    int rep_set = 0;

    // ------------------------------------------------------------------------
    //    CLI INPUT
    // ------------------------------------------------------------------------
    if (argc > 1) {

        for (int i = 1; i < argc; ++i) {
            lengths[i - 1] = strtol(argv[i], NULL, 10);
        }

        // to generate a password, print the password, then exit.
        printf("%s\n", password(lengths[0], lengths[1], lengths[2]));
    }
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------
    

    // ------------------------------------------------------------------------
    //    STD INPUT
    // ------------------------------------------------------------------------
    // otherwise, loop, gathering user input, and produce 
    // passwords w/r/t user input. Exit on EOF or dedicated quit statement.
    printf("Enter in character boundaries for each password you choose to generate..."); // FIXME: prompt/instructions on input requirements
    printf("Cumulative length of password cannot exceed %d.\n", MAX_LEN);  // FIXME: should be able to access MAX_LEN from password.c

    do {
        if (!rep_set) {
            get_lengths(lengths);
        }

        // determine if the user would like another passowrd
        printf("\n%s\n\nWould you like another password?", password(lengths[0], lengths[1], lengths[2]));
        scanf("%s", tmp);

        if (!strcmp(tmp, "yes")) {  // check for other forms of 'yes'

            printf("\nDo you want to use the same settings as last time?\n");
            if (!strcmp(tmp, "yes")) {
                
                    if (!strcmp(tmp, "yes")) {
                        rep_set = 1;

                    } else if (!strcmp(tmp, "no")) {
                        // reset default values
                        rep_set = 0;
                        lengths[0] = DEF_LEN;
                        lengths[1] = DEF_INTS;
                        lengths[2] = DEF_SP;
                    }
            }

        } else if (!strcmp(tmp, "no")) {  // check for other forms of no/quit
            break;
        }

    } while(1);

    free(lengths);
    // ------------------------------------------------------------------------
    // ------------------------------------------------------------------------

    return 0;
}
