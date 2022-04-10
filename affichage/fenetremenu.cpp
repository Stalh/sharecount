#include "fenetremenu.h"

#include <QInputDialog>

FenetreMenu::FenetreMenu(BaseDeDonnees* bd, Model &model, QWidget *parent)
    : Fenetre(bd,model, parent), ui(new Ui::FenetreMenu){
    ui->setupUi(this);
}


FenetreMenu::~FenetreMenu()
{
    delete ui;
}

void FenetreMenu::on_contact_clicked()
{
    model.changerFenetre("contact");
}


void FenetreMenu::on_creerCagnotte_clicked()
{
    model.changerFenetre("creationCagnotte");
}


void FenetreMenu::on_creationGDB_clicked()
{
    model.changerFenetre("creationGdb");
}


void FenetreMenu::on_deconnexionButton_clicked()
{
    model.deconnexion();
    model.changerFenetre("authentification");

}


void FenetreMenu::on_visualisation_clicked()
{
    model.visuGdb(); //met à jour la liste des gdb
    model.changerFenetre("visuGdb");

}


void FenetreMenu::on_visualisation_2_clicked()
{
    model.visuCagnotte();
    model.changerFenetre("visuCagnotte");
}


void FenetreMenu::on_rejoindreGDB_clicked()
{
    bool ok = false;
       QString dialogue = QInputDialog::getText(this, "Rejoindre", "Saisir le code d'un gestionnaire", QLineEdit::Normal, QString(), &ok);

       if (ok && !dialogue.isEmpty()){
            if(bd->idGdbExist(dialogue)){
                QString idU = QString::fromStdString( model.getUtilisateur()->getId());
                bd->ajouterUtilisateurAuGdb( dialogue, idU);

            }
       }
}


void FenetreMenu::on_rejoindreCagnotte_clicked()
{
    bool ok = false;
       QString dialogue = QInputDialog::getText(this, "Rejoindre", "Saisir le code d'une cagnotte", QLineEdit::Normal, QString(), &ok);
       if (ok && !dialogue.isEmpty()){
            if(bd->idCagnotteExist(dialogue)){
                QString idU = QString::fromStdString( model.getUtilisateur()->getId());
                bd->ajouterUtilisateurACagnotte(dialogue, idU);
            }
       }
}


void FenetreMenu::on_user_clicked()
{
    model.afficherMail();
    model.changerFenetre("profile");

}

