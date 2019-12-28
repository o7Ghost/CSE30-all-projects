/*
 * filename: convertOrder
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: Unit test program to test the function convertOrder
 * Date: 3/6/2018
 * Source of Help: Tutor and Discussion slides
 */

#include <string.h>
#include "test.h"
#include "pa4.h"
#include <stdio.h>
 /*
  * Unit test for convertOrder
  *
  * void convert ( unsigned char * toConvert );
  *
  * test if the order has switched
  */
void testconvertOrder() {
  unsigned char charBank[4];
  charBank[0] = 0xCA;
  charBank[1] = 0xFE;
  charBank[2] = 0xBA;
  charBank[3] = 0xBE;

  unsigned char correct[4];
  correct[0] = 0xBE;
  correct[1] = 0xBA;
  correct[2] = 0xFE;
  correct[3] = 0xCA;

  convertOrder(charBank);
  TEST( charBank[0] == correct[0] );
  TEST( charBank[1] == correct[1] );
  TEST( charBank[2] == correct[2] );
  TEST( charBank[3] == correct[3] ); 
}

int main() {
  testconvertOrder();
  return 0;
}
