#ifndef BASEDEDONNEES_H
#define BASEDEDONNEES_H

#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <iostream>


/**
 * @file basededonnees.h
 * @brief La class BaseDeDonnees génére et gère la base de données
 * @version 1.0
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 */
class BaseDeDonnees
{
public:
    /**
     * @brief BaseDeDonnees Constructeur
     */
    BaseDeDonnees();
    /**
     * @brief envoieDonneesInscription envoyer les données à la bdd
     * @param id identifiant de l'utilisateur
     * @param mail adresse mail de web
     * @param mdp mot de passe de l'utilisateur
     */
    bool envoieDonneesInscription(QString id, QString mail, QString mdp);

    /**
     * @brief verificationUtilisateur verification des données
     * @param id
     * @param mdp
     * @return booleen true si l'utilisateur et son mdp sont bien dans la base de donnée
     */
    bool verificationUtilisateur(QString id, QString mdp);
    /**
     * @brief envoieDonneesGdb envoyer les données à la bdd
     * @param nom du gestionnaire de budget
     * @param description du gestionnaire
     */
    void envoieDonneesGdb(QString id, QString nom, QString description,  QString idUtilisateur);

    /**
     * @brief envoieDonneesCagnotte envoyer les données à la bdd
     * @param nom   nom de la cagnotte
     * @param description de la cagnoote
     * @param objectif montant que l'on souhaite atteindre (par défaut = 0)
     */
    void envoieDonneesCagnotte(QString id, QString nom, QString description, QString objectif,  QString idUtilisateur);

    /**
     * @brief getMailUtilisateur fonction pour récupérer le mail d'un utilisateur à partir de son id
     * @param id de l'utilisateur
     * @return mail de l'utilisateur
     */
    QString getMailUtilisateur(std::string id);

    /**
     * @brief ajouterUtilisateurACagnotte ajoute l'utilisateur à une cagnotte en tant que participant
     * @param nom de la cagnotte
     * @param nomUtilisateur
     */
    void ajouterUtilisateurACagnotte(QString nom, QString nomUtilisateur);
    /**
     * @brief ajouterUtilisateurAuGdb ajoute l'utilisateur à un gdb en tant que participant
     * @param nom du gdb
     * @param nomUtilisateur
     */
    void ajouterUtilisateurAuGdb(QString nom, QString nomUtilisateur);

    /**
     * @brief supprimerGDB
     * @param titre
     */
    void supprimerGDB(QString titre);

    /**
     * @brief supprimerParticipantGDB
     * @param id
     */
    void supprimerParticipantGDB(QString id);

    /**
     * @brief obtenirIdGDB
     * @param titre
     * @return l'id du gestionnaire budget
     */
    QString obtenirIdGDB(QString titre);
    /**
     * @brief obtenirMontantDepense
     * @param nomDepense
     * @return
     */
    QString obtenirMontantDepense(QString nomDepense);
    /**
     * @brief supprimerCagnotte
     * @param id
     */
    void supprimerCagnotte(QString id);

    /**
     * @brief supprimerParticipantCagnotte
     * @param id
     */
    void supprimerParticipantCagnotte(QString id);

    /**
     * @brief obtenirIdCagnotte
     * @param titre
     * @return l'id de la cagnotte
     */
    QString obtenirIdCagnotte(QString titre);

    /**
     * @brief getGdbUtilisateur Récupérer la liste de gdb auxquels participe l'utilisateur
     * @param idUtilisateur connecté
     * @return  model pour la listview
     */
    QSqlQueryModel* getGdbUtilisateur(QString idUtilisateur);

    /**
     * @brief getCagnottesUtilisateur Récupérer la liste de cagnottes aux quelles participe l'utilisateur
     * @param idUtilisateur connecté
     * @return model pour la listview
     */
    QSqlQueryModel* getCagnottesUtilisateur(QString idUtilisateur);

    /**
     * @brief idExist
     * @param id
     * @return  vrai si l'id du gdb est dans la bdd
     */
    bool idGdbExist(QString id);
    /**
     * @brief idCagnotteExist
     * @param id
     * @return  vrai si l'id de la cagnotte est dans la bdd
     */
    bool idCagnotteExist(QString id);

