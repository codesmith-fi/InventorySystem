/**
 * BasicItem
 * A concrete item class
 *
 * Project: InventorySystem
 * Author: Erno Pakarinen
 * Date: 29th March 2021
 * mailto: codesmith.fi@gmail.com
 */

#include "BasicItem.h"

namespace codesmith {
	namespace Container {
		const int BasicItem::KItemTypeUndefined = 0;

		BasicItem::BasicItem(const std::string& name, 
			unsigned int weight, unsigned int value) : 
			iWeight(weight), iValue(value), iType(KItemTypeUndefined)
		{
			setName(name);
		}

		BasicItem::BasicItem(const BasicItem& other) {
			*this = other;
		}

		BasicItem& BasicItem::operator=(const BasicItem& other)
		{
			setName(other.name());
			iType = other.iType;
			iWeight = other.iWeight;
			iValue = other.iValue;
			return *this;
		}

		void BasicItem::setWeight(unsigned int w)
		{
			iWeight = w;
		}

		unsigned int BasicItem::weight() const
		{
			return iWeight;		
		}

		unsigned int BasicItem::value() const
		{
			return iValue;
		}

		void BasicItem::setValue(unsigned int value)
		{
			iValue = value;
		}
	}
}
