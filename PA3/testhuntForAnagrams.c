#include <string.h>
#include "test.h"
#include "pa3.h"
#include <stdlib.h>

void testhuntForAnagrams() {
  struct Anagram array[6];

  
  strncpy(array[0].word, "hello", strlen("hello") + 1); 
  strncpy(array[1].word, "santa", strlen("santa") + 1);
  strncpy(array[2].word, "abc", strlen("abc") + 1);
  strncpy(array[3].word, "john", strlen("john") + 1);
  strncpy(array[4].word, "lucia", strlen("lucia") + 1); 
  strncpy(array[5].word, "acb", strlen("acb") + 1);

  strncpy(array[0].key, "OLLHE", strlen("OLLHE") + 1); 
  strncpy(array[1].key, "TSNAA", strlen("TSNAA") + 1);
  strncpy(array[2].key, "CBA", strlen("CBA") + 1);
  strncpy(array[3].key,"ONJH", strlen("ONJH") + 1);
  strncpy(array[4].key, "ULICA", strlen("ULICA") + 1);
  strncpy(array[5].key, "CBA", strlen("CBA") + 1);
  
  qsort(array, 6, sizeof(struct Anagram), compareAnagram);

/*
  int i;
  for (i = 0; i < 6; i++ ) {
    fprintf(stdout, "%s\n", array[i].word);
    fprintf(stdout, "%s\n", array[i].key);

  }
 */
  huntForAnagrams(array, 6);

}

int main() {

  testhuntForAnagrams();
  return 0;
}
