/* Filename: testisOdd.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: Unit test program to test the function isOdd
 * Date: 1/31/18
 * Source of Help: Tutors, and lecture write up
 */

#include <stdio.h>

#include "pa1.h"
#include "test.h"

/*
 * Unit test for isOdd.s
 *
 * isOdd ( long value );
 * 
 * Check to see if the return value is odd or even
 *
 * return 0 if the value is not odd
 * return 1 or -1 if the value is odd
 */
void testisOdd( ) {

  /* test return odd */
  TEST( isOdd(5) == 1);
  TEST( isOdd(-5) == -1);

  /* test return value is even */
  TEST( isOdd(0) == 0);
  TEST( isOdd(2) == 0);
  TEST( isOdd(-2) == 0);
}

int main(void) {

  fprintf(stderr, "Running test for isOdd...\n");
  testisOdd();
  fprintf(stderr, "Done running tests!\n");

  return 0;
}
