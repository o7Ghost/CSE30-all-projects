/*
 * Filename: huntAnagramMain.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: This program controls the hunt for anagrams
 * Date: 2/28/18
 * Source of Help: Tutors and Discussion
 */

#include <string.h>
#include "pa3.h"
#include "pa3Strings.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

/*
 * Function name: main()
 * Function prototype: main ( int argc, char * argv[] );
 * Description: This program controls the hunt for anagrams
 * Paramters: argc - the number of arguments that is passed in
 *            argv - array of commands that is passed in
 * Side Effects: None
 * Error Conditions: wrong number of arguments, file doesn't have ao,
 * errnor reading the anagram file
 * Return Value: returns EXIT_FAILURE if error and EXIT_SUCCESS if 
 * success
 */

int main( int argc, char * argv[] ) {
  //declaration
  struct Anagram * anagramArray;
  int checkReadFile;
  char * nameExtension;

  //check argument for 1
  if ( argc != MAX_ARGUMENTS ) {
    printUsage(stderr, STR_SPAWN_USAGE_SHORT, argv[0]);
    return EXIT_FAILURE;
  }

  //check for extension
  nameExtension = strrchr(argv[1], '.');
  if (nameExtension == NULL) {
    fprintf(stderr, STR_ERR_ANAGRAM_FILE_EXT, argv[1], ANAGRAM_FILE_EXT );
    return EXIT_FAILURE;
  }
  else {
    if(strcmp(nameExtension, ANAGRAM_FILE_EXT) != 0) {
      fprintf(stderr, STR_ERR_ANAGRAM_FILE_EXT, argv[1], ANAGRAM_FILE_EXT );
      return EXIT_FAILURE;
    }
  }

  //read ao file
  checkReadFile = readAnagramFile(argv[1], &anagramArray);

  //check if reading was success
  if ( checkReadFile == -1 ) { 
    return EXIT_FAILURE;
  }

  //sort the anagram array
  qsort(anagramArray, checkReadFile, sizeof(struct Anagram), compareAnagram);

  //hunt for anagrams
  huntForAnagrams(anagramArray, checkReadFile);

  //free memory
  free(anagramArray);
  return EXIT_SUCCESS;
}
