#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>

#define LIST_SIZE 100  // Taille de la liste d'entiers
#define MAX_NUMBER 1000  // Valeur maximale pour les entiers générés

// Fonction qui vérifie si un entier est déjà présent dans la liste
int contains(int *list, int size, int value) {
	for (int i = 0; i < size; i++) {
		if (list[i] == value) {
			return 1;  // l'entier est déjà présent
		}
	}
	return 0;  // l'entier n'est pas présent
}

int main() {
	int list[LIST_SIZE];  // Liste d'entiers
	srand(time(NULL));  // Initialisation du générateur de nombres aléatoires

	// Génération de la liste d'entiers
	for (int i = 0; i < LIST_SIZE; i++) {
		int value;
		do {
			value = rand() % MAX_NUMBER + 1;  // Génère un entier aléatoire entre 1 et MAX_NUMBER
		} while (contains(list, i, value));  // Vérifie si l'entier est déjà présent dans la liste
		list[i] = value;  // Ajoute l'entier à la liste
	}

	// Écriture de la liste dans le fichier
	FILE *f = fopen("liste.txt", "w");  // Ouverture du fichier en mode écriture
	if (f == NULL) {
		printf("Erreur : impossible d'ouvrir le fichier\n");
		return 1;
	}

	for (int i = 0; i < LIST_SIZE; i++) {
		fprintf(f, "%d ", list[i]);  // Écrit l'entier suivi d'un espace dans le fichier
	}

	fclose(f);  // Fermeture du fichier
	printf("La liste a été écrite dans le fichier liste.txt\n");

	return 0;
}
