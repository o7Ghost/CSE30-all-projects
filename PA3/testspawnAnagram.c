/*
 * Filename: testspawnAnagram.c
 * Author: Qiao Jia Lu
 * Userid: cs30xcq
 * Description: Unit test program to test the function spawnAnagram().
 * Date: 2/17/2018
 * Sources of Help: Tutor and Discussion slides
 */ 
#include <string.h>
#include "test.h"
#include "pa3.h"

/*
 * Unit Test for spawnAnagram.s
 *
 * void spawnAnagram( char const * originalWord, struct Anagram * anagram );
 *
 * Fills the members of the anagram struct based on the originalWord (copies
 * word into anagram->word, and spawns anagram->key by calling spawnKey()).
 */
void testspawnAnagram() {
  struct Anagram a;
  struct Anagram b;
  struct Anagram c;
  struct Anagram d;

  // All lowercase short word
  spawnAnagram("santa", &a);
  TEST(strncmp("santa", a.word, MAX_WORD_LEN) == 0);
  TEST(strncmp("TSNAA", a.key, MAX_WORD_LEN) == 0);

  //long word
  spawnAnagram("aaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbb", &b);
  TEST(strncmp("aaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbb", b.word, 
                MAX_WORD_LEN) == 0);
  TEST(strncmp("BBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAAAAAAAAA", b.key,
                MAX_WORD_LEN) == 0);

  //All word are capital
  spawnAnagram("SANTA", &c);
  TEST(strncmp("SANTA", c.word, MAX_WORD_LEN) == 0);
  TEST(strncmp("TSNAA", c.key, MAX_WORD_LEN) == 0);

  //mix character 
  spawnAnagram("SaNTa", &d);
  TEST(strncmp("SaNTa", d.word, MAX_WORD_LEN) == 0);
  TEST(strncmp("TSNAA", d.key, MAX_WORD_LEN) == 0);

  //empty string
  spawnAnagram("\0", &d);
  TEST(strncmp("\0", d.word, MAX_WORD_LEN) == 0);
  TEST(strncmp("\0", d.key, MAX_WORD_LEN) == 0);
}

int main() {
  printf("Running tests on spawnAnagram()\n");
  testspawnAnagram();
  printf("Finished running tests on spawnAnagram()\n");
  return 0;
}
