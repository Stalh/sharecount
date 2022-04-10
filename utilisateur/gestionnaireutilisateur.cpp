#include "gestionnaireutilisateur.h"

/**
 * \file gestionnaireutilisateur.cpp
 * \brief Le GestionnaireUtilisateur manipule et modifie une collection d'utilisateurs
 * \version 1.0
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 */
GestionnaireUtilisateur::GestionnaireUtilisateur()
{

}

GestionnaireUtilisateur::~GestionnaireUtilisateur(){

}

const std::map<std::string, Utilisateur> &GestionnaireUtilisateur::getUtilisateurs() const
{
    return utilisateurs;
}

Utilisateur &GestionnaireUtilisateur::getUtilisateur(std::string id){
    return utilisateurs.at(id);
}

void GestionnaireUtilisateur::ajouterUtilisateur(std::string id, std::string mail, std::string mdp){
    Utilisateur utilisateurCree(id, mail, mdp); //on suppose l'unicité
    utilisateurs.insert(std::pair<std::string,Utilisateur>(utilisateurCree.getId(),utilisateurCree)); //getUtilisateur = getID
}

