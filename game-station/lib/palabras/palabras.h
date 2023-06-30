#ifndef PALABRAS_DEFINED
#define PALABRAS_DEFINED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "palabras.h"
char **texto_a_vector(FILE *archivo);
char * palabra_random(char **vector);

#endif