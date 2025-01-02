/*
** EPITECH PROJECT, 2024
** Cylinder
** File description:
** Cylinder Primitive
*/

#ifndef CYLINDER_HPP_
#define CYLINDER_HPP_

#include "../../IPrimitive.hpp"

namespace RayTracer {

    class Cylinder : public IPrimitive {
        public:
            Cylinder(Math::Point3D center, double radius, double h, Color color)
                : center(center), radius(radius), height(h), color(color) {};
            ~Cylinder() {};
            bool hits(RayTracer::Ray, double, double, Hit_info &hit_point);
            std::unique_ptr<IPrimitive> clone() const;
            Color getColor() const {
                return color;
            }

            void print_data();

            Math::Point3D get_center() const {
                return center;
            }

            double get_radius() const {
                return radius;
            }

        private:
            Math::Point3D center;  
            double radius;
            double height;
            Color color;
    };
}

#endif /* !CYLINDER_HPP_ */
