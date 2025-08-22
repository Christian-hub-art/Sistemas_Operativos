# Nombre del ejecutable
TARGET = CalculadoraMasaCorporal

# Buscar automáticamente todos los archivos .c
SRC = $(wildcard *.c)

# Generar lista de archivos .o a partir de los .c
OBJ = $(SRC:.c=.o)

# Compilador y banderas
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Regla principal
all: $(TARGET)

# Enlazar
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

# Regla para compilar .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar
clean:
	rm -f $(OBJ) $(TARGET)

