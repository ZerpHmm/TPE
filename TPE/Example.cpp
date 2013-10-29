#include "global.hpp"
#include <iostream>
#include "GWEntity.hpp"
#include "GWRules.hpp"
#include "math/Probability.hpp"

void tpe::example1()
{
    std::cout.precision(2);

    GWRules rules({
        Fraction(1, 10),
        Fraction(18, 100),
        Fraction(40, 100),
        Fraction(22, 100),
        Fraction(7,  100),
        Fraction(3,  100)
    });

    const int NB_TEST = 1000000;

    // [nombre d'enfants par femme] <=> [nombre de femmes sur NB_TEST tests]
    std::map<uint, uint> map;

    for(int i(0) ; i < NB_TEST ; ++i)
    {
        GWEntity entity;

        map[
            entity.processReproduction(rules)
        ]++;
    }

    for(uint i(0) ; i < rules.size() ; ++i)
    {
        debug(
            "Proba ", i, " enfants = simulation:",
            Fraction(map[i], NB_TEST).toDouble(),
            " ; théorique: ",
            rules.get(i).frac().toDouble()
        );
    }

    double total(0.0);

    for(uint i(0) ; i < rules.size() ; ++i)
    {
        total += i * map[i];
    }

    debug("Nombre moyen d'enfants (simulation): ", total / NB_TEST);
    debug("Nombre moyen d'enfants (théorique): ", rules.getChildrenAverage().toDouble());
}
