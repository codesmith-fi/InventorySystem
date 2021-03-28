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
			Inventory(int bagLimit) : iBagLimit(bagLimit) { };
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

			size_t maxBagLimit() const;

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

		private: // Data
			std::list<std::shared_ptr<Bag>> iBags;
			size_t iBagLimit;
		};
	} // namespace Container
} // namespace codesmith

#endif // __INVENTORY_H_DEFINED__

