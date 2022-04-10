#include "fenetrecagnotte.h"

#include <QUuid>

FenetreCagnotte::FenetreCagnotte(BaseDeDonnees* bd, Model &model, QWidget *parent) : Fenetre(bd, model, parent),ui(new Ui::FenetreCagnotte)
{
    ui->setupUi(this);

    ui->label_4->setVisible(false);


}

FenetreCagnotte::~FenetreCagnotte(){
    delete ui;
}

void FenetreCagnotte::setAffichageCagnotte(QString label, QString objectif){
    ui->label->setText(label);
    ui->objectifValue->setText(objectif+ " €");
    ui->montantValue->setText(QString::number(bd->getMontant(bd->obtenirIdCagnotte(ui->label->text())), 'f', 2)+ " €"); //afficher le montant avec 2 décimaux

}

void FenetreCagnotte::on_logo_clicked()
{
    model.changerFenetre("menu");
}


void FenetreCagnotte::on_cloturerButton_clicked()
{
    bd->supprimerParticipantCagnotte(bd->obtenirIdCagnotte(ui->label->text()));
    bd->supprimerCagnotte(bd->obtenirIdCagnotte(ui->label->text()));
    model.changerFenetre("menu");
}

void FenetreCagnotte::on_inviterCagnotte_clicked()
{
    QMessageBox fenetreCode;
    fenetreCode.setWindowTitle("Inviter un ami");
    QString id = bd->obtenirIdCagnotte(ui->label->text());
    fenetreCode.setButtonText(QMessageBox::Ok , " Copier ");
    fenetreCode.setText("Partagez ce code pour inviter à rejoindre cette cagnotte!\n  " + id);

    fenetreCode.setStyleSheet("QPushButton{width:71px;height:31px; border-width: 2px; border-style: solid;border-radius: 3px; border-color: black; background: qlineargradient(spread:pad, x1:1 y1:1, x2:0, y2:0, stop:0 #F2F3F4, stop:1 #CACFD2);} ");

    if(fenetreCode.exec()==QMessageBox::Ok ){
        //copier le code dans le clipboard de l'utilisateur
        QClipboard *clipboard = QApplication::clipboard();
        clipboard->setText(id);
    }

}



void FenetreCagnotte::on_ajouterArgentButton_clicked()
{

    QString utilisateur = QString::fromStdString(model.getUtilisateur()->getId()); //récupération de l'utilisateur
    QString id = QUuid::createUuid().toString() ; //Générer id unique pour la contribution
    QString idCagnotte = bd->obtenirIdCagnotte(ui->label->text()); //récupération de l'id de la cagnotte
    QRegExp re("\\d*\\.\\d{2}$");  // a digit (\d), zero or more times (*)

        bool ok = false;
           QString dialogue = QInputDialog::getText(this, "Contribution", "Saisir le montant de votre contribution", QLineEdit::Normal, QString(), &ok);
           if (ok && !dialogue.isEmpty() && dialogue.toDouble() > 0.00 && re.exactMatch(dialogue)){ //on vérifie si l'input n'est pas vide ou supérieur à 0
                if(bd->envoieDonneesContributions(id , utilisateur, idCagnotte, dialogue,"0")){ //on entre les données corrects dans la base de donneés
                    double somme =bd->getMontant(bd->obtenirIdCagnotte(ui->label->text()))+ dialogue.toDouble();
                    bd->updateMontant(idCagnotte, QString::number(somme));
                    ui->montantValue->setText(QString::number(bd->getMontant(bd->obtenirIdCagnotte(ui->label->text())))+ " €");
                    qDebug() << "ui->montant: " << ui->montantValue->text().toDouble() ;
                } else {
                    qDebug() << "Erreur dans la base de données";
                }
           } else {
               QMessageBox msgBox;

               msgBox.critical(this, tr(" Erreur ! "), tr("Veuillez saisir un montant de la forme XXX.XX ! "),
                               QMessageBox::Ok);
               msgBox.setStyleSheet("QMessageBox { text-align:justify;}"
                                    "QLabel{color:red;}"
                                    "QPushButton{ border-width: 2px;"
                                    "border-style: solid;"
                                    "border-radius: 3px;"
                                    "border-color: black;"
                                    "background: qlineargradient(spread:pad, x1:1 y1:1, x2:0, y2:0, stop:0 #F2F3F4, stop:1 #CACFD2);}");

               msgBox.setButtonText(QMessageBox::Ok, " Ok ");
           }

           if(bd->getMontant(bd->obtenirIdCagnotte(ui->label->text()))>=bd->getObjectif(bd->obtenirIdCagnotte(ui->label->text()))){
               ui->label_4->setVisible(true);
           }else{
              ui->label_4->setVisible(false);
           }

}


