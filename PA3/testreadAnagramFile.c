#include <string.h>
#include "test.h"
#include "pa3.h"

void testreadAnagramFile() {
  struct Anagram *testpointer;
  readAnagramFile("testAppend.ao", &testpointer);

  
  for ( int i = 0; i < 5; i++ ) {
    printf("%s\n", testpointer[i].word);
    printf("%s\n", testpointer[i].key);
  }
  
}

int main() {
  testreadAnagramFile();
}
