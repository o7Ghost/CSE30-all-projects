#include <string.h>
#include "test.h"
#include "pa3.h"

void testspawnAnagramArray() {
 // struct Anagram test[5];
  struct Anagram *testpointer;
 // struct Anagram **testdouble = &testpointer;
  spawnAnagramArray("testArray.txt",&testpointer);

  for (int i = 0; i < 5; i++) {
    printf("%s\n", testpointer[i].word);
    printf("%s\n", testpointer[i].key);
  }

}


int main () {
  testspawnAnagramArray();
  return 0;
}
