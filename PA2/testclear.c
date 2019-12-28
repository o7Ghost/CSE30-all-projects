/*
 * Filename: testclear.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: only clear that lights that is on and is in the pattern
 * Date: 2/4/2018
 * Source of Help:
 */

#include "test.h"
#include "pa2.h"

/*
 * Unit Test for clear.s
 *
 * void clear( unsigned int lightBank[], const unsigned int pattern0,
 *           const unsign int pattern1);
 * 
 * clear the lights that is on and is in the pattern
 */

void testclear() {

  unsigned int lightBank[2];
  unsigned int pattern0 = 0xFF000000;
  unsigned int pattern1 = 0x88888888;

  (void) printf( "Testing clear()\n" );

  lightBank[0] = 0xFF00FF00;
  lightBank[1] = 0xAAAAAAAA;

  /* test 1 */
  clear( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0x0000FF00 && lightBank[1] == 0x22222222 );

  pattern0 = 0xFFFFFFFF;
  pattern1 = 0xFFFFFFFF;

  lightBank[0] = 0xFFFFFFFF;
  lightBank[1] = 0xFFFFFFFF;

  /* test 2 */
  clear( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0x00000000 && lightBank[1] == 0x00000000);

  pattern0 = 0x00000000;
  pattern1 = 0x00000000;

  lightBank[0] = 0xFFFFFFFF;
  lightBank[1] = 0xFFFFFFFF;

  /* test 3 */
  clear( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0xFFFFFFFF && lightBank[1] == 0xFFFFFFFF);
}

int main() {

  testclear();
  return 0;
}
