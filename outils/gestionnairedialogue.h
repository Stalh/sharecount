#ifndef GESTIONNAIREDIALOGUE_H
#define GESTIONNAIREDIALOGUE_H
//Pour les affichages
#include <iostream>
#include "../smtp/SmtpMime"
#include "utilisateur/utilisateur.h"

/**
 * \file gestionnairedialogue.h
 * \brief Le GestionnaireDialogue s'occupe des interactions entre l'utilisateur et la base de données/l'applicaton
 * \version 1.0
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 */
class GestionnaireDialogue
{
private:


    SmtpClient* smtp;   /*!< instance du Serveur de mail */
    MimeMessage message; /*!< message du mail */
public:
    /**
     * @brief Constructeur d'un gestionnaire
     */
    GestionnaireDialogue();


    /**
     * @brief Destructeur
     */
    ~GestionnaireDialogue();

    /**
     * @brief authentification fonction pour donner l'accès à l'utilisateur à son espace et ses données
     * @param mail de l'utilisateur qui se connecte
     * @param mdp
     */
    void authentification(std::string mail , std::string mdp);
    /**
     * @brief setMessageParam défini les paramètre d'un mail à envoyer
     * @param user mail de la personne qui envoie
     * @param mdp son mdp
     * @param expediteur du mail
     * @param destinataire du mail
     */
    void setMessageParam( QString expediteur, QString  destinataire);
    /**
     * @brief envoyerMail fonction pour envoyer un mail de confirmation lors de la création d'un compte utilisateur
     * @param mail de l'utilisateur
     */
    void envoyerMail(QString titre, QString textMsg);
    /**
     * @brief creationUtilisateur Ajoute un nouveau utilisateur à la BDD
     * @param id
     * @param mail
     * @param mdp
     */
    void creationUtilisateur(std::string id, std::string mail , std::string mdp);

};

#endif // GESTIONNAIREDIALOGUE_H
