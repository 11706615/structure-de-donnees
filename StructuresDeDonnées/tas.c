#include <stdlib.h>

#include "tas.h"

int construire_tas(tas * Tas, unsigned int Taille, int (*Ordre)(void *, void *))
{
	if ((Tas->Element = (void * *) malloc(sizeof(void *) * Taille)) == NULL)
	{
		Tas->Taille = 0;
		Tas->Nombre = 0;
		Tas->Ordre = NULL;
		
		return 1;
	}
	else
	{
		Tas->Taille = Taille;
		Tas->Nombre = 0;
		Tas->Ordre = Ordre;
		
		return 0;
	}
}

void detruire_tas(tas * Tas)
{
	free(Tas->Element);
	
	Tas->Taille = 0;
	Tas->Nombre = 0;
	Tas->Ordre = NULL;
}

unsigned int tester_tas_vide(const tas * Tas)
{
	if (Tas->Nombre == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

unsigned int obtenir_pere(const tas * Tas, unsigned int Fils, unsigned int * Pere)
{
	if (Fils > 0)
	{
		*Pere = 0.5 * (Fils - 1);
		
		return 1;
	}
	else
	{
		return 0;
	}
}

unsigned int obtenir_fils_gauche(const tas * Tas, unsigned int Pere, unsigned int * Fils)
{
	if (2 * Pere + 1 < Tas->Nombre)
	{
		*Fils = 2 * Pere + 1;
		
		return 1;
	}
	else
	{
		return 0;
	}
}

unsigned int obtenir_fils_droit(const tas * Tas, unsigned int Pere, unsigned int * Fils)
{
	if (2 * Pere + 2 < Tas->Nombre)
	{
		*Fils = 2 * Pere + 2;
		
		return 1;
	}
	else
	{
		return 0;
	}
}

tas * inserer_element(tas * Tas, void * Element)
{
	if (Tas->Nombre < Tas->Taille)
	{
		unsigned int Fils = Tas->Nombre, Pere;
		
		Tas->Element[Fils] = Element;
		
		while (obtenir_pere(Tas, Fils, &Pere) && Tas->Ordre(Tas->Element[Pere], Element) < 0)
		{
			void * NouvelElement = Tas->Element[Fils];
			Tas->Element[Fils] = Tas->Element[Pere];
			Tas->Element[Pere] = NouvelElement;
			
			Fils = Pere;
		}
		
		Tas->Nombre++;
	}
	
	return Tas;
}

int retirer_element(tas * Tas, void * * Element)
{
	if (Tas->Nombre > 0)
	{
		unsigned int Fils, FilsGauche, FilsDroit, Pere = 0;
		
		*Element = Tas->Element[0];
		
		Tas->Element[0] = Tas->Element[--Tas->Nombre];
		
		while (obtenir_fils_gauche(Tas, Pere, &FilsGauche))
		{
			if (obtenir_fils_droit(Tas, Pere, &FilsDroit) && Tas->Ordre(Tas->Element[FilsGauche], Tas->Element[FilsDroit]) < 0)
			{
				Fils = FilsDroit;
			}
			else
			{
				Fils = FilsGauche;
			}
			
			if (Tas->Ordre(Tas->Element[Pere], Tas->Element[Fils]) < 0)
			{
				void * NouvelElement = Tas->Element[Fils];
				Tas->Element[Fils] = Tas->Element[Pere];
				Tas->Element[Pere] = NouvelElement;
				
				Pere = Fils;
			}
			else
			{
				break;
			}
		}
		
		return 0;
	}
	else
	{
		return 1;
	}
}
