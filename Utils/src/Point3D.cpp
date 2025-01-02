/*
** EPITECH PROJECT, 2024
** Point3D
** File description:
** Point 3D class implementation
*/

#include "../includes/Point3D.hpp"

namespace Math
{
    Point3D::Point3D(double _x, double _y, double _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

    double Point3D::dot(Vector3D second) const
    {
        return (x * second._x + y * second._y + z * second._z);
    }

    Point3D Point3D::operator+(Point3D second) const
    {
        return Point3D(x + second.x, y + second.y, z + second.z);
    }

    Point3D Point3D::operator-(Point3D second) const
    {
        return Point3D(x - second.x, y - second.y, z - second.z);
    }
    Point3D Point3D::operator-(double op) const
    {
        return Point3D(x - op, y - op, z - op);
    }

    Point3D Point3D::operator*(Point3D second) const
    {
        return Point3D(x * second.x, y * second.y, z * second.z);
    }

    Point3D Point3D::operator/(Point3D second) const
    {
        double _x = (second.x == 0) ? 0 : x / second.x;
        double _y = (second.y == 0) ? 0 : y / second.y;
        double _z = (second.z == 0) ? 0 : z / second.z;

        return Point3D(_x, _y, _z);
    }

    void Point3D::operator+=(Point3D second)
    {
        x += second.x;
        y += second.y;
        z += second.z;
    }

    void Point3D::operator-=(Point3D second)
    {
        x -= second.x;
        y -= second.y;
        z -= second.z;
    }

    void Point3D::operator*=(Point3D second)
    {
        x *= second.x;
        y *= second.y;
        z *= second.z;
    }

    void Point3D::operator/=(Point3D second)
    {
        x = (second.x == 0) ? 0 : x / second.x;
        y = (second.y == 0) ? 0 : y / second.y;
        z = (second.z == 0) ? 0 : z / second.z;
    }
    void Point3D::operator/=(double p) {
        x = (p == 0) ? 0 : x / p;
        y = (p == 0) ? 0 : y / p;
        z = (p == 0) ? 0 : z / p;
    }

    Point3D Point3D::operator+(Vector3D vector)
    {
        return Point3D(x + vector._x, y + vector._y, z + vector._z);
    }

    Point3D Point3D::operator-(Vector3D vector)
    {
        return Point3D(x - vector._x, y - vector._y, z - vector._z);
    }

    void Point3D::operator=(Point3D p) {
        x = p.x;
        y = p.y;
        z = p.z;
    }
}