#include "pa4.h"
#include "pa4Strings.h"
#include "test.h"
#include <stdio.h>

void testundump() {
  
  char *infile = "stdoutF";
  FILE *fp = NULL;
  FILE *fp2 = NULL;

  fp = fopen(infile, "r");
  char *outfile = "infile";

  fp2 = fopen(outfile, "w");

  undump(fp, fp2, 0);

}

int main() {
  testundump();
}
