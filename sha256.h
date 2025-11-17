#ifndef SHA256_H
#define SHA256_H

#include <stddef.h>
#include <stdint.h>

#define SHA256_BLOCK_SIZE 64  // 512 bits = 64 bytes
#define SHA256_DIGEST_SIZE 32 // 256 bits = 32 bytes
#define SHA256_ROUNDS 64      // Número de rodadas

typedef struct {
  uint32_t h[8];
  uint8_t buffer[SHA256_BLOCK_SIZE];
  size_t buffer_len;
  uint64_t total_len;
  uint8_t digest[SHA256_DIGEST_SIZE];
  int finalized;
} SHA256;

void sha256_init(SHA256 *ctx);

void sha256_update(SHA256 *ctx, const uint8_t *data, size_t len);

void sha256_final(SHA256 *ctx);

uint8_t *sha256_get_digest(SHA256 *ctx);

void sha256_print_digest(const uint8_t *digest);

#endif
