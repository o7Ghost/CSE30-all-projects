/*
 * Filename: testcompareKey.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: Unit test program to test the function compareAnagram
 * Date: 2/19/18
 * Source of Help: Tutor and Discussion slides
 */

#include <string.h>
#include "test.h"
#include "pa3.h"

/*
 * Unit test for compareAnagram.s
 *
 * void compareAnagram( const void * p1, const void * p2 ) 
 *
 * test if the keys and word in struct are the same
 */

void testcompareAnagram() {

  //declaration
  struct Anagram a;
  struct Anagram b;
   
  strcpy(a.word, "santa");
  strcpy(b.word, "santa");

  struct Anagram *p1;
  struct Anagram *p2;
  p1 = &a;
  p2 = &b;

  //test when key and word are the same
  strcpy(a.key, "TSNAA");
  strcpy(b.key, "TSNAA");

  TEST( compareAnagram(p1,p2) == 0 );
  
  //Test when key are the same but has a smaller word than p2
  strcpy(a.word, "SANTA");

  TEST( compareAnagram(p1,p2) == -1 );
  
  //Test when key are the same but has a larger word than p2
  strcpy(a.word, "uanta");
  
  TEST( compareAnagram(p1,p2) == 1 );

  //Test when key p1 comes earlier than p2
  strcpy(a.key, "ASNAA");

  TEST( compareAnagram(p1,p2) == -1);
 
  //Test when key p1 comes after p2
  strcpy(a.key, "USNAA");

  TEST( compareAnagram(p1,p2) == 1); 
}

int main() {
  printf("Running tests on compareAnagram()\n");
  testcompareAnagram();
  printf("Finished running tests on compareAnagram()\n");
  return 0;
}
