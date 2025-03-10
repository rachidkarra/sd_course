#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure voiture
typedef struct voiture {
    char modele[50];  // Nom du modèle
    int annee;        // Année de fabrication
    char type[30];    // Type (SUV, berline, sport, etc.)
    float prix;       // Prix en euros
} voiture;

// Définition de la structure noeud (élément de la liste chaînée)
typedef struct noeud {
    void* valeur;         // Pointeur vers une voiture
    struct noeud* suivant;   // Pointeur vers le prochain nœud
} noeud;

// Fonction pour créer une nouvelle voiture
voiture* creerVoiture(char* modele, int annee, char* type, float prix) {
    voiture* v = (voiture*)malloc(sizeof(voiture));
    if (v == NULL) {
        printf("Erreur d'allocation mémoire pour la voiture.\n");
        return NULL;
    }
    strcpy(v->modele, modele);
    v->annee = annee;
    strcpy(v->type, type);
    v->prix = prix;
    return v;
}

// Fonction pour ajouter une voiture à la liste
void ajouterVoiture(noeud** head, voiture* v) {
    noeud* newNode = (noeud*)malloc(sizeof(noeud));
    if (newNode == NULL) {
        printf("Erreur d'allocation mémoire pour le noeud.\n");
        return;
    }
    newNode->valeur = v;
    newNode->suivant = *head;
    *head = newNode;
}

// Fonction pour afficher la liste des voitures
void afficherListe(noeud* head) {
    if (head == NULL) {
        printf(" Aucune voiture enregistrée.\n");
        return;
    }
    printf("Liste des voitures :\n");
    noeud* current = head;
    while (current != NULL) {
        voiture* v = current->valeur;
        printf(" Modèle: %s | Année: %d | Type: %s | Prix: %.2fdh\n",
               v->modele, v->annee, v->type, v->prix);
        current = current->suivant;
    }
}

// Fonction pour supprimer une voiture selon son modèle
void supprimerVoiture(noeud** head, char* modele) {
    noeud* current = *head;
    noeud* prev = NULL;

    while (current != NULL) {
        if (strcmp(((voiture*)current->valeur)->modele, modele) == 0) {
            if (prev == NULL) { // Suppression en tête
                *head = current->suivant;
            } else {
                prev->suivant = current->suivant;
            }
            free(current->valeur); // Libérer la voiture
            free(current);         // Libérer le nœud
            printf("Voiture \"%s\" supprimée avec succès !\n", modele);
            return;
        }
        prev = current;
        current = current->suivant;
    }
    printf(" Modèle \"%s\" introuvable dans la liste.\n", modele);
}

// Fonction pour libérer toute la liste et éviter les fuites mémoire
void libererListe(noeud* head) {
    noeud* current = head;
    while (current != NULL) {
        noeud* temp = current;
        free(current->valeur); // Libérer la structure voiture
        current = current->suivant;
        free(temp); // Libérer le nœud
    }
}

// 
int main() {
    noeud* head = NULL; // Liste vide

    // Ajout de quelques voitures
    ajouterVoiture(&head, creerVoiture("BYD", 2022, "Électrique", 69999.99));
    ajouterVoiture(&head, creerVoiture("BMW X5", 2021, "SUV", 75000.00));
    ajouterVoiture(&head, creerVoiture("Renault Clio", 2019, "Citadine", 15000.00));

    // Affichage initial
    afficherListe(head);

    // Suppression d'une voiture
    printf("\n Suppression d'un véhicule...\n");
    supprimerVoiture(&head, "BMW X5");

    // Affichage après suppression
    afficherListe(head);

    // Libération de la mémoire avant de quitter
    libererListe(head);
    return 0;
}
