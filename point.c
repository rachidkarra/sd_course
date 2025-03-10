#include <stdio.h>
#define MAX 5

typedef struct point
{
	int x;
	int y;
} Point;


void afficher_point(Point p) {
	printf("Les coordonnees du point sont [%d, %d] \n", p.x, p.y );
}

Point saisir_point() {
	Point p;
	printf("x = "); scanf("%d", &p.x);
	printf("y = "); scanf("%d", &p.y);
	return p;
}

int main() {
	Point tab_points[MAX];
	int i;
	// Saisie de points
	for (i = 0; i < MAX-1; i++) {
		tab_points[i] = saisir_point();
	}
	// Afficher les points
	for (i = 0; i < MAX-1; i++) {
		afficher_point(tab_points[i]);
	}
		return 0;
	}