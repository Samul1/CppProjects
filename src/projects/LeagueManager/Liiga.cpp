/*######################################################################################################

	Author: Samul1
	22.09.2024

########################################################################################################*/

#include "Liiga.h"
#include "Joukkue.h"
#include"Pelaaja.h"
#include<iostream>
#include<string>
#include<vector>
#include<memory>

// Kostructori
Liiga::Liiga(std::string n)
{
}

// P��ohjelma.
bool Liiga::p��Valikko(std::string liigaNimi)
{
	// Muuttujien esittely
	bool end = false;
	int k�ytt�j�Valinta = 0;
	// silmukka py�rii kunnes exit == true
	while (end == false)
	{
		do
		{
			std::cout << " --------- " << liigaNimi << " -------- - " << std::endl;
			std::cout << " 1. Lis�� joukkue" << std::endl;
			std::cout << " 2. Lis�� pelaaja" << std::endl;
			std::cout << " 3. Lis�� ottelu" << std::endl;
			std::cout << " 4. Joukkue info" << std::endl;
			std::cout << " 5. Pelaaja info" << std::endl;
			std::cout << " 6. Ottelu info" << std::endl;
			std::cout << " 0. Exit" << std::endl;
			std::cin >> k�ytt�j�Valinta;
			// tarkistetaan sy�te
			if(k�ytt�j�Valinta < 0 || k�ytt�j�Valinta > 7)
			{
				std::cout << "Tarkista sy�te." << std::endl;
				// reset failbit
				std::cin.clear();
				// skip bad input
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				system("pause");
				system("cls");
			}
		} while (k�ytt�j�Valinta < 0 && k�ytt�j�Valinta > 7);
		
		system("cls");
		switch (k�ytt�j�Valinta)
		{
		case 1:
			addTeam();
			break;
		case 2:
			addPlayer();
			system("pause");
			break;
		case 3:
			addTurnament();
			system("pause");
			break;
		case 4:
			getInfo(k�ytt�j�Valinta);
			system("pause");
			break;
		case 5:
			getInfo(k�ytt�j�Valinta);
			system("pause");
			break;
		case 6:
			getInfo(k�ytt�j�Valinta);
			system("pause");
			break;
			break;
		case 0:
			end = true;
		default:
			break;
		}
		
		system("cls");
	}

	

	return end;
}

