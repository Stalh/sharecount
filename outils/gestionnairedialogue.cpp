#include "gestionnairedialogue.h"

/**
 * \file gestionnairedialogue.cpp
 * \brief Le GestionnaireDialogue s'occupe des interactions entre l'utilisateur et la base de données/l'applicaton
 * \version 1.0
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 */
GestionnaireDialogue::GestionnaireDialogue()
{
}

GestionnaireDialogue::~GestionnaireDialogue(){
    //delete this;
}


void GestionnaireDialogue::authentification(std::string mail , std::string mdp){


}

void GestionnaireDialogue::setMessageParam( QString expediteur, QString destinataire){
    // Premièrement, nous allons créer un objet SmtpClient
    // on utilisera le serveur gmail smtp  (smtp.gmail.com, port 465, ssl)

    smtp = new SmtpClient("smtp.gmail.com", 465, SmtpClient::SslConnection);

    // Connection avec mail/mdp

    smtp->setUser("noreplysharecount@gmail.com");
    smtp->setPassword("c_r_g_cpoa");

    // On crée un object MimeMessage, ceci sera le mail
    message.setSender(new EmailAddress(expediteur, expediteur));
    message.addRecipient(new EmailAddress(destinataire, destinataire)); //TODO mettre l'id de l'utilisateur

}


void GestionnaireDialogue::envoyerMail( QString titre, QString textMsg){
    // on ajoute le texte
    //  En créant un objet MimeText

    MimeText text;

    text.setText(textMsg);
    message.setSubject(titre);

    // On l'ajoute au mail

    message.addPart(&text);

    // On envoie le mail

    smtp->connectToHost();
    smtp->login();
    smtp->sendMail(message);
    smtp->quit();
}


void creationUtilisateur(std::string id, std::string mail , std::string mdp){


}
