/*
 * Filename: spawnAnagramFile.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: make file with io extension and copy the array over  
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
 * Function name: spawnAnagramFile()
 * Function prototype: spawnAnagramFile( char * anagramFile, struct * Anagram
 *                                       anagramArray, int numAnagram );
 * Description: make file with io extension and copy the array over to the file
 * Paramters: anagramFile - the file that will copy to
 *            anagramArray - the anagramArray to copy from
 *            numAnagram - the number of anagram to copy on to the file
 * Side Effects: None
 * Error Conditon: anagram file can't be created
 * Return Value: return the number of anagrams written to file on
 *               success and -1 on failure
 */

int spawnAnagramFile ( char * anagramFile, struct Anagram * anagramsArray,
                       int numAnagrams) {

  //delcaration
  errno = 0;
  char filename[BUFSIZ];
  char extension[BUFSIZ];

  //append ao to the name and add null terminator
  strncpy(filename, anagramFile, BUFSIZ);
  strncpy(extension, ANAGRAM_FILE_EXT, BUFSIZ);
  strncat(filename, extension, BUFSIZ);
  filename[BUFSIZ - 1] = '\0'; 

  //open and creat the write to write
  FILE *file = fopen(filename, "w");

  //check for error
  if ( errno != 0 ) {
    fprintf(stderr, STR_ERR_CREATE_ANAGRAM_FILE, filename);
    errno = 0;
    return -1;
  }

  //write it in one go
  fwrite (anagramsArray, sizeof(struct Anagram), numAnagrams, file);

  fclose(file);
  return numAnagrams;
}

