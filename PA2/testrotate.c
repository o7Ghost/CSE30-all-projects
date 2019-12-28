/*
 * Filename: testrotate.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: Unit test program to test the function rotate().
 * Date: 2/6/2018
 * Sources of Help: Discussion slides and Tutor
 */ 

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa2.h"     /* For shift() function prototype */


/*
 * Unit Test for rotate.s
 *
 * void rotate( unsigned int lightBank[], const int rotateCnt );
 * 
 * Rotate the current light pattern in the lightBank by rotateCnt places.
 * If rotateCnt is positive, rotate right. 
 * If shiftCnt is negative, rotate left.
 */
void testrotate()
{
  unsigned int lightBank[2];
  int rotateCnt;

  (void) printf( "Testing rotate()\n" );

  /* Shift right by 1 bit */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  rotateCnt = 1;

  rotate( lightBank, rotateCnt );
  TEST( lightBank[0] == 0xE57F5D5F && lightBank[1] == 0x6F657DD6 );

  /* Shift right by 13 bit */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  rotateCnt = 13;

  rotate( lightBank, rotateCnt );
  TEST( lightBank[0] == 0xDD6E57F5 && lightBank[1] == 0xD5F6F657 );


  /* Shift left by 28 bit */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  rotateCnt = -28;

  rotate( lightBank, rotateCnt );
  TEST( lightBank[0] == 0xEDECAFBA && lightBank[1] == 0xDCAFEBAB );

  /* test 64 */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  rotateCnt = 64;

  rotate( lightBank, rotateCnt );
  TEST( lightBank[0] == 0xCAFEBABE && lightBank[1] == 0xDECAFBAD );


  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  rotateCnt = 32;

  rotate( lightBank, rotateCnt );
  TEST( lightBank[0] == 0xDECAFBAD && lightBank[1] == 0xCAFEBABE );
  printf( "Finished running tests on rotate()\n" );
}


int main() {
  testrotate();

  return 0;
}
