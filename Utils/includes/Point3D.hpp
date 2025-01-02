/*
** EPITECH PROJECT, 2024
** 3DPoint
** File description:
** A 3D Point
*/

#ifndef POINT3D_HPP_
#define POINT3D_HPP_

#include <iostream>
#include <cmath>
#include "Vector3D.hpp"

// namespace Math
// {
//     class Point3D {
//         public:
//             Point3D() {};
//             Point3D(double _x, double _y, double _z);
//             ~Point3D() = default;

//             Point3D operator+(Point3D second) const;
//             Point3D operator-(Point3D second) const;
//             Point3D operator*(Point3D second) const;
//             Point3D operator/(Point3D second) const;
//             void operator+=(Point3D second);
//             void operator-=(Point3D second);
//             void operator*=(Point3D second);
//             void operator/=(Point3D second);
//             void operator*(double op);
//             void operator/(double op);
//             void operator*=(double op);
//             void operator/=(double op);
//             void operator=(Point3D point);

//             Point3D operator+(Vector3D vector);
//             double x = 0;
//             double y = 0;
//             double z = 0;

//         protected:
//         private:
//     };    
// } // namespace Math

namespace Math
{
    class Point3D {
        public:
            Point3D() {};
            Point3D(double _x, double _y, double z);
            ~Point3D() = default;
            double dot(Vector3D second) const;

            Point3D operator+(Point3D second) const;
            Point3D operator-(Point3D second) const;
            Point3D operator*(Point3D second) const;
            Point3D operator/(Point3D second) const;
            Point3D operator-(double op) const;
            Point3D operator-(Vector3D vector);
            void operator+=(Point3D second);
            void operator-=(Point3D second);
            void operator*=(Point3D second);
            void operator/=(Point3D second);
            void operator*(double op);
            void operator/(double op);
            void operator*=(double op);
            void operator/=(double op);
            void operator=(Point3D point);

            Point3D operator+(Vector3D vector);
            double x = 0;
            double y = 0;
            double z = 0;

        protected:
        private:
    };    
}


#endif /* !POINT3D_HPP_ */
