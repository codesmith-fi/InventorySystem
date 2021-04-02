/**
 * Vector class
 *
 * Has a vertical and horizontal position (a 2-D coordinate)
 *
 * Project: InventorySystem
 * Author: Erno Pakarinen
 * Date: April 2nd, 2021
 * mailto: codesmith.fi@gmail.com
 */

#include <math.h>
#include "Vector.h"

namespace codesmith {
	namespace Primitives {
		Vector::Vector(const Vector& other)
		{
			iX = other.iX;
			iY = other.iY;
		}

		Vector& Vector::operator=(const Vector& other)
		{
			iX = other.iX;
			iY = other.iY;
			return *this;
		}

		Vector Vector::operator+(const Vector& other) const
		{
			Vector v(iX, iY);
			v.iX += other.iX;
			v.iY += other.iY;
			return v;
		}

		Vector& Vector::operator+=(const Vector& other)
		{
			*this = *this + other;
			return *this;
		}

		void Vector::set(int x, int y)
		{
			iX = x;
			iY = y;
		}

		void Vector::set(const Vector& pos)
		{
			*this = pos;
		}

		void Vector::move(int dX, int dY)
		{
			iX += dX;
			iY += dY;
		}

		void Vector::move(const Vector& delta)
		{
			iX += delta.iX;
			iY += delta.iY;
		}

		void Vector::reset()
		{
			iX = 0;
			iY = 0;
		}

		int Vector::length() const
		{
			return length(Vector(0, 0));
		}

		int Vector::length(const Vector& aPos) const
		{
			// Length of a vector with Pythagora's equation 
			//     c^2 = a^2 + b^2 
			// --> c = sqrt(a^2 + b^2)

			return (int)sqrt(iX ^ 2 + iY ^ 2);
		}
	}
}