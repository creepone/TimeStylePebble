#pragma once
#include <pebble.h>

void timer_set_next_timestamp(uint32_t timestamp);
bool timer_is_running();
int timer_remaining_seconds();
char *timer_get_text();