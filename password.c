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
#include <time.h>
#include <sodium.h>

#include "password.h"

#define START_OFFSET 33
#define ASCII_RANGE 90

/**
 * @brief Generate a password of length l.
 * 
 * @param l desired length of password
 * @return a randomized password, constituted of numbers, letters, and special chars
 */
static char * make_password(int l) {
  if (l > MAX_LEN) {
    l = MAX_LEN;
  }
  
  char * pswrd = malloc(l * sizeof(char));

  if (sodium_init() < 0) {
    return NULL;
  }

  for (int i = 0; i < l; i++) {
    pswrd[i] = START_OFFSET + randombytes_uniform(90);
  }

  return pswrd;
}

/**
 * Calls make_password to generate a password. 
 */
char * password(int l) {

  return make_password(l);
}