#include <stdlib.h>

#include "arbre.h"

unsigned int tester_feuille(const branche * Branche)
{
	if (Branche->Gauche == NULL && Branche->Droite == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
