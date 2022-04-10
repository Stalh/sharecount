#ifndef CAGNOTTE_H
#define CAGNOTTE_H

#include <iostream>
#include "compte.h"

/**
 * @file cagnotte.h
 * @brief Une cagnotte gère l'argent d'un groupe d'utilisateurs
 * @author R. Martini
 * @version 1.0
 */
class Cagnotte: public Compte
{
protected:
    float montant; /*!< Montant de la cagnotte*/
    float objectif;  /*!< Objectif minimal à atteindre pour la cagnotte */
    std::string description;  /*!< Description de la cagnotte*/
public:
    /**
     * \brief Le constructeur permet de définir une cagnotte avec :
     * \param nom : nom de la cagnotte
     * \param objectif : la somme minimale souhaité pour la cagnotte
     * \param desctiption: quelques mots à propos de la cagnotte
     * \param u : Référence vers le créateur du compte
    */
    Cagnotte(std::string nom,float objectif,std::string description,Utilisateur& u);

    /**
     * @brief getMontant Retourne le montant de la cagnotte
     * @return Le montant de la cagnotte
     */
    float getMontant() const;

    /**
     * @brief setMontant Modifie le montant de la cagnotte par la valeur passée en paramètre
     * @param newMontant Le nouveau montant de la cagnotte
     */
    void setMontant(float newMontant);
    /**
     * @brief getObjectif Retourne la valeur de l'objectif de la cagnotte
     * @return La valeur de l'objectif de la cagnotte
     */
    float getObjectif() const;
    /**
     * @brief setObjectif Modifie la valeur de l'objectif par celle passée en paramètre
     * @param newObjectif Nouvelle valeur de l'objectif
     */
    void setObjectif(float newObjectif);
    /**
     * @brief getDescription Retourne la description de la cagnotte
     * @return La description
     */
    const std::string &getDescription() const;
    /**
     * @brief setDescription Modifie la description de la cagnotte par la chaine passée en paramètre
     * @param newDescription La nouvelle description
     */
    void setDescription(const std::string &newDescription);
};

#endif // CAGNOTTE_H
