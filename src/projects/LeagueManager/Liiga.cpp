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

// Pääohjelma.
bool Liiga::pääValikko(std::string liigaNimi)
{
	// Muuttujien esittely
	bool end = false;
	int käyttäjäValinta = 0;
	// silmukka pyörii kunnes exit == true
	while (end == false)
	{
		do
		{
			std::cout << " --------- " << liigaNimi << " -------- - " << std::endl;
			std::cout << " 1. Lisää joukkue" << std::endl;
			std::cout << " 2. Lisää pelaaja" << std::endl;
			std::cout << " 3. Lisää ottelu" << std::endl;
			std::cout << " 4. Joukkue info" << std::endl;
			std::cout << " 5. Pelaaja info" << std::endl;
			std::cout << " 6. Ottelu info" << std::endl;
			std::cout << " 0. Exit" << std::endl;
			std::cin >> käyttäjäValinta;
			// tarkistetaan syöte
			if(käyttäjäValinta < 0 || käyttäjäValinta > 7)
			{
				std::cout << "Tarkista syöte." << std::endl;
				// reset failbit
				std::cin.clear();
				// skip bad input
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				system("pause");
				system("cls");
			}
		} while (käyttäjäValinta < 0 && käyttäjäValinta > 7);
		
		system("cls");
		switch (käyttäjäValinta)
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
			getInfo(käyttäjäValinta);
			system("pause");
			break;
		case 5:
			getInfo(käyttäjäValinta);
			system("pause");
			break;
		case 6:
			getInfo(käyttäjäValinta);
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

// Metodi ottaa vastaan parametrina integer arvon pääValikko metodista
// ja sen avulla valitsee tulostukseen, joko joukkueet tai sitten pelaajat.
void Liiga::getInfo(int valinta)
{
	// Luodaan shared pointer ja osoitetaan sillä joukkueet vektorille
	std::vector<std::shared_ptr<Joukkue>> shrPtr1 = joukkueet;
	// Luodaan unique pointer ja osoitetaan sillä ottelut vektorille
	std::vector<std::unique_ptr<Ottelu>>& uqPtr1 = ottelut;

	// Jos käyttäjä valitsi joukkueet
	if (valinta == 4)
	{
		// Käydään läpi pointerin sisältö
		for (unsigned i = 0; i < shrPtr1.size(); i++)
			// tulostetaan joukkue
			shrPtr1.at(i)->tulosta();
	}

	// Jos käyttäjä valitsi pelaajat
	else if (valinta == 5)
	{
		// Pelaaja info
		int valinta;
		size_t koko = shrPtr1.size();
		if(!shrPtr1.empty())
		{
			do
			{
				// Käyttäjä saa valita joukkueen, jota haluaa tarkastella
				std::cout << "Valitse joukkue" << std::endl;
				// Tulostetaan kaikki joukkueet
				for (unsigned i = 0; i < koko; i++)
				{
					std::cout << i + 1 << ". ";
					shrPtr1.at(i)->tulosta();
				}
				std::cin >> valinta;
				// tarkistetaan syöte
				if (valinta < 0 || valinta > koko)
				{
					std::cout << "Tarkista syöte." << std::endl;
					// reset failbit
					std::cin.clear();
					// skip bad input
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					system("pause");
					system("cls");
				}
			} while (valinta < 0 && valinta > koko);
			system("cls");

			// Päivitetään koko
			koko = shrPtr1.at(valinta - 1)->getPelaajat().size();

			shrPtr1.at(valinta - 1)->tulosta();
			for (unsigned j = 0; j < koko; j++)
				// Tulostetaan joukkueen pelaajat
				shrPtr1.at(valinta - 1)->getPelaajat().at(j)->tulosta();

			std::cout << std::endl;
		}
	}
	
	// Jos käyttäjä valitsi ottelut
	else if (valinta == 6)
	{
		int valinta;
		size_t koko = uqPtr1.size();
		if (!uqPtr1.empty())
		{
			do
			{
				// Käyttäjä saa valita joukkueen, jota haluaa tarkastella
				std::cout << "Valitse ottelu" << std::endl;
				// Tulostetaan kaikki joukkueet
				for (unsigned i = 0; i < koko; i++)
				{
					std::cout << i + 1 << ". ";
					uqPtr1.at(i)->tulosta();
				}
				std::cin >> valinta;
				// tarkistetaan syöte
				if (valinta < 0 || valinta > koko)
				{
					std::cout << "Tarkista syöte." << std::endl;
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
			std::cout << "Otteluita ei löydetty" << std::endl;
			system("pause");
		}

	}
		
	
	else
		std::cout << "Miten päädyit tänne?";
}

// Lisätään tiimi liigaan
void Liiga::addTeam()
{
	std::string nimiJoukkue;
	int määräPelaajat = -1;
	std::cin.ignore();
	// Kysytään käyttäjä syöte
	std::cout << "Syötä joukkueen nimi: ";
	std::getline(std::cin, nimiJoukkue);

	// Luodaan joukkue shared pointerilla
	std::shared_ptr<Joukkue> spJoukkue(new Joukkue(nimiJoukkue));

	// Pyöritään silmukassa kunnes käyttäjä syöttää positiivisen pelaajamäärän
	// ja tekee pelaajat
	while (määräPelaajat < 0)
	{
		std::cout << "Syötä pelaajien määrä: ";
		std::cin >> määräPelaajat;
		if (määräPelaajat > 0)
		{
			// Lisätään pelaajat
			for(int i = 0; i < määräPelaajat; i++)
				spJoukkue->addPlayer();
		}
		else
			std::cout << "Pelaajia täytyy olla vähintään yksi." << std::endl;
	}
	
	

	// Pusketaan pointerin sisältö joukkueet vektorille
	joukkueet.push_back(spJoukkue);

	// Infotaan käyttäjää
	std::cout << "Joukkue lisätty." << std::endl;
	system("pause");
	system("cls");

}

// Metodi lisää pelaaja-olion käyttäjän valitsemaan joukkueeseen.
void Liiga::addPlayer()
{
	// Luodaan shared pointer ja osoitetaan sillä joukkueet vektorille
	std::vector<std::shared_ptr<Joukkue>> shrPtr1 = joukkueet;
	int valinta;
	size_t koko = shrPtr1.size();
	
	if (shrPtr1.empty())
		std::cout << "Joukkueita ei löydetty." << std::endl;
	else
	{
		do
		{
			// Käyttäjä saa valita joukkueen, jota haluaa tarkastella
			std::cout << "Valitse joukkue" << std::endl;
			// Tulostetaan kaikki joukkueet
			for (unsigned i = 0; i < koko; i++)
			{
				std::cout << i + 1 << ". ";
				shrPtr1.at(i)->tulosta();
			}
			std::cin >> valinta;
			// tarkistetaan syöte
			if (valinta < 0 || valinta > koko)
			{
				std::cout << "Tarkista syöte." << std::endl;
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
// Metodi tarkistaa onko vähintään kaksi joukkuetta kirjattu
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
		std::cout << "Joukkueita ei löydetty." << std::endl;
	// Jos on vähemmän kuin kaksi joukkuetta
	else if (shrPtr1.size() < 2)
		std::cout << "Joukkueita tarvitaan vähintään kaksi." << std::endl;
	// Muuten
	else
	{
		size_t koko = shrPtr1.size();
		// Käyttäjä valitsee kotijoukkueen
		do
		{
			// Käyttäjä saa valita joukkueen, jota haluaa tarkastella
			std::cout << "Valitse kotijoukkue" << std::endl;

			// Tulostetaan kaikki joukkueet
			for (unsigned i = 0; i < koko; i++)
			{
				std::cout << i + 1 << ". ";
				shrPtr1.at(i)->tulosta();
			}
			std::cin >> valinta1;
			
			// tarkistetaan syöte
			if (valinta1 < 0 || valinta1 > koko)
			{
				std::cout << "Tarkista syöte." << std::endl;
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

		// Käyttäjä valitsee vierasjoukkueen
		do {

			// Käyttäjä saa valita joukkueen, jota haluaa tarkastella
			std::cout << "Valitse vierasjoukkue" << std::endl;

			// Tulostetaan kaikki joukkueet
			for (unsigned i = 0; i < koko; i++)
			{
				std::cout << i + 1 << ". ";
				shrPtr1.at(i)->tulosta();
			}
			std::cin >> valinta2;

			// tarkistetaan syöte
			if (valinta2 < 0 || valinta2 > koko)
			{
				std::cout << "Tarkista syöte." << std::endl;
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
			// Pusketaan pointerin sisältö ottelut vektorille
			ottelut.push_back(std::move(upOttelu));
		}
	}
}
