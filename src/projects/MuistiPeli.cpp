#include<iostream>
#include<set>
#include<Windows.h>

/*

Author: Samul1

Tee moninpelattava muistipeli, jossa pelaajien pitää muistaa muiden pelaajien jo syöttämiä numeroita (0-20). 
Peli kysyy ensin pelaajien määrän ja sen jälkeen pelaajilta vuoron perään yhden numeron ja puhdistaa näytön 
(system("cls")) Jos pelaaja syöttää numeron, jonka joku toinen on jo syöttänyt, hän häviää pelin ja peli päättyy. 
Käytä numeroiden tallentamiseen std::set-tietorakennetta.

Jos pelaajat syöttävät kaikki numerot välillä 0-20, peli tyhjentää set-tietorakenteen, 
mutta pelaajia ei informoida asiasta ja peli jatkuu normaalisti.


*/


// Funktioiden esittely kääntäjälle:
int pelaajienLkm();
void peliSilmukka(int pelaajat);
bool onkoNumero(int numero, std::set<int> salaisetNumerot);
void onkoTäysi(std::set<int> &salaisetNumerot);
void logo();

int main()
{
	// Muuttujat:
	int uusiPeli = 1;
	// Tulostuksen ääkköset:
	setlocale(LC_ALL, "");

	while (uusiPeli == 1)
	{
		// Kysytään pelaajien lukumäärä:
		int pelaajat = pelaajienLkm();
		system("cls");

		// Siirrytään pelisilmukkaan:
		peliSilmukka(pelaajat);

		// Kysytään pelataanko uusi peli:
		do
		{
			logo();
			std::cout << "Uusi peli?" << std::endl;
			std::cout << " 1. Kyllä" << std::endl;
			std::cout << " 2. Ei" << std::endl;
			std::cin >> uusiPeli;
			if (uusiPeli < 1 || uusiPeli > 2)
			{
				system("cls");
				std::cout << "Tarkista syöte." << std::endl;
			}
		} while (uusiPeli < 1 || uusiPeli > 2);
		system("cls");
	}
	logo();
	std::cout << "Kiitos peleistä!";
}

// Funktio kysyy kuinka monta pelaajaa on pelaamassa ja palauttaa annetun arvon.
int pelaajienLkm()
{
	int pelaajat = 0;
	logo();

	std::cout << "Kuinka monta pelaajaa?" << std::endl;
	// Tarkistetaan silmukassa, ettei tule negatiivista tai 0 syötettä:
	do
	{
		std::cin >> pelaajat;
		if (pelaajat <= 0)
		{
			// clean screen
			system("cls");
			// reset failbit
			std::cin.clear();
			// skip bad input
			std::cin.ignore();
			logo();
			std::cout << "Pelaajien lukumäärä ei voi olla 0 tai negatiivinen." << std::endl;
		}
	} while (pelaajat <= 0);
	// Palautetaan paluuarvona pelaajien lukumäärä:
	return pelaajat;
}

// Funktio ottaa vastaan pelaajien lukumäärän integer arvona ja käsittelee pelin pääsilmukan:
void peliSilmukka(int pelaajat)
{
	// Muuttujien esittely:
	std::set<int> salaisetNumerot;
	int valinnat[10];
	bool onkoNumeroOlemassa = false;
	int peliOhi = 0;
	// Peli silmukka alkaa:
	while (peliOhi == 0)
	{
		for (int i = 1; i <= pelaajat; i++)
		{
			// Tarkistetaan syöte:
			do
			{
				logo();
				std::cout << "Pelaaja" << i << std::endl;
				std::cout << "Syötä numero 0-20: ";
				std::cin >> valinnat[i];
				// Jos väärä syöte:
				if (valinnat[i] < 0 || valinnat[i] > 20)
				{
					// clean screen
					system("cls");
					std::cout << "Tarkista syöte." << std::endl;
				}
			} while (valinnat[i] < 0 || valinnat[i] > 20);
			
			// Tarkistetaan onko setti täynnä:
			onkoTäysi(salaisetNumerot);
			// Tarkistetaan löytyykö syötettyä numeroa:
			onkoNumeroOlemassa = onkoNumero(valinnat[i], salaisetNumerot);
			// Jos löytyi:
			if (onkoNumeroOlemassa == true)
			{
				std::cout << "Numero löytyi! Pelaaja " << i << " hävisi!" << std::endl;
				peliOhi = 1;
				system("pause");
				break;
			}
			// Jos ei löytynyt:
			else
				// Tallennetaan syötetty numero settiin:
				salaisetNumerot.insert(valinnat[i]);
			// Tyhjennetään näyttö vuoron lopuksi:
			system("cls");
		}
		system("cls");
	}
}

