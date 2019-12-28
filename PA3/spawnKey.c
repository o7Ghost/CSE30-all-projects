/*
 * Filename: spwanKey.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: This function will fill the character array key with the 
 * reverse-sorted, all uppercase version of the string word
 * Date: 2/20/18
 * Source of Help: Tutor and Discussion slides
 */

#include <string.h>
#include "pa3.h"
#include <stdlib.h>
#include <ctype.h>

/* 
 * Function name: spawnKey
 * Function Prototype: void spawnKey ( char * key, const char * const word
 *                                     int keyLen );
 * Description: create a key
 * Paramters: key - the key that the new word to be put in
 *            word - the orginal word
 *            keyLen - the length of the key
 * Side Effects: None
 * Error Conditions: None
 * Return value: None
 */ 
void spawnKey( char * key, const char * const word, int keyLen ) {

  //delcaration
  int counter = 0;
  
  //set all string to null first
  memset(key, '\0', keyLen);

  //then copy over all the string 
  strncpy(key, word, keyLen - 1);

  //change to capital
  while (*(key + counter) != '\0') {
    *(key + counter) = toupper(*(key + counter));
    counter++;
  }
  
  //sort in reverse order
  qsort(key, strlen(key), sizeof(char), compareChar);
}
