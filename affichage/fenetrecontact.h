#ifndef FENETRECONTACT_H
#define FENETRECONTACT_H

#include <QMessageBox>

#include <ui_fenetrecontact.h>
#include "affichage/fenetre.h"
#include "formulaire/formulairecontact.h"
#include "outils/gestionnairedialogue.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FenetreContact; }
QT_END_NAMESPACE

class FenetreContact : public Fenetre
{
    Q_OBJECT
private:
    Ui::FenetreContact *ui; /*!< Instance ui de la fenetre  >*/
    FormulaireContact formulaireContact;/*!< Instance du formulaire de contact >*/
    GestionnaireDialogue dialogue; /*!< Instance du gestionnaire dialogue >*/
public:
    /**
     * @brief FenetreContact ui de contact
     * @param bd Base de Donnés
     * @param model
     * @param parent widget
     */
    explicit FenetreContact(BaseDeDonnees* bd, Model &model, QWidget *parent = nullptr);
    /**
     * Destructeur
     */
    ~FenetreContact();


private slots:
    /**
     * @brief on_goBackToMenu_clicked retour au menu
     */
    void on_goBackToMenu_clicked();
    /**
     * @brief on_sendContact_clicked écouteur contactez-nous : affiche le formulaire de contact
     */
    void on_sendContact_clicked();

    /**
     * @brief on_deconnexionButton_clicked se déconnecter
     */
    void on_deconnexionButton_clicked();
};

#endif // FENETRECONTACT_H
