// GererTache.h
#ifndef GERERTACHE_H
#define GERERTACHE_H

#include <iostream>
#include <vector>
#include "tache.hpp"

class GererTache {
public:
    GererTache();

    void lancerApplication();

private:
    std::vector<Tache> taches;

    void afficherMenu();
    void ajouterTache();
    void afficherTaches();
    void modifierTache();
    void supprimerTache();
};

#endif
