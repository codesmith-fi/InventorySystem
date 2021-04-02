/**
 * Rectangle class
 * 
 * Contains 2 vectors
 *  topleft -> Position to the top left corner, a vector
 *  size -> size of the rectangle, a vector
 *
 * Project: InventorySystem
 * Author: Erno Pakarinen
 * Date: April 2nd, 2021
 * mailto: codesmith.fi@gmail.com
 */

#ifndef __RECTANGLE_H_DEFINED__
#define __RECTANGLE_H_DEFINED__

#include "Vector.h"

namespace codesmith {
    namespace Primitives {
        class Rectangle{
        public: // Constructors
            Rectangle() : Rectangle(Vector(0,0), Vector(0,0)) { };
            Rectangle(const Vector& tl, const Vector& size) :
                iTl(tl), iSize(size) { };
            virtual ~Rectangle() { };
            Rectangle(const Rectangle& other);
            Rectangle& operator=(const Rectangle& other);
        public: // New methods
            /**
             * @return x position of the rectangle
             */
            int x() const;

            /**
             * @return y position of the rectangle
             */
            int y() const;

            /**
             * Move the position with the given x and y delta
             * @param dX amount to move horizontally
             * @param dY amount to move vertically
             */
            void set(const Vector& aPos, const Vector& aSize);
            void move(int dX, int dY);
            void move(const Vector& delta);
            void setSize(const Vector& size);
            void setSize(int sx, int sy);
            void setPosition(const Vector& pos);
            void setPosition(int px, int py);
            void grow(const Vector& delta);
            void grow(int dX, int dY);

            /**
             * Reset the position to 0,0
             */
            void reset();

        private: // data
            Vector iTl;
            Vector iSize;
        };
    }
} // namespace codesmith

#endif // __RECTANGLE_H_DEFINED__
