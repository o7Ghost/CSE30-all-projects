#include <string.h>
#include "test.h"
#include "pa3.h"
#include "pa3Strings.h"

void testprintUsage() {
  printUsage(stderr, STR_SPAWN_FILE, "dog");

}

int main() {
  testprintUsage();
  return 0;
}
