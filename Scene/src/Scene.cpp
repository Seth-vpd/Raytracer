/*
** EPITECH PROJECT, 2024
** Scene
** File description:
** Scene
*/

#include "../includes/Scene.hpp"

namespace RayTracer
{

    Scene::Scene(const Scene &obj)
    {
        camera = std::make_unique<Camera>(*obj.getCamera());
        primitives.clear();
        lights.clear();

        for (const auto& primitive : obj.getPrimitives()) {
            primitives.push_back(primitive->clone());
        }
        for (const auto& light : obj.getLights()) {
            lights.push_back(light->clone());
        }

        for (const auto& transformation : obj.getTransformations()) {
            transformations.push_back(transformation->clone());
        }
    }

    void Scene::setCamera(Camera _camera)
    {
        camera = std::make_unique<Camera>(_camera);
    }

    void Scene::addTransformation(std::unique_ptr<ITransformation> transformation)
    {
        transformations.push_back(std::move(transformation));
    }

    void Scene::addPrimitive(std::unique_ptr<IPrimitive> primitive)
    {
        primitives.push_back(std::move(primitive));
    }

    void Scene::addLight(std::unique_ptr<ILight> light)
    {
        lights.push_back(std::move(light));
    }

    void Scene::render(std::vector<std::unique_ptr<IPrimitive>> &primitives, RayTracer::Ray ray) {
        RayTracer::Hit_info hit_info;
        processTransformations();
        for (size_t i = 0; i < primitives.size(); i++) {
            if (primitives[i]->hits(ray, 0.001, MAXFLOAT, hit_info)) {
                processLight(hit_info);
                std::cout << hit_info.color.r << " " << hit_info.color.g << " " << hit_info.color.b << std::endl;
                return;
            }
        }
        std::cout << 0 << " " << 0 << " " << 0 << std::endl;
        return;
    }
    void Scene::processLight(RayTracer::Hit_info& hit_info)
    {
        for (const auto& light: lights) {
            if (light->getType() == "point") {
                Math::Point3D ligthVecPoint = light->getPosition() - hit_info.hit_point;
                Math::Vector3D lightVec(ligthVecPoint.x, ligthVecPoint.y, ligthVecPoint.z);
                lightVec = Math::normalized(lightVec);
                Math::Vector3D normal(hit_info.normal.x, hit_info.normal.y, hit_info.normal.z);
                normal = Math::normalized(normal);
                double coef = normal.dot(lightVec);
                hit_info.color *= std::abs(coef + light->getAmbient());
            }
        }
    }

    void Scene::processTransformations() {
        for (const auto& transform : transformations) {
            transform->applyTransformation(primitives);
        }
    }

    void Scene::loop() {
        std::cout << "P3" << std::endl << camera->get_width() << " ";
        std::cout << camera->get_height() << std::endl << "255" << std::endl;
        for (int j = camera->get_height() - 1; j >= 0; j--) {
           for (int i = 0; i < camera->get_width(); i++) {
                double u = double(i) / double(camera->get_width());
                double v = double(j) / double(camera->get_height());
                RayTracer::Ray ray = camera->emitRay(u, v);
                render(primitives, ray);
            }
        }
    }
}
