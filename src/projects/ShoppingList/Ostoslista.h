/*######################################################################################################

	Author: Samul1
	09.12.2023

########################################################################################################*/

#pragma once
#include "Ostos.h"
#include <vector>
#include <string>
class Ostoslista
{
public:
	// Konstruktori:
	Ostoslista(std::string tn);
	// Destruktori:
	~Ostoslista();
	// Metodit:
	void n‰yt‰P‰‰valikko(Ostoslista lista);
	void tulostaOstokset();
	void lis‰‰UusiOstos();
	void tyhjenn‰Lista();
	void lueTiedosto();
	void tallennaTiedostoon();

private:
	std::vector<Ostos*> ostosVektori;
	std::string tiedosto_nimi;
};

