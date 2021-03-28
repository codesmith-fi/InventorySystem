/**
 * Item, a base class for all Items, can't be instantiated
 * Items are held by Bags 
 *
 * Project: InventorySystem
 * Author: Erno Pakarinen
 * Date: 29th March 2021
 * mailto: codesmith.fi@gmail.com
 */

#ifndef __ITEM_H_DEFINED__
#define __ITEM_H_DEFINED__

#include <string>
#include <list>
#include <memory>

namespace codesmith
{
	namespace Container
	{
		/**
		 * This class can't be instantiated
		 */
		class Item
		{
		public: // Constants
			static const std::string KDefaultItemName;

		public: // Constructors
			Item() : iName(KDefaultItemName) { };
			virtual ~Item() { };
			Item(const Item& other);
			Item& operator=(const Item& other);

		public: // Public interface which can be overridden
			virtual inline bool isContainer() const;

		public: // Public interface
			const std::string name() const;
			void setName(const std::string& name);

		public: // Public virtual interface to be implemented by concrete classes
			virtual unsigned int weight() const = 0;

		private: // Data
			std::string iName;
		};

		typedef std::list<std::shared_ptr<Item>>::iterator item_iterator;
		typedef std::list<std::shared_ptr<Item>>::const_iterator const_item_iterator;
		typedef std::list<std::shared_ptr<Item>> TItemList;
		typedef std::shared_ptr<TItemList> TItemListPointer;
		typedef std::shared_ptr<Item> TItemPointer;
	} // namespace Container
} // namespace codesmith

#endif // __ITEM_H_DEFINED__

