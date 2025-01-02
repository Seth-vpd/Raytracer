/*
** EPITECH PROJECT, 2024
** Sphere
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "../../IPrimitive.hpp"
#include "../../../Utils/includes/c++libs.hpp"

namespace RayTracer
{
    class Sphere : public IPrimitive {
        public:
            Sphere(Math::Point3D, double, Color);
            ~Sphere();
            bool hits(RayTracer::Ray, double, double, Hit_info &hit_point);
            Color getColor() const;
            std::unique_ptr<IPrimitive> clone() const;
            void print_data();
            Math::Point3D getPosition() const;
            void setPosition(Math::Point3D position) { origin = position; };
            double get_radius();

        protected:
        private:
            Math::Point3D origin;
            Color color;
            double radius;
    };
}

#endif /* !SPHERE_HPP_ */
