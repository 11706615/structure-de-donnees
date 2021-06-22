/*
	Ce code permet de construire et manipuler des tas d'éléments génériques.
	Un tas stocke les éléments de manière ordonnée à l'aide d'une relation d'ordre préalablemment fournie.
	
	Tout pointeur envoyé comme argument d'une fonction doit contenir l'adresse d'une zone mémoire allouée.
	
	@ Andréa Gourion, Adrien Simonnet
*/


// Contient les informations permettant de gérer un tas d'éléments génériques.
typedef struct tas_s
{
	// Taille maximale du tas.
	unsigned int Taille;
	
	// Nombre d'éléments contenus dans le tas.
	unsigned int Nombre;
	
	// Adresse du tableau contenant les pointeurs génériques vers les éléments.
	void * * Element;
	
	// Adresse de la fonction qui détermine une relation d'ordre entre les éléments du tas.
	int (*Ordre)(void *, void *);
} tas;


// Construit un tas.
// Reçoit l'adresse du tas, la taille maximale du tas et un pointeur sur la fonction capable de comparer deux éléments du tas (celle-ci devra retourner Gauche - Droite).
// Retourne 0 si aucune erreur n'est survenue.
int construire_tas(tas *, unsigned int, int (*)(void *, void *));

// Détruit un tas.
// Reçoit l'adresse du tas.
void detruire_tas(tas *);

// Teste le tas et indique s'il est vide.
// Reçoit l'adresse du tas.
// Retourne 1 s'il est vide, sinon 0.
unsigned int tester_tas_vide(const tas *);

// Obtient la position du père d'un élément d'un tas.
// Reçoit l'adresse du tas, la position de l'élément et l'adresse où sera stockée la position du père.
// Retourne 1 si l'élément a un père, 0 sinon.
unsigned int obtenir_pere(const tas *, unsigned int, unsigned int *);

// Obtient la position du fils gauche d'un élément d'un tas.
// Reçoit l'adresse du tas, la position de l'élément et l'adresse où sera stockée la position du fils gauche.
// Retourne 1 si l'élément a un fils gauche, 0 sinon.
unsigned int obtenir_fils_gauche(const tas *, unsigned int, unsigned int *);

// Obtient la position du fils droit d'un élément du tas.
// Reçoit l'adresse du tas, la position de l'élément et l'adresse où sera stockée la position du fils droit.
// Retourne 1 si l'élément a un fils droit, 0 sinon.
unsigned int obtenir_fils_droit(const tas *, unsigned int, unsigned int *);

// Insère un élément à sa place dans le tas en appelant la fonction de relation d'ordre en temps logarithmique en fonction du nombre d'éléments du tas.
// Reçoit l'adresse du tas et l'adresse de l'élément qui sera inséré.
// Retourne le tas après insertion.
tas * inserer_element(tas *, void *);

// Retire l'élément le plus important du tas.
// Reçoit l'adresse du tas et l'adresse où sera stockée l'adresse de l'élément retiré en temps logarithmique en fonction du nombre d'éléments du tas.
// Retourne 0 si aucune erreur n'est survenue.
int retirer_element(tas *, void **);
