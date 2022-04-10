#ifndef FENETREDEPENSES_H
#define FENETREDEPENSES_H

#include "fenetre.h"
#include "ui_fenetredepenses.h"
#include <QWidget>

/**
 * @file fenetredepenses.h
 * @brief La class FenetreDepenses permet de créer une dépense dans un gestionnaire de budget
 * @version 1.0
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 */
namespace Ui {
class FenetreDepenses;
}
class FenetreDepenses: public Fenetre
{
    Q_OBJECT
public:
    /**
     * @brief FenetreDepenses Constructeur
     * @param bd Base de données
     * @param model de l'applicaiton
     * @param parent widget de l'interface
     */
    FenetreDepenses(BaseDeDonnees* bd,Model &model, QWidget *parent = nullptr);
    /**
     * @brief setTitreGdbDepense mettre le titre du gdb dans la fenetre
     * @param label
     */
    void setTitreGdbDepense(const QString label);
private slots:
    void on_ajouterButton_clicked();
    /**
     * @brief on_logo_clicked retourner au menu
     */
    void on_logo_clicked();

private:
    Ui::FenetreDepenses *ui; /*!< Instance de l'ui de la fenetre*/

};

#endif // FENETREDEPENSES_H
