/*
 * Filename: printStrings.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: This function will print out all valid sequences of
 * characters in the file.
 * Date: 3/13/18
 * Source of Help: Discussion slides and Tutors
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "pa4.h"
#include "pa4Strings.h"
/*
 * Function name: printStrings()
 * Function prototype: void printStrings ( FILE *fp, long endAddr );
 * Description: This function will print out all valid sequences of
 * character in the file
 * Paramters: fp - the file to read and print from
 *            endAddr - end of the file
 * Side Effects: None
 * Error Conditions: Memory allocation fail
 * Return Value: None
 */
void printStrings( FILE *fp, long endAddr ) {
  //delcaration
  char *starting = NULL;
  char *init = NULL;
  char *tmp = NULL;
  char buf[STR_BUFFER_SIZE];
  size_t readTracker;
  int arrayTracker = 0;
  int previousCount = 0;

  //loop through file and print
  for ( long i = 0; i < endAddr; i += STR_BUFFER_SIZE ) {

    readTracker = fread(buf, sizeof(char), STR_BUFFER_SIZE, fp);

    //loop through the buffer
    for ( long k = 0; k < readTracker; k++ ) {

      //check if the character is printable
      if ( isprint(buf[k] ) != 0 ) {

        if (starting == NULL ) {
          starting = &buf[k];
          arrayTracker++;
        }
        else {
          arrayTracker++;
        }
      }

      //not a printable character
      else {
        
        //if the none printable character is null terminator
        if ( starting != NULL && init == NULL && buf[k] == '\0' ) {
          init = (char *)calloc( arrayTracker + 1, sizeof(char));

          //check for error
          if ( init == NULL ) {
            perror(init);
            free(init);
            return;
          }
          
          //print the string out
          strncpy(init, starting, arrayTracker + 1);
          fprintf(stdout, STR_STRING_OUT, init);

          //free and reset everything
          free(init);
          init = NULL;
          starting = NULL;
          arrayTracker = 0;
        }

        //if already allocate but havn't hit null
        if ( init != NULL && buf[k] == '\0' ) {
          tmp = realloc (init, (previousCount + (arrayTracker + 1)) * sizeof(char));

          //check for error
          if ( tmp == NULL ) {
            perror(tmp);
            free(init);
            return;
          }

          
          init = tmp;

          //copy the string and add null terminator
          strncpy (init + previousCount, starting, arrayTracker);
          init[previousCount + arrayTracker] = '\0';

          //print the string out
          fprintf(stdout, STR_STRING_OUT, init);

          //reset everything
          free(init);
          init = NULL;
          starting = NULL;
          arrayTracker = 0;
          previousCount = 0;
        }

        //if its not null and is not a printable then reset
        if ( isprint(buf[k]) == 0 && buf[k] != '\0' ) {

          starting = NULL;

          if (init != NULL ) {
            free(init);
          }

          init = NULL;
          arrayTracker = 0;
          previousCount = 0;
        }
      }
    }

  //if null terminator is not found
  if ( (buf[STR_BUFFER_SIZE - 1] != '\0') && (isprint(buf[STR_BUFFER_SIZE - 1]) != 0) )  {

    //calculate and allocate new length
    tmp = realloc(init, (previousCount + arrayTracker) * sizeof(char));

    if ( tmp == NULL ) {
      perror(init);
      free(init);
      return;
    }

    //change pointer
    init = tmp;

    //copy new length in
    strncpy(init + previousCount, starting, arrayTracker);

    //reset and increase total length
    starting = NULL;
    previousCount += arrayTracker;
    arrayTracker = 0;
  }
 }
}
