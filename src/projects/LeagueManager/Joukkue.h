/*######################################################################################################

	Author: Samul1
	22.09.2024

########################################################################################################*/

#pragma once
#include<string>
#include<vector>
#include<memory>
#include"Pelaaja.h"

class Joukkue {
public:
    // Konstruktori
    Joukkue(std::string n);

    void tulosta();
    void addPlayer();
    std::string getNimi();
    std::vector<std::shared_ptr<Pelaaja>> getPelaajat();

    std::string nimi;
    std::vector<std::shared_ptr<Pelaaja>> pelaajat;
};
