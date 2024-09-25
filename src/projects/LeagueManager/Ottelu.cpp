/*######################################################################################################

	Author: Samul1
	22.09.2024

########################################################################################################*/

#include "Ottelu.h"
#include<iostream>

std::string Ottelu::getKotiJoukkue()
{
	std::shared_ptr<Joukkue> shrPtr1 = kotiJoukkue.lock();
	return shrPtr1->getNimi();
}

std::string Ottelu::getVierasJoukkue()
{
	std::shared_ptr<Joukkue> shrPtr1 = vierasJoukkue.lock();
	return shrPtr1->getNimi();
}

void Ottelu::tulosta()
{
	std::shared_ptr<Joukkue> shrPtr1 = kotiJoukkue.lock();
	std::cout << "Kotijoukkue: " << shrPtr1->getNimi() << " Pisteet: " << kotiJoukkuePisteet << " , ";
	shrPtr1.reset();
	shrPtr1 = vierasJoukkue.lock();
	std::cout << "Vierasjoukkue: " << shrPtr1->getNimi() << " Pisteet: " << vierasJoukkuePisteet << std::endl;
}
