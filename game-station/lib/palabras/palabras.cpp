#include "palabras.h"
#define dim 50

char **texto_a_vector(FILE *archivo)
{
	char *linea = (char *)malloc(dim * sizeof(char));
	char **vector = (char**)malloc(sizeof(char *));
	int dimVector = 0;
	FILE *palabras = fopen("./palabras.txt", "r");
	if (!palabras)
		return NULL;

	fgets(linea, dim, palabras);
	while (!feof(palabras))
	{
		realloc(vector, sizeof(char *)); // agrando el vector para que entre un string mas
		vector[dimVector] = (char *)malloc(dim * sizeof(char)); // reservo espacio para la nueva string
		dimVector++;
		fgets(linea, dim, palabras);
	}
	return vector;
}

// funcion para debug
char* palabra_random(char **vector)
{
	srand(time(NULL));
	return vector[rand()];
}