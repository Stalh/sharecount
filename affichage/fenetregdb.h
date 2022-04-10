#ifndef FENETREGDB_H
#define FENETREGDB_H

#include <ui_fenetregdb.h>
#include "affichage/fenetre.h"
#include <QWidget>
#include <QClipboard>
#include <ui_fenetredepenses.h>
/**
 * @file fenetregdb.h
 * @brief La class FenetreGdb affiche l'ensemble des dépenses du gestionnaire et gère les opérations sur un gestionnaire de budget
 * @version 1.0
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 */
QT_BEGIN_NAMESPACE
namespace Ui { class FenetreGDB; }
QT_END_NAMESPACE

class FenetreGDB : public Fenetre
{
    Q_OBJECT
private:
    Ui::FenetreGDB *ui; /*!< ui de la fenetre*/
    QString titre; /*!< titre du gestionnaire*/
    QSqlTableModel* modelSql;
public:
    /**
     * @brief FenetreGDB Constructeur
     * @param bd Base De Données de l'application
     * @param model
     * @param parent widget interface
     */
    explicit FenetreGDB(BaseDeDonnees* bd, Model &model, QWidget *parent = nullptr);
    ~FenetreGDB();
    /**
     * @brief setTitreGDB Modifie le label représentant le titre dans la fenêtre d'un gestionnaire
     * @param label Le nouveau titre
     */
    void setTitre(const QString label);
    /**
     * @brief setTableGdb met à jour les informations du tableau
     */
    void setTableGdb();
    /**
     * @brief afficherSuppressionGDB Modifie l'affichage du bouton pour clôturer le gestionnaire
     * @param isEnabled Le nouvel affichage
     */
    void afficherSuppressionGDB(bool isVisible);

private slots:
    /**
     * @brief on_logo_clicked retour au menu
     */
    void on_logo_clicked();
    /**
     * @brief on_cloturerButton_clicked fermer le gestionnaire de budget
     */
    void on_cloturerButton_clicked();
    /**
     * @brief on_invitationGDB_clicked inviter à rejoindre un gestionnaire
     */
    void on_invitationGDB_clicked();
    /**
     * @brief on_ajouterDepensesButton_clicked écouteur du bouton ajouter une dépense
     */
    void on_ajouterDepensesButton_clicked();

    void on_consulterButton_clicked();
};

#endif // FENETREGDB_H
