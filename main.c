
#include "helper.h"
#include "sha256.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void run_tests() {
  printf("=== Executando Testes ===\n");

  SHA256 ctx1;
  sha256_init(&ctx1);
  sha256_update(&ctx1, (const uint8_t *)"", 0);
  sha256_final(&ctx1);

  uint8_t *digest1 = sha256_get_digest(&ctx1);
  printf("Teste 1 (string vazia): ");
  sha256_print_digest(digest1);

  SHA256 ctx2;
  sha256_init(&ctx2);
  sha256_update(&ctx2, (const uint8_t *)"abc", 3);
  sha256_final(&ctx2);

  uint8_t *digest2 = sha256_get_digest(&ctx2);
  printf("Teste 2 (string \"abc\"): ");
  sha256_print_digest(digest2);

  printf("=== Fim dos Testes ===\n\n");
}

void hash_string_wrapper(void *arg) {
  char *str = (char *)arg;
  SHA256 ctx;
  sha256_init(&ctx);
  sha256_update(&ctx, (uint8_t *)str, strlen(str));
  sha256_final(&ctx);
}

int main(int argc, char *argv[]) {
  printf("=================================================\n");
  printf("       Implementação SHA-256 \n");
  printf("   Algoritmos e Estruturas de Dados              \n");
  printf("=================================================\n\n");

  // Modo de uso
  if (argc < 2) {
    printf("Uso:\n");
    printf("  %s --test                    # Executa testes \n", argv[0]);
    printf("  %s --string \"mensagem\"       # Calcula hash de uma string\n",
           argv[0]);
    return 1;
  }

  if (strcmp(argv[1], "--test") == 0) {
    run_tests();
  } else if (strcmp(argv[1], "--string") == 0 && argc >= 3) {
    SHA256 ctx;
    sha256_init(&ctx);

    const char *input = argv[2];
    printf("Entrada: \"%s\"\n", input);
    printf("Tamanho: %zu bytes\n", strlen(input));

    sha256_update(&ctx, (const uint8_t *)input, strlen(input));
    sha256_final(&ctx);

    uint8_t *digest = sha256_get_digest(&ctx);
    sha256_print_digest(digest);
  } else {
    fprintf(stderr, "Erro: Opção inválida: %s\n", argv[1]);
    return 1;
  }

  return 0;
}
