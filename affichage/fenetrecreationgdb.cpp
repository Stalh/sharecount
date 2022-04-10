#include "fenetrecreationgdb.h"
#include "ui_fenetrecreationgdb.h"


FenetreCreationGdb::FenetreCreationGdb(BaseDeDonnees* bd,Model &model, QWidget *parent) :
   Fenetre(bd, model, parent),ui(new Ui::FenetreCreationGdb)
{
    ui->setupUi(this);
}

FenetreCreationGdb::~FenetreCreationGdb()
{
    delete ui;
}

void FenetreCreationGdb::on_logo_clicked()
{
    ui->nomGdb->clear();
    ui->descGdb->clear();
    model.changerFenetre("menu");

}

void FenetreCreationGdb::on_creerGdb_clicked()
{
    QString nomGdb = ui->nomGdb->text();
    QString description = ui->descGdb->text();

    qDebug()<<nomGdb << description;
    if(nomGdb.isEmpty()){
        QMessageBox msgBox;
        msgBox.setText("Veuillez saisir le nom du gestionnaire de budget.");
        msgBox.exec();
    }
    else{
        QString owner = QString::fromStdString(model.getUtilisateur()->getId());
        QString id = QUuid::createUuid().toString() ; //Générer id unique pour le gdb
        bd->envoieDonneesGdb(id, nomGdb, description, owner); //ajouter le gdb à la bdd
        bd->ajouterUtilisateurAuGdb(id, owner); //ajouter le créateur en tant que participant
        ui->nomGdb->clear();
        ui->descGdb->clear();

        //ouvrir la fenetre du nouveau gestionnaire
        model.setTitre("gdb", nomGdb);
        if (bd->isCreateurCompte("gestionnaire_de_budget",id,QString::fromStdString(model.getUtilisateur()->getId()))){
            model.afficherSuppressionGDB(true);
        }else {
            model.afficherSuppressionGDB(false);
        }
        model.changerFenetre("gdb");
    }


}

