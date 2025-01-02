/*
** EPITECH PROJECT, 2024
** Ray
** File description:
** Ray
*/

#ifndef RAY_HPP_
#define RAY_HPP_

#include "Point3D.hpp"
#include "Vector3D.hpp"
#include "Color.hpp"

namespace RayTracer
{
    class Ray {
        public:
            Ray() {};
            Ray(Math::Point3D point, Math::Vector3D vector) : origin(point), direction(vector) {};
            ~Ray() = default;
            Math::Point3D getOrigin() const { return origin; };
            Math::Vector3D getDirection() const { return direction; };
            Math::Point3D pointAt(double t) { return origin + direction * t; };

        protected:
        private:
            Math::Point3D origin;
            Math::Vector3D direction;
    };
    typedef struct Hit_info_t {
        double p;
        Math::Point3D hit_point;
        Math::Point3D normal;
        Color color;
    } Hit_info;
}

#endif /* !RAY_HPP_ */
