#include "fenetregdb.h"

#include <QInputDialog>
#include <QMessageBox>

/**
 * @file fenetregdb.cpp
 * @brief La class FenetreGdb affiche l'ensemble des dépenses du gestionnaire et gère les opérations sur un gestionnaire de budget
 * @version 1.0
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 */
FenetreGDB::FenetreGDB(BaseDeDonnees* bd, Model &model, QWidget *parent) : Fenetre(bd, model, parent),ui(new Ui::FenetreGDB)
{
    ui->setupUi(this);
}

FenetreGDB::~FenetreGDB()
{
    delete ui;
    delete modelSql;
}

void FenetreGDB::on_logo_clicked()
{
    model.changerFenetre("menu");
}

void FenetreGDB::setTitre(QString label){
    this->titre = label;
    ui->label->setText(label);
    setTableGdb();
}

void FenetreGDB::setTableGdb(){
    modelSql =bd->getGdbDepenses(bd->obtenirIdGDB(this->titre));
    ui->tableauDepenses->setModel(modelSql);
    ui->tableauDepenses->setSelectionBehavior(QAbstractItemView::SelectRows);//Selection de toute la ligne lorsqu'on clique
   //cacher les colonnes
    ui->tableauDepenses->hideColumn(0); // l'id de la depense
    ui->tableauDepenses->hideColumn(2); //l'id du gestionnaire
    ui->tableauDepenses->show();
}

void FenetreGDB::on_cloturerButton_clicked()
{
    bd->supprimerParticipantGDB(bd->obtenirIdGDB(ui->label->text()));
    bd->supprimerGDB(bd->obtenirIdGDB(ui->label->text()));
    model.changerFenetre("menu");
}


void FenetreGDB::on_invitationGDB_clicked()
{
    QMessageBox fenetreCode;
    fenetreCode.setWindowTitle("Inviter un ami");
    QString id = bd->obtenirIdGDB(ui->label->text());
    fenetreCode.setButtonText(QMessageBox::Ok , " Copier ");
    fenetreCode.setText("Partagez ce code pour inviter à rejoindre ce gestionnaire!\n  " + id);
    fenetreCode.setStyleSheet("QPushButton{ width:71px;height:31px;border-width: 2px; border-style: solid;border-radius: 3px; border-color: black; background: qlineargradient(spread:pad, x1:1 y1:1, x2:0, y2:0, stop:0 #F2F3F4, stop:1 #CACFD2);} ");

    if(fenetreCode.exec()==QMessageBox::Ok ){
        //copier le code dans le clipboard de l'utilisateur
        QClipboard *clipboard = QApplication::clipboard();
        clipboard->setText(id);
    }

}

void FenetreGDB::afficherSuppressionGDB(bool isVisible){
    ui->cloturerButton->setVisible(isVisible);
}

void FenetreGDB::on_ajouterDepensesButton_clicked()
{
    model.setTitreGdbDepense(this->titre);
    model.changerFenetre("depenses");
}



void FenetreGDB::on_consulterButton_clicked()
{
    qDebug()<< this->titre;
    model.setTitre("mesDepenses", this->titre);
    model.changerFenetre("mesDepenses");
}

