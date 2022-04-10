#ifndef GESTIONNAIREDEBUDGET_H
#define GESTIONNAIREDEBUDGET_H

#include <iostream>
#include "compte.h"
/**
 * @file gestionnairedebudget.h
 * @brief Le gestionnaire de budget gère les dépenses d'un groupe d'utilisateurs sans transactions financières
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 * @version 1.0
 */
class GestionnaireDeBudget : public Compte
{
public:
    /**
     * @brief GestionnaireDeBudget Constructeur d'un gestionnaire de budget à partir du nom du gestionnaire et du créateur
     * @param nom Nom du gestionnaire
     * @param u Référence à l'utilisateur qui a créé le gestionnaire
     */
    GestionnaireDeBudget(std::string nom, Utilisateur& u);
};

#endif // GESTIONNAIREDEBUDGET_H