void FenetreCagnotte::on_consulterContributions_clicked()
{
    QMessageBox msgBox;
    QString contributions = QString::number( bd->getContributionsUtilisateur(QString::fromStdString(model.getUtilisateur()->getId()),bd->obtenirIdCagnotte(ui->label->text())), 'f', 2);
    QString total = QString::number(bd->getMontant(bd->obtenirIdCagnotte(ui->label->text())), 'f', 2);
    QString message = "Vous avez contribué à "+ contributions+" € de la somme totale ("+ total+" €). ";

    msgBox.setText(message);
    msgBox.exec();
}


void FenetreCagnotte::on_retirerArgentButton_clicked()
{
    QString utilisateur = QString::fromStdString(model.getUtilisateur()->getId()); //récupération de l'utilisateur
    QString id = QUuid::createUuid().toString() ; //Générer id unique pour la contribution
    QString idCagnotte = bd->obtenirIdCagnotte(ui->label->text()); //récupération de l'id de la cagnotte
    QRegExp re("\\d*\\.\\d{2}$");  // un chiffre 0 ou n fois suivi de 2 décimaux

        bool ok = false;
           QString dialogue = QInputDialog::getText(this, "Retrait", "Saisir le montant que vous souhaitez retirer", QLineEdit::Normal, QString(), &ok);
           if (ok && !dialogue.isEmpty() && dialogue.toDouble() > 0.00 && re.exactMatch(dialogue)){ //on vérifie si l'input n'est pas vide ou supérieur à 0
                if(bd->envoieDonneesContributions(id , utilisateur, idCagnotte, dialogue,"1")){ //on entre les données corrects dans la base de donneés
                    if(dialogue.toDouble()<= bd->getMontant(bd->obtenirIdCagnotte(ui->label->text()))){
                        double diff =bd->getMontant(bd->obtenirIdCagnotte(ui->label->text()))- dialogue.toDouble();
                        bd->updateMontant(idCagnotte, QString::number(diff));
                        ui->montantValue->setText(QString::number(bd->getMontant(bd->obtenirIdCagnotte(ui->label->text())))+ " €");
                        qDebug() << "ui->montant: " << ui->montantValue->text().toDouble() ;
                    }else{
                        //Message erreur
                        QMessageBox msgBox;
                        msgBox.setWindowTitle("Opération impossible");
                        msgBox.setText("\n\nLe montant que vous souhaitez retirer est supérieur au solde de la cagnotte.");
                        msgBox.exec();
                    }

                } else {
                    qDebug() << "Erreur dans la base de données";
                }
           } else {
               QMessageBox msgBox;

               msgBox.critical(this, tr(" Erreur ! "), tr("Veuillez saisir un montant de la forme XXX.XX ! "),
                               QMessageBox::Ok);
               msgBox.setStyleSheet("QMessageBox { text-align:justify;}"
                                    "QLabel{color:red;}"
                                    "QPushButton{ border-width: 2px;"
                                    "border-style: solid;"
                                    "border-radius: 3px;"
                                    "border-color: black;"
                                    "background: qlineargradient(spread:pad, x1:1 y1:1, x2:0, y2:0, stop:0 #F2F3F4, stop:1 #CACFD2);}");

               msgBox.setButtonText(QMessageBox::Ok, " Ok ");
           }
           if(bd->getMontant(bd->obtenirIdCagnotte(ui->label->text()))>=bd->getObjectif(bd->obtenirIdCagnotte(ui->label->text()))){
               ui->label_4->setVisible(true);
           }else{
              ui->label_4->setVisible(false);
           }
}


void FenetreCagnotte::on_accepterRetrait_clicked()
{
    model.changerFenetre("autorisation");

}

void FenetreCagnotte::afficherSuppressionCagnotte(bool isVisible){
    ui->cloturerButton->setVisible(isVisible);
}
