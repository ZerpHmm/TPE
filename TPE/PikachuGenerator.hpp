#ifndef PIKACHUGENERATOR_HPP
#define PIKACHUGENERATOR_HPP

#include <map>
#include "math/Probability.hpp"

/**
 *  @brief PikachuGenerator
 *
 *      Modèle de reproduction (génération) des Pikachus
 *      Suite de probabilité
 *
 *      Normalement, la somme de la suite de probabilité doit être égale à 1.
 *      La vérification n'est pas présente pour ne pas ralentir les routines
 *
 *
 *  @see Pikachu
**/
    class PikachuGenerator final
    {
        public:

        /**
         *  @brief Constructeur par défaut
         *
         *  @param probs Initialise directement la suite de probabilités
         *
         *      probs[0] = probabilité d'avoir 0 enfants
         *      probs[N] = probabilité d'avoir N enfants
         *
        **/
            PikachuGenerator(const std::vector<Probability> &probs = {Fraction(1)});

        /**
         * @brief Destructor
        **/
            ~PikachuGenerator();

        private:
            std::map<uint, Probability> childrenProbas; /// Table associative [nombre d'enfants] <=> [probabilité d'avoir ce nombre d'enfants]
    };

#endif // PIKACHUGENERATOR_HPP
