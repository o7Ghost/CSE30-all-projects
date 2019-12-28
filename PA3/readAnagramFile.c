/*
 * Filename: readAnagramFile.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: This function will open and read the anagramFile in order to 
 * create and populate the anagramsArray in memory
 * Date: 2/27/18
 * Source of Help: Tutor and Discussion slides
 */

#include <strings.h>
#include <string.h>
#include "pa3.h"
#include "pa3Strings.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>

/*
 * Function name: readAnagramFile()
 * Function prototype: readAnagrameFile ( char * anagramFile, struct Anagram
 *                                        ** anagramArray );
 * Description: This function will open and read the anagramFile in order 
 * to create and populate the anagramsArray in memory.
 * Paramters: anagramFile - the pointer
 * Side Effects: None
 * Error Conditions: error opening file, Anagram file invalid size
 * memory allocation error, number of anagrams read is not the same as 
 * expected
 * Return Value: -1 if fail and number of anagram in array if success
 */

int readAnagramFile( char * anagramFile, struct Anagram ** anagramArray ) {

  //declaration
  errno = 0;
  FILE *fileByte;
  struct stat tmpSize;
  int anagramSize;
  int expectedSize;
  int actualSize;
  struct Anagram * pointer = NULL;
  size_t fileSize;

  //open the file
  fileByte = fopen ( anagramFile, "r" );

  //check if the file is open sccuessfully
  if ( errno == EACCES ) {
    fprintf(stderr, STR_ERR_ANAGRAM_FILE_PERMISSION, anagramFile);
    fprintf(stderr, "\n");
    errno = 0;
    return -1;
  }

  if ( errno == ENOENT ) {
    fprintf(stderr, STR_ERR_ANAGRAM_FILE_INVALID, anagramFile);
    fprintf(stderr, "\n");
    errno = 0;
    return -1;
  }

  //get file size
  stat(anagramFile, &tmpSize);
  fileSize = tmpSize.st_size;

  //get the size of the amagrams
  anagramSize = fileSize % sizeof (struct Anagram);
  expectedSize = fileSize / sizeof (struct Anagram);

  //check anagramsize
  if ( anagramSize != 0 ) {
    fprintf(stderr, STR_ERR_ANAGRAM_FILE_CORRUPT, anagramFile);
    fprintf(stderr, "\n");
    return -1;
  }
 
  //allocate memory for the anagrams
  pointer = malloc(expectedSize * sizeof(struct Anagram));

  //if can't malloc then error
  if ( pointer == NULL ) {
    fprintf(stderr, STR_ERR_MEM_EXCEEDED); 
    free(pointer);
  }
 
  //get the actualsize of the anagram
  actualSize = fread( pointer, sizeof(struct Anagram), expectedSize, fileByte );
 
  //check the size
  if ( actualSize != expectedSize ) {
    free(pointer);
    return -1;
  }
  
  //save into the array
  *anagramArray = pointer;

  //print success message
  fprintf(stdout, STR_HUNT_FILE, anagramFile, expectedSize);
  fprintf(stdout, STR_HUNT_ARRAY, actualSize);
  fclose(fileByte);

  return actualSize;
}
