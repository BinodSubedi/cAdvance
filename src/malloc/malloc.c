#include <stdio.h>
#include <stdlib.h>

void allocate() {
  char *val;

  val = malloc(10);

  printf("write something man::");

  scanf("%s", val);

  printf("the value read was:: %s\n", val);

  free(val);
}
