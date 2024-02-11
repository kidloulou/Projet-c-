#include "tache.hpp"

Tache::Tache() : complete(false) {
    
}

std::string Tache::getNomTache() const {
    return nomTache;
}

void Tache::setNomTache(const std::string& nom) {
    nomTache = nom;
}

bool Tache::estComplete() const {
    return complete;
}

void Tache::marquerCommeComplete() {
    complete = true;
}

void Tache::marquerCommeIncomplete() {
    complete = false;
}
