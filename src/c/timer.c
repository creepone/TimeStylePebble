#include <pebble.h>
#include "timer.h"

static time_t s_timestamp = 0;
static char s_text_buffer[6];

void timer_set_next_timestamp(uint32_t timestamp) {
  s_timestamp = timestamp;
  APP_LOG(APP_LOG_LEVEL_INFO, "Set timestamp: %i", timestamp);
}

bool timer_is_running() {
  time_t now = time(NULL);
  return s_timestamp > now;
}

int timer_remaining_seconds() {
  time_t now = time(NULL);
  return s_timestamp > now ? s_timestamp - now : 0;
}

char *timer_get_text() {
  int total_seconds = timer_remaining_seconds();
  if (total_seconds >= 600) {
  	snprintf(s_text_buffer, 6, "%imin", total_seconds / 60);
  } else {
    snprintf(s_text_buffer, 6, "%02i:%02i", total_seconds / 60, total_seconds % 60);
  }
  return s_text_buffer;
}
