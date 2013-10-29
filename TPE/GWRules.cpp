#include "GWRules.hpp"
#include <algorithm>
#include "GWEntity.hpp"

//////////////////////
// class GWRules
//////////////////////

    GWRules::GWRules()
    {
    }

    GWRules::GWRules(const std::vector<Probability> &vec)
    {
        for(uint i = 0 ; i < vec.size() ; ++i)
        {
            this->set(i, vec[i]);
        }
    }

    GWRules::~GWRules() {
        // Nothing to do
    }

    /////////////////////////////////////////////
    // Réimplémentation de fonctions de std::map
    /////////////////////////////////////////////

    bool GWRules::set(uint i, Probability p)
    {
        bool alreadyExists(false);

        if(this->contains(i))
        {
            alreadyExists = true;
        }

        childrenProbas[i] = p;
        return alreadyExists;
    }

    Probability GWRules::get(uint i) const
    {
        if(this->contains(i))
        {
            return childrenProbas.at(i);
        }
        else
        {
            return Fraction(0);
        }
    }

    bool GWRules::contains(uint i) const
    {
        return childrenProbas.find(i) != childrenProbas.end();
    }

    bool GWRules::isEmpty() const
    {
        return childrenProbas.empty();
    }

    uint GWRules::size() const
    {
        return childrenProbas.size();
    }

    bool GWRules::remove(uint i)
    {
        if(!this->contains(i))
        {
            return false;
        }
        else
        {
            childrenProbas.erase(childrenProbas.find(i));
            return true;
        }
    }

    void GWRules::clear()
    {
        childrenProbas.clear();
    }

    /////////////////////////////////////////////
    // isValid
    /////////////////////////////////////////////

    bool GWRules::isValid() const
    {
        Fraction result;

        for(const std::pair<uint, Probability> &p : childrenProbas) {
            result += p.second.frac();
        }

        return (result == 1);
    }

    /////////////////////////////////////////////
    // getChildrenAverage
    /////////////////////////////////////////////

    Fraction GWRules::getChildrenAverage() const
    {
        Fraction result;

        for(uint i(0) ; i < childrenProbas.size() ; ++i)
        {
            result += (get(i).frac() * i);
        }

        return result;
    }

    /////////////////////////////////////////////
    // givebirth
    /////////////////////////////////////////////

    uint GWRules::givebirth(const GWEntity&) const
    {
        C_PRE(this->isValid());

        const double d(drand());
        Fraction f;

        for(const std::pair<uint, Probability> &p : childrenProbas)
        {
            f += p.second.frac();

            if(f.toDouble() > d)
            {
                return p.first;
            }
        }

        // Impossible
        FATAL();
    }
