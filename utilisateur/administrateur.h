#ifndef ADMINISTRATEUR_H
#define ADMINISTRATEUR_H

#include <iostream>
#include <sstream>
#include "utilisateur.h"
/**
 * @file administrateur.h
 * @brief La classe Administrateur contient les informations d'un utilisateur et octroit des droits en plus (résoudre les problèmes des autres utilisateurs)
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 * @version 1.0
 */
class Administrateur: public Utilisateur
{
    public:

    /**
     * \brief Le constructeur permet de définir l'identifiant, l'adresse mail et le mot de passe de l'administrateur)
     en fonction de ses paramètres
     * \param id L'identifiant donné par utilisateur
     * \param mail L'adresse mail donnée par l'utilisateur
     * \param motDePasse Le mot de passe donné par l'utilisateur
     */
    Administrateur(std::string id, std::string mail, std::string motDePasse);


};
#endif // ADMINISTRATEUR_H
