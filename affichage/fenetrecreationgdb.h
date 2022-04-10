#ifndef FENETRECREATIONGDB_H
#define FENETRECREATIONGDB_H

#include <QWidget>
#include <QMessageBox>
#include <iostream>
#include "affichage/fenetre.h"
#include "formulaire/formulairecompte.h"

namespace Ui {
class FenetreCreationGdb;
}

class FenetreCreationGdb : public Fenetre
{
    Q_OBJECT

public:
    /**
     * @brief FenetreCreationGdb Constructeur
     * @param bd    Base de Données
     * @param gestFenetres  Gestionnaire de Fenetres
     * @param parent    la widget
     */
    explicit FenetreCreationGdb(BaseDeDonnees* bd,Model &model, QWidget *parent = nullptr);
    /**
     * @brief Destructeur
     */
    ~FenetreCreationGdb();

private slots:

    /**
     * @brief on_logo_clicked retourner vers la fenetre menu
     */
    void on_logo_clicked();
    /**
     * @brief on_creerGdb_clicked écouteur du bouton creer Gdb : crée un gestionnaire
     */
    void on_creerGdb_clicked();

private:
    Ui::FenetreCreationGdb *ui; /*!< Instance de l'ui de la fenetre*/

};

#endif // FENETRECREATIONGDB_H
