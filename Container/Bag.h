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
#include "Item.h"

namespace codesmith
{
	namespace Container
	{
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
		public: // Public methods
			/**
			 * @return The the maximum size of the bag
			 */
			size_t size();

			/**
			 * @return The number of items held in this bag
			 */
			int count();

			/**
			 * @return Name of the bag
			 */
			const std::string name() const;

			/**
			 * Add item to the container
			 */
			bool addItem(std::shared_ptr<Item> item);

		private: // Data
			std::list<std::shared_ptr<Item>> iItems;
			std::string iName;
			size_t iItemLimit;
		};
	} // namespace Container
} // namespace codesmith

#endif // __BAG_H_DEFINED__
