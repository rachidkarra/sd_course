#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "noeud.h"

noeud* initialiser_liste(void) {
	return(NULL);
}

void afficher_liste(noeud* n) {
	while (n != NULL) {
		printf("%d -> ", n->valeur);
		n = n->suivant;
	}
	printf("\n");
}


int longueur_liste(noeud* l) {  //recursive
	if (l == NULL) {
		return 0;
	}
	else {
		return 1 + longueur_liste(l->suivant);
	}
}


// Insertion au debut de la liste
void insertion_debut_liste(noeud** l, int x) {
	noeud* p;
	p = malloc(sizeof(noeud));
	p->valeur = x;
	p->suivant = *l;
	*l = p;        /* p prend la t�te de la liste*/
}

void insertion_fin_liste(noeud** l, int x)
{
	//creer un nouveau noeud
	noeud* nouveauNoeud = malloc(sizeof(noeud));
	nouveauNoeud->valeur = x;
	nouveauNoeud->suivant = NULL;
	//Si la tete est NULL, c'est que la liste est vide
	if (*l == NULL)
		*l = nouveauNoeud;
	//Sinon, trouver le dernier element et ajoute le nouveau noeud
	else
	{
		struct noeud* dernierNode = *l;
		//l'adresse suivante du dernier noeud sera NULL.
		while (dernierNode->suivant != NULL)
		{
			dernierNode = dernierNode->suivant;
		}
		//ajouter le nouveauNoeud a la fin de la liste chainee
		dernierNode->suivant = nouveauNoeud;
	}
}

noeud* recherche_liste(noeud* l, int x) {
	if (l == NULL) {
		return(NULL);
	}

	if (l->valeur == x) {
		return(l);
	}
	else {
		return(recherche_liste(l->suivant, x));
	}
}

noeud* noeud_preced(noeud* l, noeud* x) {       // Le predecesseur du noeud x de la liste l
	if ((l == NULL) || (l->suivant == NULL)) {
		return(NULL);
	}
	if ((l->suivant) == x) {
		return(l);
	}
	else {
		return(noeud_preced(l->suivant, x));
	}
}

void supprimer_liste(noeud** l, noeud** x) {
	noeud* p; /* item pointer */
	noeud* pred;   /* pointeur du predecesseur */
	p = *l;
	pred = noeud_preced(*l, *x);
	if (pred == NULL) { /* le predecesseur n'existe pas: Debut de la liste */
		*l = p->suivant;
	}
	else {
		pred->suivant = (*x)->suivant;
	}
	free(*x); /* liberation */
}

void supprimer_dernier(noeud** l) {

	if (*l != NULL) {

		//Si la liste chainee ne contient qu'un seul element, on le libere
		if ((*l)->suivant == NULL) {
			*l = NULL;
		}
		else {

			//Aller jusqu'au "second dernier" element
			noeud* temp = *l;
			while (temp->suivant->suivant != NULL)
				temp = temp->suivant;

			//Rendre le "second dernier" element le dernier et liberer le dernier  
			noeud* dernierNoeud = temp->suivant;
			temp->suivant = NULL;
			free(dernierNoeud);
		}
	}
}

int main() {
	char c;
	int d;
	noeud* l;
	noeud* tmp;
	l = initialiser_liste();
	printf("Entrez: \n 'i' pour ajouter un element, \n 'd' pour retirer un element, \n 'l' pour afficher la longueur de la liste,\n 'a' pour afficher la liste\n 'r' pour rechercher un element\n 's' pour supprimer un element\n");
	
	while (scanf_s("%c", &c) != EOF) {

		if (tolower(c) == 'a') {
			afficher_liste(l);
		}

		if (tolower(c) == 'i') {
			scanf_s("%d", &d);
			printf("nouveau element: %d\n", d);
			insertion_debut_liste(&l, d);
		}

		if (tolower(c) == 'l') {
			int x = longueur_liste(l);
			printf("La longueur est : %d\n", x);
		}

		if (tolower(c) == 'd') {
			supprimer_dernier(&l);
			printf("Dernier element supprimer. \n");
		}

		if (tolower(c) == 'r') {
			scanf_s("%d", &d);
			tmp = recherche_liste(l, d);
			if (tmp == NULL) {
				printf("element %d non trouve\n", d);
			}
			else {
				printf("element %d trouve\n", d);
			}
		}

		if (tolower(c) == 's') {
			scanf_s("%d", &d);
			tmp = recherche_liste(l, d);
			if (tmp == NULL) {
				printf("L'element %d n'est pas trouve\n", d);
			}
			else {
				supprimer_liste(&l, &tmp);
				printf("element %d supprime\n", d);
			}
		}
	}

	return 0;
}