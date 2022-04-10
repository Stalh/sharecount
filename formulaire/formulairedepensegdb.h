#ifndef FORMULAIREDEPENSEGDB_H
#define FORMULAIREDEPENSEGDB_H

#include "formulaire/formulaire.h"


class FormulaireDepenseGdb : public Formulaire
{
public:
    /**
     * @brief FormulaireDepenseGdb Constructeur
     */
    FormulaireDepenseGdb();
    /**
     * @brief verifNom
     * @return  vrai si le nom de la dépense est correctement saisi
     */
    bool verifNom();
};

#endif // FORMULAIREDEPENSEGDB_H
