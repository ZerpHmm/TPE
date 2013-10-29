#ifndef GWRULES_HPP
#define GWRULES_HPP

#include <map>
#include <vector>
#include "global.hpp"
#include "math/Probability.hpp"

class GWEntity;

/**
 *  @class GWRules
 *  @brief Règles régissant la reproduction des GWEntity d'un GWTree
 *         Contient une suite de probabilité. La somme des probabilités de cette suite doit être égale à 1
 *  @see GWTree
**/
    class GWRules
    {
        public:
            typedef std::map<uint, Probability> ProbabilityMap;

        public:
            GWRules(); /// @brief Warning ! Rules are empty
            GWRules(const std::vector<Probability> &vec); /// @brief vec[0] proba 0 children ; vec[1] proba 1 children ; ...
            ~GWRules(); /// @brief Destructor

            /**
             *  @brief Réimplémentation des fonctions de std::map
            **/
                /**
                 *  @brief set
                 *  @param i Number of children
                 *  @param p Probability
                 *  @return true ssi la probabilité n'existait pas encore (dans le cas contraire, l'ancienne probabilité est écrasée)
                 */
                    bool set(uint i, Probability p);

                Probability get(uint i) const;  /// @return 0 si la probabilité n'existe pas
                bool contains(uint i) const;    /// @brief Check if the probability exists
                bool isEmpty() const;           /// @brief Check if there is no probabilities
                uint size() const;              /// @return Number of probabilities in the map
                bool remove(uint i);            /// @return false ssi la probabilité n'existe pas
                void clear();                   /// @brief Remove all probabilities

            bool isValid() const; /// @return true ssi la somme des probabilités vaut 1

        /**
         * @brief getChildrenAverage
         * @return La moyenne du nombre d'enfants par entité selon childrenProbas
         */
            Fraction getChildrenAverage() const;

        /**
         *  @brief Fonction principale
         *         Toute-puissante qui décide de combien de gosses le GWEntity accouchera
         *  @param GWEntity
        **/
            virtual uint givebirth(const GWEntity&) const;

        protected:
            ProbabilityMap childrenProbas; /// @brief Association [Number of children] <=> [Probability]
    };

#endif // GWRULES_HPP
