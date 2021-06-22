/*
	Ce code permet de construire et manipuler des arbres d'éléments génériques.
	
	Tout pointeur envoyé comme argument d'une fonction doit contenir l'adresse d'une zone mémoire allouée.
	
	@ Andréa Gourion, Adrien Simonnet
*/


// Contient les informations permettant de gérer une branche d'éléments génériques.
typedef struct branche_s
{
	// Pointeur générique vers un élément.
	void * Valeur;
	
	// Adresse de la sous-branche gauche.
	struct branche_s * Gauche;
	
	// Adresse de la sous-branche droite.
	struct branche_s * Droite;
} branche;


// Teste la branche et indique s'il s'agit d'une feuille.
// Reçoit l'adresse de la branche.
// Retourne 1 si la branche est une feuille, sinon 0.
unsigned int tester_feuille(const branche *);
