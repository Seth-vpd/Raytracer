/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Light.hpp
*/

#include "../includes/PointLight.hpp"

namespace RayTracer
{
    PointLight::PointLight(double ambient, double diffuse, Math::Point3D coor)
    {
        _ambient = ambient;
        _diffuse = diffuse;
        _position = coor;
    }

    PointLight::~PointLight() {}

    double PointLight::getAmbient() const
    {
        return _ambient;
    }
    double PointLight::getDiffuse() const
    {
        return _diffuse;
    }
    Math::Point3D PointLight::getPosition() const
    {
        return _position;
    }

    std::string PointLight::getType() const
    {
        return "point";
    }

    std::unique_ptr<ILight> PointLight::clone() const
    {
        return std::make_unique<PointLight>(*this);
    }

    void PointLight::print_data()
    {
        printf("Light PointLight data:\n");
        printf("\tambient: %f\n", _ambient);
        printf("\tdiffuse: %f\n", _diffuse);
        printf("\tcoor x:%f\n", _position.x);
        printf("\tcoor y:%f\n", _position.y);
        printf("\tcoor z:%f\n", _position.z);
    }
}
