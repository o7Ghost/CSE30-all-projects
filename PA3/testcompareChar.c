/*
 * Filename: testcompareChar.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: Unit test program to test the function compareChar().
 * Date: 2/17/18
 * Source of Help: Tutor and Discussion slides
 */

#include <string.h>
#include "test.h"
#include "pa3.h"

/*
 * Unit Test for compareChar.s
 *
 * void compareChar( const void * p1, const void * p2 )
 * 
 * checks if two char are the same by comparing two char's ASCII
 * value
 */

void testcompareChar() {

  //declaration
  char char1 = 'a';
  char char2  = 'b';

  char upChar1 = 'A';
  char upChar2 = 'B';

  char *p1; 
  char *p2;

  //test lower case
  p1 = &char1;
  p2 = &char2;

  TEST( compareChar( p1, p2 ) == 1 );

  char2 = 'a';
  TEST( compareChar( p1, p2 ) == 0 );

  char1 = 'c';
  TEST( compareChar( p1, p2 ) == -1);

  //test upper case
  p1 = &upChar1;
  p2 = &upChar2;

  TEST( compareChar( p1, p2 ) == 1 );

  upChar1 = 'B';
  TEST( compareChar( p1, p2 ) == 0 );

  upChar1 = 'C';
  TEST( compareChar( p1, p2 ) == -1 );
}

int main() {
  printf("Running tests on compareChar())\n");
  testcompareChar();
  printf("Finished running tests on compareChar()\n");
  return 0;
}
