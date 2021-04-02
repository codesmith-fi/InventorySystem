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

#include "Rectangle.h"

namespace codesmith {
	namespace Primitives {
        Rectangle::Rectangle(const Rectangle& other) {
            iTl = other.iTl;
            iSize = other.iSize;            
        }

        Rectangle& Rectangle::operator=(const Rectangle& other) {
            iTl = other.iTl;
            iSize = other.iSize;
            return *this;
        }

        int Rectangle::x() const
        {
            return iTl.x();
        }

        int Rectangle::y() const
        {
            return iTl.y();
        }

        void Rectangle::set(const Vector& aPos, const Vector& aSize)
        {
            iTl = aPos;
            iSize = aSize;
        }

        void Rectangle::move(int dX, int dY)
        {
            move(Vector(dX, dY));
        }

        void Rectangle::grow(const Vector& delta)
        {
            iSize += delta;
        }

        void Rectangle::grow(int dX, int dY)
        {
            iSize.move(dX, dY);
        }

        void Rectangle::move(const Vector& delta)
        {
            iTl += delta;
        }

        void Rectangle::setSize(const Vector& size)
        {
            iSize = size;
        }

        void Rectangle::setSize(int sx, int sy)
        {
            iSize = Vector(sx, sy);
        }

        void Rectangle::setPosition(const Vector& pos)
        {
            iTl = pos;
        }

        void Rectangle::setPosition(int px, int py)
        {
            iTl.set(px, py);
        }
    }
}