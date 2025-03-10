#include <stdio.h>
#include <stdlib.h>

struct personne;
typedef struct personne {
	int cin;
	struct personne* est_pere_de; // Personne pere; --> syntax erreur
} Personne;

int main() {

	Personne khalid;
	khalid.cin = 80;
	khalid.est_pere_de = NULL;

	Personne* jilali = malloc(sizeof(Personne)); 
	jilali->cin = 12;
	jilali->est_pere_de = &khalid;

	printf("CIN de khalid %d \n", khalid.cin);
	printf("Khalid est le pere de %s \n", khalid.est_pere_de);
	printf("CIN de jilali %d \n", jilali->cin);     // (*jilali).cin
	printf("Jilali est pere de khalid (cin= %d )  \n", jilali->est_pere_de->cin);
	printf("Khalid est le pere de %s  \n", jilali->est_pere_de->est_pere_de);

	free(jilali);

	return 0;
}