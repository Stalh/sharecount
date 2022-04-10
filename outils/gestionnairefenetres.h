#ifndef GESTIONNAIREFENETRES_H
#define GESTIONNAIREFENETRES_H

#include <map>
#include "outils/basededonnees.h"
/**
 * @file gestionnairefenetres.h
 * @brief La classe GestionnaireFenetres gère l'affichage des différentes fenêtres
 * @version 1.0
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 */

class FenetreAuthentification;
class FenetreInscription;
class FenetreContact;
class FenetreMenu;
class Fenetre;
class FenetreCreationCagnotte;
class FenetreCreationGdb;
class FenetreVisuGdb;
class FenetreVisuCagnotte;
class MainWindow;
class Model;
class FenetreGDB;
class FenetreCagnotte;
class FenetreProfile;
class FenetreDepenses;
class FenetreConsulterMesDepenses;


class GestionnaireFenetres
{
public:
    /**
     * @brief GestionnaireFenetres Constructeur d'un gestionnaire pour l'affichage des fenêtres
     */
    GestionnaireFenetres( MainWindow& mainwindow,  Model &model);
    /**jj
     * @brief lancerFenetre Affiche la fenêtre dont le nom est passé en paramètre
     * @param nomFenetre Le nom de la fenêtre que l'on veut afficher
     */
    void changerFenetre(const std::string nomFenetre);
    /**
     * @brief Destructeur du gestionnaire de fenetres
     */
    ~GestionnaireFenetres();
    /**
     * @brief getFenetres getter des fenetres
     * @return la liste des fenetres
     */
    const std::map<std::string, Fenetre *> &getFenetres() const;
    /**
     * @brief visuGdb mise à jour interface visualisaition Gdb
     */
    void visuGdb();
    /**
     * @brief visuCagnotte mise à jour interface visualisaition cagnottes
     */
    void visuCagnotte();


    /**
     * @brief setTitreGDB Modifie le label représentant le titre dans la fenêtre d'un gestionnaire
     * @param label Le nouveau titre
     */
    void setTitre(QString pageSuivante,QString label);
    /**
     * @brief setTitreCagnotte Modifie le label représentant le titre dans la fenêtre d'une cagnotte
     * @param label Le nouveau titre
     */
    void setAffichageCagnotte(QString label, QString objectif);
    /**
     * @brief afficherMail afficher le mail dans l'espace perso de l'utilisateur
     */
    void afficherMail();
    /**
     * @brief setTitreGdbDepense modifie l'affichage du titre du gdb dans la fenetre depense
     * @param label titre du gdb
     */
    void setTitreGdbDepense(QString label);

    /**
     * @brief Actualise le tableau de dépense lors de l'ajout d'une dépense
     */
    void actualiserTableau();

    /**
     * @brief afficherSuppressionGDB Modifie l'affichage du bouton pour clôturer le gestionnaire
     * @param isEnabled Le nouvel affichage
     */
    void afficherSuppressionGDB(bool isVisible);

    /**
     * @brief afficherSuppressionCagnotte Modifie l'affichage du bouton pour clôturer la cagnotte
     * @param isEnabled Le nouvel affichage
     */
    void afficherSuppressionCagnotte(bool isVisible);
private:
    BaseDeDonnees bd;   /*!< Base de données de l'application>*/

    std::map<std::string, Fenetre*> fenetres; /*!< La collection de fenêtres*/

    MainWindow& mainwindow;/*!< Pointeur vers la fenêtre principale*/

};

#endif // GESTIONNAIREFENETRES_H
