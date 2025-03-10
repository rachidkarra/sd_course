#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 50

// Définition de la structure dictionnaire
typedef struct dictionnaire {
    char cle[50];  // Clé de recherche
    void* valeur;  // Pointeur vers une valeur
    struct dictionnaire* suivant; // Pointeur vers le prochain élément (pour le chaînage)
} dictionnaire;

// Définition de la table de hachage
dictionnaire* table[TABLE_SIZE];

// Fonction de hachage
unsigned int hash(char* cle) {
    unsigned int hash = 0;
    // Décalage de bits vers la gauche de 5 positions
    // et ajout de la valeur ASCII du caractère
    while (*cle) {
        hash = (hash << 5) + *cle++;
    }
    return hash % TABLE_SIZE;
}

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
void ajouterElement(char* cle, void* valeur) {
    unsigned int index = hash(cle);
    dictionnaire* newNode = creerDictionnaire(cle, valeur);
    if (newNode == NULL) {
        printf("Erreur d'allocation mémoire pour le nouvel élément.\n");
        return;
    }
    if (table[index] == NULL) {
        table[index] = newNode;
    } else {
        dictionnaire* current = table[index];
        while (current->suivant != NULL) {
            current = current->suivant;
        }
        current->suivant = newNode;
    }
}

// Fonction pour rechercher un élément dans le dictionnaire
void* rechercherElement(char* cle) {
    unsigned int index = hash(cle);
    dictionnaire* current = table[index];
    while (current != NULL) {
        if (strcmp(current->cle, cle) == 0) {
            return current->valeur;
        }
        current = current->suivant;
    }
    return NULL;
}

// Fonction pour afficher le dictionnaire
void afficherDictionnaire() {
    printf("Dictionnaire :\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        dictionnaire* current = table[i];
        while (current != NULL) {
            printf(" Clé: %s | Valeur: %p\n", current->cle, current->valeur);
            current = current->suivant;
        }
    }
}

int main() {
    // Initialisation de la table de hachage
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }

    // Ajout de quelques éléments au dictionnaire
    int a = 10;
    float b = 3.14;
    char c[50] = "Xffff";
    ajouterElement("entier", &a);
    ajouterElement("reel", &b);
    ajouterElement("string", &c);

    // Affichage du dictionnaire
    afficherDictionnaire();

    // Recherche d'un élément dans le dictionnaire
    int* entier = (int*)rechercherElement("entier");
    if (entier != NULL) {
        printf("Valeur de l'entier: %d\n", *entier);
    } else {
        printf("Clé non trouvée.\n");
    }

    return 0;
}