#include "fenetrevisucagnotte.h"

FenetreVisuCagnotte::FenetreVisuCagnotte(BaseDeDonnees* bd,Model &model, QWidget *parent) :
    Fenetre(bd,model, parent),ui(new Ui::FenetreVisuCagnotte)
{
  ui->setupUi(this);

}

FenetreVisuCagnotte::~FenetreVisuCagnotte()
{
    delete ui;
    delete modelList;

}

void FenetreVisuCagnotte::visuCagnotte(){
    QString id = QString::fromStdString(model.getUtilisateur()->getId());
    this->modelList =bd->getCagnottesUtilisateur(id) ;
    ui->listViewCagnotte->setModel(this->modelList);

}

void FenetreVisuCagnotte::on_logo_clicked()
{
    model.changerFenetre("menu");

}


void FenetreVisuCagnotte::on_deconnexionButton_clicked()
{
    model.deconnexion();
    model.changerFenetre("authentification");
}


void FenetreVisuCagnotte::on_listViewCagnotte_doubleClicked(const QModelIndex &index)
{
    //on récupère l'objectif de la cagnotte pour l'afficher dans la fenetre
    QString idCagnotte = bd->obtenirIdCagnotte(index.data(Qt::DisplayRole).toString());
    QString objectif = QString::number(bd->getObjectif(idCagnotte), 'f', 2); // objectif avec 2 décimaux de précision
    model.setAffichageCagnotte(index.data(Qt::DisplayRole).toString(),objectif );
    if (bd->isCreateurCompte("cagnotte",idCagnotte,QString::fromStdString(model.getUtilisateur()->getId()))){
        model.afficherSuppressionCagnotte(true);
    }else {
        model.afficherSuppressionCagnotte(false);
    }
    model.changerFenetre("cagnotte");
}

