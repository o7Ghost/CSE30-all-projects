#include <string.h>
#include "test.h"
#include "pa3.h"

void testspawnAnagramFile() {

  struct Anagram *testpointer;
  spawnAnagramArray("testArray.txt", &testpointer);
  spawnAnagramFile("testAppend", testpointer, 5);

}

int main() {

  testspawnAnagramFile();
  return 0;
}
