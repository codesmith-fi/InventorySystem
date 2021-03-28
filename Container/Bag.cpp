#include "Bag.h"
#include "../util/DebugLogger.h"

namespace codesmith {
	namespace Container {
		const std::string Bag::KDefaultBagName = "Bag";

		size_t Bag::size() 
		{
			return iItemLimit;
		}

		int Bag::count() 
		{
			return 0;
		}

		const std::string Bag::name() const
		{
			return iName;
		}

		bool Bag::addItem(std::shared_ptr<Item> newItem)
		{
			// TODO: Allows duplicates for now, add a check later
			if (iItems.size() < iItemLimit) {
				for (auto item : iItems) {
					LOG_INFO() << "Item \"" << item->name() << "\" already exists in the inventory";
					if (item == newItem) {
						return false;
					}
				}
				iItems.push_back(newItem);
				return true;
			}
			else {
				return false;
			}
		}
	}
}
