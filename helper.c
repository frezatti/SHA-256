#include "helper.h"

uint32_t bytes_to_word(const uint8_t *data) {
  if (!data)
    return 0;

  // printf("[DEBUG] bytes_to_word: %02x %02x %02x %02x\n",
  //        data[0], data[1], data[2], data[3]);

  return ((uint32_t)data[0] << 24) | ((uint32_t)data[1] << 16) |
         ((uint32_t)data[2] << 8) | ((uint32_t)data[3]);
}
