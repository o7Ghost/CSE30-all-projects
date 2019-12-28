/*
 * Filename: checkCmd.s
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: check if command is in the list
 * Date: 2/11/2018
 * Source of Help: Tutors and Discussion
 */

#include <stdio.h>
#include "string.h"
#include "pa2.h"

/*
 * Function Name: checkCmd()
 * Function Prototype: int checkCmd( const char* const cmdString,
 *                                   const char* const commands[])
 * Description: checks to see if cmdString is in the commands array
 * Parameters: cmdString - the command that needs to be check
 *             commands[] - the array of command to check with
 * Side Effects: None
 * Error Conditions: None
 * Return Value: Returns the index of the command found. Otherwise
 * return -1 to indicate cmdString was not in the command array
 */

int checkCmd( const char* const cmdString, const char* const commands[] ) {
 
  //iniliazation
  int returnV = -1;
  int counter = 0;

  //check paramters are correct
  if ( cmdString == NULL || commands == NULL ) {
    return returnV;
  }

  //check if command exist in the array
  while (commands[counter] != NULL ) {
    if ( strncmp ( cmdString, commands[counter], BUFSIZ) == 0 ) {
      return counter;
    }
    counter++;
  }

  return returnV;
}

