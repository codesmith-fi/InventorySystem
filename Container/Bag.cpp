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
						LOG_WARN() << " -> Item \"" << newItem->name() << "\" already exists in the inventory";
						return false;
					}
				}
				iItems.push_back(newItem);
				LOG_INFO() << " -> New item added to bag \"" << name() << "\" : " << newItem->name();
				return true;
			}
			else {
				return false;
			}
		}

		TItemListPointer Bag::findItem(const std::string& partial)
		{
			TItemListPointer results(new TItemList);
			for (auto item : iItems) {
				if (item->name().find(partial) != std::string::npos) {
					results->push_back(item);
				}
			}
			return results;
		}
	}
}
