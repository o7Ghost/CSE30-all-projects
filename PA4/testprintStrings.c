#include "pa4.h"
#include "pa4Strings.h"
#include "test.h"
#include <stdio.h>

void testprintStrings() {
  
  char *infile = "undump.o"; 
  FILE *fp = NULL;

  fp = fopen(infile, "r");

  printStrings(fp, 4736);

  fclose(fp);
}

int main() {
  testprintStrings();
  return 0;
}
