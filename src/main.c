// #include "./include/check.h"
// #include <stdio.h>
#include <stdbool.h>

#include "./include/linkedList.h"
#include "./include/malloc.h"

void adder(int a, int b, int *target) {
  *target = a + b;
  return;
}

int main() {
  /*
  int a, b, result;
  a = 2;
  b = 3;
  adder(a, b, &result);
  printf("%d\n", result);
  int z = check();
  printf("%d\n", z);
  */
  // allocate();

  addNodeTail("hellothere1");
  addNodeTail("hellothere2");
  addNodeTail("hellothere3");
  printNodes();

  return 0;
}
