/*######################################################################################################

	Author: Samul1
	09.12.2023

########################################################################################################*/

#include "Ostoslista.h"
#include "Ostos.h";
#include <iostream>
#include <fstream>

// Konstruktori:
Ostoslista::Ostoslista(std::string tn)
{
	tiedosto_nimi = tn;
}

// Destruktori:
Ostoslista::~Ostoslista()
{
	// Tyhjennet‰‰n ostosVektori:
	for (int i = 0; i < ostosVektori.size(); i++)
	{
		delete ostosVektori[i];
	}
	// Tyhjent‰‰ vektorin, koko: 0
	ostosVektori.clear();
}

// N‰ytet‰‰n p‰‰valikko:
void Ostoslista::n‰yt‰P‰‰valikko(Ostoslista lista)
{
	// Tyhjennet‰‰n p‰‰ohjelman alkutekstit:
	system("cls");
	// Alustetaan muuttujat:
	int tarkistus = 0;
	int k‰ytt‰j‰nValinta;
	// P‰‰valikon silmukka alkaa t‰st‰:
	do 
	{
		std::cout << "1) Tulosta ostoslista" << std::endl;
		std::cout << "2) Lis‰‰ uusi ostos" << std::endl;
		std::cout << "3) Tyhjenn‰ lista" << std::endl;
		std::cout << "4) Tallenna ostoslista" << std::endl;
		std::cout << "0) Lopeta ohjelma" << std::endl;
		std::cin >> k‰ytt‰j‰nValinta;
		switch (k‰ytt‰j‰nValinta)
		{
		// Jos K‰ytt‰j‰ haluaa tulostaa ostoslistan sis‰llˆn:
		case 1:
			system("cls");
			tulostaOstokset();
			system("pause");
			system("cls");
			break;
		// Jos k‰ytt‰j‰ haluaa lis‰t‰ uuden ostoksen:
		case 2:
			system("cls");
			lis‰‰UusiOstos();
			system("pause");
			system("cls");
			break;
		// Jos k‰ytt‰j‰ haluaa tyhjent‰‰ ostoslistan sis‰llˆn:
		case 3:
			system("cls");
			tyhjenn‰Lista();
			system("pause");
			system("cls");
			break;
		// Jos k‰ytt‰j‰ haluaa tallentaa ostosVektorin sis‰llˆn kauppalista.txt-tiedostoon:
		case 4:
			system("cls");
			tallennaTiedostoon();
			system("pause");
			system("cls");
			break;
		// Jos k‰ytt‰j‰ haluaa poistua ohjelmasta:
		case 0:
			system("cls");
			tarkistus = 1;	// Lopettaa silmukan.
			break;
		// Jos k‰ytt‰j‰ antaa jonkin muun syˆtteen:
		default:
			std::cout << "Tarkista syˆte" << std::endl;
			system("pause");
			system("cls");
			break;
		}
	} while (tarkistus == 0);
}

// Tulostaa ostosVektorin sis‰llˆn:
void Ostoslista::tulostaOstokset()
{
	// K‰yd‰‰n for-silmukalla l‰pi ostosVektori:n sis‰ltˆ:
	for (int i = 0; i < ostosVektori.size(); i++)
		// Kutsutaan tulosta metodia:
		ostosVektori[i]->tulosta();
}

// Kysyy uuden ostoksen tiedot ja lis‰‰ sen ostosVektorille:
void Ostoslista::lis‰‰UusiOstos()
{
	// Alustetaan muuttujat:
	std::string nimi = "";
	int kplM‰‰r‰;
	// Kysyt‰‰n k‰ytt‰j‰lt‰ tuotteen nimi:
	std::cout << "Tuote: ";
	std::cin >> nimi;
	do
	{	// Silmukan suoritus alkaa t‰st‰:
		// Kysyt‰‰n k‰ytt‰j‰lt‰ kpl-m‰‰r‰:
		std::cout << "KPL m‰‰r‰: ";
		std::cin >> kplM‰‰r‰;
		// Jos kpl-m‰‰r‰ on v‰hemm‰n kuin 0:
		if (kplM‰‰r‰ <= 0)
		{	// Niin n‰ytet‰‰n viesti:
			system("cls");
			std::cout << "Kappale m‰‰r‰ ei voi olla negatiivinen tai nolla." << std::endl;
		}
		// Suoritetaan niin kauan kuin kpl-m‰‰r‰ on enemm‰n kuin 0:
	} while (kplM‰‰r‰ <= 0);

	// Tallennetaan uusi ostos ja pusketaan se ostosVektoriin:
	Ostos* ostos = new Ostos(nimi, kplM‰‰r‰);
	ostosVektori.push_back(ostos);

}

