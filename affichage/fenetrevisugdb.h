#ifndef FENETREVISUGDB_H
#define FENETREVISUGDB_H

#include <QWidget>
#include "model.h"
#include "fenetre.h"
#include "ui_fenetrevisugdb.h"


/**
 * @file fenetrevisugdb.h
 * @brief La class FenetreVisuGdb représente la fenetre de visualisation de la liste de gdb auquel un utilisateur participe
 * @version 1.0
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 */

QT_BEGIN_NAMESPACE
namespace Ui { class FenetreVisuGdb; }
QT_END_NAMESPACE

class FenetreVisuGdb : public Fenetre
{
    Q_OBJECT
public:
    /**
     * @brief Constructeur
     * @param bd
     * @param model
     * @param parent
     */
    FenetreVisuGdb(BaseDeDonnees* bd,Model &model, QWidget *parent =nullptr);


    ~FenetreVisuGdb();

    /**
     * @brief visuGdb met à jour l'affichage de la listview
     */
    void visuGdb();

    /**
     * @brief getTitreGDB  met à jour l'affichage du titre de la fenetre
     * @return
     */
    const QString &getTitreGDB() const;

private slots:
    /**
     * @brief Quand on clique sur le logo ça nous ramène au menu
     */
    void on_logo_clicked();

    /**
     * @brief On se déconnecte
     */
    void on_deconnexionButton_clicked();

    /**
     * @brief Quand on clique ça nous emmene au gestionnaire
     * @param index
     */
    void on_listViewGdb_doubleClicked(const QModelIndex &index);

private:
    Ui::FenetreVisuGdb *ui;/*!< Instance de l'ui de la fenêtre de visualisation de gestionnaires de budgets>*/
    QSqlQueryModel *modelList; /*!< Instance du model de la liste des gestionnaires de l'utilisateur>*/
};

#endif // FENETREVISUGDB_H
