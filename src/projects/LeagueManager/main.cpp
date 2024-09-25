/*######################################################################################################

	Author: Samul1
	22.09.2024

########################################################################################################*/

#include<iostream>
#include"Liiga.h"

/*

* Smart-pointerit:
	* K�ytet��n shared_ptr:a hallitsemaan muistinhallintaa pelaajien ja joukkueiden osalta, koska pelaajat voivat kuulua useisiin rakenteisiin yht� aikaa.
	* unique_ptr on k�yt�ss� otteluiden hallinnassa, koska ottelut ovat yksiselitteisesti liigan omistamia
	* weak_ptr Ottelu-luokassa optimoi muistinhallintaa k�ytt�m�ll� osoitinta vain, kun luokka on k�yt�ss�
	* Metodeja tarvitaan olioiden (pelaajat, joukkueet, ottelut) lis�yksiin ja tietojen tulostuksiin.

Ty�nalla:




Tehty:

	* Pelaaja-luokka sis�lt�� pelaajan tiedot: nimen ja pelinumeron.
	* Joukkueeseen voi lis�t� pelaajia.
	* Joukkue-luokka sis�lt�� joukkueen nimen ja vektorin pelaajista.
	* Ottelu-luokka tallentaa ottelun tiedot, mukaan lukien koti- ja 
	vierasjoukkueet sek� niiden pisteet.
	* Uusia otteluita voidaan tallentaa.
	* Liiga-luokka hallinnoi joukkueita ja otteluita.
	* Liigaan voidaan lis�t� joukkueita ja otteluita, ja sen tiedot 
	voidaan tulostaa.
*/


int main()
{
	// ��kk�set
	setlocale(LC_ALL, "");
	// muuttujien alustus
	bool end = false;
	std::string liigaNimi;
	

	// Silmukka alkaa t�st�
	while (end == false)
	{
		std::cout << "------------------- Uusi Liiga ------------------- " << std::endl;
		// Kysyt��n k�ytt�j�lt� liigan nimi
		std::cout << "Anna nimi: ";
		std::getline(std::cin, liigaNimi);
		// Luodaan liiga olio
		Liiga liiga(liigaNimi);

		system("cls");
		// Kutsutaan mainmenu-funktio
		end = liiga.p��Valikko(liigaNimi);

		// Pyyhit��n n�ytt�
		system("cls");

	}


}