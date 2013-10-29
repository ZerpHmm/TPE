#include "GWTree.hpp"
#include "GWEntity.hpp"

/**
 *  Constructor
 *
 *      At begin, the root and the last generation are the same
 *      The root has the generation-ID 0
**/
    GWTree::GWTree(GWEntity *root) :
        gw_root(root),
        lastGenID(0)
    {
        gw_root->setGenID(0);
        lastGen.push_back(gw_root);
    }

/**
 *  Destructor
**/
    GWTree::~GWTree()
    {
        delete gw_root, gw_root = 0;
    }


/**
 *  Getters
**/
    void GWTree::setRules(const GWRules& r)
    {
        gw_rules = r;
    }

    const GWRules& GWTree::rules() const
    {
        return gw_rules;
    }

    GWRules& GWTree::rules()
    {
        return gw_rules;
    }

    uint GWTree::generations() const
    {
        return lastGenID + 1;
    }

void GWTree::processNextGen()
{
    lastGenID++;

    for(GWEntity* gwe : this->lastGen)
    {
        debug(gwe->getGenID(), " / ", lastGenID);
        gwe->processReproduction(this->gw_rules);
    }

    this->updateLastGenList();
}

/**
 *       A      <= gen 1
 *     B   C    <= gen 2
 *    D E F G   <= gen 3 (dernière génération, créée lors de processNextGen())
 *
 *  Avant appel, lastGen contient: B C
 *  Après appel, lastGen contient: D E F G
 *
 *  Add the new descendants (iterator's current value children) before the iterator
 *  And erase the parent
**/
    void GWTree::updateLastGenList()
    {
        typedef std::list<GWEntity*>::iterator
            Iterator;

        Iterator it = lastGen.begin();

        while(it != lastGen.end())
        {
            for(GWEntity *lastChild : (*it)->children())
            {
                it = lastGen.insert(it, lastChild);
                it++;
            }

            it = lastGen.erase(it);
        }
    }
