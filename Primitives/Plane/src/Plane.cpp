/*
** EPITECH PROJECT, 2024
** Plane
** File description:
** Plane Class implementation
*/

#include "../includes/Plane.hpp"

namespace RayTracer
{
    Plane::Plane(std::string axis, double position, Color color) : _axis(axis), _position(position) {
        _color.r = color.r;
        _color.g = color.g;
        _color.b = color.b;
    }

    Plane::~Plane()
    {
    }

bool Plane::hits(RayTracer::Ray ray, double min, double max, Hit_info &hit_point)
{
    Math::Point3D origin = ray.getOrigin();
    Math::Vector3D dir = ray.getDirection();

    Math::Point3D normal;
    if (_axis == "X")
        normal = Math::Point3D(1.0, 0.0, 0.0);
    else if (_axis == "Y")
        normal = Math::Point3D(0.0, 1.0, 0.0);
    else
        normal = Math::Point3D(0.0, 0.0, 1.0);

    double denom = normal.dot(dir);
    
    if (std::abs(denom) < 1e-6)
        return false;

 double t = (normal.dot(Math::Vector3D(_position, _position, _position)) - normal.dot(Math::Vector3D(origin.x, origin.y, origin.z))) / denom;

    if (t < min || t > max)
        return false;

    Math::Point3D intersection_point = ray.pointAt(t);

    hit_point.hit_point = intersection_point;
    hit_point.normal = normal;
    hit_point.p = t;
    hit_point.color = _color;

    return true;
}

    std::string Plane::get_axis()
    {
        return _axis;
    }
    
    Math::Point3D Plane::getPosition() const
    {
        if (_axis == "X")
            return Math::Point3D(_position, 0.0, 0.0);
        if (_axis == "Y")
            return Math::Point3D(0.0, _position, 0.0);
        if (_axis == "Z")
            return Math::Point3D(0.0, 0.0, _position);
        return Math::Point3D(0.0, 0.0, 0.0);
    }

    void Plane::setPosition(Math::Point3D pos)
    {
        if (_axis == "X")
            _position = pos.z;
        if (_axis == "Y")
            _position = pos.y;
        if (_axis == "Z")
            _position = pos.z;
    }
    
    Color Plane::getColor() const
    {
        return _color;
    }

    std::unique_ptr<IPrimitive> Plane::clone() const
    {
        return std::make_unique<Plane>(*this);
    }

    void Plane::print_data()
    {
        printf("Plane data:\n");
        printf("\taxis: %s\n\tposition: %.2f\n", _axis.c_str(), _position);
        printf("\tcolor: {r: %.2f, g: %.2f, b: %.2f}\n", _color.r, _color.g, _color.b);
    }
}
