#include "pa2.h"

void testripple() {
unsigned int lightBank[2];
lightBank[0] = 0x00000001;
lightBank[1] = 0x00000000;

ripple(lightBank, 4);

}

int main() {
  testripple();

  return 0;

}
