/*
 * Filename: evaluateArgs.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Date: 3/4/2018
 * Source of Help: Tutors and Discussion slides
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "pa4.h"
#include "pa4Strings.h"

static struct option options[] = {
  { HEX_FLAG_STR, no_argument, NULL, HEX_FLAG_CHAR },  
  { OCTAL_FLAG_STR, no_argument, NULL, OCTAL_FLAG_CHAR },  
  { ASCII_FLAG_STR, no_argument, NULL, ASCII_FLAG_CHAR }, 
  { STRING_FLAG_STR, no_argument, NULL, STRING_FLAG_CHAR },
  { BE_FLAG_STR, no_argument, NULL, BE_FLAG_CHAR }, 
  { LE_FLAG_STR, no_argument, NULL, LE_FLAG_CHAR },
  { HELP_FLAG_STR, no_argument, NULL, HELP_FLAG_CHAR }, 
  { RANGE_FLAG_STR, required_argument, NULL, RANGE_FLAG_CHAR },
  { UNDUMP_FLAG_STR, required_argument, NULL, UNDUMP_FLAG_CHAR },
  { 0, 0, 0, 0 }, 
};
/*
 * Function name: evaluateArgs()
 * Function Prototype: int evaluateArgs ( int argc, char * argv[],
 *                                        char ** infile, char ** outfile
 *                                        char ** rangeStr, OutType * type
 *                                        int * convert);
 * Parameters: argc - the number of arguments that is passed in
 *             argv - array of argument
 *             infile - the address of the pointer to be saved to for infile
 *             outfile - the address of the ponter to be saved to for outfile
 *             rangeStr - the address of the pointer to be saved to for range
 *             type - the type of the file
 *             convert - the convert type
 * Side Effects: save files into pointer
 * Error Conditions: An un known flag is countered, A flag argument is not
 *                   supplied, more than one flag is suppied, more than
 *                   one endian flag is suppied
 * Return Value: -1 if error, 0 if no error and 1 if help flag is encountered
 */

int evaluateArgs( int argc, char * argv[], char ** infile, char ** outfile,
                  char ** rangeStr, OutType * type, int * convert ) {
  //declaration
  int opt = 0;
  int xcosCount = 0;
  int blCount = 0;

  //parse the command
  while ((opt = getopt_long(argc, argv, OPT_STR, options, NULL)) != -1) {
    switch (opt) {
    
      //check -x -o -c -s
      case HEX_FLAG_CHAR:

        *type = HEX;
        xcosCount++;
        break;
      case OCTAL_FLAG_CHAR:

        *type = OCTAL;
        xcosCount++;
        break;
      case ASCII_FLAG_CHAR:
 
        *type = ASCII;
        xcosCount++;
        break;
      case STRING_FLAG_CHAR:
 
        *type = STRING;
        xcosCount++;
        break;

      //check -b -l
      case BE_FLAG_CHAR:
        if (IS_LITTLE_ENDIAN == 1) {
          *convert = 1;
        }

        else {
          *convert = 0;
        }

        blCount++;
        break;
      case LE_FLAG_CHAR:
        if(IS_LITTLE_ENDIAN == 0) {
          *convert = 1;
        }

        else {
          *convert = 0;
        } 
        blCount++;
        break;

      //check -r -u
      case RANGE_FLAG_CHAR:
        *rangeStr = optarg;
        break;
      case UNDUMP_FLAG_CHAR:
        *outfile = optarg;
        break;

      //check -h
      case HELP_FLAG_CHAR:
        fprintf(stdout, STR_USAGE_LONG, argv[0]);
        return 1;
      
      //undefined flag
      default: /* '?' */
        fprintf(stderr, STR_USAGE_SHORT, argv[0]);
        return -1;
    }
  }

  if ( xcosCount > 1 ) {

    fprintf(stderr, ERR_OUT_FLAGS);
    fprintf(stderr, STR_USAGE_SHORT, argv[0]);
    return -1;
  }

  
  if (blCount > 1 ) {
          
    fprintf(stderr, ERR_END_FLAGS);
    fprintf(stderr, STR_USAGE_SHORT, argv[0]);
    return -1;
  }

  if ( argc - optind != 1 ) {
    fprintf(stderr, ERR_NUM_ARGS);
    fprintf(stderr, STR_USAGE_SHORT, argv[0]);
    return -1;
  }

  else {
    *infile = argv[optind];
  }

  return 0;
}

