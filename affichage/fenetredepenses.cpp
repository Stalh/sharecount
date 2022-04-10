#include "fenetredepenses.h"

#include <QMainWindow>
#include <QMessageBox>

FenetreDepenses::FenetreDepenses(BaseDeDonnees* bd,Model &model, QWidget *parent) :
    Fenetre(bd, model, parent),ui(new Ui::FenetreDepenses)
 {
    ui->setupUi(this);
}



void FenetreDepenses::on_ajouterButton_clicked()
{
    QString utilisateur = QString::fromStdString(model.getUtilisateur()->getId());
    QString idDep = QUuid::createUuid().toString() ; //Générer id unique pour la dépense

    QString nomDep= ui->nomDep->text();

    QString idGdb = bd->obtenirIdGDB(ui->titreGdbLabel->text());
    QString montantDep =ui->montant->text();
    double valeur = ui->montant->value();
    if(nomDep.isEmpty()|| montantDep.isEmpty() || valeur==0.00){
        QMessageBox msgBox;

        msgBox.critical(this, tr(" Erreur ! "), tr("Les informations sont incorrectes!\n\nMerci de saisir tous les champs."),
                        QMessageBox::Ok);
        msgBox.setStyleSheet("QMessageBox { text-align:justify;}"
                             "QLabel{color:red;}"
                             "QPushButton{ border-width: 2px;"
                             "border-style: solid;"
                             "border-radius: 3px;"
                             "border-color: black;"
                             "background: qlineargradient(spread:pad, x1:1 y1:1, x2:0, y2:0, stop:0 #F2F3F4, stop:1 #CACFD2);}");

        msgBox.setButtonText(QMessageBox::Ok, " Ok ");
    }else{
        bd->envoieDonneesDepenses(idDep, utilisateur, idGdb, nomDep, montantDep); //ajouter le gdb à la bdd

    }

    ui->nomDep->clear();
    ui->montant->setValue(0.00);

    model.actualiserTableau();
    if (bd->isCreateurCompte("gestionnaire_de_budget",bd->obtenirIdGDB(ui->titreGdbLabel->text()),QString::fromStdString(model.getUtilisateur()->getId()))){
        model.afficherSuppressionGDB(true);
    }else {
        model.afficherSuppressionGDB(false);
    }
    model.changerFenetre("gdb");
}

void FenetreDepenses::setTitreGdbDepense(QString label){
    ui->titreGdbLabel->setText(label);
}

void FenetreDepenses::on_logo_clicked()
{
    model.changerFenetre("menu");
}

