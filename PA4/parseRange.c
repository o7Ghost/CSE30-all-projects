/*
 * filename: parseRange.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: This function will help you parse the range string that was 
 * provided as an argument to the -r flag
 * Date: 3/6/18
 * Source of Help: Discussion slides and tutor
 */

#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include "pa4.h"
#include "pa4Strings.h"
/*
 * function name: parseRange()
 * function prototype: int parseRange ( char * rangeStr, char * infile, 
 *                                      long * start, long * end );
 * Description: this function will help you parse the range string that
 * was provided as an argument to the -r flag
 * Parameters: rangeStr - the range that needs to be parse
 *             infile - the file that needs to be parse
 *             start - value to store the start
 *             end - value to store the end
 * Side Effects; save the start and end range
 * Error Conditions: String is not formmated correctly
 *                   start is not valid
 *                   end is not valid
 * Return Value: 0 if success -1 if not
 */

int parseRange ( char * rangeStr, char * infile, long * start, long * end ) {

  //declaration
  char *delims = ":";
  char *wordPtr1;
  char *wordPtr2;
  int errorFlag = 0;
  long parseNum1 = 0;
  long parseNum2 = 0;
  struct stat tmpSize;
  size_t fileSize;

  //parse the first part
  wordPtr1 = strtok ( rangeStr, delims );  
  wordPtr2 = strtok ( NULL, delims );

  if ( wordPtr2 == NULL ) {
    fprintf(stderr, ERR_RANGE_FMT);
    return -1;
  }

  //convert to long
  parseNum1 = parseLong( wordPtr1, &errorFlag );

  if ( errorFlag == 1 ) {
    fprintf(stderr, ERR_RANGE_INV);
    return -1;
  }

  //reset error flag
  errorFlag = 0;
  
  parseNum2 = parseLong ( wordPtr2, &errorFlag );

  if ( errorFlag == 1 ) {
    fprintf(stderr, ERR_RANGE_INV);
    return -1;
  }

  //check if both range is smaller than zero
  if ( parseNum1 < 0 || parseNum2 < 0 ) {
    fprintf(stderr, ERR_RANGE_INV);
    return -1;
  }

  //check if first range is greater than second
  if ( parseNum1 >= parseNum2 ) {
    fprintf(stderr, ERR_RANGE_INV);
    return -1;
  }

  //get file size
  stat(infile, &tmpSize);
  fileSize = tmpSize.st_size;

  //check file size
  if (  parseNum2 > fileSize ) {
    fprintf(stderr, ERR_RANGE_INV);
    return -1;
  }

  //assign the range
  *start = parseNum1;
  *end = parseNum2;

  return 0;
}