// Metodi ottaa vastaan parametrina integer arvon p��Valikko metodista
// ja sen avulla valitsee tulostukseen, joko joukkueet tai sitten pelaajat.
void Liiga::getInfo(int valinta)
{
	// Luodaan shared pointer ja osoitetaan sill� joukkueet vektorille
	std::vector<std::shared_ptr<Joukkue>> shrPtr1 = joukkueet;
	// Luodaan unique pointer ja osoitetaan sill� ottelut vektorille
	std::vector<std::unique_ptr<Ottelu>>& uqPtr1 = ottelut;

	// Jos k�ytt�j� valitsi joukkueet
	if (valinta == 4)
	{
		// K�yd��n l�pi pointerin sis�lt�
		for (unsigned i = 0; i < shrPtr1.size(); i++)
			// tulostetaan joukkue
			shrPtr1.at(i)->tulosta();
	}

	// Jos k�ytt�j� valitsi pelaajat
	else if (valinta == 5)
	{
		// Pelaaja info
		int valinta;
		size_t koko = shrPtr1.size();
		if(!shrPtr1.empty())
		{
			do
			{
				// K�ytt�j� saa valita joukkueen, jota haluaa tarkastella
				std::cout << "Valitse joukkue" << std::endl;
				// Tulostetaan kaikki joukkueet
				for (unsigned i = 0; i < koko; i++)
				{
					std::cout << i + 1 << ". ";
					shrPtr1.at(i)->tulosta();
				}
				std::cin >> valinta;
				// tarkistetaan sy�te
				if (valinta < 0 || valinta > koko)
				{
					std::cout << "Tarkista sy�te." << std::endl;
					// reset failbit
					std::cin.clear();
					// skip bad input
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					system("pause");
					system("cls");
				}
			} while (valinta < 0 && valinta > koko);
			system("cls");

			// P�ivitet��n koko
			koko = shrPtr1.at(valinta - 1)->getPelaajat().size();

			shrPtr1.at(valinta - 1)->tulosta();
			for (unsigned j = 0; j < koko; j++)
				// Tulostetaan joukkueen pelaajat
				shrPtr1.at(valinta - 1)->getPelaajat().at(j)->tulosta();

			std::cout << std::endl;
		}
	}
	
	// Jos k�ytt�j� valitsi ottelut
	else if (valinta == 6)
	{
		int valinta;
		size_t koko = uqPtr1.size();
		if (!uqPtr1.empty())
		{
			do
			{
				// K�ytt�j� saa valita joukkueen, jota haluaa tarkastella
				std::cout << "Valitse ottelu" << std::endl;
				// Tulostetaan kaikki joukkueet
				for (unsigned i = 0; i < koko; i++)
				{
					std::cout << i + 1 << ". ";
					uqPtr1.at(i)->tulosta();
				}
				std::cin >> valinta;
				// tarkistetaan sy�te
				if (valinta < 0 || valinta > koko)
				{
					std::cout << "Tarkista sy�te." << std::endl;
					// reset failbit
					std::cin.clear();
					// skip bad input
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					system("pause");
					system("cls");
				}
			} while (valinta < 0 && valinta > koko);
			system("cls");

			std::cout << "Ottelu historia: " << std::endl;
			std::cout << std::endl;
			for (unsigned i = 0; i < koko; i++)
			{
				uqPtr1.at(0)->tulosta();
				std::cout << std::endl;
			}


		}
		else
		{
			std::cout << "Otteluita ei l�ydetty" << std::endl;
			system("pause");
		}

	}
		
	
	else
		std::cout << "Miten p��dyit t�nne?";
}

// Lis�t��n tiimi liigaan
void Liiga::addTeam()
{
	std::string nimiJoukkue;
	int m��r�Pelaajat = -1;
	std::cin.ignore();
	// Kysyt��n k�ytt�j� sy�te
	std::cout << "Sy�t� joukkueen nimi: ";
	std::getline(std::cin, nimiJoukkue);

	// Luodaan joukkue shared pointerilla
	std::shared_ptr<Joukkue> spJoukkue(new Joukkue(nimiJoukkue));

	// Py�rit��n silmukassa kunnes k�ytt�j� sy�tt�� positiivisen pelaajam��r�n
	// ja tekee pelaajat
	while (m��r�Pelaajat < 0)
	{
		std::cout << "Sy�t� pelaajien m��r�: ";
		std::cin >> m��r�Pelaajat;
		if (m��r�Pelaajat > 0)
		{
			// Lis�t��n pelaajat
			for(int i = 0; i < m��r�Pelaajat; i++)
				spJoukkue->addPlayer();
		}
		else
			std::cout << "Pelaajia t�ytyy olla v�hint��n yksi." << std::endl;
	}
	
	

	// Pusketaan pointerin sis�lt� joukkueet vektorille
	joukkueet.push_back(spJoukkue);

	// Infotaan k�ytt�j��
	std::cout << "Joukkue lis�tty." << std::endl;
	system("pause");
	system("cls");

}

