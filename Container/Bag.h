/**
 * Bag, a single bag which is owned by the Inventory
 * This is a base class for every type of bag in the system
 * Can hold only items, not other bags
 *
 * Project: InventorySystem
 * Author: Erno Pakarinen
 * Date: 29th March 2021
 * mailto: codesmith.fi@gmail.com
 */

#ifndef __BAG_H_DEFINED__
#define __BAG_H_DEFINED__

#include <list>
#include <memory>
#include <string>
#include <iterator>
#include "Item.h"

namespace codesmith
{
	namespace Container
	{
		typedef std::list<std::shared_ptr<Item>>::iterator item_iterator;
		typedef std::list<std::shared_ptr<Item>>::const_iterator const_item_iterator;
		typedef std::list<std::shared_ptr<Item>> TItemList;
		typedef std::shared_ptr<TItemList> TItemListPointer;

		class Bag
		{
		public: // Constants
			static const std::string KDefaultBagName;

		public: // Constructors
			Bag() : Bag(0, KDefaultBagName) { };
			Bag(size_t sizeLimit, const std::string name) : iItemLimit(sizeLimit), iName(name) { };
			virtual ~Bag() { };

			// Disabled copy and assignment (C++11)
			Bag(const Bag& other) = delete;
			Bag& operator=(const Bag& other) = delete;

		public: // STL iterator support
			item_iterator begin() { return iItems.begin(); }
			item_iterator end() { return iItems.end(); }
			const_item_iterator cbegin() const { return iItems.cbegin(); }
			const_item_iterator cend() const { return iItems.cend(); }

		public: // Public methods
			/**
			 * @return The the maximum size of the bag
			 */
			unsigned int size() const;

			/**
			 * @return The number of items held in this bag
			 */
			unsigned int count() const;

			/**
			 * @return The weight of this bag
			 */
			unsigned int weight() const;

			/**
			 * @return Name of the bag
			 */
			const std::string name() const;

			/**
			 * Add item to the container
			 */
			bool addItem(std::shared_ptr<Item> item);

			/**
			 * Search for item by partial name
			 * @param partial a item name (part or full) to be searched for
			 */
			TItemListPointer findItem(const std::string& partial);

		private: // Data
			TItemList iItems;
			std::string iName;
			size_t iItemLimit;
		};
	} // namespace Container
} // namespace codesmith

#endif // __BAG_H_DEFINED__
