#include <stdio.h>
#include <stdlib.h>

#include "../../misc/arrayutil.h"
#include "../../misc/ioutil.h"
#include "parser.h"

int main(void) {
  char* data = read_file("../input.txt");

  array_t parsed = parse_array(data);

  num_t times_increased = 0;

  for (num_t i = 1; i < parsed->size; i++)
    if (parsed->data[i] > parsed->data[i - 1]) times_increased++;

  printf("%d\n", times_increased);

  free(parsed->data);
  free(parsed);
  free(data);

  return 0;
}