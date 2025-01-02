/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** RayTracer
*/

// #include "Vector3D.hpp"
// #include "Sphere.hpp"
#include "Primitives/IPrimitive.hpp"
#include "Primitives/Sphere/includes/Sphere.hpp"
#include "./Builder/SceneLoader/includes/SceneLoader.hpp"

using namespace RayTracer;

// int main(int ac, char **av) 
// {
//     // Code to test parsing:
    
//     // SceneLoader scene(av[1]);
//     // std::unique_ptr<Camera> camera = scene.get_camera();
//     // std::vector<std::unique_ptr<IPrimitive>> primitives = scene.get_primitives();
//     // std::vector<std::unique_ptr<Point>> points_light = scene.get_points_light();
//     // std::vector<std::unique_ptr<Directional>> directionals_light = scene.get_directionals_light();
//     // camera->print_data();
//     // for (auto& point: points_light) {
//     //     point->print_data();
//     // }
//     // for (auto& dir: directionals_light) {
//     //     dir->print_data();
//     // }
//     // for (const auto& primitive: primitives) {
//     //     primitive->print_data();
//     // }
//     // return 0;
// }

Math::Vector3D color(const RayTracer::Ray &ray, std::vector<std::unique_ptr<IPrimitive>> &primitives)
{
    RayTracer::Hit_info hit_info;
    for (size_t i = 0; i < primitives.size(); i++) {
        if (primitives[i]->hits(ray, 0.001, MAXFLOAT, hit_info)) {
            return Math::Vector3D(hit_info.normal.x + 1, hit_info.normal.y + 1, hit_info.normal.z + 1) * 0.5;
        }
    }
    Math::Vector3D unit = Math::normalized(ray.getDirection());
    double n = 0.5 * (unit._y + 1.0f);
    return Math::Vector3D(0.5, 1.0, 1.0) * (1 - n) + Math::Vector3D(0.5, 0.7, 1.0) * n;
}

void it_hits(std::vector<std::unique_ptr<IPrimitive>> &primitives, RayTracer::Ray ray)
{
    RayTracer::Hit_info hit_info;
    for (size_t i = 0; i < primitives.size(); i++) {
        if (primitives[i]->hits(ray, 0.001, MAXFLOAT, hit_info)) {
            //return Math::Vector3D(hit_info.normal.x + 1, hit_info.normal.y + 1, hit_info.normal.z + 1) * 0.5;
            //std::cout << hit_info.color.r << " " << hit_info.color.g << " " << hit_info.color.b << std::endl;
            return;
            //return primitives[i]->get_color();
        }
    }
    //std::cout << 0 << " " << 0 << " " << 0 << std::endl;
    return;
    //return Math::Point3D(0, 0, 0);
}

int main(int ac, char **av)
{
    SceneLoader scene(av[1]);
    std::unique_ptr<Camera> camera = scene.get_camera();
    std::vector<std::unique_ptr<IPrimitive>> primitives = scene.get_primitives();
    std::cout << primitives.size() << std::endl;
    //std::unique_ptr<Light> light = scene.get_light();
    // int width = 1920;
    // int height = 1080;
    std::cout << "P3" << std::endl << camera->get_width() << " " << camera->get_height() << std::endl << "255" << std::endl;
    // Math::Vector3D top_left(-2.0, -1.0, -1.0);
    // Math::Vector3D viewport_u(4.0, 0.0, 0.0);
    //Math::Vector3D viewport_v(0.0, 2.0, 0.0);
    
    //Math::Point3D origin(0.0, 0.0, 0.0);
    // std::vector<RayTracer::Sphere> spheres;
    // RayTracer::Sphere sphere1(Math::Point3D(0, 0, -1), 0.5, Math::Point3D(0, 0, 0));
    // RayTracer::Sphere sphere(Math::Point3D(0, -70.5, -1), 100, Math::Point3D(0, 0, 0));
   // spheres.push_back(sphere1); spheres.push_back(sphere);
    
    for (int j = camera->get_height() - 1; j >= 0; j--) {
        for (int i = 0; i < camera->get_width(); i++) {
            double u = double(i) / double(camera->get_width());
            double v = double(j) / double(camera->get_height());
            //RayTracer::Ray ray(origin, top_left + viewport_u * u + viewport_v * v);
            RayTracer::Ray ray = camera->emitRay(u, v);
            it_hits(primitives, ray);
            //Math::Point3D colo = it_hits(primitives, ray);
            ///*Math::Vector3D col =*/ color(ray, primitives);// * 255.99;
            // int ir = int(colo.x);
            // int ig = int(colo.y);
            // int ib = int(colo.z);
            // int ir = int(col._x);
            // int ig = int(col._y);
            // int ib = int(col._z);
            // std::cout << ir << " " << ig << " " << ib << std::endl;
        }
    }
    return 0;
}
