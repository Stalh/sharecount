#ifndef FORMULAIRECONTACT_H
#define FORMULAIRECONTACT_H

#include "formulaire.h"


/**
 * @brief Le FormulaireContact permet de contacter un admin
 * @file formulairecontact.h
 * @author C. Mathias
 * @author G. Zimol
 * @author R. Martini
 * @version 1.0
 */
class FormulaireContact : public Formulaire
{
public:
    /**
     * @brief Constructeur de FormulaireContact
     */
    FormulaireContact();

    /**
     * @brief verifContact
     * @return vrai si les informations sont valides
     */
    bool verifContact();
};

#endif // FORMULAIRECONTACT_H
