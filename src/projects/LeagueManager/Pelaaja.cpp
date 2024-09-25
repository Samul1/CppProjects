/*######################################################################################################

	Author: Samul1
	22.09.2024

########################################################################################################*/

#include "Pelaaja.h"
#include<iostream>

// Konstruktori
Pelaaja::Pelaaja(std::string n, int pn)
{
	nimi = n;
	pelinumero = pn;
}

// Tulostaa pelaajan nimen ja pelaajanumeron
void Pelaaja::tulosta()
{
	std::cout << "Nimi: " << nimi << " Pelaajanumero: " << pelinumero << std::endl;
}
