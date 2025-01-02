/*
** EPITECH PROJECT, 2024
** Plane
** File description:
** Plane
*/

#ifndef PLANE_HPP_
#define PLANE_HPP_

#include "../../IPrimitive.hpp"
#include "../../../Utils/includes/c++libs.hpp"

namespace RayTracer
{
    class Plane : public IPrimitive {
        public:
            Plane(std::string axis, double position, Color color);
            ~Plane();
            bool hits(RayTracer::Ray ray, double min, double max, Hit_info &hit_point);
            Color getColor() const;
            std::unique_ptr<IPrimitive> clone() const;
            void print_data();
            std::string get_axis();
            Math::Point3D getPosition() const;
            void setPosition(Math::Point3D);

        protected:
        private:
            std::string _axis;
            double _position;
            Color _color;
    };
}

#endif /* !PLANE_HPP_ */