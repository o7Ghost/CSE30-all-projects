/*
 * Filename: testcompareKey.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: Unit test program to test the function compareKey
 * Date: 2/17/2018
 * Source of Help: Tutor and Discussion slides
 */

#include <string.h>
#include "test.h"
#include "pa3.h"

/*
 * Unit Test for compareKey.s
 *
 * void compareKey( const void * p1, const void * p2 )
 * 
 * test if the keys in the anagram struct are the same
 */
void testcompareKey() {

  //declaration
  struct Anagram a;
  struct Anagram b;

  strcpy(a.word, "santa");
  strcpy(b.word, "santa");

  struct Anagram *p1;
  struct Anagram *p2;
  p1 = &a;
  p2 = &b;

  //Test when key are the same
  strcpy(a.key, "TSNAA");
  strcpy(b.key, "TSNAA");

  TEST( compareKey(p1,p2) == 0 );

  //Test when first value earlier
  strcpy(a.key, "ASNAA");

  TEST ( compareKey(p1,p2) == -1);

  //Test when first value is later
  strcpy(a.key, "USNAA");
  
  TEST ( compareKey(p1,p2) == 1);
}

int main() {
  printf("Running tests on compareKey()\n");
  testcompareKey();
  printf("Finished running tests on compareKey()\n");
  return 0;
}


