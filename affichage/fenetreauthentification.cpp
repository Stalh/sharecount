#include "fenetreauthentification.h"

FenetreAuthentification::FenetreAuthentification(BaseDeDonnees* bd,Model &model, QWidget *parent) :
      Fenetre(bd,model, parent),ui(new Ui::FenetreAuthentification)
{
  ui->setupUi(this);
  cacherMdp = true;
  ui->mdp->setEchoMode(QLineEdit::Password);


}


FenetreAuthentification::~FenetreAuthentification()
{
    delete ui;
}


void FenetreAuthentification::on_authentifierButton_clicked()
{
    QString id  = ui->identifiant->text();

    QString mdp = ui->mdp->text();
    if(bd->verificationUtilisateur(id, mdp) == false){
        QMessageBox msgBox;
        msgBox.setText("Id ou mot de passe incorrect !");
        msgBox.exec();
    } else {
        model.changerFenetre("menu");
        //Ouvrir session utilisateur
        ui->identifiant->setText("");
        ui->mdp->setText("");
        model.connexion(new Utilisateur(id.toStdString(), bd->getMailUtilisateur(id.toStdString()).toStdString(), mdp.toStdString()));

    }
}


void FenetreAuthentification::on_creerCompteButton_clicked()
{
    ui->identifiant->setText("");
    ui->mdp->setText("");
    model.changerFenetre("inscription");
}




void FenetreAuthentification::on_voirMdp_clicked()
{
    cacherMdp= !cacherMdp;
    if(cacherMdp){
        ui->voirMdp->setIcon(QIcon(":/new/images/eye.png"));

        ui->mdp->setEchoMode(QLineEdit::Password);
    }else{
        ui->voirMdp->setIcon(QIcon(":/new/images/eye_closed.png"));
        ui->mdp->setEchoMode(QLineEdit::Normal);
    }
}