// Funktio ottaa vastaan integer tyypin paramertin ja palauttaa paluuarvona bool arvon, löytyykö luku jo.
bool onkoNumero(int numero, std::set<int> salaisetNumerot)
{
	std::set<int>::iterator it;
	//Etsitään setistä numero:
	it = salaisetNumerot.find(numero);
	// Jos numero löytyy:
	if (it != salaisetNumerot.end())
		// Palautetaan arvo true:
		return true;
	// Jos numero ei löydy:
	else
		// Palautetaan arvo false:
		return false;
}

// Funktio ottaa vastaan setin ja katsoo onko se täynnä. Jos se on täynnä, niin se tyhjennetään.
void onkoTäysi(std::set<int> &salaisetNumerot)
{
	// Muuttujat:
	int laskuri = 0;
	// Iteraattori:
	std::set<int>::iterator it;
	// Käydään läpi setti:
	for (int i = 0; i <= 20; i++)
	{
		// iteraattorilla etsitään numeroa i:
		it = salaisetNumerot.find(i);
		// Jos i:n arvo löytyy:
		if (it != salaisetNumerot.end())
			// Kasvatetaan laskuria:
			laskuri++;
	}
	// Jos laskuri on saavuttanut 21, eli kaikki numerot 0-20 ovar käytetty:
	if (laskuri == 21)
	{
		// Poistetaan kaikki luvut setistä:
		for (int i = 0; i <= 20; i++)
		{
			it = salaisetNumerot.find(i);
			if (it != salaisetNumerot.end())
				salaisetNumerot.erase(it);
		}
	}
}

// Tulostaa logon:
void logo()
{
	std::cout << "" << std::endl;
	std::cout << "   ,   ,                ______    __              " << std::endl;
	std::cout << "  / \\,/ \\  __  __   __ /\\  __ \\  /\\ \\__  __       " << std::endl;
	std::cout << " /\\      \\/\\ \\ \\ \\ /\\_\\\\ \\,\\ \\_\\ \\ \\  _\\/\\_\\      " << std::endl;
	std::cout << " \\ \\ \\__\\ \\ \\ \\ \\ \\\\/\\ \\\\/_\\___ \\ \\ \\ \\/\\/\\ \\     " << std::endl;
	std::cout << "  \\ \\ \\_/\\ \\ \\ \\_\\ \\\\ \\_\\ /\\ \\_\\ \\ \\ \\_\\ \\ \\_\\    " << std::endl;
	std::cout << "   \\ \\ \\\\ \\_\\/_____/ \\/_/ \\ \\_____\\ \\/_/  \\/_/    " << std::endl;
	std::cout << "    \\/_/ \\/_/              \\/_____/               " << std::endl;
	std::cout << " " << std::endl;
	std::cout << "  ______          ___            " << std::endl;
	std::cout << " /\\  __ \\    __  /\\_ \\    __     " << std::endl;
	std::cout << " \\ \\ \\/\\ \\ /'__`\\\\//\\ \\  /\\_\\    " << std::endl;
	std::cout << "  \\ \\  __//\\  __/  \\_\\ \\_\\/\\ \\   " << std::endl;
	std::cout << "   \\ \\ \\  \\ \\____\\ /\\____\\\\ \\_\\  " << std::endl;
	std::cout << "    \\/_/   \\/____/ \\/____/ \\/_/  " << std::endl;
	std::cout << " " << std::endl;
}