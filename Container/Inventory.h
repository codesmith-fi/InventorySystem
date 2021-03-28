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
#include "Bag.h"

namespace codesmith
{
	namespace Container
	{
		class Inventory
		{
		public: // Constructors
			Inventory() : Inventory(1) { };
			Inventory(int bagLimit) : iBagLimit(bagLimit) { };
			virtual ~Inventory() { };
			// Disabled copy and assignment (C++11)
			Inventory(const Inventory& other) = delete;
			Inventory& operator=(const Inventory& other) = delete;

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

