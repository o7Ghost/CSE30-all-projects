#include <string.h>
#include "test.h"
#include "pa3.h"
#include "pa3Strings.h"

void testevaluateFlags(int argc, char* argv[]) {

  char * dict;
  char * anagram;
  int check;
  check = evaluateFlags( argc, argv, &dict, &anagram );
  printf("%d\n", check);
}

int main(int argc, char* argv[]) {
  testevaluateFlags(argc, argv);
}
