/*######################################################################################################

	Author: Samul1
	22.09.2024

########################################################################################################*/

#include "Joukkue.h"
#include<iostream>

// Konstruktori
Joukkue::Joukkue(std::string n)
{
	nimi = n;
}
// Tulostaa joukkueen nimen
void Joukkue::tulosta()
{
	std::cout << "Joukkue: " << nimi << std::endl;
}
// Metodi kysyy käyttäjäntä pelaajan nimen ja pelaaja numeron.
// Sitten tekee shared pointerin pelaajalle ja puskee sitten luodun 
// pelaajan pelaaja vektorille.
// Lopuksi vielä ilmoittaa käyttäjälle, että "pelaaja luotu".
void Joukkue::addPlayer()
{
	std::cin.ignore();
	std::string namePlayer;
	int numPlayer;
	std::cout << "Pelaajan nimi: ";
	std::getline(std::cin, namePlayer);
	
	// käsitellään pelaaja numero ja pyöritään siinä, kunnes
	// saadaan positiivinen pelaaja numero.
	do
	{
		std::cout << "Pelaaja numero: ";
		std::cin >> numPlayer;
		if (numPlayer < 0)
		{
			std::cout << "Pelaajan numeron täytyy olla positiivinen" << std::endl;
			// reset failbit
			std::cin.clear();
			// skip bad input
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			system("pause");
			system("cls");
		}
			
	} while (numPlayer <= 0);
	
	{
		// Luodaan pelaaja shared pointerilla
		std::shared_ptr<Pelaaja> spPlayer(new Pelaaja(namePlayer, numPlayer));
		// Pusketaan pointerin sisältö pelaajat vektorille
		pelaajat.push_back(spPlayer);
	}
	//Infotaan pelaajaa luodusta pelaajasta
	std::cout << "Pelaaja luotu." << std::endl;
	system("pause");
	system("cls");
}
std::string Joukkue::getNimi()
{
	return nimi;
}
// Metodi palauttaa pelaajat vektorin.
std::vector<std::shared_ptr<Pelaaja>> Joukkue::getPelaajat()
{
	return pelaajat;
}
