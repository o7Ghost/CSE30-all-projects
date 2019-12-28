/*
 * Filename: testspawnKey.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: Unit test program to test the function spwanKey
 * Date: 2/20/18
 * Source of Help: Tutor and Discussion slides
 */

#include <string.h>
#include "test.h"
#include "pa3.h"

/*
 * Unit test for spwanKey.s
 *
 * void spwanKey( char * key, const char * const word, int keyLen );
 *
 * test if the keys in the anagram struct are the same
 */
void testspawnKey() {

  //delcaration
  char keyR[7];
  char word[6] = "santa";
  
  char *key;
  char *orginWord;
  char *orginalWordC;
  char *orginalWordM;

  key = keyR;
  orginWord = word;

  //test if key is larger
  spawnKey(key, orginWord, 7);

  TEST( strncmp("TSNAA", key, MAX_WORD_LEN) == 0 );

  //test if key is smaller
  char keyT[5];
  key = keyT;

  spawnKey(key, orginWord, 5);
  TEST( strncmp("TSNA", key, MAX_WORD_LEN) == 0 );  
 
  //test if key is the same
  char keyL[6];
  key = keyL;

  spawnKey(key, orginWord, 6);
  TEST( strncmp("TSNAA", key, MAX_WORD_LEN) == 0 );

  //test spawn key with all caps
  char wordC[6] = "SANTA";
  char keyC[6];

  orginalWordC = wordC;
  key = keyC;

  spawnKey(key, orginalWordC, 6);
  TEST( strncmp("TSNAA", key, MAX_WORD_LEN) == 0 );

  //test spawn key with mix char
  char wordM[6] = "SaNtA";
  char keyM[6];

  orginalWordM = wordM;
  key = keyM;

  spawnKey(key, orginalWordM, 6);
  TEST( strncmp("TSNAA", key, MAX_WORD_LEN) == 0 );
}

int main() {
  printf("Running tests on spwanKey()\n");
  testspawnKey();
  printf("Finished running tests on spawnKey()\n");
  return 0;
}