    /**
     * @brief supprimerutilisateur
     * @param id
     */
    void supprimerUtilisateur(QString id);
    /**
     * @brief supprimerGDBCascade supprimer les gdb de l'utilisateur lorsqu'il supprime son compte
     * @param id de l'utilisateur
     */
    void supprimerGDBCascade(QString id);
    /**
     * @brief supprimerCagnotteCascades supprimer les cagnottes de l'utilisateur lorsqu'il supprime son compte
     * @param id de l'utilisateur
     */
    void supprimerCagnotteCascade(QString id);
    /**
     * @brief supprimerParticipantCagnotteCascade supprimer l'utilisateur de la liste des participants à une cagnotte
     * @param id de l'utilisateur
     */
    void supprimerParticipantCagnotteCascade(QString id);
    /**
     * @brief supprimerParticipantGDBCascade supprimer l'utilisateur de la liste des participants à un gdb
     * @param id de l'utilisateur
     */
    void supprimerParticipantGDBCascade(QString id);
    /**
     * @brief supprimerDepense supprimer la dépense
     * @param idDep identifiant de la depense à supprimer
     */
    void supprimerDepense(QString idDep);
    /**
     * @brief changerMail mise à jour du mail de l'utilisateur dans la base de données
     * @param id de l'utilisateur
     * @param mail la nouvelle adresse mail
     */
    bool changerMail(QString id, QString mail);
    /**
     * @brief changerMdp mise à jour du mot de passe de l'utilisateur dans la base de données
     * @param id de l'utilisateur
     * @param mdp nouveau mot de passe
     */
    bool changerMdp(QString id, QString mdp);
    /**
     * @brief getObjectif
     * @param id de la cagnotte
     * @return l'objectif de la cagnotte
     */
    double getObjectif(QString id);
    /**
     * @brief envoieDonneesDepenses ajout des données à la bdd
     * @param idDep identifiant unique de la dépense
     * @param idU identifiant de l'utilisateur
     * @param idGdb  identifiant de gestionnaire de budget
     * @param nomDep nom de la dépense
     * @return Vrai si toutes les données ont bien été saisies
     */
    bool envoieDonneesDepenses(QString idDep, QString idU , QString idGdb, QString nomDep, QString montant);
    /**
     * @brief getGdbDepensesUtilisateur
     * @param idUtilisateur l'utilisateur connecté
     * @param idGdb auquel appartient la dépense
     * @return liste des dépenses de l'utilisateur
     */
    QSqlQueryModel* getDepensesUtilisateur(QString idUtilisateur, QString idGdb);
    /**
     * @brief getGdbDepenses Retourne le tableau des données (tuples) des dépenses pour le gestionnaire dont l'id est passé en paramètre
     * @param idGdb
     * @return Tableau avec les données des dépenses pour un gestionnaire
     */
    QSqlTableModel* getGdbDepenses(QString idGdb);

    /**
     * @brief getGdbDepensesUtilisateur Retourne la table des données des dépenses de l'utilisateur pour un certain gestionnaire
     * @param idUtilisateur
     * @param idGdb
     * @return Le tableau des dépenses d'un utilisateur sur un des gestionnaires où il participe
     */
    QSqlTableModel* getGdbDepensesUtilisateur(const QString idUtilisateur,const QString idGdb);

    /**
     * @brief envoi les données des contributions
     * @param idU l'id de l'utilisateur
     * @param idCagnotte l'id de la Cagnotte
     * @param montant
     * @param demandeRetrait indique si l'utilisateur fait une demande de retrait d'argent de la cagnotte
     * @return Vrai si toutes les données ont bien été saisies
     */
    bool envoieDonneesContributions(QString id, QString idU , QString idCagnotte, QString montant,QString demandeRetrait);

    /**
     * @brief BaseDeDonnees::updateMontant
     * @param idCagnotte
     * @param montant
     * @return
     */
    bool updateMontant(QString idCagnotte, QString montant);

    /**
     * @brief on obtient le montant de la cagnotte
     * @param id
     * @return return le montant
     */
    double getMontant(QString id);
    /**
     * @brief getContributionsUtilisateur retourne le montant que l'utilisateur a ajouté.
     * @param idUtilisateur utilisateur actuellement connecté
     * @return double : somme ajoutée par l'utilisateur
     */
    double getContributionsUtilisateur(QString idUtilisateur, QString idCagnotte);
    /**
     * @brief isCreateurCompte Vérifie si l'utilisateur d'id idUti est le créateur du compte d'id idCompte
     * @param tableComptes Nom de la table de comptes (gdb ou cagnotte)
     * @param idCompte id du gestionnaire ou de la cagnotte dont on veut le nom du créateur
     * @param idUti Numéro de l'utilisateur
     * @return Vrai si le créateur passé en paramètre est le créateur du compte, faux sinon
     */
    bool isCreateurCompte(QString tableComptes, QString idCompte,QString idUti);
private:
    QSqlDatabase bdd; /*!< Instance de l'objet QSqlDataBase >*/
};

#endif // BASEDEDONNEES_H
