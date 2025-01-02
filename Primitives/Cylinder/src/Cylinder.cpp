/*
** EPITECH PROJECT, 2024
** Cylinder
** File description:
** Cylinder Primitive
*/

#include "../includes/Cylinder.hpp"

namespace RayTracer {
    bool Cylinder::hits(RayTracer::Ray, double, double, Hit_info &hit_point) {
        return false;
    }

    std::unique_ptr<IPrimitive> Cylinder::clone() const {
        return std::make_unique<Cylinder>(*this);
    }

    void Cylinder::print_data()
    {
        printf("Cylinder data:\n");
        printf("\tcenter: {x: %.2f, y: %.2f, z: %.2f}\n", center.x, center.y, center.z);
        printf("\tradius: %.2f\n", radius);
        printf("\tcolor: {r: %.2f, g: %.2f, b: %.2f}\n", color.r, color.g, color.b);
    }
}