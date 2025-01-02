/*
** EPITECH PROJECT, 2024
** Sphere
** File description:
** Sphere Class implementation
*/

#include "../includes/Sphere.hpp"

namespace RayTracer
{
    Sphere::Sphere(Math::Point3D point, double rd, RayTracer::Color _color) : radius(rd) {
        origin = point;
        color = _color;
    }

    Sphere::~Sphere()
    {
    }

    bool Sphere::hits(RayTracer::Ray ray, double min, double max, Hit_info &hit_point)
    {
        Math::Vector3D dir = ray.getDirection();
        Math::Point3D point = ray.getOrigin();

        double a = dir.dot(dir);
        double b = 2 * ((point.x - origin.x) * dir._x + (point.y - origin.y) * dir._y + (point.z - origin.z) * dir._z);
        double c = pow(point.x - origin.x, 2) + pow(point.y - origin.y, 2) + pow(point.z - origin.z, 2) - pow(radius, 2);

        double d = pow(b, 2) - (4 * a * c);
        if (d > 0) {
            hit_point.color = color;
            double t0 = (-b - sqrt(b*b - a*c)) / a;
            double t1 = (-b + sqrt(b*b - a*c)) / a;
            double tmp = std::min(t0, t1);
            if (tmp > min && tmp < max) {
                hit_point.p = tmp;
                hit_point.hit_point = (ray.pointAt(tmp));
                hit_point.normal = (hit_point.hit_point - origin);
                hit_point.normal /= radius;
                return true;
            }
        }
        return false;
    }

    Math::Point3D Sphere::getPosition() const
    {
        return origin;
    }

    RayTracer::Color Sphere::getColor() const
    {
        return color;
    }
    
    std::unique_ptr<IPrimitive> Sphere::clone() const {
        return std::make_unique<Sphere>(*this);
    }

    double Sphere::get_radius()
    {
        return radius;
    }

    void Sphere::print_data()
    {
        printf("Sphere data:\n");
        printf("\torigin: {x: %.2f, y: %.2f, z: %.2f}\n", origin.x, origin.y, origin.z);
        printf("\tcolor: {r: %.2f, g: %.2f, b: %.2f}\n", color.r, color.g, color.b);
        printf("\tradius: %.2f\n", radius);
    }
}