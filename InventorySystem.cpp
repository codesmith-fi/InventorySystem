/**
 * InventorySystem
 * 
 * A base line OO design and implementation for a full and extendable
 * inventory system for games that require that the player character
 * and perhaps also other entities like monsters can carry a various
 * number of different kind of items
 * 
 * The aim for this is to make a general inventory container that
 * can be used for multiple purposes. Include an inventory for
 * a player or a monster, having multiple bags. Or a stash container
 * for player stash, again having multiple stash slots for bags/containers.
 * 
 * Author: Erno Pakarinen
 * Date: 29th March 2021
 * mailto: codesmith.fi@gmail.com
 */
#include <iostream>
#include <memory>
#include "Container/Inventory.h"
#include "Container/Bag.h"
#include "util/DebugLogger.h"

using namespace codesmith::Container;

int main(int argc, char** argv)
{
    LOG_INFO() << "Here's an example use of the Inventory System";

    Inventory inv(10);
    LOG_INFO() << "Initial state:";
    LOG_INFO() << "Current number of bags in the inventory is " << inv.bagCount();
    LOG_INFO() << "Inventory can hold " << inv.maxBagLimit() << " bags";
    LOG_INFO() << "Total number of items in the inventory is " << inv.itemCount();
    LOG_INFO() << "";
    LOG_INFO() << "Adding two new bags";

    std::shared_ptr<Bag> b1(new Bag(20, "Bag 1"));
    std::shared_ptr<Bag> b2(new Bag(10, "Bag 2"));

    inv.addBag(b1);
    inv.addBag(b2);

    LOG_INFO() << "Now there are " << inv.bagCount() << " bags in the inventory";
    LOG_INFO() << "Maximum number of items allowed in is " << inv.maxItemLimit();

    return 0;
}


