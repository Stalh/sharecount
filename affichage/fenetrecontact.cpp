#include "fenetrecontact.h"

FenetreContact::FenetreContact(BaseDeDonnees* bd,Model &model,  QWidget *parent)
    : Fenetre(bd,model, parent), ui(new Ui::FenetreContact)
{
    ui->setupUi(this);
}


FenetreContact::~FenetreContact(){
    delete ui;
}

void FenetreContact::on_goBackToMenu_clicked()
{
    ui->prenomContact->setText("");
    ui->nomContact->setText("");
    ui->mailContact->setText("");
    ui->messageContact->setText("");
    model.changerFenetre("menu");
}


void FenetreContact::on_sendContact_clicked()
{
    QString prenom,nom, mail, message;
    prenom = ui->prenomContact->text();
    nom = ui->nomContact->text();
    mail = ui->mailContact->text();
    message = ui->messageContact->text();

    std::vector<std::pair<std::string,std::string>> donneesASauvegarder;

    donneesASauvegarder.push_back(std::make_pair(("prenom"),prenom.toStdString()));
    donneesASauvegarder.push_back(std::make_pair(("nom"),nom.toStdString()));
    donneesASauvegarder.push_back(std::make_pair("mail", mail.toStdString()));

    QMessageBox msgBox;
    if(!message.isEmpty() && !mail.isEmpty()){
        qDebug()<< prenom << nom << mail << message;
        this->dialogue.setMessageParam(mail, "noreplysharecount@gmail.com");
        this->dialogue.envoyerMail("Demande de la part d'un utilisateur", message);
        qDebug() << "mail envoyé";
        msgBox.setText("Merci. Nous avons bien reçu votre demande.\n Nous essayerons d'y donner suite dans les plus brefs délais. ");
        msgBox.exec();
        ui->prenomContact->setText("");
        ui->nomContact->setText("");
        ui->mailContact->setText("");
        ui->messageContact->setText("");
    }
    formulaireContact.initialiserDonnees(donneesASauvegarder);

    bool res = formulaireContact.verifContact();
    if(!res){
        msgBox.setText("Nom ou prenom invalide !");
        msgBox.exec();
    }


}


void FenetreContact::on_deconnexionButton_clicked()
{
    model.deconnexion();
    model.changerFenetre("authentification");
}

