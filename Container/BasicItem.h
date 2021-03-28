/**
 * BasicItem
 * A concrete item class
 *
 * Project: InventorySystem
 * Author: Erno Pakarinen
 * Date: 29th March 2021
 * mailto: codesmith.fi@gmail.com
 */

#ifndef __BASICITEM_H_DEFINED__
#define __BASICITEM_H_DEFINED__

#include <string>
#include "Item.h"

namespace codesmith {
	namespace Container {

		class BasicItem : public Item
		{
		public: // constructors
			BasicItem() : BasicItem(KDefaultItemName) { };
			BasicItem(const std::string& name) : BasicItem(name, 0) { };
			BasicItem(const std::string& name, unsigned int weight) : BasicItem(name, weight, 0) { };
			BasicItem(const std::string& name, unsigned int weight, unsigned int value);

			BasicItem(const BasicItem& other);
			BasicItem& operator=(const BasicItem& other);


		public: // From base class
			unsigned int weight() const;

		public: // New methods
			void setWeight(unsigned int w);
			unsigned int value() const;
			void setValue(unsigned int value);

		private: // Data
			unsigned int iWeight;
			unsigned int iValue;
		};

	} // namespace Container
} // namespace codesmith

#endif // __BASICITEM_H_DEFINED__
