#desVariables dans makefile
SRC_DIR := algorithm/src
BUILD_DIR := algorithm/build
#fichier sources .c willcard equivo a *.c en unix tous les fichier
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
#variable flag
CFLAGS := -Wall -g 
#compilateur object 
CC := gcc
#%compiler tous me fichier .c en .o 
all: $(SRC_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%) main
main: main.c traitement
	$(CC) $(CFLAGS) main.c traitement -o main
$(BUILD_DIR)/%: $(SRC_DIR)/%.c traitement
	@mkdir -p $(@D)
	$(CC) -nostartfiles $(CFLAGS) -o $@ $^
traitement: traitement.c
	$(CC) -o traitement -c traitement.c
#nettoyer mes fichier objets
clean:
	rm -rf algorithm/build
	rm -f main


