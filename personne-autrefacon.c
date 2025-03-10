#include <stdio.h>

struct personne;
typedef struct personne* PtrPersonne;
typedef PtrPersonne Ascendant;
//
struct personne {
	int cin;
	Ascendant pere;
} ;

int main() {
	PtrPersonne khalid;
	PtrPersonne jilali;
    //
	jilali = (PtrPersonne)malloc(sizeof(PtrPersonne)); // en C
	khalid = (PtrPersonne)malloc(sizeof(PtrPersonne)); // en C
	//
	jilali->cin = 12;
	jilali->pere = khalid;
	//
	khalid->cin = 80;
	khalid->pere = NULL;
	//
	printf("CIN de khalid %d \n", khalid->cin);
	printf("CIN de jilali %d \n", jilali->cin);
	printf("Le CIN du pere khalid est %d", jilali->pere->cin);   // On ne peut faire directement ->cin parceque khalid n'ai pas dynamique


	free(jilali);
	free(khalid);

	return 0;
}