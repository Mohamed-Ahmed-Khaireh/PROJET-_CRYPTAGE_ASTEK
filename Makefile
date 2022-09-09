#Makefile du Project Cryptage_C_ASTEK
SUPP = rm


CC = gcc
cxx = g++

CFLAGS = -Wno-unused-variable
LIB = -lsqlite3
EXE = main

ARCHIVE = sortie.zip


#Identifier tous les fichier .c de mon programme
SRC = $(wildcard *.c)


#Créer une liste des fichiers .o liés au fichier .c
OBJ = $(SRC:.c=.o)


all: $(EXE)


$(EXE): $(OBJ)
	$(CC) -o $(EXE) $^ $(CFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)




# main.o: main.c
	$(CC) -o main.o -c main.c $(CFLAG)



# fonctions.o: fonctions.c
	     $(CC) -o fonctions.o -c fonctions.c $(CFLAG)


clean: 
	$(SUPP) -r *.o

mrpropre: clean
	$(SUPP) -rf $(EXE)

zip: 
	tar -cvzf $(ARCHIVE) *.c *.h
