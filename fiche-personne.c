#include "../CProject.h"
#define MAX_FICHES 10

typedef struct fiche {
	char nom[50];
	char prenom[50];
	int age;
}Fiche;
Fiche T[MAX_FICHES];

void saisir() {
	int termine = 0;
	int i = 0;
	char reponse;
	while (!termine) {
		printf("Vous voulez saisir une nouvelle fiche? y/n: ");
		scanf(" %c", &reponse);
		if (reponse == 'y') {
			printf("Nom = "); scanf("%s", &T[i].nom);
			printf("Prenom = "); scanf("%s", &T[i].prenom);
			printf("Age = "); scanf("%d", &T[i].age);
			i++;
			termine = 0;
		}
		else {
			termine = 1;
			printf("Merci pour votre passage \n");
		}
	}
}
void afficher() {
	int i;
	for (i= 0; i < MAX_FICHES;i++) {
		printf("Nom = %s, Prenom = %s, Age = %d \n", T[i].nom, T[i].prenom, T[i].age);
	}
}

//int main() {
//	saisir();
//	afficher();
//}
