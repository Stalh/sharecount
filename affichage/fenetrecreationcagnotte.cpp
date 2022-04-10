#include "fenetrecreationcagnotte.h"


FenetreCreationCagnotte::FenetreCreationCagnotte(BaseDeDonnees* bd,Model &model, QWidget *parent) :
    Fenetre(bd,model,parent),ui(new Ui::FenetreCreationCagnotte)
{
    ui->setupUi(this);
}

FenetreCreationCagnotte::~FenetreCreationCagnotte()
{
    delete ui;
}


void FenetreCreationCagnotte::on_logo_clicked()
{
    ui->lineEdit_nom->clear();
    ui->lineEdit_description->clear();
    ui->objectifBox->setValue(0.00);
    model.changerFenetre("menu");
    }


void FenetreCreationCagnotte::on_creerCagnotte_clicked()
{
    QString nomCagnotte = ui->lineEdit_nom->text();
    QString description = ui->lineEdit_description->text();
    double objectifCagnotte = ui->objectifBox->value();
    //conversion du double en QString pour la requete
    QString ob = QString::number(ui->objectifBox->value(), 'f', ui->objectifBox->decimals());
    if(nomCagnotte.isEmpty() || objectifCagnotte==0.00){
        //erreur
        QMessageBox msgBox;
        msgBox.setText("Veuillez saisir le nom et l'objectif de la cagnotte.");
        msgBox.exec();
    }
    else{
        qDebug() << nomCagnotte << description << objectifCagnotte;
        QString owner = QString::fromStdString(model.getUtilisateur()->getId());
        //ajout de la cagnotte
        QString id = QUuid::createUuid().toString() ; //générer un id unique pour la cagnotte
        bd->envoieDonneesCagnotte(id, nomCagnotte, description, ob, owner  );  //ajouter la cagnotte à la bdd
        bd->ajouterUtilisateurACagnotte(id,owner ); //ajouter le créateur en tant que participant
        ui->lineEdit_nom->clear();
        ui->lineEdit_description->clear();
        ui->objectifBox->setValue(0.00);
        //ouvrir la fenetre de la nouvelle cagnotte

        model.setAffichageCagnotte(nomCagnotte, QString::number(objectifCagnotte, 'f', 2));// objectif avec 2 décimaux de précision
        if (bd->isCreateurCompte("cagnotte",id,QString::fromStdString(model.getUtilisateur()->getId()))){
            model.afficherSuppressionCagnotte(true);
        }else {
            model.afficherSuppressionCagnotte(false);
        }
        model.changerFenetre("cagnotte");
    }


}

