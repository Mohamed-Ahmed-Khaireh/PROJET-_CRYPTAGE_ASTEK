#ifndef ENTETE_H_INCLUDED
#define ENTETE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//constante de pr�processeur (taille de la cha�ne de caract�res � saisir)
#define TEXT 100

//Les prototypes des fonctions


int Interface();
int Write(char [], char []);
int Crypt();
int Decrypt();

#endif // ENTETE_H_INCLUDED
