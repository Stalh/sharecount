#ifndef FENETRECREATIONCAGNOTTE_H
#define FENETRECREATIONCAGNOTTE_H

#include <QWidget>
#include "affichage/fenetre.h"
#include <QMessageBox>
#include "ui_fenetrecreationcagnotte.h"

namespace Ui {
class FenetreCreationCagnotte;
}
/**
 * @file fenetrecreationcagnotte.h
 * @brief La class FenetreCreationCagnotte représente la page permettant à l'utilisateur de se créer une cagnotte
 * @version 1.0
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 */
class FenetreCreationCagnotte : public Fenetre
{
    Q_OBJECT

public:
    /**
     * @brief FenetreCreationCagnotte Constructeur
     * @param bd Base de données
     * @param model
     * @param parent widget interface
     */
    explicit FenetreCreationCagnotte(BaseDeDonnees* bd,Model &model, QWidget *parent = nullptr);
    ~FenetreCreationCagnotte();

private slots:

    /**
     * @brief on_logo_clicked Permet de retourner au menu
     */
    void on_logo_clicked();
    /**
     * @brief on_creerCagnotte_clicked écouteur creation cagnotte
     */
    void on_creerCagnotte_clicked();

private:
    Ui::FenetreCreationCagnotte *ui;/*!< Instance de l'ui de la fenêtre de création de cagnotte >*/
};

#endif // FENETRECREATIONCAGNOTTE_H
