#include "parser.h"

#include <string.h>

static uint8_t char_to_num(const char* ptr) { return ptr[0] - 48; }

void parse_string(char* str, uint32_t* horizontal_pos, uint32_t* depth
#ifdef HAS_AIM
                  ,
                  uint32_t* aim
#endif
) {
  char* nl_token;

  while ((nl_token = strtok_r(str, "\n", &str))) {
    char* instruction = strtok_r(nl_token, " ", &nl_token);
    const uint8_t arg = char_to_num(strtok_r(nl_token, " ", &nl_token));

    if (!strcmp(instruction, "forward")) {
      *horizontal_pos += arg;
#ifdef HAS_AIM
      *depth += (*aim) * arg;
#endif
    } else if (!strcmp(instruction, "up")) {
#ifdef HAS_AIM
      *aim -= arg;
#else
      *depth -= arg;
#endif
    } else if (!strcmp(instruction, "down")) {
#ifdef HAS_AIM
      *aim += arg;
#else
      *depth += arg;
#endif
    }
  }
}