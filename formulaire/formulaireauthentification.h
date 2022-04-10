#ifndef FORMULAIREAUTHENTIFICATION_H
#define FORMULAIREAUTHENTIFICATION_H
#include "formulaire.h"

/**
 * @brief Le FormulaireAuthentification permet de s'authentifier où de naviguer vers la page d'inscription
 * @author C. Mathias
 * @author G. Zimol
 * @author R. Martini
 */
class FormulaireAuthentification : public Formulaire
{
public:
    /**
     * @brief FormulaireAuthentification constructeur
     */
    FormulaireAuthentification();
    /**
     * @brief verifAuthentification
     * @return vrai si le compte existe
     */
    bool verifAuthentification();
};

#endif // FORMULAIREAUTHENTIFICATION_H
