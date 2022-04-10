#ifndef FENETREVISUCAGNOTTE_H
#define FENETREVISUCAGNOTTE_H

#include <QWidget>

#include <QWidget>
#include "model.h"
#include "fenetre.h"
#include "ui_fenetrevisucagnotte.h"


/**
 * @file fenetrevisugdb.h
 * @brief La class FenetreVisuCagnotte représente la fenetre de visualisation de la liste de cagnottes aux quelles un utilisateur participe
 * @version 1.0
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 */

QT_BEGIN_NAMESPACE
namespace Ui { class FenetreVisuCagnotte; }
QT_END_NAMESPACE

class FenetreVisuCagnotte:public Fenetre
{
    Q_OBJECT
public:
    /**
     * @brief FenetreVisuCagnotte Constructeur
     * @param bd Base de Données
     * @param model de l'application
     * @param parent widget interface affichage
     */
    FenetreVisuCagnotte(BaseDeDonnees* bd,Model &model, QWidget *parent =nullptr);
    ~FenetreVisuCagnotte();
    /**
     * @brief visuCagnotte met à jour l'affichage de la list view des cagnottes
     */
    void visuCagnotte();
private slots:
    /**
     * @brief on_logo_clicked retour au menu
     */
    void on_logo_clicked();
    /**
     * @brief on_deconnexionButton_clicked se déconnecter
     */
    void on_deconnexionButton_clicked();
    /**
     * @brief on_listViewCagnotte_doubleClicked écouteur des items de la listview
     * @param index nom de l'item
     */
    void on_listViewCagnotte_doubleClicked(const QModelIndex &index);

private :
    Ui::FenetreVisuCagnotte *ui;/*!< Instance de l'ui de la fenêtre de création de cagnotte >*/
    QSqlQueryModel *modelList; /*!< instance du model de la liste des cagnottes de l'utilisateur>*/
};

#endif // FENETREVISUCAGNOTTE_H
