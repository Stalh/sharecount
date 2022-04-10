#include "gestionnairefenetres.h"

#include "affichage/fenetreauthentification.h"
#include "affichage/fenetrecontact.h"
#include "affichage/fenetreinscription.h"
#include "affichage/fenetremenu.h"
#include "affichage/fenetrecreationcagnotte.h"
#include "affichage/fenetrecreationgdb.h"
#include "affichage/fenetrevisugdb.h"
#include "affichage/fenetrevisucagnotte.h"
#include "affichage/fenetregdb.h"
#include "affichage/fenetrecagnotte.h"
#include "affichage/fenetreprofile.h"
#include "affichage/fenetredepenses.h"
#include "affichage/fenetreconsultermesdepenses.h"
#include "mainwindow.h"


/**
 * @file gestionnairefenetres.cpp
 * @brief La classe GestionnaireFenetres gère l'affichage des différentes fenêtres
 * @version 1.0
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 */
GestionnaireFenetres::GestionnaireFenetres(MainWindow& mainwindow, Model &model): mainwindow(mainwindow)
{
    //Création de toutes les fenêtres
    FenetreAuthentification* fenAuth = new FenetreAuthentification(&bd, model);
    fenetres.insert(std::pair<std::string,Fenetre*>("authentification",fenAuth));

    FenetreContact* fenContact = new FenetreContact(&bd,model);
    fenetres.insert(std::pair<std::string,Fenetre*>("contact",fenContact));

    FenetreInscription* fenInscription = new FenetreInscription(&bd,model);
    fenetres.insert(std::pair<std::string,Fenetre*>("inscription",fenInscription));

    FenetreMenu* fenMenu = new FenetreMenu(&bd,model);
    fenetres.insert(std::pair<std::string,Fenetre*>("menu",fenMenu));

    FenetreCreationCagnotte* fenCreationCagnotte = new FenetreCreationCagnotte(&bd,model);
    fenetres.insert(std::pair<std::string,Fenetre*>("creationCagnotte",fenCreationCagnotte));

    FenetreCreationGdb* fenCreationGdb = new FenetreCreationGdb(&bd, model);
    fenetres.insert(std::pair<std::string, Fenetre*> ("creationGdb", fenCreationGdb));

    FenetreVisuGdb* fenVisuGdb = new FenetreVisuGdb(&bd, model);
    fenetres.insert(std::pair<std::string, Fenetre*> ("visuGdb", fenVisuGdb));

    FenetreVisuCagnotte* fenVisuCagnotte = new FenetreVisuCagnotte(&bd, model);
    fenetres.insert(std::pair<std::string, Fenetre*> ("visuCagnotte", fenVisuCagnotte));

    FenetreGDB* fenGDB = new FenetreGDB(&bd,model);
    fenetres.insert(std::pair<std::string,Fenetre*>("gdb",fenGDB));

    FenetreCagnotte* fenCagnotte = new FenetreCagnotte(&bd,model);
    fenetres.insert(std::pair<std::string,Fenetre*>("cagnotte",fenCagnotte));

    FenetreProfile* fenProfile = new FenetreProfile(&bd,model);
    fenetres.insert(std::pair<std::string,Fenetre*>("profile",fenProfile));

    FenetreDepenses* fenDep = new FenetreDepenses(&bd, model);
    fenetres.insert(std::pair<std::string, Fenetre*>("depenses", fenDep));

    FenetreConsulterMesDepenses* fenMesDep = new FenetreConsulterMesDepenses(&bd, model);
    fenetres.insert(std::pair<std::string, Fenetre*>("mesDepenses", fenMesDep));

}

GestionnaireFenetres::~GestionnaireFenetres(){
    //Parcours des fenêtres pour les supprimer (car allocation avec new)
    std::map<std::string,Fenetre*>::const_iterator iterator;
        for(iterator = fenetres.begin(); iterator != fenetres.end();iterator++){
            delete iterator->second; //Suppression de la fenêtre
        }
}

const std::map<std::string, Fenetre *> &GestionnaireFenetres::getFenetres() const
{
    return fenetres;
}

void GestionnaireFenetres::changerFenetre(std::string nomFenetre){
    mainwindow.setFenetre(fenetres.at(nomFenetre));
}

void GestionnaireFenetres::visuGdb(){
    dynamic_cast<FenetreVisuGdb*>(fenetres.at("visuGdb"))->visuGdb();

}

void GestionnaireFenetres::visuCagnotte(){
    dynamic_cast<FenetreVisuCagnotte*>(fenetres.at("visuCagnotte"))->visuCagnotte();
}


void GestionnaireFenetres::setTitre(QString pageSuivante, QString label){
       fenetres.at(pageSuivante.toStdString())->setTitre(label);
}

void GestionnaireFenetres::setAffichageCagnotte(QString label, QString objectif){
    dynamic_cast<FenetreCagnotte*>(fenetres.at("cagnotte"))->setAffichageCagnotte(label, objectif);
}

void GestionnaireFenetres::afficherMail(){
    dynamic_cast<FenetreProfile*>(fenetres.at("profile"))->afficherMail();
}


void GestionnaireFenetres::setTitreGdbDepense(QString label){
    dynamic_cast<FenetreDepenses*>(fenetres.at("depenses"))->setTitreGdbDepense(label);
}

void GestionnaireFenetres::actualiserTableau(){
    dynamic_cast<FenetreGDB*>(fenetres.at("gdb"))->setTableGdb();
}

void GestionnaireFenetres::afficherSuppressionGDB(bool isVisible){
    dynamic_cast<FenetreGDB*>(fenetres.at("gdb"))->afficherSuppressionGDB(isVisible);
}

void GestionnaireFenetres::afficherSuppressionCagnotte(bool isVisible){
    dynamic_cast<FenetreCagnotte*>(fenetres.at("cagnotte"))->afficherSuppressionCagnotte(isVisible);
}
