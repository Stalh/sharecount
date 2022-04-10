#ifndef FENETRECONSULTERMESDEPENSES_H
#define FENETRECONSULTERMESDEPENSES_H

#include "fenetre.h"
#include <QMessageBox>
#include <ui_fenetreconsultermesdepenses.h>

/**
 * @file fenetreconsultermesdepenses.h
 * @brief La class FenetreConsulterMesDepenses affiche l'ensemble des dépenses de l'utilisateur sur un gestionnaire de budget en particulier
 * @version 1.0
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 */
QT_BEGIN_NAMESPACE
namespace Ui { class FenetreConsulterMesDepenses; }
QT_END_NAMESPACE

class FenetreConsulterMesDepenses: public Fenetre
{
    Q_OBJECT
private:
    Ui::FenetreConsulterMesDepenses *ui; /*!< Instance ui de la fenetre  >*/
    QSqlTableModel* modelSql;/*!< Données de la table d'affichage des dépenses de l'utilisateur*/
    QString titre; /*!< titre du gestionnaire*/
public:
    /**
     * @brief fenetreConsulterMesDepenses Constructeur
     * @param bd Base de données
     * @param model model
     * @param parent widget interface
     */
    explicit FenetreConsulterMesDepenses(BaseDeDonnees* bd, Model &model, QWidget *parent = nullptr);
    ~FenetreConsulterMesDepenses();
    /**
     * @brief setTitre Modifie le label de la page (nom du gestionnaire) à partir du paramètre
     * @param label Nouveau nom du titre
     */
    void setTitre(const QString label);
    /**
     * @brief setTableGdb Modifie les données de la table d'affichage
     */
    void setTableGdb();
    /**
     * @brief setTableGdbDepenses Actualise la table des dépenses affichée à partir de la table dans la base de données
     */
    void setTableGdbDepenses();



private slots:
    void on_logo_clicked();

    void on_supprimerDepensesButton_clicked();

};

#endif // FENETRECONSULTERMESDEPENSES_H
