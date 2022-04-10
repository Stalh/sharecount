#include "idgenerator.h"
#include <iostream>
using namespace std;

/**
 * @file idgenerator.cpp
 * @brief Singleton permettant de générer des identifiants
 * @author G.Zimol
 * @version 1.0
 */

IdGenerator IdGenerator::m_instance=IdGenerator();

IdGenerator::IdGenerator()
{
    lastIdCompte = 1;
}

int IdGenerator::getNewIdCompte()
{
    int idAReturn = this-> lastIdCompte;       //Sauvegarde de l'id à retourner avant incrémentation
    this -> lastIdCompte ++;                   //Incrémentation
    return idAReturn;
}

IdGenerator& IdGenerator::Instance()
{
    return m_instance;
}
