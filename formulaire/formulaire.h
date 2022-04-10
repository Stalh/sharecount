#ifndef FORMULAIRE_H
#define FORMULAIRE_H

#include <iostream>
#include <map>
#include <vector>
#include <regex>

/**
 * @file formulaire.h
 * @brief La classe Formulaire sauvegarde les données entrées et les expressions régulières pour vérifier les données
 * @author C. Mathias
 * @version 1.0
 */

class Formulaire {

public:
    /**
     * @brief getDonnee retourne la donnée enregistrée en fonction du nom donnée en paramètre
     * @param nomDonnee Nom de la donnée à rechercher
     * @return La valeur de la donnée
     */
    const std::string &getDonnee(const std::string nomDonnee) const;

    /**
     * @brief setDonnee modifie la valeur de la donnée dont le nom est passé en paramètre par la nouvelle valeur
     * @param nomDonnee Donnée dont on doit modifier la valeur
     * @param newDonnee Nouvelle valeur de la donnée
     */
    void setDonnee(const std::string &nomDonnee,const std::string &newDonnee);
    /**
     * @brief getPattern retourne l'expression regulière enregistrée en fonction du nom donnée en paramètre
     * @param regex Nom de l'expression à rechercher
     * @return La valeur de l'expression régulière
     */
    const std::regex &getPattern(std::string regex) const;
    /**
     * @brief setDonnee modifie la valeur de la donnée dont le nom est passé en paramètre par la nouvelle valeur
     * @param nomDonnee Donnée dont on doit modifier la valeur
     * @param newDonnee Nouvelle valeur de la donnée
     */
    void setPattern(const std::string idPattern,const std::regex &newPattern);

    /**
     * @brief initialiserDonnees ajoute les données dans donneesASauvegarder
     * @param donneesASauvegarder
     */
    void initialiserDonnees(std::vector<std::pair<std::string,std::string>> donneesASauvegarder);


protected:
        std::map<std::string,std::string> donnees;  /*!< Données entrées par l'utilisateur dans le formulaire*/

        std::map<std::string, std::regex> patterns; /*!< Expressions régulières que les données de l'utilisateur doivent respecter*/
        /**
         * @brief Constructeur d'un formulaire
         */
        Formulaire();
        /**
         * @brief Retourne vrai si les données correspondent aux expressions régulières
         * @return Vrai si les données sont correctes, faux sinon
         */
        bool verifierDonnees();

        /**
         * @brief verifIdentite
         * @return Vrai si les données sont valides, faux sinon
         */
        bool verifIdentite();

        bool verifierMail();

        bool verifierMotDePasse();

        bool verifNom();

};
#endif // FORMULAIRE_H
