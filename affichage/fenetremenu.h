#ifndef FENETREMENU_H
#define FENETREMENU_H
#include <ui_fenetremenu.h>
#include "affichage/fenetre.h"

/**
 * @file fenetremenu.h
 * @brief La class FenetreMenu représente le menu proposé à l'utilisateur une fois connecté
 * @version 1.0
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 */
QT_BEGIN_NAMESPACE
namespace Ui { class FenetreMenu; }
QT_END_NAMESPACE

class FenetreMenu : public Fenetre
{
    Q_OBJECT

private:
    Ui::FenetreMenu *ui; /*!< ui de la fenetre*/

public:
    /**
     * @brief Constructeur de FenetreMenu
     * @param parent
     */
    explicit FenetreMenu(BaseDeDonnees* bd, Model &model, QWidget *parent = nullptr);

    /**
     * @brief Destructeur de FenetreMenu
     */
    ~FenetreMenu();

private slots:
    /**
     * @brief on_contact_clicked écouteur du bouton contactez-nous
     */
    void on_contact_clicked();
    /**
     * @brief on_creerCagnotte_clicked écouteur du bouton créer cagnotte: ouvre la fenetre de creation cagnotte
     */
    void on_creerCagnotte_clicked();
    /**
     * @brief on_creationGDB_clicked écouteur du bouton créer gdb: ouvre la fenêtre de creation Gdb
     */
    void on_creationGDB_clicked();
    /**
     * @brief on_deconnexionButton_clicked se déconnecter
     */
    void on_deconnexionButton_clicked();

    /**
     * @brief on_visualisation_clicked écouteur bouton visualisation Gdb
     */
    void on_visualisation_clicked();

    /**
     * @brief on_visualisation_2_clicked écouteur bouton visualisation cagnotte
     */
    void on_visualisation_2_clicked();
    /**
     * @brief on_rejoindreGDB_clicked écouteur bouton ok quand on rejoint un gdb
     */
    void on_rejoindreGDB_clicked();
    /**
     * @brief on_rejoindreCagnotte_clickedécouteur bouton ok quand on rejoint un gdb
     */
    void on_rejoindreCagnotte_clicked();
    void on_user_clicked();
};

#endif // FENETREMENU_H
