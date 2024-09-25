/*######################################################################################################

	Author: Samul1
	09.12.2023

########################################################################################################*/

#include "Ostos.h"
#include "Ostoslista.h"
#include <iostream>

// Konstruktori:
Ostos::Ostos(std::string n, int kpl)
{
	nimi = n;
	kplm‰‰r‰ = kpl;
}

Ostos::~Ostos()
{
}

// Tulostaa tuotteen tiedot(nimi kplm‰‰r‰):
void Ostos::tulosta()
{
	std::cout << nimi << " " << kplm‰‰r‰ << " kpl." << std::endl;
}

std::string Ostos::haeNimi()
{
	return nimi;
}

int Ostos::haeKplm‰‰r‰()
{
	return kplm‰‰r‰;
}
