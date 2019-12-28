/* Filename: spawnAnagramMain
 * Author: Qiao Jia Lu
 * userid: cs30xcq
 * Description: evaluate the flags entered on the command line, spawn the array 
 * of struct anagrams (and report its size), spawn the anagram file (and report
 * how many anagrams were written to the file)
 * Date: 2/26/18
 * Source of Help: Tutor and Discussion
 */

#include <string.h>
#include "pa3.h"
#include "pa3Strings.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Function name: main()
 * Function prototype: main( int argc, char * argv[] );
 * Description: evaluate the flags entered on the command line, spawn the array
 * of struct anagrams ( and report its size ), spawn the anagram file (and
 * report how many anagrams were written to the file
 * Paramters: argc - the number of arguments that is passed in
 *            argv - array of commands that is passed in
 * Side Effects: None
 * Error Conditions: evaluating flag returns -1, anagram array returns -1
 * and anagramFile returns -1
 * Return value: EXIT_SUCCESS or EXIT FAILURE
 */

int main( int argc, char * argv[] ) {

  //declaration
  struct Anagram *anagramArray;
  char * dictionaryFile;
  char * anagramFile;
  char defaultDic[BUFSIZ];
  char defaultAna[BUFSIZ];
  int eval;
  int spawnArray;
  int spawnFile;

  //check if it is default case or not
  if ( argc == 1 ) {
    strncpy(defaultDic, DEFAULT_DICTIONARY_FILE, BUFSIZ);
    strncpy(defaultAna, DEFAULT_ANAGRAM_FILE, BUFSIZ);
    dictionaryFile = defaultDic;
    anagramFile = defaultAna;
  }

  else {
    strncpy(defaultDic, DEFAULT_DICTIONARY_FILE, BUFSIZ);
    strncpy(defaultAna, DEFAULT_ANAGRAM_FILE, BUFSIZ); 
    dictionaryFile = defaultDic;
    anagramFile = defaultAna;
    eval = evaluateFlags( argc , argv, &dictionaryFile, &anagramFile );
  }

  //check eval error
  if ( eval == -1 ) {
    return EXIT_FAILURE;
  }

  if ( eval == 1 ) {
    return EXIT_SUCCESS;
  }

  spawnArray = spawnAnagramArray( dictionaryFile, &anagramArray);

  //check spawnAnagramArray error
  if ( spawnArray == -1 ) {
    return EXIT_FAILURE;
  }

  spawnFile = spawnAnagramFile ( anagramFile, anagramArray, spawnArray );

  //check spawnAnagramArray error
  if ( spawnFile == -1 ) {
    return EXIT_FAILURE;
  }

  //print success message
  fprintf(stdout, STR_SPAWN_ARRAY, spawnArray);
  fprintf(stdout, STR_SPAWN_FILE, anagramFile, spawnFile);
  
  //free array
  free(anagramArray);
  return EXIT_SUCCESS;
}
