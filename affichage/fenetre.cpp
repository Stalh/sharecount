#include "fenetre.h"

Fenetre::Fenetre(BaseDeDonnees* bd,Model &model ,QWidget *parent)
    : QWidget(parent),bd(bd), model(model)
{

}

void Fenetre::setTitre(QString label){

}

