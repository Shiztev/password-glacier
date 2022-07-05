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
 * @brief Allows the user to specify how they would like their 
 * password formated.
 * 
 * @param argc number of command line arguments passed in
 * @param argv string array of command line arguments
 * @return 0 if successful, 1 otherwise
 */
int main(int argc, char * argv[]) {
  /// Temporary storage for input.
  char tmp = 'n';

  /// Password storage.
  char* pswrd;

  /// Boolean determining if previous settings should be reused.
  int rep_set = 0;

  /// Length of the password.
  long length = DEF_LEN;

  // ------------------------------------------------------------------------
  //    CLI INPUT
  // ------------------------------------------------------------------------
  if (argc == 2) {
    length = strtol(argv[1], NULL, 10);
    pswrd = password(length);
    printf("password: %s\n", pswrd);

    free(pswrd);
    pswrd = NULL;

    return 0;
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
    printf("Enter length: ");
    scanf("%ld", &length);
    pswrd = password(length);
    printf("\npassword: %s\n", pswrd);
    free(pswrd);
    pswrd = NULL;

    while (1) {
      printf("\nWould you like another password? (y/n) ");
      scanf("%c", &tmp);

      if (tmp == 'y') {
        rep_set = 1;
        break;

      } else if (tmp == 'n') {
        rep_set = 0;
        break;
      }
    }

  } while(rep_set);
  // ------------------------------------------------------------------------
  // ------------------------------------------------------------------------

  return 0;
}
