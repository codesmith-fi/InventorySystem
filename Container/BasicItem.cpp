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
		BasicItem::BasicItem(const std::string& name, unsigned int weight, unsigned int value) : iWeight(weight), iValue(value)
		{
			setName(name);
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
