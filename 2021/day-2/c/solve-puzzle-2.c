#include <stdio.h>
#include <stdlib.h>

#include "../../misc/ioutil.h"
#include "parser.h"

int main(void) {
  char* data = read_file("../input.txt");

  uint32_t horizontal_pos = 0;
  uint32_t depth = 0;
  uint32_t aim = 0;

  parse_string(data, &horizontal_pos, &depth, &aim);

  printf("%d\n", horizontal_pos * depth);

  free(data);

  return 0;
}