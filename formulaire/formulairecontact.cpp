#include "formulairecontact.h"

FormulaireContact::FormulaireContact()
{

}

bool FormulaireContact::verifContact(){

    return Formulaire::verifIdentite();

}
