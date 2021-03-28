#include "Bag.h"
#include "../util/DebugLogger.h"

namespace codesmith {
	namespace Container {
		const std::string Bag::KDefaultBagName = "Bag";

		unsigned int Bag::size() const
		{
			return iItemLimit;
		}

		unsigned int Bag::count() const
		{
			return 0;
		}

		const std::string Bag::name() const
		{
			return iName;
		}

		unsigned int Bag::weight() const
		{
			int weight = 0;
			for (auto item : iItems) {
				weight += item->weight();
			}
			return weight;
		}

		bool Bag::addItem(std::shared_ptr<Item> newItem)
		{
			// TODO: Allows duplicates for now, add a check later
			if (iItems.size() < iItemLimit) {
				for (auto item : iItems) {
					if (item == newItem) {
						LOG_INFO() << "Item \"" << item->name() << "\" already exists in the inventory";
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
