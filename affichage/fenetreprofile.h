#ifndef FENETREPROFILE_H
#define FENETREPROFILE_H

#include <ui_fenetreprofile.h>
#include <QWidget>
#include "affichage/fenetre.h"
#include "formulaire/formulairemodification.h"
#include <QMessageBox>




QT_BEGIN_NAMESPACE
namespace Ui { class FenetreProfile; }
QT_END_NAMESPACE

class FenetreProfile : public Fenetre
{
    Q_OBJECT
private:
    Ui::FenetreProfile *ui; /*!< ui de la fenetre*/
    FormulaireModification formulaireModification;/*!< instance du formulaire de modification*/

public:
    /**
     * @brief FenetreProfile Constructeur
     * @param bd Base de données
     * @param model
     * @param parent widget interface
     */
    explicit FenetreProfile(BaseDeDonnees* bd, Model &model, QWidget *parent = nullptr);
    ~FenetreProfile();
    /**
     * @brief afficherMail afficher le mail dans l'espace perso
     */
    void afficherMail();

private slots:
    /**
     * @brief on_logo_clicked retourner au menu
     */
    void on_logo_clicked();

    /**
     * @brief on_changerMailButton_clicked Changer le mail
     */
    void on_changerMailButton_clicked();
    /**
     * @brief on_changerMdpButton_clicked changer mot de passe
     */
    void on_changerMdpButton_clicked();
    /**
     * @brief on_suppCompteButton_clicked supprimer le compte
     */
    void on_suppCompteButton_clicked();

};

#endif // FENETREPROFILE_H
