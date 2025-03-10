#include <stdio.h>

// Définition de la structure dictionnaire
typedef struct dictionnaire {
    char cle[50];  // Clé de recherche
    void* valeur;  // Pointeur vers une valeur
    struct dictionnaire* suivant;  // Pointeur vers le prochain élément
} dictionnaire;

// Fonction pour créer un nouveau dictionnaire
dictionnaire* creerDictionnaire(char* cle, void* valeur) {
    dictionnaire* d = (dictionnaire*)malloc(sizeof(dictionnaire));
    if (d == NULL) {
        printf("Erreur d'allocation mémoire pour le dictionnaire.\n");
        return NULL;
    }
    strcpy(d->cle, cle);
    d->valeur = valeur;
    d->suivant = NULL;
    return d;
}

// Fonction pour ajouter un élément au dictionnaire
void ajouterElement(dictionnaire** head, char* cle, void* valeur) {
    dictionnaire* newNode = creerDictionnaire(cle, valeur);
    if (newNode == NULL) {
        printf("Erreur d'allocation mémoire pour le nouvel élément.\n");
        return;
    }
    newNode->suivant = *head;
    *head = newNode;
}

// Fonction pour rechercher un élément dans le dictionnaire
void* rechercherElement(dictionnaire* head, char* cle) {
    dictionnaire* current = head;
    while (current != NULL) {
        if (strcmp(current->cle, cle) == 0) {
            return current->valeur;
        }
        current = current->suivant;
    }
    return NULL;
}

// Fonction pour afficher le dictionnaire
void afficherDictionnaire(dictionnaire* head) {
    if (head == NULL) {
        printf(" Dictionnaire vide.\n");
        return;
    }
    printf("Dictionnaire :\n");
    dictionnaire* current = head;
    while (current != NULL) {
        printf("➡ Clé: %s | Valeur: %p\n", current->cle, current->valeur);
        current = current->suivant;
    }
}

int main() {
    // Création d'un dictionnaire vide
    dictionnaire* dico = NULL;

    // Ajout de quelques éléments au dictionnaire
    int a = 10;
    float b = 3.14;
    char c = 'X';
    ajouterElement(&dico, "entier", &a);
    ajouterElement(&dico, "reel", &b);
    ajouterElement(&dico, "caractere", &c);

    // Affichage du dictionnaire
    afficherDictionnaire(dico);

    // Recherche d'un élément dans le dictionnaire
    int* entier = (int*)rechercherElement(dico, "entier");
    if (entier != NULL) {
        printf("Valeur de l'entier: %d\n", *entier);
    } else {
        printf("Clé non trouvée.\n");
    }

    return 0;
}