#ifndef UTILISATEUR_H
#define UTILISATEUR_H

//Pour les affichages
#include <iostream>
//Pour l'utilisation d'une liste d'éléments
#include <map>

//Le include de compte.h est optionnel car on include cagnotte.h qui include compte.h
#include "../compte/compte.h"
#include "../compte/cagnotte.h"
#include "../compte/gestionnairedebudget.h"

/**
 * @file utilisateur.h
 * \brief La classe Utilisateur contient les informations d'un utilisateur de ShareCount et permet de modifier ses comptes
 * \version 1.0
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 */
class Utilisateur {

    protected:

        std::string nom; /*!< Nom de l'utilisateur*/
        std::string prenom; /*!< Prénom de l'utilisateur*/
        std::string id; /*!< Identifiant de l'utilisateur*/
        std::string mail;/*!< Adresse mail de l'utilisateur*/
        std::string motDePasse; /*!< Mot de passe de l'utilisateur*/

    public:
        /**
         * \brief Le constructeur permet de définir l'identifiant, l'adresse mail et le mot de passe de l'utilisateur
         en fonction de ses paramètres
         * \param id L'identifiant donné par utilisateur
         * \param mail L'adresse mail donnée par l'utilisateur
         * \param motDePasse Le mot de passe donné par l'utilisateur
         */
        Utilisateur(std::string id, std::string mail, std::string motDePasse);



        /**
         * \brief getter de Nom
         * \param Le nom de l'utilisateur
         */
        const std::string &getNom() const;

        /**
         * \brief setter de Nom
         * \param newNom Le nouveau nom de l'utilisateur
         */
        void setNom(const std::string &newNom);

        /**
         * \brief getter de Prenom
         * \return Le prénom de l'utilisateur
         */
        const std::string &getPrenom() const;

        /**
         * \brief setter de Prenom
         * \param newPrenom Le nouveau prénom de l'utilisateur
         */
        void setPrenom(const std::string &newPrenom);

        /**
         * \brief getter de Id
         * \return L'identifiant de l'utilisateur
         */
        const std::string &getId() const;

        /**
         * \brief setter de Id
         * \param newId Le nouvel identifiant
         */
        void setId(const std::string &newId);

        /**
         * \brief getter de Mail
         * \return L'adresse mail de l'utilisateur
         */
        const std::string &getMail() const;

        /**
         * \brief setter de Mail
         * \param newMail La nouvelle adresse mail
         */
        void setMail(const std::string &newMail);

        /**
         * \brief getter de Mot de passe
         * \return Le mot de passe de l'utilisateur
         */
        const std::string &getMotDePasse() const;

        /**
         * \brief setter de Mot de passe
         * \param newMotDePasse Nouvelle valeur du mot de passe
         */
        void setMotDePasse(const std::string &newMotDePasse);



};

#endif
