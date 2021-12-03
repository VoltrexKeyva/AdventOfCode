#ifndef PARSER_H
#define PARSER_H

#include <stdint.h>

void parse_string(char * str, uint32_t * horizontal_pos, uint32_t * depth
#ifdef HAS_AIM
, uint32_t * aim
#endif
);

#endif