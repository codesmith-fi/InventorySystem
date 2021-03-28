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
		public: // Public methods
			/**
			 * @return The number of bags in this Inventory container
			 */
			int bagCount();

			/**
			 * @return The number of items held in this Inventory 
			 */
			int itemCount();
		private: // Data
			int iBagLimit;
		};
	} // namespace Container
} // namespace codesmith

#endif // __INVENTORY_H_DEFINED__

