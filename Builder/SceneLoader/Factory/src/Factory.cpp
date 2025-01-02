/*
** EPITECH PROJECT, 2024
** Factory
** File description:
** Factory.cpp
*/

#include "../includes/Factory.hpp"

namespace RayTracer {
    
    std::unique_ptr<IPrimitive> Factory::createPrimitive(const std::string& type, libconfig::Setting& objectSetting) {
        if (type == "plane") {
            return createPlane(objectSetting);
        } else if (type == "sphere") {
            return createSphere(objectSetting);
        } else if (type == "cylinder"){
            return createCylinder(objectSetting);
        } else {
            throw RayTracer::Error("No such Primitive.");
            return nullptr;
        }
    }

    std::unique_ptr<IPrimitive> Factory::createPlane(libconfig::Setting& planesSetting)
    {
        Color color; std::string axis; double position;
        planesSetting.lookupValue("axis", axis);
        position = planesSetting["position"];
        color.r = planesSetting["color"]["r"];
        color.g = planesSetting["color"]["g"];
        color.b = planesSetting["color"]["b"];
        std::unique_ptr<Plane> plane = std::make_unique<Plane>(axis, position, color);
        return std::move(plane);
    }

    std::unique_ptr<IPrimitive> Factory::createSphere(libconfig::Setting& spheresSetting)
    {
        Math::Point3D origin; double radius; Color color;
        origin.x = spheresSetting["x"];
        origin.y = spheresSetting["y"];
        origin.z = spheresSetting["z"];
        radius = spheresSetting["r"];
        color.r = spheresSetting["color"]["r"];
        color.g = spheresSetting["color"]["g"];
        color.b = spheresSetting["color"]["b"];
        std::unique_ptr<Sphere> sphere = std::make_unique<Sphere>(origin, radius, color);
        return std::move(sphere);
    }

    std::unique_ptr<IPrimitive> Factory::createCylinder(libconfig::Setting& cynlinderSetting)
    {
        Math::Point3D center; double radius; double h; Color color;
        center.x = cynlinderSetting["x"];
        center.y = cynlinderSetting["y"];
        center.z = cynlinderSetting["z"];
        radius = cynlinderSetting["r"];
        h = cynlinderSetting["h"];
        color.r = cynlinderSetting["color"]["r"];
        color.g = cynlinderSetting["color"]["g"];
        color.b = cynlinderSetting["color"]["b"];
        std::unique_ptr<Cylinder> cylinder = std::make_unique<Cylinder>(center, radius, h, color);
        return std::move(cylinder);
    }

    std::unique_ptr<ILight> Factory::createLight(const std::string type, libconfig::Setting& lightSetting, libconfig::Setting& settings)
    {
        if (type == "point") return createPointLight(lightSetting, settings);
        else if (type == "directional") return createDirectionaLight(lightSetting, settings);
        else {
            throw RayTracer::Error("No such Light implemented.");
        }
    }

    std::unique_ptr<ILight> Factory::createPointLight(libconfig::Setting& lightSetting, libconfig::Setting& settings)
    {
        double ambient, diffuse, point_x, point_y, point_z;
        ambient = lightSetting["ambient"];
        diffuse = lightSetting["diffuse"];
        point_x = settings["x"];
        point_y = settings["y"];
        point_z = settings["z"];
        std::unique_ptr<PointLight> pointLight = std::make_unique<PointLight>(ambient, diffuse, Math::Point3D(point_x, point_y, point_z));
        return std::move(pointLight);
    }

    std::unique_ptr<ILight> Factory::createDirectionaLight(libconfig::Setting& lightSetting, libconfig::Setting& settings)
    {
        double ambient, diffuse, point_x, point_y, point_z;
        ambient = lightSetting["ambient"];
        diffuse = lightSetting["diffuse"];
        point_x = settings["x"];
        point_y = settings["y"];
        point_z = settings["z"];
        std::unique_ptr<Directional> dirLight = std::make_unique<Directional>(ambient, diffuse, Math::Point3D(point_x, point_y, point_z));
        return std::move(dirLight);
    }
}
