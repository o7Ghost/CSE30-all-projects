/*
 * Filename: testshift.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: Unit test program to test the function shift().
 * Date: 2/6/2018
 * Sources of Help: Tutor and Discussion slide
 */ 

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa2.h"     /* For shift() function prototype */


/*
 * Unit Test for shift.s
 *
 * void shift( unsigned int lightBank[], const int shiftCnt );
 * 
 * Shifts the current light pattern in the lightBank by shiftCnt places.
 * If shiftCnt is positive, shift right.  If shiftCnt is negative, shift left.
 */
void testshift()
{
  unsigned int lightBank[2];
  int shiftCnt;

  (void) printf( "Testing shift()\n" );

  /* Shift left by 0 bit */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  shiftCnt = 0;
 
  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0xCAFEBABE && lightBank[1] == 0xDECAFBAD );

  /* Shift left by 1 bit */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  shiftCnt = -1;
 
  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0x95FD757D && lightBank[1] == 0xBD95F75A );


  /* Shift left by 2 bit */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  shiftCnt = -2;
 
  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0x2BFAEAFB && lightBank[1] == 0x7B2BEEB4 );

  /* Shift right by 1 bit */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  shiftCnt = 1;

  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0x657F5D5F && lightBank[1] == 0x6F657DD6 );

  /* Shift right by 2 bit */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  shiftCnt = 2;

  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0x32BFAEAF && lightBank[1] == 0xB7B2BEEB);

  printf( "Finished running tests on shift()\n" );
}


int main() {
  testshift();

  return 0;
}
