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

/* rand() is not secure. An improvement woould be to utilize a more secure
    random number generator (e.g. randombytes API) */
    // libsodium: https://github.com/jedisct1/libsodium


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
 * @brief Generates a password with respect to parameters.
 * 
 * @param l desired length of password
 * @param num number of integers to be in password
 * @param sp number of special characters to be in password
 * @return a randomized password, within the provided parameters
 */
static char * make_password(int l, int num, int sp) {
    // declare (and initialize) variables
    int * indexs = (int *)malloc(l * sizeof(char));
    int c = (l - num) - sp;
    char pswrd[l];
    char ints[num];
    char special[sp]; 
    char alpha[c];

    srand(time(NULL));  // set random seed, is more secure way to do this? yes: openssl rand/RAND_bytes
    // https://stackoverflow.com/questions/822323/how-to-generate-a-random-int-in-c/39475626#39475626

    for (int i = 0; i < l; i++) {  // find api for a set implementation
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
    for (int i = 0; i < sp; i++){
        special[i] = SPECIALS[rand() % SP_LEN];
    }

    // choose l - num - sp alphabetic characters
    for (int i = 0; i < c; i++) {
        // randomly determine if it should be upper-case/lower-case
        if ((rand() % 2) == 0) {  // upper-case
            alpha[i] = (char)(65 + (rand() % 26));  // ascii translation
        
        } else {  // lower-case
            alpha[i] = (char)(97 + (rand() % 26));  // ascii translation
        }
    }

    // randomly insert characters into string such that
    // they are not inserted on a used index

    // maybe add feature so that params are passed by reference, reassigned
    // values (e.g. NULL), and deallocated for security?

    return pswrd;
}


char * password(int l, int num, int sp) {
    return make_password(l, num, sp);
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
    // if user provides args from command line, utilize those 
    // to generate a password, print the password, then exit.

    // otherwise, loop, gathering user input, and produce 
    // passwords w/r/t user input. Exit on EOF or dedicated 
    // quit statement.


    return 0;
}
