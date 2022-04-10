#include "cagnotte.h"

/**
 * @file cagnotte.cpp
 * @brief Une cagnotte gère l'argent d'un groupe d'utilisateurs
 * @author R. Martini
 * @version 1.0
 */


float Cagnotte::getMontant() const
{
    return montant;
}

void Cagnotte::setMontant(float newMontant)
{
    montant = newMontant;
}

float Cagnotte::getObjectif() const
{
    return objectif;
}

void Cagnotte::setObjectif(float newObjectif)
{
    objectif = newObjectif;
}

const std::string &Cagnotte::getDescription() const
{
    return description;
}

void Cagnotte::setDescription(const std::string &newDescription)
{
    description = newDescription;
}

Cagnotte::Cagnotte(std::string nom,float objectif, std::string description, Utilisateur& u):Compte(nom,u)
{
    this->montant = 0;
    this->objectif = objectif;
    this-> description= description;

}
