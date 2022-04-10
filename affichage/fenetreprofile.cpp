#include "fenetreprofile.h"

#include <QInputDialog>


FenetreProfile::FenetreProfile(BaseDeDonnees* bd, Model &model, QWidget *parent)
    : Fenetre(bd,model, parent), ui(new Ui::FenetreProfile){
    ui->setupUi(this);
}


FenetreProfile::~FenetreProfile()
{
    delete ui;
}

void FenetreProfile::on_logo_clicked()
{
    model.changerFenetre("menu");
}
void FenetreProfile::on_changerMailButton_clicked()
{
    bool ok = false;
    QMessageBox message;

    QString dialogue = QInputDialog::getText(this, "Mail", "Saisir votre nouvelle adresse", QLineEdit::Normal, QString(), &ok);

       if (ok && !dialogue.isEmpty()){
           std::vector<std::pair<std::string,std::string>> donneesASauvegarder;
           donneesASauvegarder.push_back(std::make_pair(("mail"),dialogue.toStdString()));
           formulaireModification.initialiserDonnees(donneesASauvegarder);
            if(formulaireModification.verifModificationMail() && bd->changerMail(QString::fromStdString(model.getUtilisateur()->getId()), dialogue)){
                model.getUtilisateur()->setMail(dialogue.toStdString());
                //ui->mailUtilisateur->setText(QString::fromStdString(model.getUtilisateur()->getMail()));
                message.setText("\nVotre adresse a été changée ! ");
                message.exec();
                model.afficherMail();
             }else{
                message.critical(this, tr(" Erreur ! "), tr("\nAdresse mail invalide (ou déjà utilisée)!"),
                                QMessageBox::Ok);
                message.setStyleSheet("QMessageBox { text-align:justify;}"
                                     "QLabel{color:red;}"
                                     "QPushButton{ border-width: 2px;"
                                     "border-style: solid;"
                                     "border-radius: 3px;"
                                     "border-color: black;"
                                     "background: qlineargradient(spread:pad, x1:1 y1:1, x2:0, y2:0, stop:0 #F2F3F4, stop:1 #CACFD2);}");

                message.setButtonText(QMessageBox::Ok, " Ok ");
            }
       }
}



void FenetreProfile::on_changerMdpButton_clicked()
{
    bool ok = false;
    QMessageBox message;

       QString dialogue = QInputDialog::getText(this, "Mot de passe", "Saisir votre nouveau mot de passe", QLineEdit::Normal, QString(), &ok);

       if (ok && !dialogue.isEmpty()){
           std::vector<std::pair<std::string,std::string>> donneesASauvegarder;
           donneesASauvegarder.push_back(std::make_pair(("mdp"),dialogue.toStdString()));
           formulaireModification.initialiserDonnees(donneesASauvegarder);
            if(formulaireModification.verifModificationMdp() && bd->changerMdp(QString::fromStdString(model.getUtilisateur()->getId()), dialogue)){
                model.getUtilisateur()->setMotDePasse(dialogue.toStdString());
                message.setText("\nVotre mot de passe a été changé ! ");
                message.exec();

             }else{
                message.critical(this, tr(" Erreur ! "), tr("\nMot de passe invalide!"),
                                QMessageBox::Ok);
                message.setStyleSheet("QMessageBox { text-align:justify;}"
                                     "QLabel{color:red;}"
                                     "QPushButton{ border-width: 2px;"
                                     "border-style: solid;"
                                     "border-radius: 3px;"
                                     "border-color: black;"
                                     "background: qlineargradient(spread:pad, x1:1 y1:1, x2:0, y2:0, stop:0 #F2F3F4, stop:1 #CACFD2);}");

                message.setButtonText(QMessageBox::Ok, " Ok ");
            }
       }
}


void FenetreProfile::on_suppCompteButton_clicked()
{
    QMessageBox fenetreVerifSuppression;
    fenetreVerifSuppression.setWindowTitle("Confirmation");
    fenetreVerifSuppression.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    fenetreVerifSuppression.setButtonText(QMessageBox::Ok,"Oui");
    fenetreVerifSuppression.setButtonText(QMessageBox::Cancel,"Non");
    fenetreVerifSuppression.setText("Voulez-vous vraiment supprimer votre compte ?");

    if(fenetreVerifSuppression.exec() == QMessageBox::Ok){
        bd->supprimerParticipantGDBCascade(QString::fromStdString(model.getUtilisateur()->getId()));
        bd->supprimerParticipantCagnotteCascade(QString::fromStdString(model.getUtilisateur()->getId()));
        bd->supprimerGDBCascade(QString::fromStdString(model.getUtilisateur()->getId()));
        bd->supprimerCagnotteCascade(QString::fromStdString(model.getUtilisateur()->getId()));
        bd->supprimerUtilisateur(QString::fromStdString(model.getUtilisateur()->getId()));
        model.deconnexion();

    }

}


void FenetreProfile::afficherMail(){
    ui->mailUtilisateur->setText(QString::fromStdString(model.getUtilisateur()->getMail()));
}

