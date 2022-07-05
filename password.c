/**
 * @file password.c
 * @brief Private functions to generate a password. 
 * 
 * Compile: gcc -Wall -Wextra -pedantic -ggdb -std=c99 -c password.c
 * @author Stevie Alvarez
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "password.h"


/**
 * Minimum length of the password.
 */
#define MIN_LEN 3


/**
 * Maximum number of possible characters that can be used in a password.
 */
#define MAX_CHARS 68


/**
 * Number of possible character 'types' e.g. upper-case, int, etc.
 */
#define TYPE_LEN 4


/**
 * Length of CHARS.
 */
static const int CHARS_LEN = 71;


/**
 * Array of possible capital alphabetical characters.
 */
static const char CHARS[CHARS_LEN] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789!@#$%^&*";


/**
 * Starting indices for each type in CHARS. Includes length as final start point for computations.
 */
static const int * STARTS = {0, 26, 52, 62, 71};


// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// find API for sets for type data structure?
/**
 * Data structure containing the current possible data types that can be
 * appended to the password. 
 */
int type [] = {0, 1, 2};

/**
 * @brief Generate a password of length l.
 * 
 * @param l desired length of password
 * @return a randomized password, constituted of numbers, letters, and special chars
 */
static char * make_password(int l) {
  char * pswrd = malloc(l * sizeof(char));
  srand(time(NULL));  // set random seed, is more secure way to do this? yes: openssl rand/RAND_bytes
  // https://stackoverflow.com/questions/822323/how-to-generate-a-random-int-in-c/39475626#39475626

  for (int i = 0; i < l; ++i) {
    pswrd[i] = 33 + (rand() % 90);
  }

  return pswrd;
}


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
    /// number of alphabetic characters to be in password
    int c = (l - num) - sp;
    
    /// password's character buffer
    char pswrd[l];

    /// Character type lengths, respective of type index array
    int type_lens[] = {c, num, sp};

    /// Temporary storage for current index from type index array
    int curr_type;

    srand(time(NULL));  // set random seed, is more secure way to do this? yes: openssl rand/RAND_bytes
    // https://stackoverflow.com/questions/822323/how-to-generate-a-random-int-in-c/39475626#39475626

    // check if l within max/min length
    if (!((l <= MAX_LEN) && (l >= MIN_LEN))) {
        fprintf(stderr, "Error: length of %d out of bounds. Length must be between %d and %d.", l, MIN_LEN, MAX_LEN);
        return NULL;
    
    // check params are valid (l >= (num + sp))
    } else if (!(l >= (num + sp))) {
        fprintf(stderr, "Error: number of special (%d) and numeric (%d) characters are greater than provided length (%d).",sp, num, l);
        return NULL;
    }

    // randomly select chars from possible chars and insert them to password
    for (int i = 0; i < l; ++i) {
        // determine which type to use
        curr_type = type[rand() % TYPE_LEN];

        // decrement type lenth and remove type from type pool if neccessary 
        if (--type_lens[curr_type] <= 0) {
            // remove type from type pool (var: type)
        }

        // select a character of the respective type and append it. 
        // (random value in the index range of curr_type) + start index of curr_type
        pswrd[i] = CHARS[(rand() % (STARTS[curr_type + 1] - STARTS[curr_type])) + STARTS[curr_type]];  // (rand() % type range) + type offset
    }

    // maybe add feature so that params are passed by reference, reassigned
    // values (e.g. NULL), and deallocated for security?

    return pswrd;
}


/**
 * Calls make_password to generate a password. 
 */
char * password(int l, int num, int sp) {
    return make_password(l, num, sp);
}