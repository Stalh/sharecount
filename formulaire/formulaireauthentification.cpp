#include "formulaireauthentification.h"


FormulaireAuthentification::FormulaireAuthentification(): Formulaire()
{

}

bool FormulaireAuthentification::verifAuthentification(){
    return Formulaire::verifierDonnees();

}
