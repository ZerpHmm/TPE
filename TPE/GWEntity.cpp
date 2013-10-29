#include "GWEntity.hpp"
#include "GWRules.hpp"

/**
 *  Constructors
**/
    GWEntity::GWEntity() :
        genID(0)
    {
    }

/**
 *  Destructor
**/
    GWEntity::~GWEntity()
    {
        killChildren();
    }

/**
 *  Getters
**/
    uint GWEntity::getGenID() const
    {
        return genID;
    }

    void GWEntity::setGenID(uint i)
    {
        genID = i;
    }

    uint GWEntity::nbchildren() const
    {
        return gw_children.size();
    }

    const std::vector<GWEntity*>& GWEntity::children() const
    {
        return gw_children;
    }

    std::vector<GWEntity*>& GWEntity::children()
    {
        return gw_children;
    }

uint GWEntity::processReproduction(const GWRules &god)
{
    killChildren();

    const uint nb(god.givebirth(*this));
    gw_children.reserve(nb);

    for(uint i(0) ; i < nb ; ++i)
    {
        gw_children.push_back(new GWEntity);
    }

    return this->nbchildren();
}

void GWEntity::killChildren()
{
    if(!gw_children.empty())
    {
        for(GWEntity* &gwe : gw_children)
        {
            delete gwe, gwe = 0;
        }

        gw_children.clear();
    }
}
