
#include "pa2.h"
#include <stdio.h>
void testdisplayLights() {
  unsigned int lightBank[2];
  lightBank[0] = 0xFFFFFFFF;
  lightBank[1] = 0x00000000;

//  printf("%X", lightBank[0]);
  displayLights(lightBank);
}

int main() {
 testdisplayLights();
return 0;
}
