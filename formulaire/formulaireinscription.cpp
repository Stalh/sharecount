#include "formulaireinscription.h"

FormulaireInscription::FormulaireInscription(): Formulaire()
{

}

bool FormulaireInscription::verifInscription(){
    return Formulaire::verifierDonnees() && Formulaire::verifierMail();
}

