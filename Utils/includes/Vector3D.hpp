/*
** EPITECH PROJECT, 2024
** Vector3D
** File description:
** Vector3D
*/

#ifndef VECTOR3D_HPP_
#define VECTOR3D_HPP_

#include <iostream>
#include <cmath>

namespace Math
{
    class Vector3D {
        public:
            Vector3D(double x, double y, double z);
            Vector3D();
            ~Vector3D() = default;
            double length() const;
            double dot(Vector3D second) const;
            //static Vector3D normalized(const Vector3D);
            Vector3D cross(const Vector3D);

            Vector3D operator+(Vector3D second) const;
            Vector3D operator-(Vector3D second) const;
            Vector3D operator*(Vector3D second) const;
            Vector3D operator/(Vector3D second) const;
            void operator+=(Vector3D second);
            void operator-=(Vector3D second);
            void operator*=(Vector3D second);
            void operator/=(Vector3D second);
            Vector3D operator*(double op);
            Vector3D operator/(double op);
            //Vector3D operator+(Point3D op);
            void operator*=(double op);
            void operator/=(double op);

            double _x = 0;
            double _y = 0;
            double _z = 0;

        protected:
        private:
    };
    static Vector3D normalized(Vector3D vec) {
        return vec / vec.length();
    }
    std::ostream& operator<<(std::ostream &line, Math::Vector3D vector);
    // {
    //     return line << vector._x << ' ' << vector._y << ' ' << vector._z << std::endl;
    // };
}

#endif /* !VECTOR3D_HPP_ */

