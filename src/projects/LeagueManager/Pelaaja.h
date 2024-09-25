/*######################################################################################################

	Author: Samul1
	22.09.2024

########################################################################################################*/

#pragma once
#include<string>

class Pelaaja {
public:

    Pelaaja(std::string n, int pn);

    void tulosta();

    std::string nimi;
    int pelinumero;
};

