    #include "formulaire.h"

/**
 * @file formulaire.cpp
 * @brief La classe Formulaire sauvegarde les données entrées et les expressions régulières pour vérifier les données
 * @author C. Mathias
 * @version 1.0
 */

const std::string &Formulaire::getDonnee(const std::string nomDonnee) const
{
    return donnees.at(nomDonnee);
}

void Formulaire::setDonnee(const std::string &nomDonnee,const std::string &newDonnee)
{
    donnees.insert({nomDonnee, newDonnee});
}

const std::regex &Formulaire::getPattern(const std::string regex) const
{
    return patterns.at(regex);
}

void Formulaire::setPattern(const std::string idPattern,const std::regex &newPattern)
{
    patterns.insert({idPattern, newPattern});
}

void Formulaire::initialiserDonnees(std::vector<std::pair<std::string,std::string>> donneesASauvegarder){
    donnees.clear();
    for (unsigned i=0 ; i<donneesASauvegarder.size() ; i++) {
        std::cout<< donneesASauvegarder.at(i).first<< "  " << donneesASauvegarder.at(i).second <<std::endl;
        this->donnees.insert(donneesASauvegarder.at(i)); //On enregistre les données entrées dans notre collection pour pouvoir les vérifier après
    }


    //On enregistre les expressions régulières
    std::regex patternId {".+"}; //Pattern d'un identifiant (au moins un caractère)

    //Pattern d'une adresse mail
    std::regex patternMail {"^[^@]+@(gmail.com|free.fr|wanadoo.fr|yahoo.com|icloud.com|hotmail.fr|hotmail.com|orange.fr|sfr.fr|laposte.net)$"};

    //Pattern d'un mot de passe (8 caractères)
    std::regex patternMDP {".{8,}"};

    //Pattern d'un nom/prenom
    std::regex patternPrenom {"^[a-zA-Z ,.'éùàè-]+[^0-9&_:;!?+=§@]$"};

    std::regex patternNom {"^[a-zA-Z ,.'éùàè-]+[^0-9&_:;!?+=§@]$"};


    //Ajout à la liste d'expressions régulières
    this->patterns.insert(std::pair<std::string,std::regex>("id",patternId));

    //Ajout à la liste d'expressions régulières
    this->patterns.insert(std::pair<std::string,std::regex>("mail",patternMail));
    this->patterns.insert(std::pair<std::string,std::regex>("mdp",patternMDP));
    this->patterns.insert(std::pair<std::string,std::regex>("prenom", patternPrenom));
    this->patterns.insert(std::pair<std::string,std::regex>("nom", patternNom));


}

Formulaire::Formulaire(){

}

bool Formulaire::verifierDonnees(){
    return std::regex_match(donnees.at("id"),patterns.at("id")) && verifierMotDePasse(); //L'identifiant entré ne respecte pas l'expression régulière

}

bool Formulaire::verifIdentite(){
    return std::regex_match(donnees.at("prenom"),patterns.at("prenom")) && std::regex_match(donnees.at("nom"),patterns.at("nom"));
}

bool Formulaire::verifierMail(){
    return std::regex_match(donnees.at("mail"),patterns.at("mail"));
}

bool Formulaire::verifierMotDePasse(){
    return std::regex_match(donnees.at("mdp"),patterns.at("mdp"));
}

bool Formulaire::verifNom(){
    return std::regex_match(donnees.at("nom"),patterns.at("nom"));
}
