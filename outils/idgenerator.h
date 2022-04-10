#ifndef IDGENERATOR_H
#define IDGENERATOR_H

/**
 * @file idgenerator.h
 * @brief Singleton permettant de générer des identifiants
 * @author G.Zimol
 * @author C. Mathias
 * @author R. Martini
 * @version 1.0
 */
class IdGenerator
{
private:

        int lastIdCompte; /*!< dernier numero d'Id généré */
        static IdGenerator m_instance; /*!< Instance unique de IdGenerator privée */

        /**
          * @brief Constructeur privé de IdGenerator
          */
         IdGenerator();

    public:

        /**
         * @brief Permet d'obtenir l'instance unique de generatorId
         * @return l'instance unique de IdGenerator
         */
        static IdGenerator& Instance();

        /**
         * @brief fonction qui génère un id unique à chaque compte
         * @return un nouvel idCompte
         */
        int getNewIdCompte();

};

#endif // IDGENERATOR_H
