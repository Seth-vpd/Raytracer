/*
** EPITECH PROJECT, 2024
** Camera
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "../../Utils/includes/Ray.hpp"

namespace RayTracer
{
    class Camera {
        public:
            Camera() {};
            Camera(double width, double height, Math::Point3D position, Math::Point3D rotation,
                double fov);
            ~Camera() {};
            void setItUp();
            double get_width() const;
            double get_height() const;
            double get_fov() const;
            Math::Point3D get_position() const;
            Math::Point3D get_rotation() const;
            Ray emitRay(double, double);

            void print_data();
        private:
            double _width = 0.0;
            double _height = 0.0;
            Math::Point3D _position;
            Math::Point3D _rotation;
            Math::Point3D top_left;
            // Math::Vector3D forward;
            // Math::Vector3D right;
            // Math::Vector3D up;
            Math::Vector3D horizontal;
            Math::Vector3D vertical;
            double fov = 0.0;
            double ratio = 0.0;
    };
}

#endif /* !CAMERA_HPP_ */
