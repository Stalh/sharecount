#include "utilisateur/utilisateur.h"
#include "utilisateur/gestionnaireutilisateur.h"
#include "outils/idgenerator.h"
#include "formulaire/formulaireinscription.h"


/*int main(int argc, char *argv[])
{
    Utilisateur utilisateur("pseudo","a@gmail.com","motDePasse");
    std::cout <<"Identifiant : " << utilisateur.getId() << std::endl;

    std::cout << "Gestionnaire : " <<std::endl;
    GestionnaireUtilisateur gu;
    //std::cout << gu << std::endl;

    std::cout << "ajout d'un utilisateur : " <<std::endl;
    gu.ajouterUtilisateur(utilisateur.getId(),utilisateur.getMail(),utilisateur.getMotDePasse());
    std::cout << "Test du gestionnaire utilisateur" << gu.getUtilisateur(utilisateur.getId()).getMail() << std::endl;
    std::cout << "Test du générateur d'id : "<<IdGenerator::Instance().getNewIdCompte() <<std::endl;

    FormulaireInscription fi;

    std::vector<std::pair<std::string,std::string>> donneesASauvegarder;

    donneesASauvegarder.push_back(std::make_pair(("id"),"1"));
    donneesASauvegarder.push_back(std::make_pair(("mail"),"guillaume.zimol@icloud.com"));
    donneesASauvegarder.push_back(std::make_pair(("mdp"),"lolmdr12"));

    fi.initialiserDonnees(donneesASauvegarder);

    std::regex pattern { ".*" }; // on recherche le motif "abc"
    std::string target { "dcfgvhbj" };
    bool result = std::regex_match(target, pattern);

    std::cout << "Les données sont :" << fi.verifInscription() <<std::endl;

    //std::cout << "Les données sont :" << result <<std::endl;


    return 0;
}*/
