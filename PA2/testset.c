/*
 * Filename: testset.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: set the pattern of the lights
 * Date: 2/4/2018
 * Source of Help:
 */

#include "test.h"
#include "pa2.h"

/*
 * Unit Test for set.s
 *
 * void set( unsigned int lightBank[], const unsigned int pattern0,
 *           const unsign int pattern1);
 * 
 * set the light pattern
 */

void testset() {

  unsigned int lightBank[2];
  unsigned int pattern0 = 0x420C5E30;
  unsigned int pattern1 = 0xF001F008;

  (void) printf( "Testing set()\n" );

  /* light bank initialization */

  lightBank[0] = 0x00100001;
  lightBank[1] = 0x1F00F001;

  /* test 1 */
  set( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0x421C5E31 && lightBank[1] == 0xFF01F009 );


  lightBank[0] = 0x00000000;
  lightBank[1] = 0x00000000;

  pattern0 = 0xFFFFFFFF;
  pattern1 = 0xFFFFFFFF;

  /* test 2 */

  set(lightBank, pattern0, pattern1);
  TEST( lightBank[0] == 0xFFFFFFFF && lightBank[1] == 0xFFFFFFFF );

  
  lightBank[0] = 0x00000000;
  lightBank[1] = 0x00000000;

  pattern0 = 0x00000000;
  pattern1 = 0x00000000;

  /* test 3 */

  set(lightBank, pattern0, pattern1); 
  TEST( lightBank[0] == 0x00000000 && lightBank[1] == 0x00000000 );


  lightBank[0] = 0xFFFFFFFF;
  lightBank[1] = 0xFFFFFFFF;

  pattern0 = 0xFFFFFFFF;
  pattern1 = 0xFFFFFFFF;

  /* test 4 */

  set(lightBank, pattern0, pattern1); 
  TEST( lightBank[0] == 0xFFFFFFFF && lightBank[1] == 0xFFFFFFFF );

  printf( "Finished running tests on set()\n" );
}

int main() {
  testset();

  return 0;
}
