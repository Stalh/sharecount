#ifndef FENETRECAGNOTTE_H
#define FENETRECAGNOTTE_H

#include <ui_fenetrecagnotte.h>
#include <QWidget>
#include "affichage/fenetre.h"
#include <QMessageBox>
#include <QClipboard>
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class FenetreCagnotte; }
QT_END_NAMESPACE

class FenetreCagnotte : public Fenetre
{
    Q_OBJECT
private:
     Ui::FenetreCagnotte *ui; /*!< ui de la fenetre*/
public:
     /**
      * @brief FenetreCagnotte Constructeur d'une fenetre de cagnotte
      * @param bd La base de données
      * @param gest Le gestionnaire gérant les fenêtres
      * @param parent widget
      */
    explicit FenetreCagnotte(BaseDeDonnees* bd, Model &model, QWidget *parent = nullptr);
     /**
      * @brief Destructeur
      */
     ~FenetreCagnotte();
     /**
      * @brief setTitreCagnotte Modifie le label représentant le titre dans la fenêtre d'une cagnotte
      * @param label Le nouveau titre
      */
     void setAffichageCagnotte(const QString label, const QString objectif);

     /**
      * @brief afficherSuppressionCagnotte Modifie l'affichage du bouton pour clôturer la cagnotte
      * @param isEnabled Le nouvel affichage
      */
     void afficherSuppressionCagnotte(bool isVisible);
private slots:
     void on_logo_clicked();
     void on_cloturerButton_clicked();
     void on_inviterCagnotte_clicked();
     void on_ajouterArgentButton_clicked();
     void on_consulterContributions_clicked();
     void on_retirerArgentButton_clicked();
     void on_accepterRetrait_clicked();
};

#endif // FENETRECAGNOTTE_H
