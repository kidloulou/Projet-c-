#ifndef TACHE_H
#define TACHE_H

#include <iostream>

class Tache {
public:
    Tache();

    std::string getNomTache() const;
    void setNomTache(const std::string& nom);

    bool estComplete() const;
    void marquerCommeComplete();
    void marquerCommeIncomplete();

private:
    std::string nomTache;
    bool complete;
};

#endif
