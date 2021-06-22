#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int main(int Arguments, char * * Argument)
{
	if (Arguments > 2)
	{
		tas Tas;
		
		void * Element;
		void * PremierElement;
		void * DeuxiemeElement;
		
		branche * Branche;
		branche * PremiereBranche;
		branche * DeuxiemeBranche;
		
		symbole * Symbole;
		symbole * PremierSymbole;
		symbole * DeuxiemeSymbole;
		
		char * Chaine;
		
		construire_tas(&Tas, Arguments - 1, comparer_branches);
		
		for (unsigned int i = 1; i < Arguments; i++)
		{
			Branche = malloc(sizeof(branche));
			Symbole = malloc(sizeof(symbole));
			
			Symbole->Caractere = Argument[i][0];
			Symbole->Frequence = atoi(&(Argument[i][1]));
			
			Branche->Valeur = Symbole;
			Branche->Gauche = NULL;
			Branche->Droite = NULL;
			
			inserer_element(&Tas, Branche);
		}
		
		while (Tas.Nombre > 1)
		{
			Branche = malloc(sizeof(branche));
			Symbole = malloc(sizeof(symbole));
			
			retirer_element(&Tas, &PremierElement);
			retirer_element(&Tas, &DeuxiemeElement);
			
			PremiereBranche = (branche *) PremierElement;
			DeuxiemeBranche = (branche *) DeuxiemeElement;
			
			PremierSymbole = (symbole *) PremiereBranche->Valeur;
			DeuxiemeSymbole = (symbole *) DeuxiemeBranche->Valeur;
		
			Symbole->Caractere = '*';
			Symbole->Frequence = PremierSymbole->Frequence + DeuxiemeSymbole->Frequence;
			
			Branche->Valeur = Symbole;
			Branche->Gauche = PremiereBranche;
			Branche->Droite = DeuxiemeBranche;
			
			inserer_element(&Tas, Branche);
		}
		
		retirer_element(&Tas, &Element);
		
		Branche = (branche *) Element;
		
		Chaine = (char *) malloc(sizeof(char) * (Arguments + 1));
		
		imprimer_codes(Branche, Chaine, 0);
		
		free(Chaine);
		
		liberer_branche(Branche);
		
		detruire_tas(&Tas);
		
		return EXIT_SUCCESS;
	}
	else
	{
		fprintf(stderr, "Vous devez spécifier au moins deux arguments.\n");
		
		return EXIT_FAILURE;
	}
}

void afficher_symbole(void * Symbole)
{
	printf("%c : %d\n", ((symbole *) Symbole)->Caractere, ((symbole *) Symbole)->Frequence);
}

void afficher_branche(const branche * Branche, void (*Affichage)(void *))
{
	if (Branche->Gauche == NULL)
	{
		printf("Pas de branche gauche.\n");
	}
	else
	{
		afficher_branche(Branche->Gauche, Affichage);
	}

	Affichage(Branche->Valeur);

	if (Branche->Droite == NULL)
	{
		printf("Pas de branche droite.\n");
	}
	else
	{
		afficher_branche(Branche->Droite, Affichage);
	}
}

int comparer_branches(void * Gauche, void * Droite)
{
	return comparer_symboles(((branche *) Gauche)->Valeur, ((branche *) Droite)->Valeur);
}

int comparer_symboles(void * Gauche, void * Droite)
{
	return ((symbole *) Droite)->Frequence - ((symbole *) Gauche)->Frequence;
}

void imprimer_codes(const branche * Branche, char * Chaine, unsigned int Position)
{
	if (tester_feuille(Branche))
	{
		Chaine[Position] = '\0';
		
		symbole * Symbole = (symbole *) Branche->Valeur;
		
		printf("%c : %s\n", Symbole->Caractere, Chaine);
	}
	else
	{
		Chaine[Position] = '0';
		imprimer_codes(Branche->Gauche, Chaine, Position + 1);
		
		Chaine[Position] = '1';
		imprimer_codes(Branche->Droite, Chaine, Position + 1);
	}
}

void liberer_branche(branche * Branche)
{
	if (Branche->Gauche != NULL)
	{
		liberer_branche(Branche->Gauche);
	}
	
	if (Branche->Droite != NULL)
	{
		liberer_branche(Branche->Droite);
	}
	
	free(((branche *) Branche)->Valeur);
	
	free(Branche);
}
