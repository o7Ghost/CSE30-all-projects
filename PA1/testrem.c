 /* Filename: testrem.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: Unit test program to test the function rem
 * Date: 1/31/18
 * Source of Help: Tutors, discussion and lecture paper
 */

#include <stdio.h>

#include "pa1.h"
#include "test.h"

/*
 * Unit test for rem.s
 *
 * long rem ( long dividend, long divisor);
 *
 * Check to see if the return value is within 32 bits
 * or param is correct
 *
 * return -1 if return value is not within 32 bits or
 * input value is invalid
 * return 1 if return value is within 32 bits
 * return 0 otherwise
 */

void testrem( ) {
  
  /* Test for correct input */
  TEST( rem( 5, 5 ) == 0 );
  TEST( rem( 5, 3 ) == 2 );

  /* Test for negative input */
  TEST( rem( 5, -3 ) == 2 );
  TEST( rem( -5, 3 ) == -2 ); 
  TEST( rem( -5, -3) == -2 );
  TEST( rem( -5, -5) == 0 );

  /* Test zero dividend */
  TEST( rem( 0, 2 ) == 0 ); 
}

int main( void ) {
  fprintf(stderr, "Running tests for rem...\n");
  testrem();
  fprintf(stderr, "Done running tests!\n");

  return 0;
}
