#include "gestionnairedebudget.h"

/**
 * @file gestionnairedebudget.cpp
 * @brief Le gestionnaire de budget gère les dépenses d'un groupe d'utilisateurs sans transactions financières
 * @author R. Martini
 * @author G. Zimol
 * @author C. Mathias
 * @version 1.0
 */

GestionnaireDeBudget::GestionnaireDeBudget(std::string nom, Utilisateur& u):Compte(nom,u)
{

}
