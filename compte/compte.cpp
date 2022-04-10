#include "compte.h"
#include "utilisateur/utilisateur.h"
/**
 * @file compte.cpp
 * @brief Un Compte est une classe abstraite qui contient les éléments communs à la gestion d'argent d'un groupe
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 * @version 1.0
 */
const std::string &Compte::getNom() const
{
    return nom;
}

void Compte::setNom(const std::string &newNom)
{
    nom = newNom;
}

const std::string &Compte::getCode() const
{
    return code;
}

void Compte::setCode(const std::string &newCode)
{
    code = newCode;
}

Utilisateur &Compte::getCreateur() const
{
    return createur;
}


Compte::Compte(std::string nom, Utilisateur& createur) : createur(createur)
{
    this->code = std::to_string(IdGenerator::Instance().getNewIdCompte());//Conversion du code de int en string
    this->nom = nom;
    utilisateurs.push_back(createur);
}

