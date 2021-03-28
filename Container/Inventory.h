/**
 * Inventory, main container for the whole Inventory System
 * 
 * Project: InventorySystem
 * Author: Erno Pakarinen
 * Date: 29th March 2021
 * mailto: codesmith.fi@gmail.com
 */


#ifndef __INVENTORY_H_DEFINED__
#define __INVENTORY_H_DEFINED__

#include <list>
#include <memory>
#include <iterator>
#include "Bag.h"

namespace codesmith
{
	namespace Container
	{
		typedef std::list<std::shared_ptr<Bag>>::iterator bag_iterator;
		typedef std::list<std::shared_ptr<Bag>>::const_iterator const_bag_iterator;

		class Inventory
		{
		public: // Constructors
			Inventory() : Inventory(1) { };
			Inventory(int bagLimit) : iBagLimit(bagLimit), iWeightLimit(-1) { };
			virtual ~Inventory() { };
			// Disabled copy and assignment (C++11)
			Inventory(const Inventory& other) = delete;
			Inventory& operator=(const Inventory& other) = delete;

		public: // STL iterator support
			bag_iterator begin() { return iBags.begin(); }
			bag_iterator end() { return iBags.end(); }
			const_bag_iterator cbegin() const { return iBags.cbegin(); }
			const_bag_iterator cend() const { return iBags.cend(); }

		public: // Public methods
			/**
			 * @return The number of bags in this Inventory container
			 */
			size_t bagCount() const;

			/**
			 * @return How many items can be added to this inventory/
			 */
			size_t maxBagLimit() const;

			/**
			 * @return Weight of the whole inventory
			 */
			unsigned int weight() const;

			/**
			 * Get the weight limit for this inventory
			 * negative for no inventory specific weight limit (handled outside for example)
			 * @return The weight limit in this inventory
			 */
			int maxWeightLimit() const;

			/**
			 * @return The number of items held in this Inventory 
			 */
			int itemCount() const;

			/**
			 * @return the limit for items in the whole inventory system
			 */
			size_t maxItemLimit() const;

			/**
			 * Insert a new bag to the Inventory
			 */
			bool addBag(const std::shared_ptr<Bag> bag);

			/**
			 * Search for item by partial name, all bags are searched
			 * @param partial a item name (part or full) to be searched for
			 */
			TItemListPointer findItem(const std::string& partial);

		private: // Data
			std::list<std::shared_ptr<Bag>> iBags;
			size_t iBagLimit;
			int iWeightLimit;
		};
	} // namespace Container
} // namespace codesmith

#endif // __INVENTORY_H_DEFINED__