// Tyhjent‰‰ kauppalista.txt tiedoston ja ostosVektorin:
void Ostoslista::tyhjenn‰Lista()
{
	// Avaa tiedoston uudelleen kirjoitettavaksi ja samalla tyhjent‰‰ edellisen tekstin:
	std::ofstream myFile("kauppalista.txt", std::ofstream::trunc);
	std::cout << "Tyhjennet‰‰n ostoslistaa..." << std::endl;
	std::cout << "Valmis." << std::endl;
	// Suljetaan tiedosto:
	myFile.close();
	// Tyhjennet‰‰n ostosVektori:
	for (int i = 0; i < ostosVektori.size(); i++)
	{
		delete ostosVektori[i];
	}
	// Tyhjent‰‰ vektorin, koko: 0
	ostosVektori.clear();	
}

// Hakee tallennetun kauppalistan sis‰llˆn ja tallentaa sen ostosVektoriin:
void Ostoslista::lueTiedosto()
{
	// Alustetaan muuttujat:
	std::string nimi;
	std::string kplM‰‰r‰;
	std::ifstream myFile;
	// Avataan tiedosto johon kirjoitetaan:
	myFile.open("kauppalista.txt");

	// Jos tiedosto on olemassa:
	if (myFile)
	{
		std::cout << "Haetaan ostoslistaa..." << std::endl;
		// Katsotaan tiedostoon, jos loppu ei ole saavutettu:
		while (myFile.peek() != EOF)
		{
			// Haetaan tiedostosta nimi ja kplm‰‰r‰:
			std::getline(myFile, nimi);
			std::getline(myFile, kplM‰‰r‰);
			// Tallennetaan haetut tiedot ostosVektoriin:
			Ostos* ostos = new Ostos(nimi, stoi(kplM‰‰r‰));
			ostosVektori.push_back(ostos);
		}
		std::cout << "Valmis" << std::endl;
		// Suljetaan tiedosto:
		myFile.close();
	}
	// N‰ytet‰‰n viesti, jos tiedostoa ei voitu avata:
	else
		std::cout << "Tiedostoa ei voitu avata." << std::endl;
}

// Talentaa ostoslistan sis‰llˆn Kauppalista.txt-tiedostoon:
void Ostoslista::tallennaTiedostoon()
{
	// Avaa kauppalista.txt -tiedoston (out)kirjoitusmoodissa ja (app)laittaa kursorin tekstitiedoston loppuun:
	std::ofstream myFile("kauppalista.txt", std::ifstream::out | std::ifstream::app);
	// Jos tiedosto on olemassa:
	if (myFile)
	{
		// Jos ostosVectori:n koko on nolla, eli se on tyhj‰:
		if (ostosVektori.size() == 0)
			std::cout << "Ostoslista on tyhj‰." << std::endl;
		// Muuten:
		else	
		{
			// Kirjoitetaan ostosVektorin sis‰ltˆ tiedostoon:
			std::cout << "Kirjoitetaan tiedostoon..." << std::endl;
			for (int i = 0; i < ostosVektori.size(); i++)
			{
				myFile << ostosVektori[i]->haeNimi() << std::endl;
				myFile << ostosVektori[i]->haeKplm‰‰r‰() << std::endl;
			}
		}
		// Suljetaan tiedosto:
		myFile.close();
		std::cout << "Valmis." << std::endl;
	}
	// Jos tiedostoa ei voi avata:
	else
		std::cout << "Tiedostoa ei voitu avata." << std::endl;
}
