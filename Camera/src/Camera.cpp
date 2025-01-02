/*
** EPITECH PROJECT, 2024
** Camera
** File description:
** Camera
*/

#include "../includes/Camera.hpp"

namespace RayTracer {
    
    Camera::Camera(double width, double height,
                Math::Point3D position, Math::Point3D rotation,
                double _fov) {
        _width = width;
        _height = height;
        _position = position;
        _rotation = rotation;
        fov = _fov * M_PI / 180;
        ratio = _width / _height;
        setItUp();
    }

    void Camera::setItUp()
    {
        Math::Vector3D u, v, w;
        double half_height = tan(fov / 2);
        double half_width = ratio * half_height;

        w = Math::normalized(Math::Vector3D(_position.x, _position.y, _position.z) - Math::Vector3D(_rotation.x, _rotation.y, _rotation.z));
        u = Math::normalized(Math::Vector3D(0.0, 1.0, 0.0).cross(w));
        v = w.cross(u);

        top_left = _position - u * half_width - v * half_height - w;
        horizontal = u * 2 * half_width;
        vertical = v * 2 * half_height;
    }

    double Camera::get_width() const
    {
        return _width;
    }

    double Camera::get_height() const
    {
        return _height;
    }

    double Camera::get_fov() const
    {
        return fov;
    }

    Math::Point3D Camera::get_position() const
    {
        return _position;
    }

    Math::Point3D Camera::get_rotation() const
    {
        return _rotation;
    }

    Ray Camera::emitRay(double x, double y)
    {
        Math::Point3D f = top_left + horizontal * x + vertical * y - _position;
        return Ray(_position, Math::Vector3D(f.x, f.y, f.z));
    }

    void Camera::print_data()
    {
        printf("Camera data:\n");
        printf("\twidth: %.2f\n\theight: %.2f\n", _width, _height);
        printf("\tposition: {x: %.2f, y: %.2f, z: %.2f}\n", _position.x, _position.y, _position.z);
        printf("\trotation: {x: %.2f, y: %.2f, z: %.2f}\n", _rotation.x, _rotation.y, _rotation.z);
        printf("\tfield of view: %.2f\n", fov);
    }
}
