/*
 * Filename: testtoggle.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: toggle the pattern of the lights
 * Date: 2/4/2018
 * Source of Help:
 */

#include "test.h"
#include "pa2.h"

/*
 * Unit Test for toggle.s
 *
 * void toogle( unsigned int lightBank[], const unsigned int pattern0,
 *           const unsign int pattern1);
 * 
 * toggle the light pattern
 */

void testtoggle() {

  unsigned int lightBank[2];
  unsigned int pattern0 = 0x420C5E30;
  unsigned int pattern1 = 0xDEADBEEF;

  (void) printf( "Testing toggle()\n" );

  /* light bank initialization */

  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;

  /* test 1 */
  toggle( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0x88F2E48E && lightBank[1] == 0x00674542 );


  lightBank[0] = 0x00000000;
  lightBank[1] = 0x00000000;

  pattern0 = 0xFFFFFFFF;
  pattern1 = 0xFFFFFFFF;

  /* test 2 */

  toggle(lightBank, pattern0, pattern1);
  TEST( lightBank[0] == 0xFFFFFFFF && lightBank[1] == 0xFFFFFFFF );
  
  lightBank[0] = 0x00000000;
  lightBank[1] = 0x00000000;

  pattern0 = 0x00000000;
  pattern1 = 0x00000000;

  /* test 3 */

  toggle(lightBank, pattern0, pattern1); 
  TEST( lightBank[0] == 0x00000000 && lightBank[1] == 0x00000000 );


  lightBank[0] = 0xFFFFFFFF;
  lightBank[1] = 0xFFFFFFFF;

  pattern0 = 0xFFFFFFFF;
  pattern1 = 0xFFFFFFFF;

  /* test 4 */

  toggle(lightBank, pattern0, pattern1); 
  TEST( lightBank[0] == 0x00000000 && lightBank[1] == 0x00000000 );

  printf( "Finished running tests on toggle()\n" );
}

int main() {
  testtoggle();

  return 0;
}
