/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Light.hpp
*/

#ifndef DIRECTIONAL_HPP_
#define DIRECTIONAL_HPP_

#include "../../ILight.hpp"


namespace RayTracer
{
    class Directional: public ILight {
        public:
            Directional(): _ambient(0.0), _diffuse(0.0) {};
            Directional(double ambient, double diffuse, Math::Point3D coor);
            ~Directional();
            double getAmbient() const;
            double getDiffuse() const;
            std::string getType() const;
            Math::Point3D getPosition() const;
            std::unique_ptr<ILight> clone() const;
            void print_data();


        private:
            double _ambient;
            double _diffuse;
            Math::Point3D position;
            //std::string type;
    };
}

#endif