// Metodi lis�� pelaaja-olion k�ytt�j�n valitsemaan joukkueeseen.
void Liiga::addPlayer()
{
	// Luodaan shared pointer ja osoitetaan sill� joukkueet vektorille
	std::vector<std::shared_ptr<Joukkue>> shrPtr1 = joukkueet;
	int valinta;
	size_t koko = shrPtr1.size();
	
	if (shrPtr1.empty())
		std::cout << "Joukkueita ei l�ydetty." << std::endl;
	else
	{
		do
		{
			// K�ytt�j� saa valita joukkueen, jota haluaa tarkastella
			std::cout << "Valitse joukkue" << std::endl;
			// Tulostetaan kaikki joukkueet
			for (unsigned i = 0; i < koko; i++)
			{
				std::cout << i + 1 << ". ";
				shrPtr1.at(i)->tulosta();
			}
			std::cin >> valinta;
			// tarkistetaan sy�te
			if (valinta < 0 || valinta > koko)
			{
				std::cout << "Tarkista sy�te." << std::endl;
				// reset failbit
				std::cin.clear();
				// skip bad input
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				system("pause");
				system("cls");
			}
		} while (valinta < 0 && valinta > koko);
		system("cls");

		shrPtr1.at(valinta - 1)->addPlayer();
	}
	
}
// Metodi tarkistaa onko v�hint��n kaksi joukkuetta kirjattu
// ohjelmaan ja jos on, kysyy kotijoukkueen ja pisteet.
// Sitten kysyy vierasjoukkueen ja pisteet.
// Lopuksi tallentaa uuden ottelun ottelut-vektorille.
void Liiga::addTurnament()
{
	// Tarvitaan joukkueet vektoria
	// joukkueiden pisteet

	int kotiPisteet = 0;
	int vierasPisteet = 0;

	// Tarkistetaan onko joukkueita
	std::vector<std::shared_ptr<Joukkue>> shrPtr1 = joukkueet;
	int valinta1;
	int valinta2;
	size_t koko = shrPtr1.size();

	// Weak pointerit
	std::shared_ptr<Joukkue> kotiJoukkue;
	std::shared_ptr<Joukkue> vierasJoukkue;

	// Jos ei ole joukkueita
	if (shrPtr1.empty())
		std::cout << "Joukkueita ei l�ydetty." << std::endl;
	// Jos on v�hemm�n kuin kaksi joukkuetta
	else if (shrPtr1.size() < 2)
		std::cout << "Joukkueita tarvitaan v�hint��n kaksi." << std::endl;
	// Muuten
	else
	{
		size_t koko = shrPtr1.size();
		// K�ytt�j� valitsee kotijoukkueen
		do
		{
			// K�ytt�j� saa valita joukkueen, jota haluaa tarkastella
			std::cout << "Valitse kotijoukkue" << std::endl;

			// Tulostetaan kaikki joukkueet
			for (unsigned i = 0; i < koko; i++)
			{
				std::cout << i + 1 << ". ";
				shrPtr1.at(i)->tulosta();
			}
			std::cin >> valinta1;
			
			// tarkistetaan sy�te
			if (valinta1 < 0 || valinta1 > koko)
			{
				std::cout << "Tarkista sy�te." << std::endl;
				// reset failbit
				std::cin.clear();
				// skip bad input
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				system("pause");
				system("cls");
			}
			else
			{
				kotiJoukkue = shrPtr1.at(valinta1 - 1);
				std::cout << "Kotijoukkueen pisteet: ";
				std::cin >> kotiPisteet;
			}
			
			std::cin.clear();
		} while (valinta1 < 0 && valinta1 > koko);
		system("cls");

		// K�ytt�j� valitsee vierasjoukkueen
		do {

			// K�ytt�j� saa valita joukkueen, jota haluaa tarkastella
			std::cout << "Valitse vierasjoukkue" << std::endl;

			// Tulostetaan kaikki joukkueet
			for (unsigned i = 0; i < koko; i++)
			{
				std::cout << i + 1 << ". ";
				shrPtr1.at(i)->tulosta();
			}
			std::cin >> valinta2;

			// tarkistetaan sy�te
			if (valinta2 < 0 || valinta2 > koko)
			{
				std::cout << "Tarkista sy�te." << std::endl;
				// reset failbit
				std::cin.clear();
				// skip bad input
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				system("pause");
				system("cls");
			}
			else
			{
				vierasJoukkue = shrPtr1.at(valinta2 - 1);
				std::cout << "Vierasjoukkueen pisteet: ";
				std::cin >> vierasPisteet;
			}

		} while (valinta2 < 0 && valinta2 > koko);

		{
			//
			// Luodaan ottelu unique pointerilla
			std::unique_ptr<Ottelu> upOttelu(new Ottelu(kotiJoukkue, vierasJoukkue, kotiPisteet, vierasPisteet));
			// Pusketaan pointerin sis�lt� ottelut vektorille
			ottelut.push_back(std::move(upOttelu));
		}
	}
}
