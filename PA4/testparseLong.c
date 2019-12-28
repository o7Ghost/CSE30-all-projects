/*
 * filename: testparseLong.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: a tester for parseLong
 * Date: 2/5/2018
 * Source of Help: Tutor and Dicussion slides
 */

#include <string.h>
#include "test.h"
#include "pa4.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Unit Test for parseLong
 *
 * long parseLong ( char * str, int * errorFlag )
 *
 * Test if the function has parse the string correctly
 * and if not then the flag should have error
 */

void testparseLong() {

  //declaration for error flag
  int errorflag = 0;
  long R;
  long myReturn;

  //not an integer
  char *error1 = "123abc";
  char *endPter;

  parseLong(error1, &errorflag);
  TEST( errorflag == 1 );

  //value too large
  char error2[] = "99999999999999999999999999999999999";
  errorflag = 0;
  parseLong(error2, &errorflag);
  TEST( errorflag == 1);

  //correct value
  char *correct = "123";
  errorflag = 0;
  myReturn = parseLong(correct, &errorflag);
  R = strtol(correct,&endPter, 0);

  TEST( myReturn == R );
  TEST( errorflag == 0 );

  char *error4 = "0x2001ffff";
  errorflag = 0;
  parseLong(error4, &errorflag);
  TEST( errorflag == 0);


  char *error5 = "-1";
  errorflag = 0;
  long correct22 =  parseLong(error5, &errorflag);
  TEST( errorflag == 0);
  TEST( correct22 == -1 );
}

int main() {
  testparseLong();
  return 0;
}
