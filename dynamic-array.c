//#include "../CProject.h"
//
//typedef struct {
//	int* tableau;
//	size_t utilisee;   // size_t est unsigned long
//	size_t taille;
//} Tableau;
//
//// a->utilisee est le nombre d'entrees
//
//void initialisationtableau(Tableau* a, size_t tailleinitial) {
//	a->tableau = (int *) malloc(tailleinitial * sizeof(int));
//	a->utilisee = 0;
//	a->taille = tailleinitial;
//}
//
//void insertiontableau(Tableau* a, int element) {
//	// a->tableau[a->utilisee++] on accede a l'element  suivant et on lui affecte l'element.
//	if (a->utilisee == a->taille) {
//		printf("Redimensionnement: taille x2\n");
//		a->taille *= 2;
//		a->tableau = (int *) realloc(a->tableau, a->taille * sizeof(int));
//	}
//	a->tableau[a->utilisee++] = element;
//}
//
//void liberertableau(Tableau* a) {
//	free(a->tableau);
//	a->tableau = NULL;
//	a->utilisee = a->taille = 0;
//}
//
//int main() {
//	Tableau a;
//	int i;
//
//	initialisationtableau(&a, 5);  // initialisation de 5 elements
//	printf("La taille initiale du tableau est %d\n", a.taille);
//	for (i = 0; i < 15; i++) {
//		insertiontableau(&a, i);  // Si necessaire redimensioner le tableau
//		printf("L'index %d et ",i);
//		printf("La taille %d \n", a.taille);
//	}
//	printf("La nouvelle taille du tableau est %d \n", a.utilisee);  // Nombre d'elements
//	liberertableau(&a);
//}