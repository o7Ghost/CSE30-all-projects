/*
 * Filename: main.c
 * Author: Qiao jia Lu
 * Userid: cs30xcq
 * Description: check and print error stderr
 * if no error print the lights
 * Date: 2/10/18
 * Source of Help: Tutors and Discussion slides
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "pa2.h"
#include "pa2Strings.h"


/* 
 * Function Name: main() 
 * Function Prototype: int main ( int argc, char* argv[] );
 * Description: Driver for PA2, check any errors before display any lights
 * Parameters: argc - the number of argument that is passed in
 *             argv - array of argument
 * Side Effects: 
 * Error Conditions: number too large, not an integer for second argument
 * file doesn't exist or file permission denied.
 * Return Value: returns success if lights prints and fail when
 * incounter any error conditions
 */
int main ( int argc, char* argv[]) {

  //inilization
  errno = 0;
  unsigned int lightBank[NUM_OF_BANKS];
  lightBank[0] = 0x00000000;
  lightBank[1] = 0x00000000;

  const char * const commands[] = { COMMANDS, NULL };

  FILE * inFile = stdin;
  char buf[BUFSIZ] = { 0 };
  short prompt = TRUE; 
  char *endPtr;
  char errMess[BUFSIZ];

  (void) setvbuf (stdout, NULL, _IONBF, 0);

  //check max arguments
  if ( argc - 1 != 0 && argc - 1 != MAX_ARGS ) {

    fprintf(stderr, STR_USAGE_MSG, argv[0]);
    return EXIT_FAILURE;
  }

  FILE *file = NULL;

  if ( argc - 1 == 1 ) {
    file = fopen ( argv[1], "r" );

    //check if file is readable and exist
    if ( errno != 0 ) {
      perror(argv[1]);
      errno = 0;
      return EXIT_FAILURE;
    }
  }

  //if file went through then set it up
  if ( file != NULL ) {
    inFile = file;
    prompt = FALSE;
  }

  else {
    prompt = checkPrompt();
  }
  

  displayLights(lightBank);

  //checks for errors and reprompt user
  for ( DISPLAY_PROMPT; fgets( buf, BUFSIZ, inFile ) 
        != NULL; DISPLAY_PROMPT ) {

    //initialization
    char *wordpter;
    char *firstWord;
    wordpter = strtok (buf, TOKEN_SEPARATORS);
    firstWord = wordpter;
    int pattern1;
    int pattern2;

    //checks if there is not seperator
    if ( wordpter == NULL) {
      continue; 
    }

    //check for incorrect command
    if ( checkCmd(wordpter, commands)  == -1 ) {
      fprintf(stderr, STR_BAD_CMD);
      continue;
    }
  
    //check if it is help
    if ( checkCmd(wordpter, commands) == HELP ) {
      fprintf(stderr, STR_HELP_MSG);
      continue;
    }

    //quit the program
    if ( checkCmd(wordpter, commands) == QUIT) {
      break;
    }

    //check for errors for one of the three commands
    if ( checkCmd(wordpter,commands) == SET || 
         checkCmd(wordpter,commands) == CLEAR ||
         checkCmd(wordpter,commands) == TOGGLE) {

      wordpter = strtok(NULL,TOKEN_SEPARATORS);

      //check for no argument
      if (wordpter == NULL) {
        fprintf(stderr, STR_ARGS_REQ);
        continue;
      }
      
      pattern1 = strtoul(wordpter,&endPtr,BASE);

      //check for conversion error
      if ( errno != 0 ) {
        snprintf( errMess, BUFSIZ, STR_STRTOLONG_CONVERTING, wordpter, BASE);
        perror(errMess);
        errno = 0;
        fprintf(stderr, "\n");
        continue;
      }

      //check if its a integer
      if ( *endPtr != '\0' ) {
        fprintf(stderr, STR_STRTOLONG_NOTINT, wordpter);
        continue;
      }

      wordpter = strtok(NULL, TOKEN_SEPARATORS);

      //check for second argument
      if (wordpter == NULL) {
        fprintf(stderr, STR_TWO_ARGS_REQ);
        continue;
      }

      pattern2 = strtoul(wordpter,&endPtr,BASE);
       
      //check for conversion error
      if ( errno != 0 ) {
        snprintf( errMess, BUFSIZ, STR_STRTOLONG_CONVERTING, wordpter, BASE);
        perror(errMess);
        errno = 0;
        fprintf(stderr, "\n");
        continue;
      }

      //check if its a integer
      if ( *endPtr != '\0' ) {
        fprintf(stderr, STR_STRTOLONG_NOTINT, wordpter);
        continue;
      }

      wordpter = strtok(NULL, TOKEN_SEPARATORS);

      //check for third argument
      if (wordpter != NULL) {
        fprintf(stderr, STR_EXTRA_ARG, wordpter);
        continue;
      }
    }

    //check for errors for the three commands
    if ( checkCmd(wordpter,commands) == SHIFT ||
         checkCmd(wordpter,commands) == RIPPLE ||
         checkCmd(wordpter,commands) == ROTATE ) {

      wordpter = strtok(NULL,TOKEN_SEPARATORS);

      //check if there is argument
      if (wordpter == NULL) {
        fprintf(stderr, STR_ARGS_REQ);
        continue;
      }
      
      pattern1 = strtoul(wordpter,&endPtr,BASE);

      //check for conversion
      if ( errno != 0 ) {
        snprintf( errMess, BUFSIZ, STR_STRTOLONG_CONVERTING, wordpter, BASE);
        perror(errMess);
        errno = 0;
        fprintf(stderr, "\n");
        continue;
      }

      //check if its a integer
      if ( *endPtr != '\0' ) {
        fprintf(stderr, STR_STRTOLONG_NOTINT, wordpter);
        continue;
      }

      wordpter = strtok(NULL, TOKEN_SEPARATORS);

      //check if there is a second argument
      if (wordpter != NULL) {
        fprintf(stderr, STR_EXTRA_ARG, wordpter);
        continue;
      }
    }

    //display the different kinds of lights if all tests passed
    if ( checkCmd(firstWord, commands) == SET) {
      set(lightBank, pattern1, pattern2);
      displayLights(lightBank);
    }

    if ( checkCmd(firstWord, commands) == CLEAR) {
      clear(lightBank, pattern1, pattern2);
      displayLights(lightBank);
    }

    if ( checkCmd(firstWord, commands) == TOGGLE) {
      toggle(lightBank, pattern1, pattern2);
      displayLights(lightBank);
    }

    if ( checkCmd(firstWord, commands) == SHIFT) {
      shift(lightBank, pattern1 );
      displayLights(lightBank);
    }
    
    if ( checkCmd(firstWord, commands) == RIPPLE) {
      ripple(lightBank, pattern1 );
    }

    if ( checkCmd(firstWord, commands) == ROTATE) {
      rotate(lightBank, pattern1 );
      displayLights(lightBank);
    }
  }
  
  fclose(inFile);
  return EXIT_SUCCESS;
}
