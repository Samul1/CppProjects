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
	// ��kk�set n�kyviin konsoliin.
	setlocale(LC_ALL, "");
	// ��kk�sten k�sittely k�ytt�j�n sy�tteiss�.
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	Ostoslista lista("kauppalista.txt");
	// Haetaan valmis ostoslista, jos sellainen on jo olemassa:
	lista.lueTiedosto();
	// N�ytet��n k�ytt�j�lle p��valikko:
	lista.n�yt�P��valikko(lista);

}