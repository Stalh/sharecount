#ifndef FORMULAIREINSCRIPTION_H
#define FORMULAIREINSCRIPTION_H
#include "formulaire.h"

/**
 * @brief The FormulaireInscription class
 * @file formulaire.h
 * @author C. Mathias
 * @author G. Zimol
 * @author R. Martini
 * @version 1.0
 */
class FormulaireInscription : public Formulaire
{
public:

    /**
     * @brief Constructeur de FormulaireInscription
     */
    FormulaireInscription();

    /**
     * @brief verifInscription
     * @return boolean true si les données sont valides
     */
    bool verifInscription();
};

#endif // FORMULAIREINSCRIPTION_H
