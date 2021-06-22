#include "arbre.h"
#include "tas.h"


/*
	L'objectif de ce projet est d'implémenter le codage binaire préfixe d'un ensemble de caractères avec leur respective fréquence d'apparition.
	Ceux-ci seront saisis par l'utilisateur comme arguments du programme sous la forme "LettreFrequence".
	
	Tout pointeur envoyé comme argument d'une fonction doit contenir l'adresse d'une zone mémoire allouée.
	
	@ Andréa Gourion, Adrien Simonnet
*/


// Contient les informations permettant de gérer un symbole.
typedef struct symbole_s
{
	// Variable contenant le caractère.
	char Caractere;
	
	// Variable contenant la fréquence du caractère.
	int Frequence;
} symbole;


// Détermine et affiche les codes binaires des caractères passés en arguments en temps O(Arguments * log(Arguments)).
int main(int, char * *);

// Affiche un symbole dans la console.
// Reçoit l'adresse du symbole.
void afficher_symbole(void *);

// Affiche une branche dans la console en temps linéaire en fonction de la hauteur de l'arbre.
// Reçoit l'adresse de la branche et l'adresse de la fonction qui va afficher le symbole.
void afficher_branche(const branche *, void (*)(void *));

// Compare deux symboles.
// Reçoit l'adresse des deux symboles.
// Retourne la fréquence du deuxième symbole moins la fréquence du premier symbole.
int comparer_symboles(void *, void *);

// Compare deux branches.
// Reçoit l'adresse des deux branches.
// Retourne la comparaison entre le symbole de gauche et celui de la branche de droite.
int comparer_branches(void *, void *);

// Imprime les codes binaires de chaque caractère contenu dans une branche en temps linéaire.
// Reçoit l'adresse de la branche, une chaine de caractère et le rang.
void imprimer_codes(const branche *, char *, unsigned int);

// Libère la mémoire allouée d'une branche en temps linéaire.
// Reçoit l'adresse de la branche.
void liberer_branche(branche *);
