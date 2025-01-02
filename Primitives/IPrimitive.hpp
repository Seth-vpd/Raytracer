/*
** EPITECH PROJECT, 2024
** IPrimitives
** File description:
** Primitives' Interface
*/

#ifndef IPRIMITIVE_HPP_
#define IPRIMITIVE_HPP_

#include <iostream>
#include "../Utils/includes/Ray.hpp"
#include <memory>

namespace RayTracer
{
    class IPrimitive {
        public:
            virtual ~IPrimitive() {};
            virtual bool hits(RayTracer::Ray ray, double min, double max, RayTracer::Hit_info &hit_point) = 0;
            virtual void print_data() = 0;
            virtual Color getColor() const = 0;
            virtual void setPosition(Math::Point3D) = 0;
            virtual Math::Point3D getPosition() const = 0;
            virtual std::unique_ptr<IPrimitive> clone() const = 0;

        protected:
        private:
    };    
}

#endif /* !IPRIMITIVE_HPP_ */
