/*######################################################################################################

	Author: Samul1
	16.04.2024

########################################################################################################*/

#include<iostream>
#include<set>
#include<Windows.h>

/*

Author: Samul1

Tee moninpelattava muistipeli, jossa pelaajien pit�� muistaa muiden pelaajien jo sy�tt�mi� numeroita (0-20). 
Peli kysyy ensin pelaajien m��r�n ja sen j�lkeen pelaajilta vuoron per��n yhden numeron ja puhdistaa n�yt�n 
(system("cls")) Jos pelaaja sy�tt�� numeron, jonka joku toinen on jo sy�tt�nyt, h�n h�vi�� pelin ja peli p��ttyy. 
K�yt� numeroiden tallentamiseen std::set-tietorakennetta.

Jos pelaajat sy�tt�v�t kaikki numerot v�lill� 0-20, peli tyhjent�� set-tietorakenteen, 
mutta pelaajia ei informoida asiasta ja peli jatkuu normaalisti.


*/


// Funktioiden esittely k��nt�j�lle:
int pelaajienLkm();
void peliSilmukka(int pelaajat);
bool onkoNumero(int numero, std::set<int> salaisetNumerot);
void onkoTaysi(std::set<int> &salaisetNumerot);
void logo();

int main()
{
	// Muuttujat:
	int uusiPeli = 1;
	// Tulostuksen ��kk�set:
	setlocale(LC_ALL, "");

	while (uusiPeli == 1)
	{
		// Kysyt��n pelaajien lukum��r�:
		int pelaajat = pelaajienLkm();
		system("cls");

		// Siirryt��n pelisilmukkaan:
		peliSilmukka(pelaajat);

		// Kysyt��n pelataanko uusi peli:
		do
		{
			logo();
			std::cout << "New game?" << std::endl;
			std::cout << " 1. Yes" << std::endl;
			std::cout << " 2. No" << std::endl;
			std::cin >> uusiPeli;
			if (uusiPeli < 1 || uusiPeli > 2)
			{
				system("cls");
				std::cout << "Check input." << std::endl;
			}
		} while (uusiPeli < 1 || uusiPeli > 2);
		system("cls");
	}
	logo();
	std::cout << "Thankyou for playing!";
}

// Funktio kysyy kuinka monta pelaajaa on pelaamassa ja palauttaa annetun arvon.
int pelaajienLkm()
{
	int pelaajat = 0;
	logo();

	std::cout << "How many players?" << std::endl;
	// Tarkistetaan silmukassa, ettei tule negatiivista tai 0 sy�tett�:
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
			std::cout << "Number of players can not be 0 or negative." << std::endl;
		}
	} while (pelaajat <= 0);
	// Palautetaan paluuarvona pelaajien lukum��r�:
	return pelaajat;
}

// Funktio ottaa vastaan pelaajien lukum��r�n integer arvona ja k�sittelee pelin p��silmukan:
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
			// Tarkistetaan sy�te:
			do
			{
				logo();
				std::cout << "Player" << i << std::endl;
				std::cout << "Enter a number 0-20: ";
				std::cin >> valinnat[i];
				// Jos v��r� sy�te:
				if (valinnat[i] < 0 || valinnat[i] > 20)
				{
					// clean screen
					system("cls");
					std::cout << "Check input." << std::endl;
				}
			} while (valinnat[i] < 0 || valinnat[i] > 20);
			
			// Tarkistetaan onko setti t�ynn�:
			onkoTaysi(salaisetNumerot);
			// Tarkistetaan l�ytyyk� sy�tetty� numeroa:
			onkoNumeroOlemassa = onkoNumero(valinnat[i], salaisetNumerot);
			// Jos l�ytyi:
			if (onkoNumeroOlemassa == true)
			{
				std::cout << "Number found! Player " << i << " lost!" << std::endl;
				peliOhi = 1;
				system("pause");
				break;
			}
			// Jos ei l�ytynyt:
			else
				// Tallennetaan sy�tetty numero settiin:
				salaisetNumerot.insert(valinnat[i]);
			// Tyhjennet��n n�ytt� vuoron lopuksi:
			system("cls");
		}
		system("cls");
	}
}

// Funktio ottaa vastaan integer tyypin paramertin ja palauttaa paluuarvona bool arvon, l�ytyyk� luku jo.
bool onkoNumero(int numero, std::set<int> salaisetNumerot)
{
	std::set<int>::iterator it;
	//Etsit��n setist� numero:
	it = salaisetNumerot.find(numero);
	// Jos numero l�ytyy:
	if (it != salaisetNumerot.end())
		// Palautetaan arvo true:
		return true;
	// Jos numero ei l�ydy:
	else
		// Palautetaan arvo false:
		return false;
}

// Funktio ottaa vastaan setin ja katsoo onko se t�ynn�. Jos se on t�ynn�, niin se tyhjennet��n.
void onkoTaysi(std::set<int> &salaisetNumerot)
{
	// Muuttujat:
	int laskuri = 0;
	// Iteraattori:
	std::set<int>::iterator it;
	// K�yd��n l�pi setti:
	for (int i = 0; i <= 20; i++)
	{
		// iteraattorilla etsit��n numeroa i:
		it = salaisetNumerot.find(i);
		// Jos i:n arvo l�ytyy:
		if (it != salaisetNumerot.end())
			// Kasvatetaan laskuria:
			laskuri++;
	}
	// Jos laskuri on saavuttanut 21, eli kaikki numerot 0-20 ovar k�ytetty:
	if (laskuri == 21)
	{
		// Poistetaan kaikki luvut setist�:
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