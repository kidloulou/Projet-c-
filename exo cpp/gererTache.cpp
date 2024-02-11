// GererTache.cpp
#include "gererTache.hpp"

GererTache::GererTache() {
    // Initialisations si nécessaire
}

void GererTache::lancerApplication() {
    int choix;

    do {
        afficherMenu();
        std::cout << "Votre choix : ";
        std::cin >> choix;

        switch (choix) {
            case 1:
                ajouterTache();
                break;
            case 2:
                afficherTaches();
                break;
            case 3:
                modifierTache();
                break;
            case 4:
                supprimerTache();
                break;
            case 5:
                std::cout << "Merci d'utiliser le Gestionnaire de tâches. Au revoir!\n";
                break;
            default:
                std::cout << "Choix non valide. Veuillez réessayer.\n";
                break;
        }

    } while (choix != 5);
}

void GererTache::afficherMenu() {
    std::cout << "\n------ Menu ------\n";
    std::cout << "1. Ajouter une tâche\n";
    std::cout << "2. Afficher les tâches\n";
    std::cout << "3. Modifier une tâche\n";
    std::cout << "4. Supprimer une tâche\n";
    std::cout << "5. Quitter\n";
}

void GererTache::ajouterTache() {
    Tache nouvelleTache;
    std::string nomTache;

    std::cout << "Nom de la nouvelle tâche : ";
    std::cin >> nomTache;
    nouvelleTache.setNomTache(nomTache);
    nouvelleTache.marquerCommeIncomplete();

    taches.push_back(nouvelleTache);
    std::cout << "Tâche ajoutée avec succès!\n";
}

void GererTache::afficherTaches() {
    if (taches.empty()) {
        std::cout << "Aucune tâche à afficher.\n";
    } else {
        std::cout << "------ Liste des tâches ------\n";
        for (const auto& tache : taches) {
            std::cout << "- " << tache.getNomTache() << " ("
                      << (tache.estComplete() ? "Complète" : "Non complète") << ")\n";
        }
    }
}

void GererTache::modifierTache() {
    int index;
    afficherTaches();

    if (!taches.empty()) {
        std::cout << "Sélectionnez le numéro de la tâche à modifier : ";
        std::cin >> index;

        if (index >= 1 && index <= taches.size()) {
            std::string nouveauNom;
            std::cout << "Nouveau nom pour la tâche : ";
            std::cin >> nouveauNom;
            taches[index - 1].setNomTache(nouveauNom);
            std::cout << "Tâche modifiée avec succès!\n";
        } else {
            std::cout << "Numéro de tâche non valide.\n";
        }
    }
}

void GererTache::supprimerTache() {
    int index;
    afficherTaches();

    if (!taches.empty()) {
        std::cout << "Sélectionnez le numéro de la tâche à supprimer : ";
        std::cin >> index;

        if (index >= 1 && index <= taches.size()) {
            taches.erase(taches.begin() + index - 1);
            std::cout << "Tâche supprimée avec succès!\n";
        } else {
            std::cout << "Numéro de tâche non valide.\n";
        }
    }
}
