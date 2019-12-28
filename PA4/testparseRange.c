/*
 * filename: testparseRange.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: Unit test program to test the function parseRange
 * Date: 3/6/2018
 * Source of Help: Tutor and Discussion slides
 */

 #include <string.h>
 #include "test.h"
 #include "pa4.h"
 #include <stdio.h>
 /*
  * Unit test for parseRange.c
  *
  * int parseRange ( char * rangeStr, char * infile, long * start, long * end )
  * 
  * test if the range is correct and infile has the correct range
  */
void testparseRange() {

  //declaraction
  int result = 0;
  char rangeStr[] = "1:3";
  long start;
  long end = 0;

  //correct 
  result = parseRange( rangeStr, "test.h", &start, &end );
  TEST ( result == 0 );
  TEST ( start = 1 );
  TEST ( end = 3 );

  result = 0;
  //file too small for range
  fprintf(stderr, "check file in end range\n");
  char rangeStr2[] = "0:0x2001ffff";
  result = parseRange( rangeStr2, "test.h", &start, &end );
  TEST ( result == -1 );

  result = 0;
  //end too large can't parse
  fprintf(stderr, "checking end too large can't parse\n");
  char rangeStr3[] = "0:0x2001fffffffffff";
  result = parseRange( rangeStr3, "test.h", &start, &end );
  TEST ( result == -1 );
 
  result = 0;
  //formate incorrect
  char rangeStr4[] = "123";
  fprintf(stderr, "checking formate incorrect\n");
  result = parseRange( rangeStr4, "test.h", &start, &end );
  TEST ( result == -1 );

  result = 0;
  //formate incorrect
  char rangeStr5[] = "123:";
  fprintf(stderr, "checking formate incorrect\n");
  result = parseRange( rangeStr5, "test.h", &start, &end );
  TEST ( result == -1 );
 
  result = 0;
  //incorrect parse
  char rangeStr6[] = "1b:99";
  fprintf(stderr, "checking incorrect parse\n");
  result = parseRange( rangeStr6, "test.h", &start, &end );
  TEST ( result == -1 );

  result = 0;
  //incorrect parse
  char rangeStr7[] = "1:99b";
  fprintf(stderr, "checking inccorect parse\n");
  result = parseRange( rangeStr7, "test.h", &start, &end );
  TEST ( result == -1 );
 
  result = 0;
  //end > start
  char rangeStr8[] = "99:1";
  fprintf(stderr, "checking end > start\n");
  result = parseRange( rangeStr8, "test.h", &start, &end );
  TEST ( result == -1 );

  result = 0;
  //start negative
  char rangeStr9[] = "-1:99";
  fprintf(stderr, "check start negative\n");
  result = parseRange( rangeStr9, "test.h", &start, &end );
  TEST ( result == -1 );

  result = 0;
  //negative end
  char rangeStr10[] = "1:-99";
  fprintf(stderr, "check end negative\n");
  result = parseRange( rangeStr10, "test.h", &start, &end );
  TEST ( result == -1 );

  result = 0;
  //negative end
  char rangeStr11[] = "-99:1";
  fprintf(stderr, "check is  negative and larger than 1\n");
  result = parseRange( rangeStr11, "test.h", &start, &end );
  TEST ( result == -1 );

  char rangeStr12[] = "0::::1";
  fprintf(stderr, "check is  negative and larger than 1\n");
  result = parseRange( rangeStr12, "test.h", &start, &end );
  TEST ( result == 0 );

  char rangeStr13[] = "10:31";
  fprintf(stderr, "check is  negative and larger than 1\n");
  result = parseRange( rangeStr13, "test.h", &start, &end );
  TEST ( result == 0 );
}

int main() {
  testparseRange();
  return 0;
}
