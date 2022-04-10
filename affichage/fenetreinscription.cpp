#include "fenetreinscription.h"

FenetreInscription::FenetreInscription(BaseDeDonnees* bd,Model &model,QWidget *parent)
    : Fenetre(bd,model, parent), ui(new Ui::FenetreInscription)
{
    ui->setupUi(this);
    ui->label_4->setVisible(false);
}



FenetreInscription::~FenetreInscription()
{
    delete ui;
}

void FenetreInscription::on_sendMailButton_clicked()
{
    //récupérer les données de l'utilisateur
    QString id, mail, mdp;
    id = ui->lineEdit_identifiant->text();
    mail = ui->lineEdit_mail->text();
    mdp = ui->lineEdit_mdp->text();

    //les données utilisés pour la verfication du formulaire inscription + verification du formulaire

    std::vector<std::pair<std::string,std::string>> donneesASauvegarder;

    donneesASauvegarder.push_back(std::make_pair(("id"),id.toStdString()));
    donneesASauvegarder.push_back(std::make_pair(("mail"),mail.toStdString()));
    donneesASauvegarder.push_back(std::make_pair(("mdp"),mdp.toStdString()));

    formulaireInscription.initialiserDonnees(donneesASauvegarder);


    if(formulaireInscription.verifInscription() && bd->envoieDonneesInscription(id,mail,mdp)){
        ui->label_4->setVisible(true);
        this->dialogue.setMessageParam("noreplysharecount@gmail.com", mail);
        this->dialogue.envoyerMail("Bienvenue !", "Nous sommes heureux de vous avoir parmi nous !\n ");

    } else {
        QMessageBox msgBox;

        msgBox.critical(this, tr(" Erreur ! "), tr("Les informations sont incorrectes!\n\nMerci de saisir tous les champs et de vérifier que vous n'avez pas un compte avec l'identifiant et l'adresse mail saisies."),
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

}

void FenetreInscription::on_sauthentifierButtonScreen_clicked()
{
    ui->lineEdit_identifiant->clear();
    ui->lineEdit_mail->clear();
    ui->lineEdit_mdp->clear();
    ui->label_4->hide();

    model.changerFenetre("authentification");
}

