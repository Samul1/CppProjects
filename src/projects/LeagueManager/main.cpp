/*######################################################################################################

	Author: Samul1
	22.09.2024

########################################################################################################*/

#include<iostream>
#include"Liiga.h"

/*

* Smart-pointerit:
	* Käytetään shared_ptr:a hallitsemaan muistinhallintaa pelaajien ja joukkueiden osalta, koska pelaajat voivat kuulua useisiin rakenteisiin yhtä aikaa.
	* unique_ptr on käytössä otteluiden hallinnassa, koska ottelut ovat yksiselitteisesti liigan omistamia
	* weak_ptr Ottelu-luokassa optimoi muistinhallintaa käyttämällä osoitinta vain, kun luokka on käytössä
	* Metodeja tarvitaan olioiden (pelaajat, joukkueet, ottelut) lisäyksiin ja tietojen tulostuksiin.

Työnalla:




Tehty:

	* Pelaaja-luokka sisältää pelaajan tiedot: nimen ja pelinumeron.
	* Joukkueeseen voi lisätä pelaajia.
	* Joukkue-luokka sisältää joukkueen nimen ja vektorin pelaajista.
	* Ottelu-luokka tallentaa ottelun tiedot, mukaan lukien koti- ja 
	vierasjoukkueet sekä niiden pisteet.
	* Uusia otteluita voidaan tallentaa.
	* Liiga-luokka hallinnoi joukkueita ja otteluita.
	* Liigaan voidaan lisätä joukkueita ja otteluita, ja sen tiedot 
	voidaan tulostaa.
*/


int main()
{
	// Ääkköset
	setlocale(LC_ALL, "");
	// muuttujien alustus
	bool end = false;
	std::string liigaNimi;
	

	// Silmukka alkaa tästä
	while (end == false)
	{
		std::cout << "------------------- Uusi Liiga ------------------- " << std::endl;
		// Kysytään käyttäjältä liigan nimi
		std::cout << "Anna nimi: ";
		std::getline(std::cin, liigaNimi);
		// Luodaan liiga olio
		Liiga liiga(liigaNimi);

		system("cls");
		// Kutsutaan mainmenu-funktio
		end = liiga.pääValikko(liigaNimi);

		// Pyyhitään näyttö
		system("cls");

	}


}