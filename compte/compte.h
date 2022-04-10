#ifndef COMPTE_H
#define COMPTE_H

#include <iostream>
#include <vector>
#include <functional>
#include "../outils/idgenerator.h"
#include <sstream>
/**
 * @file compte.h
 * @brief Un Compte est une classe abstraite qui contient les éléments communs à la gestion d'argent d'un groupe
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 * @version 1.0
 */

//Référence à la classe Utilisateur (pour éviter la double inclusion Compte/Utilisateur)
class Utilisateur;

class Compte
{
protected :
    std::string nom; /*!< Nom du compte*/
    std::string code; /*!< Code unique au compte*/
    Utilisateur &createur; /*!< Référence au créateur du compte*/
    std::vector<std::reference_wrapper<Utilisateur>> utilisateurs; /*!< Liste des références vers les utilisateurs de la cagnotte*/

public:
    /**
     * @brief Constructeur d'un compte
     * @param nom Nom du compte
     * @param createur Référence à un Utilisateur qui est le créateur du compte
     */
    Compte(std::string nom,Utilisateur& createur);

    /**
     * @brief getNom Retourne le nom du compte
     * @return Le nom du compte
     */
    const std::string &getNom() const;
    /**
     * @brief setNom Modifie le nom du compte par celui passé en paramètre
     * @param newNom Nouveau nom du compte
     */
    void setNom(const std::string &newNom);
    /**
     * @brief getCode Retourne le code du compte
     * @return Le code du compte
     */
    const std::string &getCode() const;
    /**
     * @brief setCode Modifie le code du compte par celui donné en paramètre
     * @param newCode Le nouveau code du compte
     */
    void setCode(const std::string &newCode);
    /**
     * @brief getCreateur Retourne la référence du créateur du compte
     * @return La référence du créateur du compte
     */
    Utilisateur &getCreateur() const;

};

#endif // COMPTE_H
