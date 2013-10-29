#include "Pikachu.hpp"
#include "global.hpp"
#include <iostream>

using namespace std;

/**
 *  Constructor
**/
    Pikachu::Pikachu(const PikachuGenerator &g, const Pikachu* const p) :
        parent(p),
        generator(&g)
    {
    }

/**
 *  Destructor
**/
    Pikachu::~Pikachu()
    {
        for(Pikachu* &p : children)
        {
            delete p, p = 0;
        }
    }

void Pikachu::reproduceMe()
{
}
