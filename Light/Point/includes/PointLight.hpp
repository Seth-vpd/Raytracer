/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Light.hpp
*/

#ifndef POINTLight_HPP_
#define POINTLight_HPP_

#include "../../ILight.hpp"

namespace RayTracer
{
    class PointLight: public ILight {
        public:
            PointLight(): _ambient(0.0), _diffuse(0.0) {};
            PointLight(double ambient, double diffuse, Math::Point3D coor);
            ~PointLight();
            double getAmbient() const;
            double getDiffuse() const;
            Math::Point3D getPosition() const;
            std::string getType() const;
            std::unique_ptr<ILight> clone() const;
            void print_data();

        private:
            double _ambient;
            double _diffuse;
            Math::Point3D _position;
            //std::string type;
    };
}

#endif