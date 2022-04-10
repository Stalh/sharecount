#ifndef GESTIONNAIREUTILISATEUR_H
#define GESTIONNAIREUTILISATEUR_H

#include <map>
#include "utilisateur.h"

/**
 * \file gestionnaireutilisateur.h
 * \brief Le GestionnaireUtilisateur manipule et modifie une collection d'utilisateurs
 * \version 1.0
 * \author G. Zimol, R. Martini, C. Mathias
 */
class GestionnaireUtilisateur
{

private:
    std::map<std::string,Utilisateur> utilisateurs; /*!< Liste des utilisateurs*/

public:
    /**
     * @brief Constructeur d'un gestionnant contenant une collectio
     */
    GestionnaireUtilisateur();

        // Destructeur

    /**
     * @brief Destructeur
     */
    ~GestionnaireUtilisateur();

    /**
     * @brief getUtilisateurs
     * @return collection d'utilisateurs
     */
    const std::map<std::string, Utilisateur> &getUtilisateurs() const;

    /**
     * @brief getUtilisateurs
     * @param id identifiant de l'utilisateur que l'on recherche
     * @return un des élements de la collection d'utilisateurs
     */
    Utilisateur &getUtilisateur(std::string id);

    /**
     * @brief ajouterUtilisateur crée et ajoute un utilisateur à partir des éléments passés en paramètres à la liste des utilisateurs
     * @param id l'identifiant du nouvel utilisateur
     * @param mail l'adresse mail du nouvel utilisateur
     * @param mdp le mot de passe du nouvel utilisateur
     */
    void ajouterUtilisateur(std::string id, std::string mail, std::string mdp);
};

#endif // GESTIONNAIREUTILISATEUR_H
