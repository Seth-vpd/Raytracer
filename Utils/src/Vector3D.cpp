/*
** EPITECH PROJECT, 2024
** Vector3D
** File description:
** Class Implementation
*/

#include "../includes/Vector3D.hpp"
#include "../includes/Point3D.hpp"

namespace Math 
{
    Vector3D::Vector3D() {}

    Vector3D::Vector3D(double x, double y, double z)
    {
        _x = x;
        _y = y;
        _z = z;
    }     

    double Vector3D::length() const
    {
        return sqrt(pow(_x, 2) + pow(_y, 2) + pow(_z, 2));
    }

    double Vector3D::dot(Vector3D second) const
    {
        return (_x * second._x + _y * second._y + _z * second._z);
    }

    Vector3D Vector3D::operator+(Vector3D second) const
    {
        return Vector3D(_x + second._x, _y + second._y, _z + second._z);
    }

    Vector3D Vector3D::operator-(Vector3D second) const
    {
        return Vector3D(_x - second._x, _y - second._y, _z - second._z);
    }

    Vector3D Vector3D::operator*(Vector3D second) const
    {
        return Vector3D(_x * second._x, _y * second._y, _z * second._z);
    }

    Vector3D Vector3D::operator/(Vector3D second) const
    {
        double x = (second._x == 0) ? 0 : _x / second._x;
        double y = (second._y == 0) ? 0 : _y / second._y;
        double z = (second._z == 0) ? 0 : _z / second._z;

        return Vector3D(x, y, z);
    }

    void Vector3D::operator+=(Vector3D second)
    {
        _x += second._x;
        _y += second._y;
        _z += second._z;
    }

    void Vector3D::operator-=(Vector3D second)
    {
        _x -= second._x;
        _y -= second._y;
        _z -= second._z;
    }

    void Vector3D::operator*=(Vector3D second)
    {
        _x *= second._x;
        _y *= second._y;
        _z *= second._z;
    }

    void Vector3D::operator/=(Vector3D second)
    {
        _x = (second._x == 0) ? 0 : _x / second._x;
        _y = (second._y == 0) ? 0 : _y / second._y;
        _z = (second._z == 0) ? 0 : _z / second._z;
    }

    Vector3D Vector3D::operator*(double op)
    {
        return Vector3D(_x * op, _y *op, _z * op);
    }

    void Vector3D::operator*=(double op)
    {
        _x *= op;
        _y *= op;
        _z *= op;
    }

    Vector3D Vector3D::operator/(double op)
    {
        if (op == 0)
            return Vector3D(0, 0, 0);
        return Vector3D(_x / op, _y / op, _z / op);
    }

    void Vector3D::operator/=(double op)
    {
        if (op != 0) {
            _x /= op;
            _y /= op;
            _z /= op;
        }
    }

    // static Vector3D Vector3D::normalized(Vector3D vec) {
    //     return vec / vec.length();
    // }

    Vector3D Vector3D::cross(const Vector3D vec)
    {
        return Vector3D(_y * vec._z - _z * vec._y,
            _z * vec._x - _x * vec._z, 
            _x * vec._y - _y * vec._x);
    }
}

static Math::Vector3D normalized(Math::Vector3D vec) {
        return vec / vec.length();
}

std::ostream& operator<<(std::ostream &line, Math::Vector3D vector)
{
    return line << vector._x << ' ' << vector._y << ' ' << vector._z << std::endl;
}