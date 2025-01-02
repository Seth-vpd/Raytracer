/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Light.hpp
*/

#ifndef I_LIGHT_HPP_
#define I_LIGHT_HPP_

#include "../Utils/includes/Ray.hpp"
#include "../Utils/includes/c++libs.hpp"

namespace RayTracer
{
    class ILight {
        public:
            virtual ~ILight() {};
            virtual double getAmbient() const = 0;
            virtual double getDiffuse() const = 0;
            virtual Math::Point3D getPosition() const = 0;
            virtual std::string getType() const = 0;
            virtual std::unique_ptr<ILight> clone() const = 0;
            virtual void print_data() = 0;
        private:
    };
}

#endif
