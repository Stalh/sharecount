#ifndef MODEL_H
#define MODEL_H

#include "outils/gestionnairefenetres.h"
#include "utilisateur/gestionnaireutilisateur.h"
#include "outils/gestionnairedialogue.h"


class Model
{
public:
    Model(MainWindow& mainwindow);

    /**
     * @brief getFenetres getter des fenetres
     * @return la liste des fenetres
     */
    const std::map<std::string, Fenetre *> &getFenetres() const;

    /**
     * @brief changerFenetre  change la fenetre
     * @param nomFenetre
     */
    void changerFenetre(std::string nomFenetre);
    /**
     * @brief getUtilisateur
     * @return l'utilisateur connecté
     */
    Utilisateur *getUtilisateur() const;
    /**
     * @brief connexion connecter l'utilisateur
     * @param newUtilisateur compte de l'utilisateur
     */
    void connexion(Utilisateur *newUtilisateur);
    /**
     * @brief deconnexion deconnecter l'utilisateur
     */
    void deconnexion();
    /**
     * @brief visuGdb met à jour l'interface de visualisation gdb
     */
    void visuGdb();
    /**
     * @brief visuCagnotte met à jour l'interface de visualisation cagnotte
     */
    void visuCagnotte();

    /**
     * @brief setTitreGDB Modifie le label représentant le titre dans la fenêtre d'un gestionnaire
     * @param label Le nouveau titre
     */
    void setTitre(const QString pageSuivante, const QString label);
    /**
     * @brief setTitreGdbDepense Modifie le label du titre du gestionnaire dans la fenetre depenses
     * @param label titre du gestionnaire
     */
    void setTitreGdbDepense(const QString label);

    /**
     * @brief setTitreCagnotte Modifie le label représentant le titre dans la fenêtre d'une cagnotte
     * @param label Le nouveau titre
     * @param objectif de la cagnotte
     */
    void setAffichageCagnotte(const QString label, const QString objectif);
    /**
     * @brief afficherMail afficher le mail de l'utilisateur dans son espace personnel
     */
    void afficherMail();
    /**
     * @brief actualiserTableau Mettre à jour le tableau des dépenses (après la suppression d'une dépense)
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
    GestionnaireFenetres gestFenetres; /*!< instance du gestionnaire des fenetres */
    GestionnaireDialogue gestDialogue;/*!< instance du gestionnaire dialogue  */
    GestionnaireUtilisateur gestUtilisateur;/*!< instance du gestionnaire des utilisateurs */
    Utilisateur* utilisateur = nullptr; /*!< instance de l'utilisateur qui va se connecter, au départ c'est null*/

};

#endif // MODEL_H
