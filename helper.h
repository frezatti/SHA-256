#ifndef HELPER_H
#define HELPER_H

#include <stdint.h>

#define ROTR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
#define SHR(x, n) ((x) >> (n))

#define SIGMA0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define SIGMA1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))

#define GAMMA0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ SHR(x, 3))
#define GAMMA1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ SHR(x, 10))

#define CH(x, y, z) (((x) & (y)) ^ ((~(x)) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))

uint32_t bytes_to_word(const uint8_t *data);

#endif /* HELPER_H */
