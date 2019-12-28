/*
 * filename: main.c
 * Author: Qiao Jia Lu
 * Description: This will be the main entry point of your program. It will be 
 * responsible for parsing command line arguments, opening all required files, 
 * and then calling the appropriate functions
 * Date: 3/14/18
 * Source of Help: Disccusion slides and Tutors
 */

#include <string.h>
#include <stdio.h>
#include "pa4.h"
#include "pa4Strings.h"
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>
/*
 * function name: main()
 * function prototype: int main ( int argc, char * argv[] ); 
 * Description: This will be the main entry point of your program. It will be 
 * responsible for parsing command line arguments, opening all required files,
 * Parameters: argc - the number of arguments that is passed in
 *             argv - the array of arguments that is passed in
 * Side Effects: None;
 * Error Conditions: evaluateArgs returns -1, parseRange returns -1,
 * error opening the file
 * Return Value: EXIT_SUCCESS and EXIT_FAILURE
 */
int main ( int argc, char * argv[] ) {
  //declaration
  errno = 0;
  char *infile = NULL;
  char *outfile = NULL;
  char *rangeStr = NULL;
  OutType type = HEX;
  int convert = 0;
  int checkEval = 0;
  FILE *fp = NULL;
  size_t fileSize;
  struct stat tmpSize;
  int checkParseRange = 0;
  long start = 0;
  long end = 0;
  FILE *wp = NULL;

  //check if flags are correct
  checkEval = evaluateArgs( argc, argv, &infile, &outfile, &rangeStr,
                            &type, &convert );

  //check if Eval has error
  if ( checkEval == -1 ) {
    return EXIT_FAILURE;
  }

  if ( checkEval == 1 ) {
    return EXIT_SUCCESS;
  }

  //open the file and check if it can be opened
  fp = fopen(infile, "r");
 
  if ( errno != 0 ) {
    perror(infile);
    errno = 0;
    return EXIT_FAILURE;
  }

  //get the size of the file
  stat(infile, &tmpSize);
  fileSize = tmpSize.st_size;
  end = fileSize;

  //check range flag is entered
  if ( rangeStr != NULL ) {
    checkParseRange = parseRange( rangeStr, infile, &start, &end );

    if ( checkParseRange == -1 ) {
      fprintf(stderr, STR_USAGE_SHORT, argv[0]);
      return EXIT_FAILURE;
    }
    else {
      fseek( fp, start, SEEK_SET);
    }
  }
 
  //check if outfile flag is entered
  if ( outfile != NULL ) {
    wp = fopen ( outfile, "w" );

    if ( errno != 0 ) {
      perror(outfile);
      errno = 0;
      return EXIT_FAILURE;
    }
    undump ( fp, wp, convert );
    fclose(wp);
  }
  else {

  //check if string characer flag is entered
    if ( type == STRING ) {
      printStrings(fp, end);
    }
  
    else {
      printBytes(fp, type, end, convert);
    }
  }
  fclose(fp);
  return EXIT_SUCCESS;
}
