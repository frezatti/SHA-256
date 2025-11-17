TARGET = sha256_program

CC = gcc
CFLAGS = -Wall -Wextra -g -O2 -std=c99
LDFLAGS = 

# Arquivos fonte
SOURCES = main.c sha256.c helper.c

OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "Compilação concluída! Execute './$(TARGET)' para usar."

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "Arquivos temporários removidos."

test: $(TARGET)
	./$(TARGET) --test

complexity: $(TARGET)
	./$(TARGET) --complexidade

help:
	@echo "Uso do Makefile:"
	@echo "  make          - Compila o programa"
	@echo "  make clean    - Remove arquivos compilados"
	@echo "  make test     - Executa testes unitários"
	@echo "  make complexity - Executa análise de complexidade"
	@echo "  make help     - Mostra esta ajuda"

# Evita conflito com arquivos existentes
.PHONY: all clean test complexity help
