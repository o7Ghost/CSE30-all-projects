#include "pa4.h"
#include "pa4Strings.h"
#include "test.h"
#include <stdio.h>

void testprintBytes() {

  char * infile = "infile";
  FILE* fp = NULL;

  fp = fopen(infile, "r");

  printBytes(fp, HEX, 4, 0);
}

int main() {
  testprintBytes();
  return 0;
}
