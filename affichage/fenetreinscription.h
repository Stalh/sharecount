#ifndef FENETREINSCRIPTION_H
#define FENETREINSCRIPTION_H
#include <QMessageBox>

#include <ui_fenetreinscription.h>

#include "formulaire/formulaireinscription.h"
#include "smtp/SmtpMime"
#include "utilisateur/utilisateur.h"
#include "affichage/fenetre.h"
#include "outils/gestionnairedialogue.h"

/**
 * @file fenetreinscription.h
 * @brief La class FenetreIncription représente le menu proposé à l'utilisateur qui veut créer un compte
 * @version 1.0
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 */

QT_BEGIN_NAMESPACE
namespace Ui { class FenetreInscription; }
QT_END_NAMESPACE

class FenetreInscription : public Fenetre
{
    Q_OBJECT
private:
    Ui::FenetreInscription *ui; /*!< Instance de l'ui de la fenetre*/
    FormulaireInscription formulaireInscription; /*!< Instance du formulaire d'inscription*/
    GestionnaireDialogue dialogue;/*!< Instance du gestionnaire dialogue >*/
public:
    /**
     * @brief FenetreInscription Constructeur d'une fenetre
     * @param bd pointeur vers la base de données
     * @param parent widget
     */
    explicit FenetreInscription(BaseDeDonnees* bd,Model &model, QWidget *parent = nullptr);
    /**
     *  @brief destructeur
    */
    ~FenetreInscription();
private slots:
    /**
     * @brief on_sendMailButton_clicked écouteur bouton envoyer mail
     */
    void on_sendMailButton_clicked();
    /**
     * @brief on_sauthentifierButtonScreen_clicked écouteur s'authentifier
     */
    void on_sauthentifierButtonScreen_clicked();
};

#endif // FENETREINSCRIPTION_H
