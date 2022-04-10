#include "fenetreconsultermesdepenses.h"

/**
 * @file fenetreconsultermesdepenses.cpp
 * @brief La class FenetreConsulterMesDepenses affiche l'ensemble des dépenses de l'utilisateur sur un gestionnaire de budget en particulier
 * @version 1.0
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 */
FenetreConsulterMesDepenses::FenetreConsulterMesDepenses(BaseDeDonnees *bd, Model &model, QWidget *parent)
    : Fenetre(bd, model, parent),ui(new Ui::FenetreConsulterMesDepenses)
{
    ui->setupUi(this);
}

FenetreConsulterMesDepenses::~FenetreConsulterMesDepenses(){
    delete ui;
}

void FenetreConsulterMesDepenses::on_logo_clicked()
{
    //faire revenir à fenetre gdb actuel
    if (bd->isCreateurCompte("gestionnaire_de_budget",this->titre,QString::fromStdString(model.getUtilisateur()->getId()))){
        model.afficherSuppressionGDB(true);
    }else {
        model.afficherSuppressionGDB(false);
    }
    model.changerFenetre("gdb");
}


void FenetreConsulterMesDepenses::setTitre(QString label){
    ui->label->setText(label);
    this->titre = label;
    setTableGdbDepenses();//On actualise la table affichée
}

void FenetreConsulterMesDepenses::setTableGdbDepenses(){

    //Récupération des dépenses à partir de la base de données
    modelSql =bd->getGdbDepensesUtilisateur(QString::fromStdString(model.getUtilisateur()->getId()),bd->obtenirIdGDB(this->titre)); //On récupère les dépenses de l'utilisateur
    //Ajout des données à la table affichée
    ui->tableauDepenses->setModel(modelSql);
    ui->tableauDepenses->setSelectionBehavior(QAbstractItemView::SelectRows);
   //cacher les colonnes
    ui->tableauDepenses->hideColumn(0); // l'id de la depense
    ui->tableauDepenses->hideColumn(1); // l'id de l'utilisateur
    ui->tableauDepenses->hideColumn(2); //l'id du gestionnaire
    ui->tableauDepenses->show();
}

void FenetreConsulterMesDepenses::on_supprimerDepensesButton_clicked()
{

    QMessageBox fenetreVerifSuppression;
    fenetreVerifSuppression.setWindowTitle("Confirmation");
    fenetreVerifSuppression.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    fenetreVerifSuppression.setButtonText(QMessageBox::Ok,"Oui");
    fenetreVerifSuppression.setButtonText(QMessageBox::Cancel,"Non");

    fenetreVerifSuppression.setText("Voulez-vous vraiment supprimer les dépenses sélectionnées?");
    fenetreVerifSuppression.setStyleSheet("QPushButton{ width:71px;height:31px; border-width: 2px; border-style: solid;border-radius: 3px; border-color: black; background: qlineargradient(spread:pad, x1:1 y1:1, x2:0, y2:0, stop:0 #F2F3F4, stop:1 #CACFD2);} ");
    if(fenetreVerifSuppression.exec() == QMessageBox::Ok){
        QModelIndexList indexes =  ui->tableauDepenses->selectionModel()->selectedRows(); ;
        int countRow = indexes.count();

        for( int i = countRow; i > 0; i--){
            //On supprime les lignes que l'utilisateur a selectionné
            modelSql->removeRow( indexes.at(i-1).row(), QModelIndex());
            model.actualiserTableau();
            setTableGdbDepenses();
            //On supprime les lignes de la base de données
            bd->supprimerDepense(indexes.at(i-1).data(Qt::DisplayRole).toString());
        }
    }
}
