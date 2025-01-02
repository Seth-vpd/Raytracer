/*
** EPITECH PROJECT, 2024
** Sphere
** File description:
** Sphere
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <libconfig.h++>
#include "../../../../Utils/includes/c++libs.hpp"
#include "../../../../Primitives/IPrimitive.hpp"
#include "../../../../Primitives/Sphere/includes/Sphere.hpp"
#include "../../../../Primitives/Plane/includes/Plane.hpp"
#include "../../../../Primitives/Cylinder/includes/Cylinder.hpp"
#include "../../../../Light/Directional/includes/Directional.hpp"
#include "../../../../Light/Point/includes/PointLight.hpp"
#include "../../../../Utils/includes/Error.hpp"

namespace RayTracer {
    class Factory {
        public:
            Factory() {};
            ~Factory() {};
            std::unique_ptr<IPrimitive> createPrimitive(const std::string& type, libconfig::Setting& objectSetting);
            std::unique_ptr<IPrimitive> createSphere(libconfig::Setting& spheresSetting);
            std::unique_ptr<IPrimitive> createPlane(libconfig::Setting& spheresSetting);
            std::unique_ptr<IPrimitive> createCylinder(libconfig::Setting& cynlinderSetting);
            std::unique_ptr<ILight> createLight(const std::string type, libconfig::Setting& lightSetting, libconfig::Setting& settings);
            std::unique_ptr<ILight> createPointLight(libconfig::Setting& pointLght, libconfig::Setting& settings);
            std::unique_ptr<ILight> createDirectionaLight(libconfig::Setting& dirLight, libconfig::Setting& settings);

        private:
    };
}

#endif
