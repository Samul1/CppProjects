/*######################################################################################################

	Author: Samul1
	22.09.2024

########################################################################################################*/

#pragma once
#include<memory>
#include"Joukkue.h"

class Ottelu {
public:
    std::weak_ptr<Joukkue> kotiJoukkue;
    std::weak_ptr<Joukkue> vierasJoukkue;
    int kotiJoukkuePisteet;
    int vierasJoukkuePisteet;

    //konstruktori
    Ottelu(const std::shared_ptr<Joukkue>& koti, const std::shared_ptr<Joukkue>& vieras,
        int kotiPisteet, int vierasPisteet)
    : kotiJoukkue(koti), vierasJoukkue(vieras),
    kotiJoukkuePisteet(kotiPisteet), vierasJoukkuePisteet(vierasPisteet) {}

    int getKotiPisteet() { return kotiJoukkuePisteet; };
    int getVierasPisteet() { return vierasJoukkuePisteet; };
    std::string getKotiJoukkue();
    std::string getVierasJoukkue();
    void tulosta();
};

