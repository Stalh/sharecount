#include "utilisateur.h"
/**
 * @file utilisateur.cpp
 * \brief La classe Utilisateur contient les informations d'un utilisateur de ShareCount et permet de modifier ses comptes
 * \version 1.0
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 */
const std::string &Utilisateur::getNom() const
{
    return nom;
}

Utilisateur::Utilisateur(std::string id, std::string mail, std::string motDePasse){
    this->id = id;
    this->mail = mail;
    this->motDePasse = motDePasse;
}

void Utilisateur::setNom(const std::string &newNom)
{
    nom = newNom;
}

const std::string &Utilisateur::getPrenom() const
{
    return prenom;
}

void Utilisateur::setPrenom(const std::string &newPrenom)
{
    prenom = newPrenom;
}

const std::string &Utilisateur::getId() const
{
    return id;
}

void Utilisateur::setId(const std::string &newId)
{
    id = newId;
}

const std::string &Utilisateur::getMail() const
{
    return mail;
}

void Utilisateur::setMail(const std::string &newMail)
{
    mail = newMail;
}

const std::string &Utilisateur::getMotDePasse() const
{
    return motDePasse;
}

void Utilisateur::setMotDePasse(const std::string &newMotDePasse)
{
    motDePasse = newMotDePasse;
}


