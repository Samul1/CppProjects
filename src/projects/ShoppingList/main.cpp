/*######################################################################################################

	Author: Samul1
	09.12.2023

########################################################################################################*/

#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<vector>
#include "Ostos.h";
#include "Ostoslista.h"

int main()
{
	// Tulosten asettelu kahden deimaalin tarkkuuteen.
	std::cout << std::fixed << std::setprecision(2);
	// Ääkköset näkyviin konsoliin.
	setlocale(LC_ALL, "");
	// Ääkkösten käsittely käyttäjän syötteissä.
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	Ostoslista lista("kauppalista.txt");
	// Haetaan valmis ostoslista, jos sellainen on jo olemassa:
	lista.lueTiedosto();
	// Näytetään käyttäjälle päävalikko:
	lista.näytäPäävalikko(lista);

}