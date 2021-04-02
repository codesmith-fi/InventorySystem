/**
 * Vector class
 * 
 * Has a vertical and horizontal position
 *
 * Project: InventorySystem
 * Author: Erno Pakarinen
 * Date: April 2nd, 2021
 * mailto: codesmith.fi@gmail.com
 */

#ifndef __VECTOR_H_DEFINED__
#define __VECTOR_H_DEFINED__

namespace codesmith {
    namespace Primitives {
        class Vector {
        public: // Constructors and operators
            Vector() : Vector(0, 0) { };
            Vector(int x, int y) : iX(0), iY(0) { };
            virtual ~Vector() { };
            Vector(const Vector& other);
            Vector& operator=(const Vector& other);
            Vector operator+(const Vector& other) const;
            Vector& operator+=(const Vector& other);
        public: // New methods
            inline int x() const { return iX; };
            inline int y() const { return iY; };
            void set(int x, int y);
            void set(const Vector& pos);
            void move(int dX, int dY);
            void move(const Vector& delta);
            void reset();
            int length() const;
            int length(const Vector& aPos) const;

        private: // data
            int iX;
            int iY;
        };
    }
} // namespace codesmith

#endif // __VECTOR_H_DEFINED__
