/**
 * @file glacier.c
 * @brief Generates passwords built around user specifications.
 * 
 * Compile: gcc -Wall -Wextra -pedantic -ggdb -std=c99 -c glacier.c
 *          gcc -Wall -Wextra -pedantic -ggdb -std=c99 -c password.c
 *          gcc -o glacier glacier.o password.o
 * @author Stevie Alvarez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "password.h"

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

    printf("\nWould you like another password? (y/n) ");

    do {
      while((tmp = getchar()) != '\n' && tmp != EOF) { }
      tmp = getchar();

      if (tmp == 'y') {
        rep_set = 1;
        break;
      } else if (tmp == 'n') {
        rep_set = 0;
        break;
      }

      printf("Please enter 'y' or 'n': ");

    } while (1);

  } while(rep_set);
  // ------------------------------------------------------------------------
  // ------------------------------------------------------------------------

  return 0;
}
