/*
 * Inventory, main container for the whole Inventory System
 *
 * Project: InventorySystem
 * Author : Erno Pakarinen
 * Date : 29th March 2021
 * mailto : codesmith.fi@gmail.com
 */

#include "Inventory.h"
#include "../util/DebugLogger.h"

using namespace codesmith::Debug;

namespace codesmith
{
	namespace Container
	{
		size_t Inventory::bagCount() const {
			return iBags.size();
		}

		int Inventory::itemCount() const {
			return 0;
		}

		bool Inventory::addBag(const std::shared_ptr<Bag> newBag)
		{
			if (iBags.size() < iBagLimit) {
				for (auto bag : iBags) {
					if (bag == newBag) {
						LOG_WARN() << "Bag \"" << bag->name() << "\" already exists";
						return false;
					}
				}
				iBags.push_back(newBag);
				return true;
			} else {
				return false;
			}
			return true;
		}

		size_t Inventory::maxBagLimit() const
		{
			return iBagLimit;
		}

		int Inventory::maxWeightLimit() const
		{
			return iWeightLimit;
		}

		unsigned int Inventory::weight() const
		{
			int w = 0;
			for (auto bag : iBags) {
				w += bag->weight();
			}
			return w;
		}

		size_t Inventory::maxItemLimit() const
		{
			int c = 0;
			for (auto bag : iBags) {
				c += bag->size();
			}
			return c;
		}

		TItemListPointer Inventory::findItem(const std::string& partial) const
		{
			TItemListPointer results(new TItemList);
			for (auto bag : iBags) {
				TItemListPointer bagRes(bag->findItem(partial));
				if(bagRes->size() > 0 ) {
					for (auto bagItem : *bagRes) {
						results->push_back(bagItem);
					}
				}
			}
			return results;
		}

		TFindResultsPointer Inventory::findItemWithBag(const std::string& partial) const
		{
			TFindResultsPointer results(new TFindResults);
			for (auto bag : iBags) {
				TItemListPointer bagRes(bag->findItem(partial));
				if (bagRes->size() > 0) {
					for (auto bagItem : *bagRes) {
						results->insert(std::pair< TBagPointer, TItemPointer>(bag, bagItem));
					}
				}
			}
			return results;
		}
	}
}
