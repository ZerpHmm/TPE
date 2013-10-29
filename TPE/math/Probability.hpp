#ifndef MATH_PROBABILITY_HPP
#define MATH_PROBABILITY_HPP

#include "global.hpp"
#include "Fraction.hpp"

/**
 *  @class Probability
 *  @brief Double compris entre 0 et 1 inclus
**/
    class Probability final
    {
        public:
            Probability();           /// @pre Probability = 0
            Probability(Fraction p); /// @pre 0 <= p <= 1
            ~Probability();          /// @brief Destructor

        /**
         *  @brief Operators
        **/
            Probability& operator*=(const Probability&);
            Probability& operator=(Fraction p); /// @pre 0 <= p <= 1

            const Fraction& frac() const; /// @brief Getter


        private:
            Fraction proba;
    };

//////////////////////
// class Probability
//////////////////////

    //////////////////////
    // Inline methods
    //////////////////////

    inline const Fraction& Probability::frac() const {
        return proba;
    }

#endif // MATH_PROBABILITY_HPP
