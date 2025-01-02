/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Light.hpp
*/

#include "../includes/Directional.hpp"

namespace RayTracer
{
    Directional::Directional(double ambient, double diffuse, Math::Point3D coor)
    {
        _ambient = ambient; _diffuse = diffuse;
        position = coor;
    }

    Directional::~Directional()
    {

    }

    double Directional::getAmbient() const
    {
        return _ambient;
    }

    double Directional::getDiffuse() const
    {
        return _diffuse;
    }

    Math::Point3D Directional::getPosition() const
    {
        return position;
    }

    std::unique_ptr<ILight> Directional::clone() const
    {
        return std::make_unique<Directional>(*this);
    }

    std::string Directional::getType() const { return "directional"; }

    void Directional::print_data()
    {
        printf("Directional Light data:\n");
        printf("\tambient: %f\n", _ambient);
        printf("\tdiffuse: %f\n", _diffuse);
        printf("\tcoor x: %f\n", position.x);
        printf("\tcoor x: %f\n", position.y);
        printf("\tcoor z: %f\n", position.z);
    }
}
