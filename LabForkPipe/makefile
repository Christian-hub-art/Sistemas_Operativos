# Definimos el compilador que se va a usar
GCC = gcc
# Lista de programas (sin extensión .c)
PROGRAMAS = lab01becerra lab02becerra lab03becerra
# Regla para compilar el programa lab01becerra
lab01becerra:
	$(GCC) $@.c -o $@

# $@ representa el nombre de la regla (lab01becerra)
# Se compila el archivo lab01becerra.c y se genera el ejecutable lab01becerra

# Regla para compilar el programa lab02becerra
lab02becerra:
	$(GCC) $@.c -o $@
# Compila lab02becerra.c y genera el ejecutable lab02becerra

# Regla para compilar el programa lab03becerra
lab03becerra:
	$(GCC) $@.c -o $@
# Compila lab03becerra.c y genera el ejecutable lab03becerra

# Regla para limpiar (eliminar) los ejecutables generados
clean:
	$(RM) $(PROGRAMAS)
# $(RM) es un comando interno de make que elimina los archivos listados en $(PROGRAMAS)
# Se usa para limpiar el directorio y dejarlo sin ejecutables
