/*######################################################################################################

	Author: Samul1
	22.09.2024

########################################################################################################*/

#pragma once
#include<string>
#include<vector>
#include<memory>
#include"Joukkue.h"
#include"Ottelu.h"

class Liiga {
public:
    // Konstruktori
    Liiga(std::string n);

    bool p‰‰Valikko(std::string liigaNimi);
    void getInfo(int valinta);
    std::vector<std::shared_ptr<Joukkue>> getJoukkue() { return joukkueet; };
    void addTeam();
    void addPlayer();
    void addTurnament();

    std::string nimi;
    std::vector<std::shared_ptr<Joukkue>> joukkueet;
    std::vector<std::unique_ptr<Ottelu>> ottelut;
};

