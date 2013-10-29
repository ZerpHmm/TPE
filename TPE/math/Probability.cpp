#include "Probability.hpp"

//////////////////////
// class Probability
//////////////////////

    Probability::Probability() :
        Probability(Fraction())
    {
    }

    Probability::Probability(Fraction p)
    {
        *this = p;
    }

    Probability::~Probability() {
        // Nothing to do
    }

    //////////////////////
    // Operators
    //////////////////////

    Probability& Probability::operator=(Fraction p)
    {
        C_PRE(p >= 0 && p <= 1);
            proba = p;

        return *this;
    }

    Probability& Probability::operator*=(const Probability &p)
    {
        proba *= p.frac();

        // Le résultat ne peut être que plus petit, pas de vérification:
        // [0;1]*[0;1] € [0;1]

        return *this;
    }
