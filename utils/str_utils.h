#pragma once
#include <common.h>

void buf_reset(char *buf);

void buf_append_flt(char *buf, float f, uint8_t places);

void buf_append_str(char *buf, const char *app);

void buf_append_int(char *buf, int d);
