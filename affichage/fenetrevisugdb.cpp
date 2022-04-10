#include "fenetrevisugdb.h"

/**
 * @file fenetrevisugdb.cpp
 * @brief La class FenetreVisuGdb représente la fenetre de visualisation de la liste de gdb auquel un utilisateur participe
 * @version 1.0
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 */
FenetreVisuGdb::FenetreVisuGdb(BaseDeDonnees* bd,Model &model, QWidget *parent) :
      Fenetre(bd,model, parent),ui(new Ui::FenetreVisuGdb)
{
  ui->setupUi(this);

}
FenetreVisuGdb::~FenetreVisuGdb(){
    delete ui;
    delete modelList;

}

void FenetreVisuGdb::on_logo_clicked()
{
    model.changerFenetre("menu");
}


void FenetreVisuGdb::visuGdb(){
    QString id = QString::fromStdString(model.getUtilisateur()->getId());
    //Récupère la liste des dépenses de la base de données
    this->modelList =bd->getGdbUtilisateur(id) ;
    //Modifie l'affichage de la liste des dépenses
    ui->listViewGdb->setModel(this->modelList);

}

void FenetreVisuGdb::on_deconnexionButton_clicked()
{
    model.deconnexion();
    model.changerFenetre("authentification");
}


void FenetreVisuGdb::on_listViewGdb_doubleClicked(const QModelIndex &index)
{
    //Indique à la fenêtre de visualisation de gdb quel gestionnaire est choisi
    model.setTitre("gdb", index.data(Qt::DisplayRole).toString());
    if (bd->isCreateurCompte("gestionnaire_de_budget",bd->obtenirIdGDB(index.data(Qt::DisplayRole).toString()),QString::fromStdString(model.getUtilisateur()->getId()))){
        model.afficherSuppressionGDB(true);
    }else {
        model.afficherSuppressionGDB(false);
    }
    model.changerFenetre("gdb");
}





