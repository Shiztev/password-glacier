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
 * Calls make_password to generate a password. 
 */
char * password(int l) {
    return make_password(l);
}