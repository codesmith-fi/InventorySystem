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
#include "Container/BasicItem.h"
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

    // Create few items
    std::shared_ptr<BasicItem> i1(new BasicItem("Uber sword"));
    i1->setValue(1000);
    std::shared_ptr<BasicItem> i2(new BasicItem("Shield of Overburdening"));
    i2->setValue(100);
    std::shared_ptr<BasicItem> i3(new BasicItem("Shining Ring of Divorcement"));
    i3->setValue(12345);
    std::shared_ptr<BasicItem> i4(new BasicItem("Unbelievable crap"));
    i4->setValue(10);
    i4->setWeight(100000);

    b1->addItem(i1);
    b1->addItem(i2);
    b1->addItem(i3);
    b2->addItem(i4);

    LOG_INFO() << "Now there are " << inv.bagCount() << " bags in the inventory";
    LOG_INFO() << "Maximum number of items allowed in is " << inv.maxItemLimit();
    for (auto bag : inv) {
        LOG_INFO() << "Bag name \"" << bag->name() << "\", size limit=" << bag->size();
        for (auto item : *bag) {
            BasicItem* bi = dynamic_cast<BasicItem*>(item.get());
            if(bi) {
                LOG_INFO() << " -> Basic item \"" << bi->name() << "\"" << " weights " << bi->weight() << " and valued at " << bi->value();
            }
            else {
                LOG_INFO() << " -> ??? undefined item type: " << item->name();
            }
        }
    }

    return 0;
}
