//Exercice c++
//-réaliser un script avec au moins 3 classes (dont une abstraites)
//-Utiliser au moins 4 constructeurs paramétriques et 1 constucteur par défaut
//-Utiliser les 4 principes de la  pdo
#include <iostream>
#include <string>


class Vehicule {
public:

    Vehicule() {
        std::cout << "Constructeur par defaut de Vehicule" << std::endl;
    }


    Vehicule(const std::string& marque) : marque(marque) {
        std::cout << "Constructeur de Vehicule avec parametre : " << marque << std::endl;
    }


    virtual void afficher() const = 0;

protected:
    std::string marque;
};


class Voiture : public Vehicule {
public:

    Voiture() : modele("Inconnu") {
        std::cout << "Constructeur par defaut de Voiture" << std::endl;
    }


    Voiture(const std::string& marque, const std::string& modele) : Vehicule(marque), modele(modele) {
        std::cout << "Constructeur de Voiture avec parametres : " << marque << ", Modele = " << modele << std::endl;
    }


    void afficher() const override {
        std::cout << "Voiture " << marque << " de modele " << modele << std::endl;
    }

private:
    std::string modele;
};


class Moto : public Vehicule {
public:

    Moto() : type_("Inconnu") {
        std::cout << "Constructeur par defaut de Moto" << std::endl;
    }

    Moto(const std::string& marque, const std::string& type) : Vehicule(marque), type_(type) {
        std::cout << "Constructeur de Moto avec parametres : " << marque << ", Type = " << type << std::endl;
    }

    void afficher() const override {
        std::cout << "Moto " << marque << " de type " << type_<< std::endl;
    }

private:
    std::string type_;
};

int main() {

    Vehicule* vehicule1 = new Voiture("Toyota", "Yaris");
    Vehicule* vehicule2 = new Moto("Ferrari", "488 Pista");

    return 0;
}
