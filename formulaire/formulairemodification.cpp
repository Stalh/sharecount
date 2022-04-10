#include "formulairemodification.h"

FormulaireModification::FormulaireModification() : Formulaire()
{

}


bool FormulaireModification::verifModificationMail(){
    return Formulaire::verifierMail();
}


bool FormulaireModification::verifModificationMdp(){
    return Formulaire::verifierMotDePasse();
}
