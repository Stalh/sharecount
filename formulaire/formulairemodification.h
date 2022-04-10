#ifndef FORMULAIREMODIFICATION_H
#define FORMULAIREMODIFICATION_H
#include "formulaire.h"

/**
 * @brief Le FormulaireAuthentification permer de modifier l'adresse mail et le mot de passe d'un utilisateur
 * @author C. Mathias
 * @author G. Zimol
 * @author R. Martini
 */

class FormulaireModification : public Formulaire
{
public:
    /**
     * @brief FormulaireModification Constructeur
     */
    FormulaireModification();
    /**
     * @brief verifModificationMail  vérifier les données saisies
     * @return vrai si le nouveau mail est correctement rensiegné
     */
    bool verifModificationMail();
    /**
     * @brief verifModificationMdp  vérifier les données saisies
     * @return vrai si le nouveau mdp est correctement rensiegné
     */
    bool verifModificationMdp();
};

#endif // FORMULAIREMODIFICATION_H
