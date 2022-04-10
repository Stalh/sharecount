#ifndef FENETREAUTHENTIFICATION_H
#define FENETREAUTHENTIFICATION_H
#include <QMessageBox>
#include <iostream>

#include <ui_fenetreauthentification.h>

#include "formulaire/formulaireauthentification.h"
#include "affichage/fenetre.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FenetreAuthentification; }
QT_END_NAMESPACE

/**
 * @file fenetreauthentification.h
 * @brief La class FenetreAuthentification représente le menu proposé à l'utilisateur qui veut se connecter
 * @version 1.0
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 */
class FenetreAuthentification : public Fenetre
{
    Q_OBJECT
private:
   Ui::FenetreAuthentification *ui;/*!< Instance de l'ui de la fenêtre d'authentification >*/
   FormulaireAuthentification formulaireauthentification; /*!< Instance du formulaire d'authentification*/
   bool cacherMdp;
public:
    /**
     * @brief FenetreAuthentification Constructeur d'une fenetre d'authentification
     * @param bd La base de données
     * @param gest Le gestionnaire gérant les fenêtres
     * @param parent widget
     */
    explicit FenetreAuthentification(BaseDeDonnees* bd, Model &model,  QWidget *parent = nullptr);

    /**
     * @brief Destructeur
     */
    ~FenetreAuthentification();

signals:

private slots:
    /**
     * @brief écouteur du bouton se connecter
     */
    void on_authentifierButton_clicked();
    /**
     * @brief on_creerCompteButton_clicked écouteur du bouton
     */
    void on_creerCompteButton_clicked();
    /**
     * @brief on_voirMdp_clicked écouteur du bouton voir/cacher le mot de passe
     */
    void on_voirMdp_clicked();
};

#endif // FENETREAUTHENTIFICATION_H
