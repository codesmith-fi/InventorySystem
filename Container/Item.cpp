/**
 * Item, a base class for all Items, can't be instantiated
 * Items are held by Bags
 *
 * Project: InventorySystem
 * Author: Erno Pakarinen
 * Date: 29th March 2021
 * mailto: codesmith.fi@gmail.com
 */
#include "Item.h"

namespace codesmith {
	namespace Container {
		const std::string Item::KDefaultItemName = "A item";

		Item::Item(const Item& other) {
			*this = other;
		}

		Item& Item::operator=(const Item& other)
		{
			iName = other.iName;
			return *this;
		}

		bool Item::isContainer() const 
		{ 
			return false; 
		}

		const std::string Item::name() const {
			return iName;
		}

		void Item::setName(const std::string& name)
		{
			iName = name;
		}

	}
}
