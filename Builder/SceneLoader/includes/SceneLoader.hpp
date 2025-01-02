/*
** EPITECH PROJECT, 2024
** Plane
** File description:
** Plane
*/

#ifndef SCENE_LOADER_HPP_
    #define SCENE_LOADER_HPP_

#include <libconfig.h++>
#include "../../../Camera/includes/Camera.hpp"
#include "../../../Light/Point/includes/PointLight.hpp"
#include "../../../Light/Directional/includes/Directional.hpp"
#include"../../SceneLoader/Factory/includes/Factory.hpp"
#include "../../IBuilder.hpp"

namespace RayTracer
{
    class SceneLoader : IBuilder {
        public:
            SceneLoader(std::string filename);
            ~SceneLoader() {};

            void load_spheres();
            void load_planes();
            void load_points_light();
            void load_cynlinders();
            void load_directionals_light();
            void load_translation();
            int read_config_file(std::string filename);

            void buildCamera();
            void buildPrimitives();
            void buildLights();
            void buildTransformations();
            Scene build() const;

        private:
            libconfig::Config config;
            Factory factory;
            Scene scene;
    };
}

#endif
