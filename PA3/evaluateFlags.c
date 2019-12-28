/*
 * Filename: evaluteFlag.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: evulate the flags and print out mess and save the files
 * if there is file
 * Date: 2/26/18
 * Source of Help: Tutors and Discussion slids
 */

#include <string.h>
#include "pa3.h"
#include "pa3Strings.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <getopt.h>

/*
 * Function name: evaluteFlag()
 * Function prototype: evaluateFlag ( int argc, char * argv[], 
 *                                    char ** dictionaryFile, 
 *                                    char ** anagramFile );
 * Description: evaluate the flags and store the files if there is file
 * Paramters: argc - the number of argument that is passed in
 *            argv - the string of argument in the array
 *            dictionaryFile - the pointer to be saved if there is file
 *            anagramFile - the pointer to be saved if there is a file
 * Side Effects: save the dictionaryFile pointer and anagramFile pointer
 * Error Conditions: getopt detects an invalid flag or missing flag
 * extra args after getopt
 * Return Value: 0 for success and -1 to indicate failure
 */
int evaluateFlags ( int argc, char * argv[], char ** dictionaryFile, 
                   char ** anagramFile ) {
  int opt;

  //parse the command
  while ((opt = getopt(argc, argv, ARG_STR)) != -1 ) {

    //check the flags
    switch (opt) {

      // -d flag
      case FLAG_DICTIONARY_FILE:

        *dictionaryFile = optarg;
        break;

      //-a flag
      case FLAG_ANAGRAM_FILE:

        *anagramFile = optarg;
        break;
      //-h flag
      case FLAG_HELP:

        printUsage(stdout, STR_SPAWN_USAGE_LONG, argv[0]);
        return 1;
      //no flag is found
      default: /* '?' */

        printUsage(stderr, STR_SPAWN_USAGE_SHORT, argv[0]);

      return -1;
    }
  }

  //extra argument
  if (optind < argc ) {
    printUsage(stderr, STR_ERR_EXTRA_ARGS, argv[optind]);
    printUsage(stderr, STR_SPAWN_USAGE_SHORT, argv[0]);
    return -1;
  }

  return 0;
}
