/*
 * Filename: testcheckRange.c
 * Author: Qiao jia Lu 
 * Userid: cs30xcq 
 * Description: Unit test program to test the function checkRange.
 * Date: 1/31/2018
 * Sources of Help: Tutor and write up
 */ 

#include <stdio.h>

#include "pa1.h"
#include "test.h"

/*
 * Unit Test for checkRange.s
 *
 * long checkRange( long value, long minRange, long maxRange );
 *
 * Checks to see if value is within the range of minRange to maxRange,
 * inclusive.
 *
 * Returns -1 if minRange > maxRange.
 * Returns 1 if value is between minRange and maxRange (inclusive).
 * Returns 0 otherwise.
 */
void testcheckRange( ) {

  /* Test around 0 */
  TEST( checkRange( 0, 0, 1 ) == 1 );
  TEST( checkRange( 0, 0, 0 ) == 1 );
  TEST( checkRange( 0, 0, -1 ) == -1 );

  /* Test inclusive */
  TEST( checkRange( 2, 2, 5 ) == 1 );
  TEST( checkRange( 5, 2, 5) == 1);

  /* Test min => max */
  TEST( checkRange( 2, 6, 1) == -1);
  TEST( checkRange( 2, -1, -10) == -1);

  /* Test negative values */
  TEST( checkRange( -2, -6, 0) == 1);
  TEST( checkRange( -5, -10, -1) == 1);

  /* Test out of range values */
  TEST( checkRange( 6, 1, 5) == 0);
  TEST( checkRange( -1, 0, 1) == 0);
}

int main( void ) {

  fprintf(stderr, "Running tests for checkRange...\n");
  testcheckRange();
  fprintf(stderr, "Done running tests!\n");

  return 0;
}
