/*
** EPITECH PROJECT, 2024
** IPrimitives
** File description:
** Transformation
*/

#include "../includes/Translation.hpp"

namespace RayTracer {

    Translation::Translation(Math::Vector3D dt): vector(dt) {};

    Translation::~Translation() {};

    std::unique_ptr<ITransformation> Translation::clone() const
    {
        return std::make_unique<Translation>(*this);
    }

    void Translation::applyTransformation(std::vector<std::unique_ptr<IPrimitive>> &primitives)
    {
        for (const auto& primitive : primitives) {
            primitive->setPosition(primitive->getPosition() + vector);
        }
    }

    void Translation::print_data()
    {
        printf("Translation vector:\n");
        printf("\t{x: %f, y: %f, z: %f}\n", vector._x, vector._y, vector._z);
    }

    Math::Vector3D Translation::getVector()
    {
        return vector;
    }
};
