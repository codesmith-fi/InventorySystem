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
#include "Container/Inventory.h"
#include "util/DebugLogger.h"

using namespace codesmith::Container;

int main(int argc, char** argv)
{
    LOG_INFO() << "Here's an example use of the Inventory System";

    Inventory inv;
    LOG_INFO() << "Current number of bags in my inventory is " << inv.bagCount();
    LOG_INFO() << "Total number of items in held is " << inv.itemCount();
    return 0;
}


