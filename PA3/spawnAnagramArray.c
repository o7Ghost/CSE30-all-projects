/*
 * Filename: spawnAnagramArray.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: spawn an array of anagram where each element of the array
 * is a struct anagram
 * Date: 2/25/18
 * Source of Help: Tutors and Discussion slids
 */

#include <string.h>
#include "pa3.h"
#include "pa3Strings.h" 
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

/*
 * Function name: spawnAnagramArray()
 * Function prototype: spawnAnagramArray( char * dictionaryFile, struct 
 *                                        Anagram ** anagramsArray );
 * Description: spawn an array of anagram where each element of the array
 * is a struct anagram
 * Paramters: dictionaryFile - the pointer to the start of the dictionary
 *            anagramArray - the array that the words are going to put into
 * Side Effects: replaces anagramArray's pointer
 * Error Conditions: can't open the file and memory allocation fail
 * Return value: -1 on failures and the number of anagrams stored in array
 */
int spawnAnagramArray (char * dictionaryFile, struct Anagram ** anagramsArray) {

  //declaration
  errno = 0;
  FILE *fileByte;
  char buf[BUFSIZ] = { 0 };
  struct Anagram * tmpArray;
  struct Anagram * init = NULL;
  int arraySize = 0;
  struct Anagram createAna;

  //open the dictionary file
  fileByte = fopen( dictionaryFile, "r");

  //check if the dictionary can open
  if ( errno == EACCES ) { 
    fprintf(stderr, STR_ERR_DICT_FILE_PERMISSION, dictionaryFile);
    fprintf(stderr, "\n");
    errno = 0;
    return -1;
  }

  if ( errno != 0 ) {
    fprintf(stderr, STR_ERR_DICT_FILE_INVALID, dictionaryFile);
    fprintf(stderr, "\n");
    errno = 0;
    return -1;
  }

  // go through the file and get the characters
  while ( fgets( buf, BUFSIZ, fileByte ) != NULL ) {

    *(strrchr(buf, '\n')) = '\0'; 

    //allocate memory for next array index
    tmpArray = realloc( init, (arraySize + 1) * sizeof(struct Anagram));

    //check if there is space to allocate
    if ( tmpArray == NULL ) {
      fprintf(stderr, STR_ERR_MEM_EXCEEDED);
      free(init);
      return -1;
    }

    //make a anagram
    spawnAnagram(buf, &createAna);

    //assign it to the first index
    tmpArray[arraySize] = createAna;
 
    //gve it the pointer
    init = tmpArray;

    //increase to next index
    arraySize++;
  }

  //assign it to the anagram array
  *anagramsArray = init;

  fclose(fileByte);
  return arraySize;
}
