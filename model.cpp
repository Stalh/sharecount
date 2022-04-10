#include "model.h"

Model::Model(MainWindow& mainwindow): gestFenetres(mainwindow, *this)
{

}


const std::map<std::string, Fenetre *> &Model::getFenetres() const
{
    return gestFenetres.getFenetres();
}


void Model::changerFenetre(std::string nomFenetre){
    gestFenetres.changerFenetre(nomFenetre);
}

Utilisateur *Model::getUtilisateur() const
{
    return utilisateur;
}

void Model::connexion(Utilisateur *newUtilisateur)
{
    utilisateur = newUtilisateur;

}

void Model::deconnexion(){
    this->utilisateur = nullptr;
    delete this->utilisateur;
    changerFenetre("authentification");
}

void Model::visuGdb(){
    gestFenetres.visuGdb();
}
void Model::visuCagnotte(){
    gestFenetres.visuCagnotte();
}

void Model::setTitre(QString pageSuivante, QString label){
    gestFenetres.setTitre(pageSuivante, label);
}

void Model::setTitreGdbDepense(QString label){
    gestFenetres.setTitreGdbDepense(label);
}

void Model::setAffichageCagnotte(QString label, QString objectif){
    gestFenetres.setAffichageCagnotte(label, objectif);
}

void Model::afficherMail(){
    gestFenetres.afficherMail();
}

void Model::actualiserTableau(){
    gestFenetres.actualiserTableau();
}

void Model::afficherSuppressionGDB(bool isVisible){
    gestFenetres.afficherSuppressionGDB(isVisible);
}

void Model::afficherSuppressionCagnotte(bool isVisible){
    gestFenetres.afficherSuppressionCagnotte(isVisible);
}
