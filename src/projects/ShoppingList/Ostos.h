/*######################################################################################################

	Author: Samul1
	09.12.2023

########################################################################################################*/

#pragma once
#include <string>

class Ostos
{
public:
	// Konstruktori:
	Ostos(std::string n, int kpl);
	// Destruktori:
	~Ostos();

	// Metodit:
	void tulosta();
	std::string haeNimi();
	int haeKplm‰‰r‰();

private:
	std::string nimi;
	int kplm‰‰r‰;
};

